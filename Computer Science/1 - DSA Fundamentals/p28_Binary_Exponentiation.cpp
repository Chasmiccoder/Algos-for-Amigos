#include <iostream>
using namespace std;



/* 
Computing powers iteratively using Binary Exponentiation

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