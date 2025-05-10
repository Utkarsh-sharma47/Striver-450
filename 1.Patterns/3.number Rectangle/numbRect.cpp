#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 4; // The outermost number
    int size = 2 * n - 1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // subtracting the minumum for start to mid and mid to end wale numbers
            int minDist = min(min(i, j), min(size - 1 - i, size - 1 - j));
            cout << n - minDist;
        }
        cout << endl;
    }

    return 0;
}
/*

4444444
4333334
4322234
4321234
4322234
4333334
4444444

*/