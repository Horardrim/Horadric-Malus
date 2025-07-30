#ifndef PARENT_CHILD_CLASS_HXX
#define PARENT_CHILD_CLASS_HXX


class ParentClass
{
public:
    ParentClass(){}
    virtual ~ParentClass(){}

    void * getAddress()
    {
        return &a;
    }
private:
    int a;
    int b;
    int c;
};

class ChildClass : public ParentClass
{
public:
    ChildClass(){}
    ~ChildClass(){}

    void * getAddress()
    {
        return &d;
    }

private:
    int d;
};

#endif
