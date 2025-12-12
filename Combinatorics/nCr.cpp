// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1, mod = 1000003;

int power(int a, int n) {
  int res = 1;
  while (n > 0) {
    if (n & 1) res = 1LL * res * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return res;
}

int f[N], invf[N];
void calc() {
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = 1LL * f[i - 1] * i % mod;
  }
  invf[N - 1] = power(f[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; i--) {
    invf[i] = 1LL * (i + 1) * invf[i + 1] % mod;
  }
}

int nCr(int n, int r) {
  // calc(); Do it before taking test cases
  if (n < r || n < 0) return 0;
  return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}

void solve(int tc) {
  int n, k; cin >> n >> k;
  calc(); // Do it before taking test cases
  cout << "Case " << tc << ": ";
  cout << nCr(n, k) << '\n';
}

// Pascal's triangle
const int M = 105;
int ncr[M][M];
void nCrMatrix() {
  for (int i = 0; i < M; i++) ncr[i][0] = 1;
  for (int i = 1; i < M; i++) {
    for (int j = 1; j <= i; j++) {
      ncr[i][j] = ncr[i - 1][j] + ncr[i - 1][j - 1];
    }
  }
}

// Time Complexity O(n) + O(a) + O(n - a) = O(n)
int rec(int n) {
  if(n <= 1) return 1;
  return n * rec(n-1);
}
int comb(int n, int a) {
  return rec(n) / (rec(a) * rec(n-a));
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int cs = 0;
  calc();
  solve(++cs);
  cout << comb(2, 1) << '\n';

  return 0;
}
