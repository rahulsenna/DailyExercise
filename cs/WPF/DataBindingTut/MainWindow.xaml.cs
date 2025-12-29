using System.ComponentModel;
using System.Configuration;
using System.Runtime.CompilerServices;
using System.Windows;

namespace DataBindingTut;

/// <summary>
/// Interaction logic for MainWindow.xaml
/// </summary>
public partial class MainWindow : Window, INotifyPropertyChanged
{
    public MainWindow()
    {
        DataContext = this;
        InitializeComponent();
    }
    private string boundText;

    public event PropertyChangedEventHandler? PropertyChanged;

    public string BoundText
    {
        get { return boundText; }
        set
        {
            boundText = value;
            OnPropertyChanged();
        }
    }

    void OnPropertyChanged([CallerMemberName] string PropertyName = null)
    {
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(PropertyName));
    }

    private void btnSet_Click(object sender, RoutedEventArgs e)
    {
        BoundText = "Set from btn click";
    }
}