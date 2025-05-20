#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
        string result;
        string word;

        for (char c : s) {
            if (c == ' ') {
                reverse(word.begin(), word.end());
                result += word + " ";
                word.clear();
            } else {
                word += c;
            }
        }

        // Reverse and add the last word (since no space after it)
        reverse(word.begin(), word.end());
        result += word;

        reverse(result.begin(), result.end());

        if (result[0] == ' ') result.erase(0,1);
        if (result[result.size()-1] == ' ') result.erase(result.size()-1,1);

        return result;
    }


int main()
{
  string s=" hi bro";
//   string ans= reverseWords(s);
//   cout<<ans; 
    
    cout<<s;

  return 0;
}