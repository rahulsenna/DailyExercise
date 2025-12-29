using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using CustomWindowsAndDiaglogs.View;

namespace CustomWindowsAndDiaglogs;


public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    private void btnNormal_Click(object sender, RoutedEventArgs e)
    {
        var window = new NormalWindow();
        window.Show();
    }

    private void btnModal_Click(object sender, RoutedEventArgs e)
    {
        var modal = new ModalWindow(this);
        Opacity = .4;
        modal.ShowDialog();
        Opacity = 1;
        if (modal.Success)
        {
            txtInput.Text = modal.Input;
        }
    }
}