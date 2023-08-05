#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream myfile1;
    myfile1.open("Mytextfile.txt");

    if (myfile1.is_open())
    {
        char ch1, ch2;
    
        while (!myfile1.eof())
        {
           
            myfile1>>ch1>>ch2;
            cout << ch1 <<" "<<ch2<<endl;
            
        }

        myfile1.close();
    }
    else
    {
        cout << "Can't open the file" << endl;
    }

    return 0;
}