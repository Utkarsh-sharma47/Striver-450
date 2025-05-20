#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
        if ((s[0] >= 'a' && s[0] <= 'z') || s[0] == '.')
            return 0;

        string ans;
        int i = 0;
        bool sign = 1;
        long long Ans = 0;
        for (i = 0; i < s.size(); i++) {
            // break when number or sign comes
            if (s[i] >= '0' && s[i] <= '9')
                break;

            else if (s[i] == '-' || s[i] == '+') {
                if (s[i] == '-')
                    sign = 0;
                i++;
                break;
            } else if (s[i] == ' ')
                continue;
            else
                return 0;
        }

        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                if((Ans*10+ (s[i]-'0')) >= INT_MAX)
                {
                    if(sign) return INT_MAX;
                    else return INT_MIN;
                }
                else{
                    Ans=Ans*10+ (s[i]-'0');
                }
            } 
            else {
                break;
            }

            i++;
        }
        // 4. Handle overflow
        if (sign)
            if (Ans * (1) >= INT_MAX)
                return INT_MAX;
            else
                return Ans * 1;
        else if (Ans * (-1) <= INT_MIN)
            return INT_MIN;
        else
            return Ans * (-1);
    }

int main()
{
  string s = " 0-1";
  cout<<myAtoi(s);
  return 0;
}
