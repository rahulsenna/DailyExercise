#define NS_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#define MTK_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#include <Metal/Metal.hpp>
#include <AppKit/AppKit.hpp>
#include <MetalKit/MetalKit.hpp>


#include <stdint.h>

#define internal static
#define local_persist static
#define global_variable static

#define Assert(Expression) if(!(Expression)) {*(volatile int *)0 = 0;}

struct mac_state
{
  MTL::Device* Device;
  MTL::CommandQueue* CommandQueue;
  NS::Window* Window;
  MTK::View* View;
};

global_variable mac_state GlobalState;


internal NS::Menu*
MacCreateMenuBar(void)
{
  using NS::StringEncoding::UTF8StringEncoding;

  NS::Menu* MainMenu = NS::Menu::alloc()->init();
  NS::MenuItem* AppMenuItem = NS::MenuItem::alloc()->init();
  NS::Menu* AppMenu = NS::Menu::alloc()->init(NS::String::string("Appname", UTF8StringEncoding));

  NS::String* AppName = NS::RunningApplication::currentApplication()->localizedName();
  NS::String* QuitItemName = NS::String::string("Quit ", UTF8StringEncoding)->stringByAppendingString(AppName);

  SEL QuitCb = NS::MenuItem::registerActionCallback("appQuit", [](void* Context, SEL Sel, const NS::Object* Sender) {
    NS::Application* App = NS::Application::sharedApplication();
    App->terminate(Sender);
    });

  NS::MenuItem* AppQuitItem = AppMenu->addItem(QuitItemName, QuitCb, NS::String::string("q", UTF8StringEncoding));
  AppQuitItem->setKeyEquivalentModifierMask(NS::EventModifierFlagCommand);
  AppMenuItem->setSubmenu(AppMenu);

  NS::MenuItem* WindowMenuItem = NS::MenuItem::alloc()->init();
  NS::Menu* WindowMenu = NS::Menu::alloc()->init(NS::String::string("Window", UTF8StringEncoding));

  SEL CloseWindowCb = NS::MenuItem::registerActionCallback("windowClose", [](void* Context, SEL Sel, const NS::Object* Sender) {
    NS::Application* App = NS::Application::sharedApplication();
    App->windows()->object<NS::Window>(0)->close();
    });

  NS::MenuItem* CloseWindowItem = WindowMenu->addItem(NS::String::string("Close Window", UTF8StringEncoding), CloseWindowCb, NS::String::string("w", UTF8StringEncoding));
  CloseWindowItem->setKeyEquivalentModifierMask(NS::EventModifierFlagCommand);

  WindowMenuItem->setSubmenu(WindowMenu);

  MainMenu->addItem(AppMenuItem);
  MainMenu->addItem(WindowMenuItem);

  AppMenuItem->release();
  WindowMenuItem->release();
  AppMenu->release();
  WindowMenu->release();

  return MainMenu->autorelease();
}

internal void
MacRenderFrame(MTK::View* View)
{
  NS::AutoreleasePool* Pool = NS::AutoreleasePool::alloc()->init();

  MTL::CommandBuffer* Cmd = GlobalState.CommandQueue->commandBuffer();
  MTL::RenderPassDescriptor* Rpd = View->currentRenderPassDescriptor();
  MTL::RenderCommandEncoder* Enc = Cmd->renderCommandEncoder(Rpd);

  Enc->endEncoding();
  Cmd->presentDrawable(View->currentDrawable());
  Cmd->commit();

  Pool->release();
}



// Metal/AppKit Delegates
// Because Metal-cpp requires classes, we keep these as thin wrappers
// that immediately pass through to our procedural functions.

class MacViewDelegate : public MTK::ViewDelegate
{
public:
  virtual ~MacViewDelegate() override = default;

  virtual void drawInMTKView(MTK::View* View) override
  {
    MacRenderFrame(View);
  }
};
global_variable MacViewDelegate GlobalViewDelegate;

class MacAppDelegate : public NS::ApplicationDelegate
{
public:
  ~MacAppDelegate()
  {
    if (GlobalState.View) GlobalState.View->release();
    if (GlobalState.Window) GlobalState.Window->release();
    if (GlobalState.CommandQueue) GlobalState.CommandQueue->release();
    if (GlobalState.Device) GlobalState.Device->release();
  }

  virtual void applicationWillFinishLaunching(NS::Notification* Notification) override
  {
    NS::Menu* Menu = MacCreateMenuBar();
    NS::Application* App = reinterpret_cast<NS::Application*>(Notification->object());
    App->setMainMenu(Menu);
    App->setActivationPolicy(NS::ActivationPolicy::ActivationPolicyRegular);
  }

  virtual void applicationDidFinishLaunching(NS::Notification* Notification) override
  {
    CGRect Frame = (CGRect){ {100.0, 100.0}, {1024.0, 1024.0} };

    GlobalState.Window = NS::Window::alloc()->init(
      Frame,
      NS::WindowStyleMaskClosable|NS::WindowStyleMaskTitled,
      NS::BackingStoreBuffered,
      false);

    GlobalState.Device = MTL::CreateSystemDefaultDevice();
    GlobalState.CommandQueue = GlobalState.Device->newCommandQueue();

    GlobalState.View = MTK::View::alloc()->init(Frame, GlobalState.Device);
    GlobalState.View->setColorPixelFormat(MTL::PixelFormat::PixelFormatBGRA8Unorm_sRGB);
    GlobalState.View->setClearColor(MTL::ClearColor::Make(1.0, 1.0, 0.6, 1.0));

    GlobalState.View->setDelegate(&GlobalViewDelegate);

    GlobalState.Window->setContentView(GlobalState.View);
    GlobalState.Window->setTitle(NS::String::string("ThisWindowSucks", NS::StringEncoding::UTF8StringEncoding));
    GlobalState.Window->makeKeyAndOrderFront(nullptr);

    NS::Application* App = reinterpret_cast<NS::Application*>(Notification->object());
    App->activateIgnoringOtherApps(true);
  }

  virtual bool applicationShouldTerminateAfterLastWindowClosed(NS::Application* Sender) override
  {
    return true;
  }
};

global_variable MacAppDelegate GlobalAppDelegate;


int main(int Argc, char** Argv)
{
  NS::AutoreleasePool* AutoreleasePool = NS::AutoreleasePool::alloc()->init();

  NS::Application* SharedApplication = NS::Application::sharedApplication();
  SharedApplication->setDelegate(&GlobalAppDelegate);
  SharedApplication->run();

  AutoreleasePool->release();

  return 0;
}