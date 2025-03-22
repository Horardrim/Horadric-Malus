#include <assert.h>
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include <sstream>

#include "binary_tree.hxx"


void verifyBST()
{
    BinaryTree treeI(5);
    BinaryTreeNode * left = treeI.root()->addToLeft(new BinaryTreeNode(3));
    BinaryTreeNode * right = treeI.root()->addToRight(new BinaryTreeNode(8));

    left->addToLeft(new BinaryTreeNode(2));
    left->addToRight(new BinaryTreeNode(4));

    right->addToLeft(new BinaryTreeNode(6));
    right->addToRight(new BinaryTreeNode(9));

    assert(treeI.isBST());
}

void verifyNoneBST()
{
    BinaryTree treeI(1);
    BinaryTreeNode * left = treeI.root()->addToLeft(new BinaryTreeNode(2));
    BinaryTreeNode * right = treeI.root()->addToRight(new BinaryTreeNode(3));

    left->addToLeft(new BinaryTreeNode(4));
    left->addToRight(new BinaryTreeNode(5));

    right->addToLeft(new BinaryTreeNode(6));
    right->addToRight(new BinaryTreeNode(7));

    assert(!treeI.isBST());
}

int main(int argc, char ** argv)
{
    BinaryTree treeI(1);
    BinaryTreeNode * left = treeI.root()->addToLeft(new BinaryTreeNode(2));
    BinaryTreeNode * right = treeI.root()->addToRight(new BinaryTreeNode(3));

    left->addToLeft(new BinaryTreeNode(4));
    left->addToRight(new BinaryTreeNode(5));

    BinaryTreeNode * targetRight = right->addToLeft(new BinaryTreeNode(6));
    right->addToRight(new BinaryTreeNode(7));

    const BinaryTreeNode * ancestor = treeI.lowestCommonAcestor(treeI.root(), left, targetRight);
    assert(ancestor == treeI.root());

    // 测试其中一个节点是root节点，公共的祖先节点也是root
    const BinaryTreeNode * ancestorI = treeI.lowestCommonAcestor(treeI.root(), left, treeI.root());
    assert(ancestorI == treeI.root());
    return 0;
}
