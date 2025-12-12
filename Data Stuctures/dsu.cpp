// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
int parent[N], _size[N], c;
long long ans;

void make_set(int v) {
  parent[v] = v;
  _size[v] = 1;
}

int find_set(int v) { // O(log n)
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (a < b) swap(a, b);
    parent[b] = parent[a];
    ans -= (1LL * _size[a] * _size[a] + 1LL * _size[b] * _size[b]);
    _size[a] += _size[b];
    ans += (1LL * _size[a] * _size[a]);
    c--;
  }
}

void solve() {
  int n, m; cin >> n >> m;
  c = n, ans = n;
  for (int i = 1; i <= n; i++) {
    make_set(i);
  }
  while (m--) {
    int type; cin >> type;
    if (type == 1) {
      int u, v; cin >> u >> v;
      union_sets(u, v);
    }
    else {
      int g = __gcd(ans, 1LL * c);
      cout << ans / g << '/' << c / g << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}