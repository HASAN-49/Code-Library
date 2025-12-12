#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
bitset<N> f;
vector<int> primes;

void sieve() {
  // int n = N - 9;
  f[1] = true;
  for (int i = 2; i * i < N; i++) {
    if (!f[i]) {
      for (int j = i * i; j < N; j += i) {
        f[j] = true;
      }
    }
  }
  for (int i = 2; i < N; i++) {
    if (!f[i]) {
      primes.push_back(i);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();
  cout << primes.size() << '\n';

  // int k = 1;
  // test 
  // solve(k++);

  return 0;
}