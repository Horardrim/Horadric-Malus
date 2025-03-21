#include "binary_tree.hxx"

BinaryTreeNode::BinaryTreeNode() :
    _left(nullptr),
    _right(nullptr),
    _data(0)
{

}

BinaryTreeNode::BinaryTreeNode(const int & data) :
    _left(nullptr),
    _right(nullptr),
    _data(data)
{

}

BinaryTree::BinaryTree() :
    _root(nullptr)
{

}

BinaryTree::BinaryTree(const int & rootData) :
    _root(nullptr)
{
    _root = new BinaryTreeNode(rootData);
}

const BinaryTreeNode * const BinaryTree::lowestCommonAcestor(const BinaryTreeNode * const parent, const BinaryTreeNode * const left, const BinaryTreeNode * const right) const
{
    if (parent == left || parent == right || parent == nullptr)
    {
        return parent;
    }
    
    const BinaryTreeNode * const leftChild = lowestCommonAcestor(parent->_left, left, right);
    const BinaryTreeNode * const rightChild = lowestCommonAcestor(parent->_right, left, right);

    if (leftChild != nullptr && rightChild != nullptr)
    {
        return parent;
    }

    if (leftChild != nullptr)
    {
        return leftChild;
    }

    return rightChild;
}
