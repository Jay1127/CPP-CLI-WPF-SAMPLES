using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
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
