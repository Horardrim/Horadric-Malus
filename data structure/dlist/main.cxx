/**
 * C++实现双向链表，带有dummy head和不带有dummy head两种实现
 */
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <cmath>
#include <vector>

#include "dlist.hxx"


int main(int argc, char ** argv)
{
    DList dlist;
    DList__ dlist__;
    assert(dlist.empty());
    assert(dlist__.empty());

    DListNode a(1);
    DListNode b(1);

    DListNode aII(2);
    DListNode bII(2);

    DListNode aIII(3);
    DListNode bIII(3);

    dlist__.append(b);
    dlist__.append(bII);
    dlist__.prepend(bIII);

    dlist__.verify();

    dlist.append(a);
    dlist.append(aII);
    dlist.prepend(aIII);

    DList__ oneElementList;
    DListNode singleNode(4);
    oneElementList.append(singleNode);
    oneElementList.verifyOneElement();
    return 0;
}
