#include <iostream>
#include <string>
using namespace std;

/**
* FUNCTION SIGNATURE: string getSecretMessage(string str)
 * PURPOSE: get secret message by taking the first character from each word in the input sentence, in the order they appear
 * PARAMETER:
 *     str, the input sentence
 * RETURN VALUE:
 *     The secret message
*/
string getSecretMessage(string str)
{
    string temp;
    for (int i = 0; i < str.length(); i++)
    {
        // adds first alpha char to temp
        if (i == 0 && str.substr(i, 1) != " ")
        {
            temp = str[i];
            str.erase(i, 1);
            i = 0;
        }
        else if (i > 0)
        {
            // adds alpha char preceded by " "
            if (str.substr(0, 1) == " " && str.substr(1, 1) != " ")
            {
                temp = temp + str[i];
                str.erase(0, 2);
                i = 0;
            }
            // erases alpha char followed by alpha char
            else if (str.substr(i, 1) != " " && str.substr(i + 1, 1) != " ")
            {
                str.erase(0, 1);
                i = 0;
            }
            // erases " " (may be redundant, but looks cleaner)
            else
            {
                str.erase(0,1);
                i = 0;
            }
        }
    }


    return temp;
}
int main()
{
    cout << getSecretMessage(" professor can code") << endl; // prints "pcc"
    cout << getSecretMessage("professor         can        code") << endl; // prints "pcc"
    cout << getSecretMessage("                ") << endl;  // prints nothing
    cout << getSecretMessage("pasadena") << endl;  // prints "p"
    return 0;
}
