#include <iostream>
using namespace std;
int two_gcd(int dividend, int divisor)
{

    if (divisor == 0)
    {
        return dividend;
    }
    else
    {

        int new_dividend = divisor;
        int new_divisor = dividend % divisor;
        int friend_gcd = two_gcd(new_dividend, new_divisor);
        return friend_gcd;
    }
}

int n_gcd(int arr[], int sz)
{

    if (sz == 2)
    {
        return two_gcd(arr[0], arr[1]);
    }
    else
    {
        int mypart = arr[sz - 1];
        int fndpart = n_gcd(arr, sz - 1 - 1);
        int mygcd = two_gcd(mypart, fndpart);
        return mygcd;
    }
}
int main()
{
    int arr[] = {8, 6, 4, 2};
    int sz = sizeof(arr) / sizeof(int);
    cout << n_gcd(arr, sz) << endl; ///output will be: 2
    return 0;
}