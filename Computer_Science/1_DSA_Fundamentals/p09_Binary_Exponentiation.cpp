#include <iostream>
using namespace std;



/* 
Computing powers iteratively using Binary Exponentiation

To compute x^n, first we write n in its binary representation. Since n has logn (base 2) digits in its binary representation, 
we need to perform only logn mulitplications
Example :----  3^13 = 3^8 * 3^4 * 3^1



Reference :-- https://cp-algorithms.com/algebra/binary-exp.html
Time complexity - O(logn)
Auxiliary space - O(1)

*/


int power_expo(int x, int n){
    long long int ret = 1;
    
    while(n>0){
        if (n%2!=0) ret = ret*x;
        n/=2;
        x *= x;
    }
    return ret;

}

int main(){
    int x,n;
    cout<<"Enter the number and its exponent"<<endl;
    cin>>x>>n;
    cout<<power_expo(x,n)<<endl;
}