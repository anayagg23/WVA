#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    int max = 1;
    for (int i=1; i<=a; i++){
        if (a % i == 0 && b % i == 0 && max<i){
            max=i; // finding the maximum value of i such that i|a and i|b
            }    
    }
    return max;
}

int powmod(int a, int b, int c){ // computes a^b mod c
     if (b==1){
         return a % c; // a^1==a mod c
         }
     return a * powmod(a, b-1, c) % c; // a^b == a*a^(b-1) mod c
    }

int inverse(int e, int n){ // finding the inverse of e mod n
    for (int d=0; d<n; d++){
        if ((d * e) % n == 1){
            return d; // finding a d such that d*e==1 mod n
        }
    }
    return 1;
}

int main()
{
  int p = 23; // setting p
  int q = 13; // setting q
  int n = p * q; // setting n
  int lam = (p-1)*(q-1)/(gcd(p-1, q-1)); // setting lambda(n)
  int e = lam; // dummy initial value for e
  while (gcd(e,lam)!=1){
        e = rand() % lam + 1; // keep generating random e until its relatively prime to lambda(n)
  }
  int d = inverse(e, lam); // d = e^(-1) mod lambda(n)
   int m = 61; // random message m
   int c = powmod(m,e,n); // c = m^e mod n
   cout<< powmod(c,d,n); // output c^d mod n, this should be m, or 61
}

