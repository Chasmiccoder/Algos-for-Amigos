#include <iostream>
#include <algorithm>



long long int maxm(long long int a, long long int b){
  if (a>b){
    return a;
  }
  else{
    return b;
  }
}

/*Computing gcd by euclidean algorithm */

long long int gcd_pro(long long int a,long long int b){
  long long int maxi = maxm(a,b);
  long long int mini = a+b-maxi;

  long long int div = mini;
  while (div!=0){
    long long int rem = maxi%div;
    maxi = div;
    div = rem;
  }
  return maxi;

}

/*Computing lcm by using property :
    lcm = (a*b)/gcd           */

long long int lcm_pro(long long int a,long long int b){
  long long int product = a*b;
  long long int hcf = gcd_pro(a,b);
  return (product/hcf);

}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_pro(a, b) << std::endl;
  return 0;
}
