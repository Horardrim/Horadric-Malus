#ifndef BINARY_TREE_HXX
#define BINARY_TREE_HXX

class BinaryTreeNode
{
friend class BinaryTree;
public:
    BinaryTreeNode();
    BinaryTreeNode(const int & data);

    inline BinaryTreeNode * addToLeft(BinaryTreeNode * child)
    {
        _left = child;
        return _left;
    }

    inline BinaryTreeNode * addToRight(BinaryTreeNode * child)
    {
        _right = child;
        return _right;
    }

    inline int data() const
    {
        return _data;
    }

private:
    BinaryTreeNode * _left;
    BinaryTreeNode * _right;
    int _data;
};

class BinaryTree
{
public:
    BinaryTree(const int & rootData);
    BinaryTree();

    inline BinaryTreeNode * root() const
    {
        return _root;
    }

    inline bool isEmpty() const
    {
        return _root == nullptr;
    }

    const BinaryTreeNode * const lowestCommonAcestor(
        const BinaryTreeNode * const parent,
        const BinaryTreeNode * const left,
        const BinaryTreeNode * const right) const;

private:
    BinaryTreeNode * _root;
};

#endif
