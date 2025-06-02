#include <iostream>
using namespace std;

void upOPY(int n) // upward odd pyramid
{
    int N = 2 * n - 1;
    int e=N/2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        if (i % 2 != 0)
        {
            for (int j = 1; j <= 2 * n - 1; j++)
            {
                if (j > e && j < N - e +1) 
                    {cout << "*";}

                else
                    {cout << " ";}
            }
            e--;
            cout << endl;
        }
        else{
            continue;
        }
    }

    return;
}
void downOPY(int n) // downward odd pyramid
{
    int N = 2 * n - 1;
    int e=0;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        if (i % 2 != 0)
        {
            for (int j = 1; j <= 2 * n - 1; j++)
            {
                if (j > e && j < N - e +1) 
                    {cout << "*";}

                else
                    {cout << " ";}
            }
            e++;
            cout << endl;
        }
        else{
            continue;
        }
    }

    return;
}


int main()
{
    cout << "Hello, World!" << endl;
    upOPY(3);
    downOPY(3);
    return 0;
}
/*

  *
 ***
*****

*/