#include<iostream>
using namespace std;

int fib(int n) {
        //your code goes here
        if(n==0) return 0;
        if(n==1) return 1;
        
        // fib(n-1)=fib(n-2)+fib(n-3);
        // fib(n-2)=fib(n-3)+fib(n-4);

        int x = fib(n-1)+fib(n-2);

        return x;
    }


int main()
{
  cout<<fib(8);
  return 0;

}