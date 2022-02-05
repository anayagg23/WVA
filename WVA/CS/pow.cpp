#include <bits/stdc++.h>

using namespace std;

double solve(double a, double n) {
  if (n == 1) {
    return a;  // a^1 = a
  }
  return solve(a, floor(n / 2)) *
         solve(a, ceil(n / 2));  // a^n=a^(floor(n/2))*a^(ceil(n/2))
}

int main() {
  cout << solve(2, 3);  // returns 8, since 2^3=8
}
