#include "Stack.h"
#include <string>

int priority(char alpha);
std::string infix2postfix(const std::string exp);
double evaluatePostfix(const std::string exp);
