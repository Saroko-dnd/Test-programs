using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BST.Classes;

namespace BST
{
    class Program
    {
        static void Main(string[] args)
        {
            BST<int, string> TestBST = new BST<int, string>();
            TestBST.AddNewKeyValuePair(1, "value");
            TestBST.AddNewKeyValuePair(2, "value");
            TestBST.AddNewKeyValuePair(3, "value");
            TestBST.AddNewKeyValuePair(4, "value");
            TestBST.AddNewKeyValuePair(5, "value");
            TestBST.AddNewKeyValuePair(-1, "value");
            TestBST.AddNewKeyValuePair(-2, "value");
            TestBST.AddNewKeyValuePair(-3, "value");
            TestBST.AddNewKeyValuePair(-4, "value");
            TestBST.AddNewKeyValuePair(-5, "value");

            Console.WriteLine("Inorder traversal of BST (keys):");
            foreach (int FoundInt in TestBST.GetListOfKeysInSortedOrder())
            {
                Console.WriteLine(FoundInt);
            }

            int LowestKey = -1;
            int HighestKey = 5; 
            Console.WriteLine("Range count (" + LowestKey + ", " + HighestKey + "):");
            Console.WriteLine(TestBST.RangeCount(LowestKey, HighestKey));

            Console.WriteLine("Range keys (" + LowestKey + ", " + HighestKey + "):");
            foreach (int FoundKey in TestBST.RangeKeys(LowestKey, HighestKey))
            {
                Console.WriteLine(FoundKey);
            }

            TestBST.DeleteKeyValuePair(-3);

            Console.ReadKey();
        }
    }
}
