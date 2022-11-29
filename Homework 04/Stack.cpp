#include "Stack.h"


Stack::Stack()
{
    top = -1;

}
bool Stack::isEmpty() const
{
    return top < 0;
}

bool Stack::push(stackItemType newItem)
{
    if(top>=MAX_STACK-1)
    {
        return false;

    }
    else
    {
        items[++top] = newItem;
        return true;
    }

}
stackItemType Stack::pop()
{
    if(isEmpty())
    {
        return '\0';
    }
    else
    {
        return items[top--];
    }
}

stackItemType Stack::getTop() const
{
    if(isEmpty())
    {
        return '\0';
    }
    else
    {
        return items[top];
    }
}
