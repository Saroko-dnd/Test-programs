using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestingOfMyExtensionMethods.ClassesWichContainExtensionMethods
{
    public static class ExtensionMethodsForStringBuilderClass
    {
        //It removes a specified number of lines from the beginning of the string
        public static void DeleteLinesFromBeginning(this StringBuilder CurrentStringBuilder, int AmountOfLines)
        {
            string[] BufferForText = CurrentStringBuilder.ToString().Split('\n');

            CurrentStringBuilder.Clear();

            for (int Index = AmountOfLines; Index < BufferForText.Count(); ++Index)
            {
                CurrentStringBuilder.Append(BufferForText[Index] + "\n");
            }
        }
    }
}
