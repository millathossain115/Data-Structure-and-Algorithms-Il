#include <iostream>
#include <stack>
using namespace std;

stack<int> s1, s2;

void push(int val)
{

    s1.push(val);
}

int pop()
{

    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    int val2 = s2.top();

    s2.pop();

    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }

    return val2;
}
int main()
{
    push(10);
    push(20);
    push(30);
    cout << pop() << endl;
    return 0;
}