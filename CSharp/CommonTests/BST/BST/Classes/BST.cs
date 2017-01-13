using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BST.Classes
{
    class BST<KeyType, ValueType> where KeyType : IComparable<KeyType>
    {
        private static bool Red = true;
        private static bool Black = false;

        private object GatesToInorderTraversal = new object();

        private Node<KeyType, ValueType> RootNode = null;

        private int GetSizeOfNode(Node<KeyType, ValueType> SelectedNode)
        {
            if (SelectedNode == null)
            {
                return 0;
            }
            else
            {
                return SelectedNode.Size;
            }
        }

        private Node<KeyType, ValueType> Min(Node<KeyType, ValueType> RootOfTreeForSearch)
        {

            if (RootOfTreeForSearch == null)
            {
                return null;
            }
            while (RootOfTreeForSearch.LeftNode != null)
            {
                RootOfTreeForSearch = RootOfTreeForSearch.LeftNode;
            }

            return RootOfTreeForSearch;
        }

        private Node<KeyType, ValueType> Max(Node<KeyType, ValueType> RootOfTreeForSearch)
        {

            if (RootOfTreeForSearch == null)
            {
                return null;
            }
            while (RootOfTreeForSearch.RightNode != null)
            {
                RootOfTreeForSearch = RootOfTreeForSearch.RightNode;
            }

            return RootOfTreeForSearch;
        }

        private Node<KeyType, ValueType> MoveRedRight(Node<KeyType, ValueType> SelectedNode)
        {
            FlipColors(SelectedNode);
            if (IsRed(SelectedNode.LeftNode.LeftNode))
            {
                SelectedNode = RotateRight(SelectedNode);
                FlipColors(SelectedNode);
            }
            return SelectedNode;
        }

        private Node<KeyType, ValueType> MoveRedLeft(Node<KeyType, ValueType> SelectedNode)
        {
            FlipColors(SelectedNode);
            if (IsRed(SelectedNode.RightNode.LeftNode))
            {
                SelectedNode.RightNode = RotateRight(SelectedNode.RightNode);
                SelectedNode = RotateLeft(SelectedNode);
                FlipColors(SelectedNode);
            }
            return SelectedNode;
        }

        private Node<KeyType, ValueType> _DeleteMax(Node<KeyType, ValueType> RootOfTreeForSearch)
        {
            if (RootOfTreeForSearch == null)
            {
                return null;
            }
            if (IsRed(RootOfTreeForSearch.LeftNode))
            {
                RootOfTreeForSearch = RotateRight(RootOfTreeForSearch);
            }
            if (RootOfTreeForSearch.RightNode == null)
            {
                return null;
            }
            if (!IsRed(RootOfTreeForSearch.RightNode) && !IsRed(RootOfTreeForSearch.RightNode.LeftNode))
            {
                RootOfTreeForSearch = MoveRedRight(RootOfTreeForSearch);
            }

            RootOfTreeForSearch.RightNode = _DeleteMax(RootOfTreeForSearch.RightNode);
            return BalanceSelectedNode(RootOfTreeForSearch);
        }

        private Node<KeyType, ValueType> _DeleteMin(Node<KeyType, ValueType> RootOfTreeForSearch)
        {
            if (RootOfTreeForSearch == null)
            {
                return null;
            }
            if (RootOfTreeForSearch.LeftNode == null)
            {
                return null;
            }
            if (!IsRed(RootOfTreeForSearch.LeftNode) && !IsRed(RootOfTreeForSearch.LeftNode.LeftNode))
            {
                RootOfTreeForSearch = MoveRedLeft(RootOfTreeForSearch);
            }

            RootOfTreeForSearch.LeftNode = _DeleteMin(RootOfTreeForSearch.LeftNode);
            return BalanceSelectedNode(RootOfTreeForSearch);
        }

        private Node<KeyType, ValueType> BalanceSelectedNode(Node<KeyType, ValueType> SelectedNode)
        {
            if (SelectedNode.LeftNode != null && SelectedNode.LeftNode.LeftNode != null)
            {
                if (IsRed(SelectedNode.LeftNode) && IsRed(SelectedNode.LeftNode.LeftNode))
                {
                    SelectedNode = RotateRight(SelectedNode);
                }
            }

            if (IsRed(SelectedNode.LeftNode) && IsRed(SelectedNode.RightNode))
            {
                SelectedNode = FlipColors(SelectedNode);
            }

            if (IsRed(SelectedNode.RightNode))
            {
                SelectedNode = RotateLeft(SelectedNode);
            }

            SelectedNode.Size = 1 + GetSizeOfNode(SelectedNode.LeftNode) + GetSizeOfNode(SelectedNode.RightNode);
            return SelectedNode;
        }

        private Node<KeyType, ValueType> FlipColors(Node<KeyType, ValueType> CurrentNode)
        {

            if (CurrentNode.LinkColor == Red)
            {
                CurrentNode.LinkColor = Black;
            }
            else
            {
                CurrentNode.LinkColor = Red;
            }
            if (CurrentNode.RightNode != null)
            {
                if (CurrentNode.RightNode.LinkColor == Red)
                {
                    CurrentNode.RightNode.LinkColor = Black;
                }
                else
                {
                    CurrentNode.RightNode.LinkColor = Red;
                }
            }
            if (CurrentNode.LeftNode != null)
            {
                if (CurrentNode.LeftNode.LinkColor == Red)
                {
                    CurrentNode.LeftNode.LinkColor = Black;
                }
                else
                {
                    CurrentNode.LeftNode.LinkColor = Red;
                }
            }
            return CurrentNode;
        }

        private bool IsRed(Node<KeyType, ValueType> CurrentNode)
        {
            if (CurrentNode == null)
            {
                return Black;
            }
            else
            {
                return CurrentNode.LinkColor;
            }
        }

        private Node<KeyType, ValueType> RotateLeft(Node<KeyType, ValueType> CurrentNode)
        {
            Node<KeyType, ValueType> BufferForRightNode = CurrentNode.RightNode;
            BufferForRightNode.LinkColor = CurrentNode.LinkColor;
            CurrentNode.RightNode = BufferForRightNode.LeftNode;
            CurrentNode.LinkColor = Red;
            BufferForRightNode.LeftNode = CurrentNode;

            CurrentNode.Size = 1 + GetSizeOfNode(CurrentNode.LeftNode) + GetSizeOfNode(CurrentNode.RightNode);
            BufferForRightNode.Size = 1 + GetSizeOfNode(BufferForRightNode.LeftNode) + GetSizeOfNode(BufferForRightNode.RightNode);

            return BufferForRightNode;
        }

        private Node<KeyType, ValueType> RotateRight(Node<KeyType, ValueType> CurrentNode)
        {
            Node<KeyType, ValueType> BufferForLeftNode = CurrentNode.LeftNode;
            BufferForLeftNode.LinkColor = CurrentNode.LinkColor;
            CurrentNode.LeftNode = BufferForLeftNode.RightNode;
            BufferForLeftNode.RightNode = CurrentNode;
            CurrentNode.LinkColor = Red;

            CurrentNode.Size = 1 + GetSizeOfNode(CurrentNode.LeftNode) + GetSizeOfNode(CurrentNode.RightNode);
            BufferForLeftNode.Size = 1 + GetSizeOfNode(BufferForLeftNode.LeftNode) + GetSizeOfNode(BufferForLeftNode.RightNode);

            return BufferForLeftNode;
        }

        private Node<KeyType, ValueType> AddKeyValueToBST(Node<KeyType, ValueType> CurrentNode, KeyType NewKey, ValueType NewValue)
        {
            if (CurrentNode == null)
            {
                return new Node<KeyType, ValueType>(NewKey, NewValue) { LinkColor = Red };
            }
            else
            {
                int CmpResult = NewKey.CompareTo(CurrentNode.Key);

                if (CmpResult == 0)
                {
                    CurrentNode.Value = NewValue;
                    return CurrentNode;
                }

                else if (CmpResult < 0)
                {
                    CurrentNode.LeftNode = AddKeyValueToBST(CurrentNode.LeftNode, NewKey, NewValue);
                }
                else if (CmpResult > 0)
                {
                    CurrentNode.RightNode = AddKeyValueToBST(CurrentNode.RightNode, NewKey, NewValue);
                }

            }

            if (CurrentNode.LeftNode != null && CurrentNode.LeftNode.LeftNode != null)
            {
                if (IsRed(CurrentNode.LeftNode) && IsRed(CurrentNode.LeftNode.LeftNode))
                {
                    CurrentNode = RotateRight(CurrentNode);
                }
            }
            if (IsRed(CurrentNode.LeftNode) && IsRed(CurrentNode.RightNode))
            {
                CurrentNode = FlipColors(CurrentNode);
            }

            if (CurrentNode.RightNode != null && CurrentNode.RightNode.LinkColor == Red)
            {
                CurrentNode = RotateLeft(CurrentNode);
            }


            CurrentNode.Size = 1 + GetSizeOfNode(CurrentNode.LeftNode) + GetSizeOfNode(CurrentNode.RightNode);
            return CurrentNode;
        }

        private Node<KeyType, ValueType> _DeleteKeyValuePair(Node<KeyType, ValueType> CurrentNode, KeyType KeyForSearch)
        {
            if (CurrentNode == null)
            {
                return CurrentNode;
            }
            else
            {
                int CmpResult = KeyForSearch.CompareTo(CurrentNode.Key);

                if (CmpResult < 0)
                {
                    if (CurrentNode.LeftNode == null)
                    {
                        return CurrentNode;
                    }
                    if (!IsRed(CurrentNode.LeftNode) && !IsRed(CurrentNode.LeftNode.LeftNode))
                    {
                        CurrentNode = MoveRedLeft(CurrentNode);
                    }
                    CurrentNode.LeftNode = _DeleteKeyValuePair(CurrentNode.LeftNode, KeyForSearch);
                }
                else if (CmpResult > 0)
                {
                    if (IsRed(CurrentNode.LeftNode))
                    {
                        CurrentNode = RotateRight(CurrentNode);
                    }
                    if (CurrentNode.RightNode == null)
                    {
                        return CurrentNode;
                    }
                    if (!IsRed(CurrentNode.RightNode) && !IsRed(CurrentNode.RightNode.LeftNode))
                    {
                        MoveRedRight(CurrentNode);
                    }
                    CurrentNode.RightNode = _DeleteKeyValuePair(CurrentNode.RightNode, KeyForSearch);
                }
                else
                {
                    Node<KeyType, ValueType> BufferForCurrentNode = CurrentNode;
                    Node<KeyType, ValueType> NodeWithReplacements = null;
                    bool MaxMustBeDeleted = false;

                    if (CurrentNode.LeftNode == null)
                    {
                        NodeWithReplacements = Min(CurrentNode.RightNode);
                    }
                    else if (CurrentNode.RightNode == null)
                    {
                        NodeWithReplacements = Max(CurrentNode.LeftNode);
                        MaxMustBeDeleted = true;
                    }
                    else
                    {
                        NodeWithReplacements = Max(CurrentNode.LeftNode);
                        MaxMustBeDeleted = true;
                    }

                    if (NodeWithReplacements == null)
                    {
                        return null;
                    }
                    else
                    {
                        CurrentNode.Key = NodeWithReplacements.Key;
                        CurrentNode.Value = NodeWithReplacements.Value;

                        if (MaxMustBeDeleted)
                        {
                            CurrentNode.LeftNode = _DeleteMax(CurrentNode.LeftNode);
                        }
                        else
                        {
                            CurrentNode.RightNode = _DeleteMin(CurrentNode.RightNode);
                        }
                    }
                }
            }

            CurrentNode = BalanceSelectedNode(CurrentNode);
            return CurrentNode;
        }

        private int _RangeCount(Node<KeyType, ValueType> CurrentNode, KeyType LowestKey, KeyType HigestKey)
        {
            if (CurrentNode == null)
            {
                return 0;
            }
            else
            {
                int Counter = 0;
                int CmpResultForLowestKey = CurrentNode.Key.CompareTo(LowestKey);
                int CmpResultForHigestKey = CurrentNode.Key.CompareTo(HigestKey);
                if (CmpResultForLowestKey > 0 && CurrentNode.LeftNode != null)
                {
                    Counter += _RangeCount(CurrentNode.LeftNode, LowestKey, HigestKey);
                }
                if (CmpResultForLowestKey >= 0 && CmpResultForHigestKey <= 0)
                {
                    Counter += 1;
                }
                if (CmpResultForHigestKey < 0 && CurrentNode.RightNode != null)
                {
                    Counter += _RangeCount(CurrentNode.RightNode, LowestKey, HigestKey);
                }
                return Counter;
            }
        }

        private List<KeyType> _RangeKeys(Node<KeyType, ValueType> CurrentNode, KeyType LowestKey, KeyType HigestKey, List<KeyType> ListForKeys)
        {
            if (CurrentNode == null)
            {
                return ListForKeys;
            }
            else
            {
                int CmpResultForLowestKey = CurrentNode.Key.CompareTo(LowestKey);
                int CmpResultForHigestKey = CurrentNode.Key.CompareTo(HigestKey);
                if (CmpResultForLowestKey > 0 && CurrentNode.LeftNode != null)
                {
                    _RangeKeys(CurrentNode.LeftNode, LowestKey, HigestKey, ListForKeys);
                }
                if (CmpResultForLowestKey >= 0 && CmpResultForHigestKey <= 0)
                {
                    ListForKeys.Add(CurrentNode.Key);
                }
                if (CmpResultForHigestKey < 0 && CurrentNode.RightNode != null)
                {
                    _RangeKeys(CurrentNode.RightNode, LowestKey, HigestKey, ListForKeys);
                }
                return ListForKeys;
            }
        }

        private class Node<_KeyType, _ValueType>
        {
            public int Size { get; set; }
            public _KeyType Key {get; set;}
            public _ValueType Value { get; set; }
            public Node<_KeyType, _ValueType> LeftNode { get; set; }
            public Node<_KeyType, _ValueType> RightNode { get; set; }
            public bool LinkColor { get; set; }

            public Node(_KeyType NewKey, _ValueType NewValue)
            {
                Key = NewKey;
                Value = NewValue;
                Size = 1;
                LeftNode = null;
                RightNode = null;
            }
        }

        public void AddNewKeyValuePair(KeyType NewKey, ValueType NewValue)
        {
            RootNode = AddKeyValueToBST(RootNode, NewKey, NewValue);
            RootNode.LinkColor = Black;
        }

        public List<KeyType> GetListOfKeysInSortedOrder()
        {
            Node<KeyType, ValueType> CurrentRootNode = RootNode;
            Node<KeyType, ValueType> CurrentOperationNode = null;
            List<KeyType> ListOfSortedKeys = new List<KeyType>();

            lock (GatesToInorderTraversal)
            {
                while (CurrentRootNode != null)
                {
                    if (CurrentRootNode.LeftNode != null)
                    {
                        CurrentOperationNode = CurrentRootNode.LeftNode;
                        while (CurrentOperationNode.RightNode != null && CurrentOperationNode.RightNode != CurrentRootNode)
                        {
                            CurrentOperationNode = CurrentOperationNode.RightNode;
                        }
                        if (CurrentOperationNode.RightNode == null)
                        {
                            CurrentOperationNode.RightNode = CurrentRootNode;
                            CurrentRootNode = CurrentRootNode.LeftNode;
                        }
                        else
                        {
                            CurrentOperationNode.RightNode = null;
                            ListOfSortedKeys.Add(CurrentRootNode.Key);
                            CurrentRootNode = CurrentRootNode.RightNode;
                        }
                    }
                    else
                    {
                        ListOfSortedKeys.Add(CurrentRootNode.Key);
                        CurrentRootNode = CurrentRootNode.RightNode;
                    }
                }
            }

            return ListOfSortedKeys;
        }

        public void DeleteKeyValuePair(KeyType KeyForSearch)
        {
            RootNode = _DeleteKeyValuePair(RootNode, KeyForSearch);
            RootNode.LinkColor = Black;
        }

        public int RangeCount(KeyType LowestKey, KeyType HigestKey)
        {
            return _RangeCount(RootNode, LowestKey, HigestKey);
        }

        public List<KeyType> RangeKeys(KeyType LowestKey, KeyType HigestKey)
        {
            List<KeyType> ListForKeys = new List<KeyType>();
            return _RangeKeys(RootNode, LowestKey, HigestKey, ListForKeys);
        }

        public void DeleteMax()
        {
            RootNode = _DeleteMax(RootNode);
            RootNode.LinkColor = Black;
        }

        public void DeleteMin()
        {
            RootNode = _DeleteMin(RootNode);
            RootNode.LinkColor = Black;
        }
    }
}
