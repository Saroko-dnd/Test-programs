using System;
using System.Collections.Generic;
using System.Linq;
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
using Ninject;
using DIContainerTest.TestClasses;

namespace DIContainerTest
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            //Example without constructor
            IKernel TestKernelObject = new StandardKernel();
            TestKernelObject.Bind<IWeapon>().To<Bow>();
            Warrior TestWarriorObject = TestKernelObject.Get<Warrior>();
            LabelWarriorGear.Content = TestWarriorObject.GetGearAsString();
        }
    }
}
