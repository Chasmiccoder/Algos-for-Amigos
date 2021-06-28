#include <iostream>
#include <vector>
using namespace std;

/* 


SIEVE OF ERATHOSTHENES

Method used for generating prime numbers upto a specified limit.

Intuition ---
    create a boolean array of size n.
    traverse through the algorithm and cross out the composite numbers in steps of already created primes

Time complexity - O(n*logn*(loglogn))  [could be improved to O(n)]


Reference - https://www.geeksforgeeks.org/sieve-of-eratosthenes/

*/

vector<bool> sieve(int n){
    vector<bool> prime(n+1, true);
    for(int i = 2; i*i <= n; i++){
        if (prime[i]){
            for(int j = i*i; j <= n; j+=i){
                prime[j] = false;
            }
        }
    }
    return prime;
}



int main(){

    int n;
    cout<<"Enter the limit up to which you wish to generate prime numbers:  ";
    cin>>n;

    vector<bool> prime_array = sieve(n);

    for(int i = 2; i<=n; i++){
        if (prime_array[i]) cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}