using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BST.Classes
{
    class BST<KeyType, ValueType> where KeyType : IComparable<KeyType>
    {
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

        private Node<KeyType, ValueType> Max(Node<KeyType, ValueType> RootOfTreeForSearch)
        {

            while (RootOfTreeForSearch.RightNode != null)
            {
                RootOfTreeForSearch = RootOfTreeForSearch.RightNode;
            }

            return RootOfTreeForSearch;
        }

        private Node<KeyType, ValueType> DeleteMax(Node<KeyType, ValueType> RootOfTreeForSearch)
        {

            if(RootOfTreeForSearch.RightNode != null)
            {
                RootOfTreeForSearch.RightNode = DeleteMax(RootOfTreeForSearch.RightNode);
                RootOfTreeForSearch.Size = 1 + GetSizeOfNode(RootOfTreeForSearch.LeftNode) + GetSizeOfNode(RootOfTreeForSearch.RightNode);
                return RootOfTreeForSearch;
            }
            else 
            {
                return RootOfTreeForSearch.LeftNode;
            }

        }

        private Node<KeyType, ValueType> AddKeyValueToBST(Node<KeyType, ValueType> CurrentNode, KeyType NewKey, ValueType NewValue)
        {
            if (CurrentNode == null)
            {
                return new Node<KeyType, ValueType>(NewKey, NewValue);
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
                    CurrentNode.LeftNode = _DeleteKeyValuePair(CurrentNode.LeftNode, KeyForSearch);
                }
                else if (CmpResult > 0)
                {
                    CurrentNode.RightNode = _DeleteKeyValuePair(CurrentNode.RightNode, KeyForSearch);
                }
                else
                {
                    if (CurrentNode.LeftNode == null)
                    {
                        return CurrentNode.RightNode;
                    }
                    else if (CurrentNode.RightNode == null)
                    {
                        return CurrentNode.LeftNode;
                    }
                    else
                    {
                        Node<KeyType, ValueType> BufferForCurrentNode = CurrentNode;
                        CurrentNode = Max(BufferForCurrentNode.LeftNode);
                        BufferForCurrentNode.LeftNode = DeleteMax(BufferForCurrentNode.LeftNode);
                        CurrentNode.LeftNode = BufferForCurrentNode.LeftNode;
                        CurrentNode.RightNode = BufferForCurrentNode.RightNode;
                    }
                }
            }
            CurrentNode.Size = 1 + GetSizeOfNode(CurrentNode.LeftNode) + GetSizeOfNode(CurrentNode.RightNode);
            return CurrentNode;
        }

        private class Node<_KeyType, _ValueType>
        {
            public int Size { get; set; }
            public _KeyType Key {get; set;}
            public _ValueType Value { get; set; }
            public Node<_KeyType, _ValueType> LeftNode { get; set; }
            public Node<_KeyType, _ValueType> RightNode { get; set; }

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
        }
    }
}
