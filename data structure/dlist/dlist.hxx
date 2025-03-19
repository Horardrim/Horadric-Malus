#ifndef DLIST_HXX
#define DLIST_HXX

#include <assert.h>

class DListNode
{
friend class DList;
friend class DList__;

public:
    DListNode();
    DListNode(const int & data);
    ~DListNode() = default;

private:
    int _data;
    DListNode * _prev;
    DListNode * _next;
};

/**
 * 不带有dummy head的实现
 */
class DList
{
public:
    DList();
    virtual ~DList();

    inline bool empty() const
    {
        return _head == nullptr;
    }

    void remove(DListNode & node);
    inline DListNode * head() const;
    inline DListNode * tail() const;
    DListNode * pop();
    DListNode * dequeue();
    void prepend(DListNode & node);
    void append(DListNode & node);
    void insertAfter(DListNode & base, DListNode & newNode);
    void insertBefore(DListNode & base, DListNode & newNode);
    void verify() const;

private:
    DListNode * _head;    
    DListNode * _tail;
};

/**
 * 带有dummy head的实现
 */
class DList__
{
public:
    DList__();
    virtual ~DList__();

    inline bool empty() const
    {
        return _head._next == &_head;
    }

    inline DListNode * head() const
    {
        return (_head._next == &_head ? nullptr : _head._next);
    }
    
    inline DListNode * tail() const
    {
        return (_head._next == &_head ? nullptr : _head._prev);
    }

    DListNode * pop();
    DListNode * dequeue();
    void remove(DListNode & node);

    inline void prepend(DListNode & node)
    {
        node._next = _head._next;
        node._prev = &_head;
        // 此处也可以写为node._next._prev = &node 因为node._next和_head._next都指向同一个节点
        _head._next->_prev = &node;
        _head._next = &node;
    }

    inline void append(DListNode & node)
    {
        node._next = &_head;
        node._prev = _head._prev;
        _head._prev->_next = &node;
        _head._prev = &node;
    }

    inline void insertAfter(DListNode & base, DListNode & newNode)
    {
        newNode._next = base._next;
        newNode._prev = &base;
        base._next->_prev = &newNode;
        base._next = &newNode;
    }

    inline void insertBefore(DListNode & base, DListNode & newNode)
    {
        newNode._prev = base._prev;
        newNode._next = &base;
        base._prev->_next = &newNode;
        base._prev = &newNode;
    }

    void verify();
    void verifyOneElement();

private:
    DListNode _head;
};

#endif
