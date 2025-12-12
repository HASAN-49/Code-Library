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
const int mod = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 5e6 + 9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;

int binPow(int a, int n, int mod) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1LL * res * a % mod;
    a = 1LL * a * a % mod;
    n >>= 1;
  }
  return res;
}

pair<int, int> pw[N], ipw[N];
void prec() { // O(n)
  pw[0].first = pw[0].second = 1;
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
    pw[i].second = 1LL * pw[i-1].second * p2 % mod2;
  }

  int ip1 = binPow(p1, mod1 - 2, mod1);
  int ip2 = binPow(p2, mod2 - 2, mod2);
  ipw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i-1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i-1].second * ip2 % mod2;
  }
}

pair<int, int> string_hash(string s) { // O(n)
  int n = s.size();
  pair<int, int> hs({0, 0});
  for (int i = 0; i < n; i++) {
    hs.first += 1LL * pw[i].first * s[i] % mod1;
    hs.first %= mod1;
    hs.second += 1LL * pw[i].second * s[i] % mod2;
    hs.second %= mod2;
  }
  return hs;
}

struct Hashing {
  pair<int, int> pre_hash[N];
  void build(string s) { // O(n)
    int n = s.size();
    for (int i = 0; i < n; i++) {
      pre_hash[i].first = 1LL * pw[i].first * s[i] % mod1;
      if (i) pre_hash[i].first = (pre_hash[i-1].first + pre_hash[i].first) % mod1;
      pre_hash[i].second = 1LL * pw[i].second * s[i] % mod2;
      if (i) pre_hash[i].second = (pre_hash[i-1].second + pre_hash[i].second) % mod2;
    }
  }

  pair<int, int> get_hash(int i, int j) { // O(1)
    // assert(i <= j);

    pair<int, int> hs({0, 0});
    hs.first = pre_hash[j].first;
    if (i) hs.first = (hs.first - pre_hash[i-1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;

    hs.second = pre_hash[j].second;
    if (i) hs.second = (hs.second - pre_hash[i-1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;

    return hs;
  }
}S, R;

string s, r;
int n;

bool is_palindrome(int i, int j) {
  return S.get_hash(i, j) == R.get_hash(n - j - 1, n - i - 1);
}

int dp[N], is_pal[N];

int f(int i) {
  // if (!is_palindrome(0, i)) return 0;
  if (!is_pal[0, i]) return 0;
  if (i == 0) return 1;
  int &ans = dp[i];
  if (ans != -1) return ans;
  int left_end = i / 2;
  if ((i + 1) % 2) left_end--;
  return ans = 1 + f(left_end);
}

void solve(int tc) {
  cin >> s;
  r = s;
  n = s.size();
  reverse(all(r));
  prec();
  S.build(s);
  R.build(r);
  for (int i = 0; i < n; i++) {
    is_pal[i] = is_palindrome(0, i);
  }
  memset(dp, -1, sizeof dp);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += f(i);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  // test 
  solve(k++);

  return 0;
}