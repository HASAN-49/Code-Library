// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long binPow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}

int power(int a, int n) {
  int res = 1;
  while (n > 0) {
    if (n & 1) res = 1LL * res * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;

  return 0;
}
