
var Colors = {black:1, red:2};
var ThisIsLeaf = true;

class Leaf
{
    constructor(ParentNode)
    {
        this.Data = ThisIsLeaf;
        this.Parent = ParentNode;
        this.Left = null;
        this.Right = null;
        this.Color = Colors.black;
    }
}

//Data must be int
class Node
{
    constructor(data)
    {
        this.Data = data;
        this.Parent = null;
        this.Left = null;
        this.Right = null;
        this.Color = Colors.black;
    }
}

class RedBlackTree
{
    constructor()
    {
        this.Root = null;
    }

    InsertNodeFixTree(CurrentNode)
    {
        if (CurrentNode.Parent.Parent == null)
        {
            CurrentNode.Color = Colors.red;
        }
        else if (CurrentNode.Parent.Parent.Left.Color == Colors.black && CurrentNode.Parent.Parent.Right.Color == Colors.black)
        {
            CurrentNode.Color = Colors.red;
        }
        else if (CurrentNode.Parent.Parent.Left.Color == Colors.red && CurrentNode.Parent.Parent.Right.Color == Colors.red) {
            CurrentNode.Parent.Parent.Color = Colors.red;
            CurrentNode.Parent.Parent.Left.Color = Colors.black;
            CurrentNode.Parent.Parent.Right.Color = Colors.black;
            CurrentNode.Color = Colors.red;
            this.InsertNodeFixTree(CurrentNode.Parent.Parent);
        }
        this.Root.Color = Colors.black;
    }

    InsertNode(NewNode)
    {
        if (this.Root == null)
        {
            this.Root = NewNode;
            this.Left = new Leaf(this.Root);
            this.Right = new Leaf(this.Root);
        }
        else
        {
            var SearchPlaceNode = this.Root;
            var NodeWasInserted = false;
            while (!NodeWasInserted)
            {
                if (SearchPlaceNode.Data > NewNode.Data) {
                    SearchPlaceNode = SearchPlaceNode.Left;
                }
                else {
                    SearchPlaceNode = SearchPlaceNode.Right;
                }
                if (SearchPlaceNode.Data == ThisIsLeaf) {
                    if (SearchPlaceNode == SearchPlaceNode.Parent.Left) {
                        SearchPlaceNode.Parent.Left = NewNode;
                    }
                    else {
                        SearchPlaceNode.Parent.Right = NewNode;
                    }
                    NewNode.Parent = SearchPlaceNode.Parent;
                    NewNode.Left = new Leaf(NewNode);
                    NewNode.Right = new Leaf(NewNode);
                    NodeWasInserted = true;
                }
            }
            InsertNodeFixTree(NewNode);
        }
    }
}