#include <iostream>
#include <algorithm>

using namespace std;

int gcd_pro(int a, int b){
/* Utilizing the euclidean algorithm to compute the gcd
   Time complexity -- O(log(n)) */

  int maxi = max(a,b);
  int mini = a+b-maxi;
  int div = mini;

  while (div!=0){
    int rem = maxi%div;
    maxi = div;
    div = rem;
  }
  return maxi;

}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_pro(a, b) << std::endl;
  return 0;
}
