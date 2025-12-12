// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)
#define ll long long
#define ull unsigned long long
#define ld long double

#define all(a) a.begin(), a.end() 
#define allr(a) a.rbegin(), a.rend()

const int N = 1e5 + 9, B = 20;
int a[N], lazy[N * 4];

struct node {
  int on[B], off[B];
};

node t[N * 4];

void push(int n, int b, int e) {
  if (lazy[n] == 0) {
    return;
  }
  for (int i = 0; i < B; i++) {
    int bit = ((lazy[n] >> i) & 1);
    if (bit) {
      swap(t[n].off[i], t[n].on[i]);
    }
  }
  if (b != e) {
    int l = n * 2, r = n * 2 + 1;
    lazy[l] ^= lazy[n];
    lazy[r] ^= lazy[n];
  }
  lazy[n] = 0;
}

node merge(node l, node r) {
  node ans;
  for (int i = 0; i < B; i++) {
    ans.on[i] = l.on[i] + r.on[i];
    ans.off[i] = l.off[i] + r.off[i];
  }
  return ans;
}

node query(int n, int b, int e, int i, int j) {
  push(n, b, e);
  if (b > j || e < i) {
    node zero;
    memset(zero.on, 0, sizeof zero.on);
    memset(zero.off, 0, sizeof zero.off);
    return zero;
  }
  if (b >= i && e <= j) {
    return t[n];
  }
  int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
  return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void upd(int n, int b, int e, int i, int j, int v) {
  push(n, b, e);
  if (b > j || e < i) return;
  if (b >= i && e <= j) {
    lazy[n] = v;
    push(n, b, e);
    return;
  }
  int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
  upd(l, b, mid, i, j, v);
  upd(r, mid + 1, e, i, j, v);
  t[n] = merge(t[l], t[r]);
}

void build(int n, int b, int e) {
  lazy[n] = 0;
  if (b == e) {
    for (int i = 0; i < B; i++) {
      int bit = ((a[b] >> i) & 1);
      if (bit) {
        t[n].on[i] = 1;
        t[n].off[i] = 0;
      }
      else {
        t[n].on[i] = 0;
        t[n].off[i] = 1;
      }
    }
    return;
  }
  int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
  build(l, b, mid);
  build(r, mid + 1, e);
  t[n] = merge(t[l], t[r]);
}

void solve(int tc) {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int l, r; cin >> l >> r;
      node ans = query(1, 1, n, l, r);
      long long sum = 0;
      for (int i = 0; i < B; i++) {
        sum += 1LL * ans.on[i] * (1 << i);
      }
      cout << sum << '\n';
    }
    else {
      int l, r, v; cin >> l >> r >> v;
      upd(1, 1, n, l, r, v);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // #ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // #endif

  int k = 1;
  // test 
  solve(k++);

  return 0;
}