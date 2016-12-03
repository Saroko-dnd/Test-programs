using MergesortBySarokoIV;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MergesortTesting
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> TestListOfIntegersForMyMergesort = new List<int>() {5, 3, 6, 0, 9, 8, 2, 1, 7, -4 };
            NonRecursiveMergesort.Sort(TestListOfIntegersForMyMergesort);
            foreach (int FoundInt in TestListOfIntegersForMyMergesort)
            {
                Console.Write(FoundInt.ToString() + " "); 
            }
            Console.ReadKey();
        }
    }
}
