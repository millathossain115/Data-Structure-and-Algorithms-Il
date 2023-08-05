#include <iostream>
using namespace std;

int numberOfway(int n)
{
    if (n == 1)
        return 1;

    else if (n == 0)
    {
        return 1;
    }

    else if (n == 2)
        return 2;

    else
    {
        int unit1 = numberOfway(n - 1);
        int unit2 = numberOfway(n - 2);
        int unit3 = numberOfway(n - 3);

        int result = unit1 + unit2 + unit3;
        return result;
    }
}

int main()
{
    cout << numberOfway(3) << endl;
    cout << numberOfway(4) << endl;
    return 0;
}
