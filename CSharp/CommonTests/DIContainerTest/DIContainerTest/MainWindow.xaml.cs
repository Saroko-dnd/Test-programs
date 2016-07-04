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
using DIContainerTest.Resources;

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
            IKernel FirstTestKernelObject = new StandardKernel();
            FirstTestKernelObject.Bind<IWeapon>().To<Bow>();
            Warrior FirstTestWarriorObject = FirstTestKernelObject.Get<Warrior>();
            LabelFirstWarriorGear.Content = FirstTestWarriorObject.GetGearAsString();

            //Example with constructor
            IKernel SecondTestKernelObject = new StandardKernel();
            SecondTestKernelObject.Bind<IWeapon>().To<Sword>().WithConstructorArgument(Texts.ConstructorArgumentName, Texts.Material);
            Warrior SecondTestWarriorObject = SecondTestKernelObject.Get<Warrior>();
            LabelSecondWarriorGear.Content = SecondTestWarriorObject.GetGearAsString();

            //Both classes have constructors
            IKernel ThirdTestKernelObject = new StandardKernel();
            ThirdTestKernelObject.Bind<IWeapon>().To<Sword>().WithConstructorArgument(Texts.ConstructorArgumentName, Texts.Material);
            var ParameterForConstructor = new Ninject.Parameters.ConstructorArgument(Texts.ConsrtuctotArgumentNameForWarrior, Texts.NameOfWarrior);
            WarriorWithConstructor TestWarriorWithConstructorObject = ThirdTestKernelObject.Get<WarriorWithConstructor>(ParameterForConstructor);
            LabeldWarriorWithConstructorGear.Content = TestWarriorWithConstructorObject.GetGearAsString();
        }
    }
}
