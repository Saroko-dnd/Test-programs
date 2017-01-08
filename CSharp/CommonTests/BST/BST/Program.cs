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
            TestBST.AddNewKeyValuePair(10, "value");
            TestBST.AddNewKeyValuePair(15, "value");
            TestBST.AddNewKeyValuePair(5, "value");
            TestBST.AddNewKeyValuePair(8, "value");
            TestBST.AddNewKeyValuePair(3, "value");
            TestBST.AddNewKeyValuePair(20, "value");
            TestBST.AddNewKeyValuePair(12, "value");
            TestBST.AddNewKeyValuePair(14, "value");
            TestBST.AddNewKeyValuePair(13, "value");
            TestBST.AddNewKeyValuePair(11, "value");

            Console.WriteLine("Inorder traversal of BST (keys):");
            foreach (int FoundInt in TestBST.GetListOfKeysInSortedOrder())
            {
                Console.WriteLine(FoundInt);
            }

            TestBST.DeleteKeyValuePair(15);

            Console.ReadKey();
        }
    }
}
