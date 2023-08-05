#include <iostream>
using namespace std;

bool palindrome(int arr[], int firstelm, int lastelm)
{

    if (firstelm >= lastelm)
        return true;

    if (arr[firstelm] == arr[lastelm]){ 
        bool x=palindrome(arr, firstelm + 1, lastelm - 1);
        return x;
    }  
    else
        return false;
}

int main()
{

    int arr[10], size;
    cin >> size;

    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << "Boolean Result- " << palindrome(arr, 0, size - 1) << endl;

    return 0;
}