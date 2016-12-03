using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MergesortBySarokoIV
{
    public static class NonRecursiveMergesort
    {
        private static void Merge(List<int> BufferForDataItems, List<int> CollectionForSortedDataItems, int StartOfLeftArray, int StartOfRightArray, int EndOfRightArray)
        {
            int LeftArrayIndex = StartOfLeftArray;
            int RightArrayIndex = StartOfRightArray;
            
            for (int IndexForResultCollection = StartOfLeftArray; IndexForResultCollection <= EndOfRightArray; ++IndexForResultCollection)
            {
                if (LeftArrayIndex >= StartOfRightArray)
                {
                    CollectionForSortedDataItems[IndexForResultCollection] = BufferForDataItems[RightArrayIndex];
                    ++RightArrayIndex;
                }
                else if (RightArrayIndex > EndOfRightArray)
                {
                    CollectionForSortedDataItems[IndexForResultCollection] = BufferForDataItems[LeftArrayIndex];
                    ++LeftArrayIndex;
                }
                else if (BufferForDataItems[RightArrayIndex] <= BufferForDataItems[LeftArrayIndex])
                {
                    CollectionForSortedDataItems[IndexForResultCollection] = BufferForDataItems[RightArrayIndex];
                    ++RightArrayIndex;
                } 
                else
                {
                    CollectionForSortedDataItems[IndexForResultCollection] = BufferForDataItems[LeftArrayIndex];
                    ++LeftArrayIndex;
                }
            }
        }

        public static void Sort(List<int> CollectionOfDataItems)
        {
            List<int> BufferForDataItems = new List<int>(CollectionOfDataItems);
            int CounterOfCycles = 0;
            for (int SizeOfArray = 1; SizeOfArray < CollectionOfDataItems.Count; SizeOfArray += SizeOfArray)
            {
                for (int StartOfLeftArray = 0; StartOfLeftArray <= CollectionOfDataItems.Count - 1 - SizeOfArray; StartOfLeftArray += (SizeOfArray * 2))
                {
                    if (CounterOfCycles % 2 == 0)
                    {
                        NonRecursiveMergesort.Merge(BufferForDataItems, CollectionOfDataItems, StartOfLeftArray, StartOfLeftArray + SizeOfArray,
                            Math.Min(StartOfLeftArray + (SizeOfArray * 2) - 1, CollectionOfDataItems.Count - 1));
                    }
                    else
                    {
                        NonRecursiveMergesort.Merge(CollectionOfDataItems, BufferForDataItems, StartOfLeftArray, StartOfLeftArray + SizeOfArray,
                           Math.Min(StartOfLeftArray + (SizeOfArray * 2) - 1, CollectionOfDataItems.Count - 1));
                    }
                }
                ++CounterOfCycles;
            }
            if (CounterOfCycles % 2 == 0)
            {
                for(int Index = 0; Index < BufferForDataItems.Count; ++Index)
                {
                    CollectionOfDataItems[Index] = BufferForDataItems[Index];
                }
            }
        }
    }
}
