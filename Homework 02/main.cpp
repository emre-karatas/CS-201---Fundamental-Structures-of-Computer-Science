//EMRE KARATAS
//22001641
#include <iostream>
#include "chrono"

using namespace std;


int recursiveFib(int);
int iterativeFib(int);
int main()
{
    //Declare necessary variables
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, std::milli > elapsedTime;
    //Code block
    int selection= 0;
    int n = 0;
    cout << "For iterative, select 1; for recursive, select 2:";
    cin >> selection;
    if(selection==1)
    {
        cout << "Iterative Fibonacci: " << endl;
        cout << "enter n: ";
        cin >> n;
        startTime = std::chrono::system_clock::now();
        cout << iterativeFib(n) << endl;
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

    }
    else if ( selection == 2)
    {

        cout << "Recursive Fibonacci: " << endl;
        cout << "enter n: ";
        cin >> n;
        startTime = std::chrono::system_clock::now();
        cout << recursiveFib(n) << endl;
        //Compute the number of seconds that passed since the starting time
        elapsedTime = std::chrono::system_clock::now() - startTime;
        cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

    }
    else
    {
        cout << "invalid input " << endl;
    }
}

int recursiveFib( int n )
{
    if ( n <= 2 )
    {
        return 1;
    }
    return recursiveFib(n - 1) + recursiveFib(n - 2);
}

int iterativeFib( int n )
{
    int previous = 1;
    int current = 1;
    int next = 1;
    for ( int i = 3; i <= n; i++ )
    {
        next = current + previous;
        previous = current;
        current = next;
    }
    return next;
}
