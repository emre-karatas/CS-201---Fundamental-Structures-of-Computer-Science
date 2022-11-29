
const int MAX_STACK=100;
typedef  char stackItemType;
class Stack
{
public:
    Stack();
    bool isEmpty() const;
    bool push(stackItemType newItem);
    stackItemType pop();
    stackItemType getTop() const;

private:
    stackItemType items[MAX_STACK];
    int top;
    stackItemType *a;

};
