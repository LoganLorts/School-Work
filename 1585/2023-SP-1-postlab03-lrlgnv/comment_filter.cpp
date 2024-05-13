#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::cin;

int main() 
{
    char comment = '#';
    std::string line;
    while(getline(cin, line))
    {
        if(line[0] != comment)
        {
            cout << line << endl;
        }
    }


    return 0;
}

