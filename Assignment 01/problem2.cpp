#include <iostream>
#include<vector>
#include<map>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream myfile1;
    myfile1.open("Mytextfile.txt");
    map < char, vector<char>>v;

    if (myfile1.is_open())
    {
        char ch1, ch2;

        while (!myfile1.eof())
        {

            myfile1 >> ch1 >> ch2;
            char key=ch1;
            
            v.insert({v.first.insert(ch1),v.second.push_back(ch2)});

            cout << ch1 << " " << ch2 << endl;
        }

        myfile1.close();
    }
    else
    {
        cout << "Can't open the file" << endl;
    }

   
	 for( const auto& pair : v)
        {
            cout << " " << pair.first << " : " ;
            for( size_t i = 0 ; i < pair.second.size() ; ++i )  cout << pair.second[i] << "  " ;
            cout << "]\n" ;
        }
}
   
