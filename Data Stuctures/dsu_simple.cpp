// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int parent[N], _size[N];

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
    _size[a] += _size[b];
  }
}

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    make_set(i);
  }
  while (m--) {
    int u, v; cin >> u >> v;
    union_sets(u, v);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, _size[i]);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}