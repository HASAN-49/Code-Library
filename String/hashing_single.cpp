// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define ll long long
#define ull unsigned long long
#define ld long double

#define all(a) a.begin(), a.end() 
#define allr(a) a.rbegin(), a.rend()
#define out(x) cout << x << endl
#define outs(x) cout << x << " "

#define yes cout << "Yes\n"
#define no cout << "No\n"
#define endl '\n'
#define nline cout << '\n'

#define __lcm(a, b) ((a / __gcd(a, b)) * b)
#define pi 3.14159265358979323846

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 1e5 + 9;
const int p = 137, mod = 1e9 + 7;

int pw[N];
void prec() {
  pw[0] = 1;
  for (int i = 1; i < N; i++) {
    pw[i] = 1LL * pw[i-1] * p % mod;
  }
}

int string_hash(string s) {
  int n = s.size();
  int hs = 0;
  for (int i = 0; i < n; i++) {
    hs += 1LL * pw[i] * s[i] % mod;
    hs %= mod;
  }
  return hs;
}

void solve(int tc) {
  string a, b;
  cin >> a >> b;
  prec();
  cout << (string_hash(a) == string_hash(b)) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  // test 
  solve(k++);

  return 0;
}