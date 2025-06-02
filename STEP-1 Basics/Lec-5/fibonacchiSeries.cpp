#include<iostream>
using namespace std;


    int fib(int n) {
        //your code goes here
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        
        int x = fib(n-1)+fib(n-2);

        return x;
    }

    int main()
    {
        cout<<fib(7); //13

        return 0;
    }
// FIBONACCHI SERIES - every element is sum of previous 2 elements
// 0 1 1 2 3 5 8 13 21 ....