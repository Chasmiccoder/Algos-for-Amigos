/*
Problem:
https://codeforces.com/contest/1593/problem/A

The elections in which three candidates participated have recently ended. 
The first candidate received a votes, the second one received b votes, the third one received c votes. 
For each candidate, solve the following problem: 
how many votes should be added to this candidate so that he wins the election 
(i.e. the number of votes for this candidate was strictly greater than the number of votes for any other candidate)?

Please note that for each candidate it is necessary to solve this problem independently, 
i.e. the added votes for any candidate do not affect the calculations when getting the 
answer for the other two candidates.

Input:
5
0 0 0
10 75 15
13 13 17
1000 0 0
0 1000000000 0

Output:
1 1 1
66 0 61
5 5 0
0 1001 1001
1000000001 0 1000000001
*/

#include<iostream>
using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    for(int test = 0; test < testcases; test++) {
        int n = 3, largest = 0, largestPos = 0;
        int* add = new int[n];
        int* votes = new int[n];

        for(int i = 0; i < n; i++) {
            add[i] = 1;

            cin >> votes[i];
            if(largest < votes[i]) {
                largest = votes[i];
                largestPos = i;
            }
        }

        // turns false if there is more than 1 largest element
        bool alone = true;
        for(int i = 0; i < n; i++) {
            if(largest == votes[i] && largestPos != i) {
                alone = false;
                break;
            }
        }

        for(int i = 0; i < n; i++) {
            if(alone && votes[i] == largest) {
                add[i] = 0;
            }
            cout << largest - votes[i] + add[i] << " ";
        }
        cout << "\n";

    }
    return 0;
}