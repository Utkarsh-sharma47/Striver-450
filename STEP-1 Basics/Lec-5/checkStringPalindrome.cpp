#include <iostream>
using namespace std;

bool palindromeCheck(string s)
{
    if (s.size() <= 1)
    {
        return true;
    }

    if (s.front() == s.back())
    {
        return palindromeCheck(s.substr(1, s.size() - 2));
    }
    else
    {
        return false;
    }
}

int main()
{
    string s ="heh";
    if (palindromeCheck(s)) cout<<"TRUE";
    else cout<<"FALSE";
    return 0;
}