#include <iostream>
#include <exception>
#include <string>
#include <sstream>
using namespace std;
//
class BadLengthException
{
private:
    int n;

public:
    BadLengthException(int errornumber)
    {
        n = errornumber;
    }
    int what()
    {
        return n;
    }
};

bool Checkusername(string username)
{
    bool isValid = true;
    int n = username.length();
    if (n < 5)
    {
        throw BadLengthException(n);
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (username[i] == 'w' && username[i + 1] == 'w')
        {
            isValid = false;
        }
    }
    return isValid;
}

int main()
{
    // the number of test cases
    int T;
    cin >> T;

    while (T--)
    {
        string username;
        cin >> username;
        try
        {
            bool isValid = Checkusername(username);
            if (isValid)
            {
                cout << "Valid!";
            }
            else
            {
                cout << "Invalid!";
            }
        }
        catch (BadLengthException e)
        {
            cout << "Too short:" << e.what();
        }
    }

    return 0;
}