#include <iostream>
using namespace std;

int max_digit(int num)
{

    if (num == 0)
        return 0;
    else
    {
        int lastdigit = num % 10;
        int restnum = max_digit(num / 10);

        if (lastdigit > restnum)
        {
            return lastdigit;
        }
        else
        {
            return restnum;
        }
    }
}

int main()
{
    int num;
    cin >> num;

    cout << "The maximum Digit is: " << max_digit(num) << endl;
    return 0;
}
