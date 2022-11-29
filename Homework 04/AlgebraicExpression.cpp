#include "AlgebraicExpression.h"
using namespace std;
#include <iostream>

int priority(char alpha)
{
    if(alpha == '+' || alpha == '-')
    {
        return 1;
    }
    if(alpha == '*' || alpha == '/')
    {
        return 2;
    }
    return 0;
}

string infix2postfix(const string exp)
{
    string postfix = "";
    int i = 0;
    Stack s;
    while(exp[i]!='\0')
    {
        if( exp[i] >= '1' && exp[i] <= '9' )
        {
            postfix += exp[i];
            i++;
        }
        else if( exp[i] == '(')
        {
            s.push(exp[i]);
            i++;

        }
        else if ( exp[i] == ')')
        {
            while(s.getTop()!= '(')
                {
                    postfix += s.getTop();
                    s.pop();

                }
                s.pop();
                i++;

        }
        else if ( exp[i] == '*' || exp[i] == '-' || exp[i] == '/' || exp[i] == '+')
        {
            while(!s.isEmpty() && (priority(exp[i]) <= priority(s.getTop())) && s.getTop() != '(' )
                {
                    postfix += s.getTop();
                    s.pop();

                }
                s.push(exp[i]);
                i++;


        }
        else
        {
            i++;
        }
    }
    while(!s.isEmpty())
    {
        postfix+=s.pop();
    }
    return postfix;
}

double evaluatePostfix(const string exp)
{
    Stack s;
    int i = 0;
    double result = 0.0;
    double remainder = 0.0;
    while(exp[i]!= '\0')
    {
        if(exp[i] >= '1' && exp[i] <= '9')
        {
            s.push(exp[i]);
        }
        else
        {
            double val1 = s.getTop()-48;
            s.pop();
            double val2 = s.getTop()-48;
            s.pop();
            switch (exp[i])
            {
            case '+': s.push((val2 + val1)+48); break;
            case '-': s.push((val2 - val1)+48); break;
            case '*': s.push((val2 * val1)+48); break;
            case '/': s.push((val2/val1)+48);remainder = ((int)val2%(int)val1)/val1; break;
            }
        }
        i++;
    }
    result = (s.pop() -48)+ remainder;
    return (result/1.00);
}
