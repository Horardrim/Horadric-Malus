#include <stdio.h>

#include "dlist.hxx"

DListNode::DListNode() :
    _data(0),
    _prev(this),
    _next(this)
{

}

DListNode::DListNode(const int & data) :
    _data(data),
    _prev(this),
    _next(this)
{

}

DList::DList() :
    _head(nullptr),
    _tail(nullptr)
{

}

DList::~DList()
{

}

void DList::remove(DListNode & node)
{
    if (node._prev != nullptr)
    {
        node._prev->_next = node._next;
    }
    else //删除头节点
    {
        _head = node._next;
    }

    if (node._next != nullptr)
    {
        node._next->_prev = node._prev;
    }
    else // 删除尾节点
    {
        _tail = node._prev;
    }

    node._next = nullptr;
    node._prev = nullptr;
}

void DList::append(DListNode & node)
{
    if (_head == nullptr)
    {
        _head = &node;
        _tail = &node;
        node._next = nullptr;
        node._prev = nullptr;
        return;
    }

    node._next = nullptr;
    node._prev = _tail;
    _tail->_next = &node;
    _tail = &node;
}

void DList::prepend(DListNode & node)
{
    if (_head == nullptr)
    {
        _head = &node;
        _tail = &node;
        node._next = nullptr;
        node._prev = nullptr;
        return;
    }

    node._prev = nullptr;
    node._next = _head;
    _head->_prev = &node;
    _head = &node;
}

void DList::insertAfter(DListNode & base, DListNode & newNode)
{
    newNode._prev = &base;
    newNode._next = base._next;
    if (base._next != nullptr)
    {
        base._next->_prev = &newNode;
    }
    else
    {
        _tail = &newNode;
    }
    base._next = &newNode;
}

void DList::insertBefore(DListNode & base, DListNode & newNode)
{
    newNode._next = &base;
    newNode._prev = base._prev;
    if (base._prev != nullptr)
    {
        base._prev->_next = & newNode;
    }
    else
    {
        _head = &newNode;
    }
    base._prev = &newNode;
}

DListNode * DList::head() const
{
    return _head;
}

DListNode * DList::tail() const
{
    return _tail;
}

DListNode * DList::pop()
{
    if (empty())
    {
        return nullptr;
    }
    else
    {
        DListNode * top = _head;
        _head = _head->_next;
        if (_head == nullptr)
        {
            _tail = nullptr;
        }
        else
        {
            _head->_prev = nullptr;
        }

        top->_next = nullptr;
        top->_prev = nullptr;
        return top;
    }
}

DListNode * DList::dequeue()
{
    if (empty())
    {
        return nullptr;
    }
    else
    {
        DListNode * buttom = _tail;
        _tail = _tail->_prev;
        if (_tail == nullptr)
        {
            _head = nullptr;
        }
        else
        {
            _tail->_next = nullptr;
        }

        buttom->_next = nullptr;
        buttom->_prev = nullptr;
        return buttom;
    }
}

void DList::verify() const
{

}

DList__::DList__()
{

}

DList__::~DList__()
{
    while (!empty())
    {
        remove(*_head._next);
    }
}

void DList__::remove(DListNode & node)
{
    if (&node == &_head)
    {
        return;
    }
    node._prev->_next = node._next;
    node._next->_prev = node._prev;
    node._next = nullptr;
    node._prev = nullptr;

}

void DList__::verify()
{
    assert(_head._next->_data == 3);
    assert(_head._next->_next->_data == 1);
    assert(_head._next->_next->_prev->_data == 3);
    assert(_head._prev->_data == 2);
    DListNode * top = pop();
    assert(top->_data == 3);
    assert(top->_next == nullptr);
    assert(top->_prev == nullptr);
    assert(!empty());
    assert(_head._next->_data == 1);
    assert(_head._next->_prev == &_head);
    assert(_head._prev->_data == 2);
}

void DList__::verifyOneElement()
{
    DListNode * top = pop();
    
    assert(empty());
    assert(top->_data == 4);
    assert(top->_prev == nullptr);
    assert(top->_next == nullptr);
    assert(_head._next = & _head);
    assert(_head._prev = & _head);
}

DListNode * DList__::pop()
{
    if (empty())
    {
        return nullptr;
    }
    else
    {
        DListNode * top = _head._next;
        _head._next = top->_next;
        top->_next->_prev = top->_prev;
        top->_next = nullptr;
        top->_prev = nullptr;
        return top;
    }
}

DListNode * DList__::dequeue()
{
    if (empty())
    {
        return nullptr;
    }
    else
    {
        DListNode * buttom = _head._prev;
        _head._prev = buttom->_prev;
        buttom->_prev->_next = buttom->_next;
        buttom->_next = nullptr;
        buttom->_prev = nullptr;
        return buttom;
    }
}
