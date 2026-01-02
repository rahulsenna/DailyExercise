using System.Collections.ObjectModel;
using ViewModelsInMVVM.Model;
using ViewModelsInMVVM.MVVM;

namespace ViewModelsInMVVM.ViewModel
{
    internal class MainWindowViewModel : ViewModelBase
    {
        public RelayCommand AddCommand => new RelayCommand(execute => AddItem());
        public RelayCommand DeleteCommand => new RelayCommand(execute => DeleteItem(), canExecute => selctedItem != null);
        public ObservableCollection<Item> Items { get; set; }

        public MainWindowViewModel()
        {
            Items = new ObservableCollection<Item>();
            Items.Add(new Item { Name = "Product1", SerialNumber = "001", Quantity = 4 });
            Items.Add(new Item { Name = "Product2", SerialNumber = "002", Quantity = 2 });
            Items.Add(new Item { Name = "Product3", SerialNumber = "003", Quantity = 5 });
        }

        private Item selctedItem;

        public Item SelectedItem
        {
            get { return selctedItem; }
            set { 
                selctedItem = value;
                OnPropertyChaned();
            }
        }

        private void AddItem()
        {
            Items.Add(new Item { Name = "NEW ITEM", SerialNumber = "XXXX", Quantity = 4 });
        }
        private void DeleteItem()
        {
            Items.Remove(selctedItem);
        }
    }


}
