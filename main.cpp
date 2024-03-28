#include <bits/stdc++.h>
#include "BigInt.h"
using namespace std;
int main()
{
    BigInt num1("12");
    BigInt num2("100000000");
    //ADDITION
    BigInt num3 = num1 + num2;
    cout<<"Addition is:";
    num3.printResult();//use printResult to print the number
    cout<<endl;
    //SUBTRACTION
    // BigInt num4 = num1 - num2;
    // cout<<"Subtraction is:";
    // num4.printResult();
    // cout<<endl;
    BigInt t;
    // BigInt ans = t.compareValues(BigInt("222222"), BigInt("222222"));

    // BigInt multiplication = num1 * num2;
    // multiplication.printResult();
    // BigInt factorial = t.calculateFactorial(100);
    // factorial.printResult();
    // BigInt ans=t.getLength(factorial);
    // ans.printResult();
    // BigInt fib = t.fibonnaci(100);
    // BigInt n = num2/num1;
    // cout<<"Division Answer is:";
    // n.printResult();
    
  
    return 0;
}