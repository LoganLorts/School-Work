// Programmer:	Logan Lorts
// Section:	301
// Date:	5/12/23

#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string word;
    bool in_word = false;
    unordered_map< string, int >words;
    while(!cin.eof())
    {
        char character;

        cin.get(character);
        if(!in_word && isalpha(character))
        {
            in_word = true;
        }

        else if (in_word && !isalpha(character))
        {
            in_word = false;
            if(words.count(word))
            {
                ++words[word];
            }
            else
            {
                words[word] = 1;
            }
            word.clear();
        }

        if (in_word)
        {
            word += tolower(character);
        }
    }

    for(const auto &freq:words)
    {
        cout << freq.first << '\t' << freq.second << endl;
    }

    return 0;
}
