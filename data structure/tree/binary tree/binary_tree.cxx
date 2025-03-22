#include <list>

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

BinaryTree::~BinaryTree()
{
    if (_root == nullptr)
    {
        return;
    }
    std::list<BinaryTreeNode*> stack;
    stack.push_back(_root);
    while(!stack.empty())
    {
        BinaryTreeNode * node = stack.front();
        stack.pop_front();
        if (node->_left != nullptr)
        {
            stack.push_back(node->_left);
        }

        if (node->_right != nullptr)
        {
            stack.push_back(node->_right);
        }

        node->_left = nullptr;
        node->_right = nullptr;
        delete node;
        node = nullptr;
    }
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

bool BinaryTree::isBST() const
{
    return _isBST(nullptr, _root->_left, _root) && _isBST(_root, _root->_right, nullptr);
}

bool BinaryTree::_isBST(
    const BinaryTreeNode * const leftParent,
    const BinaryTreeNode * const current,
    const BinaryTreeNode * const rightParent) const
{
    if (current == nullptr)
    {
        return true;
    }

    if (leftParent != nullptr && current->_data <= leftParent->_data)
    {
        return false;
    }

    if (rightParent != nullptr && current->_data >= rightParent->_data)
    {
        return false;
    }

    return _isBST(leftParent, current->_left, current) && _isBST(current, current->_right, rightParent);
}
