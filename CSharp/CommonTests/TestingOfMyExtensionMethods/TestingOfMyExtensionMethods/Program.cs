using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TestingOfMyExtensionMethods.ClassesWichContainExtensionMethods;
using TestingOfMyExtensionMethods.Resources;

namespace TestingOfMyExtensionMethods
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder TestObject = new StringBuilder(Texts.TestStringForStringBuilderClass);

            Console.WriteLine("\n\n");
            Console.WriteLine(Texts.BeforeExstensionMethod);
            Console.WriteLine();
            Console.WriteLine(TestObject.ToString());

            int AmountOfLinesToDelete = 2;
            TestObject.DeleteLinesFromBeginning(AmountOfLinesToDelete);

            Console.WriteLine("\n\n");
            Console.Write(Texts.AfterExstensionMethod);
            Console.Write("(" + Texts.Deleted + " " + AmountOfLinesToDelete.ToString() + " " + Texts.Lines + "):\n");
            Console.WriteLine();
            Console.WriteLine(TestObject.ToString());

            Console.ReadKey();
        }
    }
}
