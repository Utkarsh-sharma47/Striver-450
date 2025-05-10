#include <iostream>
using namespace std;

void upOPY(int n) // upward odd pyramid
{
        int N = 2 * n - 1;
        int e = N / 2;
        for (int i = 1; i <= n; i++)
        {
            char c = 65;
            for (int j = 1; j <= 2 * n - 1; j++)
            {
                if (j > e && j < N - e + 1)
                // which alphabet to print, decide now
                {
                    if (j > N / 2 + 1)
                    {
                        c = c - 1;
                        cout << c <<" ";
                    }
                    else
                    {
                        cout << c <<" ";
                        c = c + 1;
                    }
                    if(j==N/2+1)
                    {
                        c = c-1;
                    }
                }

                else
                {
                    cout << "  ";
                }
            }
            e--;
            cout << endl;
        }

        return;
}

int main()
{
    cout << "Hello, World!" << endl;
    upOPY(4);
    return 0;
}
/*

   A
  ABA
 ABCBA
ABCDCBA

*/