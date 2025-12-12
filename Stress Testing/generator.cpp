#include<bits/stdc++.h>
using namespace std;

const int N = 100;
const long long M = 20;

// NEVER use rand() function because rand() will always generate same random values even if you run the same code multiple times
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); // using current time as seed, so it will always generate different random values if you run this code multiple times
long long get_rand(long long l, long long r) { // random number from l to r
  assert(l <= r);
  return l + rnd() % (r - l + 1);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  for (int i = 0; i < 10; i++) {
    cout << char ('a' + get_rand(0, 25));
  }
  cout << '\n';
  test = get_rand(1, 5);
  cout << test << "\n";
  while (test--) {
    int n = get_rand(1, 10);
    for (int i = 0; i < n; i++) {
      cout << char ('a' + get_rand(0, 25));
    }
    cout << '\n';
  }
  return 0;
}