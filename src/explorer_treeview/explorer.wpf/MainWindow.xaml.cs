using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Threading.Tasks;
using System.Windows;
using Microsoft.WindowsAPICodePack.Dialogs;

namespace Explorer.Wpf
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window, INotifyPropertyChanged
    {
        public string RootPath { get; set; }
        
        public ObservableCollection<DirectoryEntityWrapper> Root { get; set; }

        public event PropertyChangedEventHandler PropertyChanged;

        public MainWindow()
        {
            InitializeComponent();
            this.DataContext = this;

            Root = new ObservableCollection<DirectoryEntityWrapper>();
        }

        private void NotityPropertyChanged([CallerMemberName] string propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        private async void OnOpenButtonClicked(object sender, RoutedEventArgs e)
        {
            string filePath = string.Empty;

            using (var dialog = new CommonOpenFileDialog())
            {
                dialog.IsFolderPicker = true;
                if (dialog.ShowDialog() == CommonFileDialogResult.Ok)
                {
                    filePath = dialog.FileName;
                }
            }

            if (!string.IsNullOrEmpty(filePath))
            {
                await Task.Run(() =>
                {
                    App.Current.Dispatcher.Invoke(() =>
                    {
                        Root.Clear();
                        Root.Add(new DirectoryEntityWrapper(filePath));
                    });
                });

                RootPath = filePath;
                NotityPropertyChanged(nameof(RootPath));
            }
        }
    }
}
