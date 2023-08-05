#include <iostream>
using namespace std;

int TOH(int n, char src, char dest, char tmp1, char tmp2)
{

    if (n <= 1)
    {
        return 1;
    }
    else
    {

        int fnd1moves = TOH(n - 2, src, tmp1, dest, tmp2);
        int fnd2moves = TOH(1, src, tmp2, dest, tmp1);
        int mymoves = TOH(1, src, dest, tmp1, tmp2);
        int fnd3moves = TOH(1, tmp2, dest, src, tmp1);
        int fnd4moves = TOH(n - 2, tmp1, dest, src, tmp2);

        int totalmoves = fnd1moves + fnd2moves + mymoves + fnd3moves + fnd4moves;
        return totalmoves;
    }
}
int main()
{
    cout << TOH(6, 'S', 'D', 'T', 'M') << endl;
    return 0;
}