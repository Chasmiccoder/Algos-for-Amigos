/*
Tribonacci starting with:
1,1,1,3,5,9,17,31
1st term of the series is 1

Officially,
Now do for 0,0,1
Later, solve it recursively
Add fibonacci cod
*/
#include <iostream>
#include <vector>

int exceptions(int m, int n);
int solve_recursively(int m, int n, int *memo);
int answer = 0;

void solve(int m, int n, int *memo) {
    int ans = 0;
    int first = 1;
    int second = 1;
    int third = 1;

    if ( m == n && m<= 3 ) {
        // ans = 1;
        answer = 1;
    }
    else if ( m == 1 && n == 2 ) {
        answer = 2;
        
    }
    else if ( m == 1 && n == 3 ) {
        answer = 3;
    }
    else if ( m == 2 && n == 3 ) {
        answer = 2;
        
    }

    else if ( m == 3 && n >= 4 ) {
        answer = 1;
        
    }

    else if ( m == 2 && n >= 4 ) {
        answer = 2;
        
    }

    else if ( m == 1 && n >= 4 ) {
        answer = 3;
        
    }

    /*
    for ( int i = 4; i <= n; i++ ) {

        int tmp1 = first;
        int tmp2 = second;
        int tmp3 = third;
        first = second;
        second = third;

        third = tmp1 + tmp2 + tmp3;
        if ( i >= m ) {
            ans += third;
        }

    }
    */
    solve_recursively(m,n,memo);
    return ;
}


// Sum of tribonacci number from m to n recursively
int solve_recursively(int m, int n, int *memo) {
    // int exception_test = exceptions(m,n);
    // if ( exception_test != 0 ) {
    //     answer = exception_test;
    //     // return exception_test;
    //     return answer;
    // }

    if ( memo[n] != 0 ) {
        return memo[n];
    }

    if ( n <= 1 ) {
        return n;
    }

    int tmp = solve_recursively(m, n-1, memo) + solve_recursively(m, n-2, memo) + solve_recursively(m, n-3, memo);
    memo[n] = tmp;
    if ( n >= m ) {
        answer = answer + tmp;
    }
    return tmp;
}

int exceptions(int m, int n){
    int ans = 0;
    int first = 1;
    int second = 1;
    int third = 1;

    if ( m == n && m<= 3 ) {
        ans = 1;
    }
    else if ( m == 1 && n == 2 ) {
        ans = 2;
    }
    else if ( m == 1 && n == 3 ) {
        ans = 3;
    }
    else if ( m == 2 && n == 3 ) {
        ans = 2;
    }

    else if ( m == 3 && n >= 4 ) {
        ans = 1;
    }

    else if ( m == 2 && n >= 4 ) {
        ans = 2;
    }

    else if ( m == 1 && n >= 4 ) {
        ans = 3;
    }
    else {
        return 0;
    }
    return ans;
}

// Find the nth tribonacci number recursively
int fib_recursion_dp(int n, int *memo) {
    if ( memo[n] != 0 ) {
        return memo[n];
    }

    if ( n <= 1 ) {
        return n;
    }

    int tmp =  fib_recursion_dp(n-1, memo) + fib_recursion_dp(n-2, memo) + fib_recursion_dp(n-3, memo);
    memo[n] = tmp;
    return tmp;
}


int main() {

    // int m,n;
    // std::cin >> m >> n;

    // int result = solve(m,n);
    // std::cout << result << "\n";

    int m,n;
    std::cin >> m >> n;
    

    int memo[n+1] = {0};
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 1;
    memo[3] = 1;

    // std::cout << fib_recursion_dp(n,memo);
    // solve_recursively(m,n,memo); // Broken function
    solve(m,n,memo);

    std::cout << answer << "\n";


    return 0;
}