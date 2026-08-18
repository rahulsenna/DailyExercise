#define NS_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#define MTK_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION

#include <Metal/Metal.hpp>
#include <MetalKit/MetalKit.hpp>

#define NSSTR(x) NS::String::string(x, NS::StringEncoding::UTF8StringEncoding)

NS::Window* Window;
MTK::View* View;
MTL::Device* Device;
MTL::CommandQueue* CommandQueue;

MTL::RenderPipelineState* PipelineState;


class MyViewDelegate : public MTK::ViewDelegate
{
  void drawInMTKView(MTK::View* View) override
  {
    auto pool = NS::AutoreleasePool::alloc()->init();

    auto CmdBuffer = CommandQueue->commandBuffer();
    auto Enc = CmdBuffer->renderCommandEncoder(View->currentRenderPassDescriptor());

    Enc->setRenderPipelineState(PipelineState);
    Enc->drawPrimitives(MTL::PrimitiveType::PrimitiveTypeTriangle, NS::UInteger(0), NS::UInteger(3));
    Enc->endEncoding();

    CmdBuffer->presentDrawable(View->currentDrawable());
    CmdBuffer->commit();
    pool->release();
  }
};

MyViewDelegate GameViewDelegate;

class MyAppDelegate : public NS::ApplicationDelegate
{
public:
  void applicationWillFinishLaunching(NS::Notification* Notification) override
  {
    auto App = (NS::Application*) Notification->object();
    App->setActivationPolicy(NS::ActivationPolicy::ActivationPolicyRegular);
  }
  void applicationDidFinishLaunching(NS::Notification* Notification) override
  {
    CGRect Frame = { 0,0,1000,1000 };

    Window = NS::Window::alloc()->init(
      Frame,
      NS::WindowStyleMaskTitled|NS::WindowStyleMaskClosable,
      NS::BackingStoreBuffered,
      false
    );

    Device = MTL::CreateSystemDefaultDevice();
    CommandQueue = Device->newCommandQueue();

    View = MTK::View::alloc()->init(Frame, Device);
    View->setDelegate(&GameViewDelegate);
    View->setColorPixelFormat(MTL::PixelFormatBGRA8Unorm_sRGB);
    View->setClearColor(MTL::ClearColor::Make(1, 1, 0.5, 1));

    auto libUrl = NS::URL::fileURLWithPath(NSSTR("default.metallib"));
    NS::Error* err;

    MTL::Library* lib = Device->newLibrary(libUrl, &err);
    auto vertFn = lib->newFunction(NSSTR("VertFn"));
    auto fragFn = lib->newFunction(NSSTR("FragFn"));

    auto Desc = MTL::RenderPipelineDescriptor::alloc()->init();
    Desc->setFragmentFunction(fragFn);
    Desc->setVertexFunction(vertFn);
    Desc->colorAttachments()->object(0)->setPixelFormat(View->colorPixelFormat());


    PipelineState = Device->newRenderPipelineState(Desc, &err);



    Window->setTitle(NSSTR("Hello"));
    Window->setContentView(View);
    Window->makeKeyAndOrderFront(0);

    auto App = (NS::Application*) Notification->object();
    App->activateIgnoringOtherApps(true);
  }
  bool applicationShouldTerminateAfterLastWindowClosed(NS::Application* Application) override
  {
    return true;
  }
};

MyAppDelegate GameDelegate;

int main()
{
  NS::AutoreleasePool::alloc()->init();

  auto App = NS::Application::sharedApplication();
  App->setDelegate(&GameDelegate);
  App->run();
  return 0;
}
