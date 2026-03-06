#include <bits/stdc++.h>
using namespace std;

vector<vector<long long> > build_pref2D(const vector<vector<long long> > &a, int n, int m) {
  vector<vector<long long> > pref2D(n + 1, vector<long long>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref2D[i][j] = a[i][j] + pref2D[i - 1][j] + pref2D[i][j - 1] - pref2D[i - 1][j - 1];
    }
  }
  return pref2D;
}

long long rectSum(const vector<vector<long long> > &pref2D, int r1, int c1, int r2, int c2) {
  if (r1 > r2) swap(r1, r2);
  if (c1 > c2) swap(c1, c2);
  return pref2D[r2][c2] - pref2D[r1 - 1][c2] - pref2D[r2][c1 - 1] + pref2D[r1 - 1][c1 - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  vector<vector<long long> > a(n + 1, vector<long long>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  auto pref2D = build_pref2D(a, n, m);
  int q; cin >> q;
  while (q--) {
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    cout << rectSum(pref2D, r1, c1, r2, c2) << "\n";
  }

  return 0;
}