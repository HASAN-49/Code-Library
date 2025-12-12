// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define ll long long

#define all(a) a.begin(), a.end() 
#define allr(a) a.rbegin(), a.rend()

#define yes cout << "Yes\n"
#define no cout << "No\n"
#define endl '\n'

const int mod = 1e9 + 7;

const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
const int N = 2e5 + 9;

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
void prec() { 
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

using T = pair<int, int>;

T add(T a, T b) {
  a.first = (a.first + b.first) % mod1;
  a.second = (a.second + b.second) % mod2;
  return a;
}

T mul(T a, int b) {
  a.first = 1LL * a.first * b % mod1;
  a.second = 1LL * a.second * b % mod2;
  return a;
}

T mul(T a, T b) {
  a.first = 1LL * a.first * b.first % mod1;
  a.second = 1LL * a.second * b.second % mod2;
  return a;
}

struct Hashing {
  vector<T> t;
  int n;
  string s;

  Hashing () {}
  Hashing (string _s) {
    s = _s;
    n = s.size();
    t.resize(4 * N);
    build(1, 0, n - 1);
  }

  T query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return make_pair(0, 0);
    if (b >= i && e <= j) return t[n];
    int l = 2 * n, r = 2 * n + 1;
    int mid = b + (e - b) / 2;
    return add(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
  }

  void upd(int n, int b, int e, int i, char ch) {
    if (b > i || e < i) return;
    if (b == i && e == i) {
      t[n] = mul(pw[b], ch);
      return;
    }
    int l = 2 * n, r = 2 * n + 1;
    int mid = b + (e - b) / 2;
    upd(l, b, mid, i, ch);
    upd(r, mid + 1, e, i, ch);
    t[n] = add(t[l], t[r]);
  }

  void build(int n, int b, int e) {
    if (b == e) {
      t[n] = mul(pw[b], s[b]);
      return;
    }
    int l = 2 * n, r = 2 * n + 1;
    int mid = b + (e - b) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = add(t[l], t[r]);
  }

  T get_hash (int i, int j) {
    return mul(query(1, 0, n - 1, i, j), ipw[i]);
  }
}S, R;

void solve(int tc) {
  int n, q; cin >> n >> q;
  string s; cin >> s;
  string r = s;
  reverse(all(r));
  prec();
  S = Hashing(s);
  R = Hashing(r);
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int pos; cin >> pos;
      char x; cin >> x;
      pos--;
      S.upd(1, 0, n - 1, pos, x);
      R.upd(1, 0, n - 1, n - pos - 1, x);
    }
    else {
      int l, r; cin >> l >> r;
      l--, r--;
      if (S.get_hash(l, r) == R.get_hash(n - r - 1, n - l - 1)) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }
} 

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  // test 
  solve(k++);

  return 0;
}