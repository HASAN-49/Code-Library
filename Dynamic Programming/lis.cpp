// Problem Link --> https://www.hackerrank.com/challenges/longest-increasing-subsequent/problem

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9; int dp[N]; int t[N * 4];

void upd(int n, int b, int e, int i, int v) {
  if (b > i || e < i) return;
  if (b == i && e == i) {
    t[n] = max(t[n], v);
    return;
  }
  int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
  upd(l, b, mid, i, v);
  upd(r, mid + 1, e, i, v);
  t[n] = max(t[l], t[r]);
}

int query(int n, int b, int e, int i, int j) {
  if (b > j || e < i) return 0;
  if (b >= i && e <= j) return t[n];
  int l = n * 2, r = n * 2 + 1, mid = b + (e - b) / 2;
  return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve(int tc) {
  int n; cin >> n;
  int a[n+1];
  map<int, int> mp;
  set<int> st;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    // dp[i] = 1;
    st.insert(a[i]);
  }
  int c = 0;
  for (auto x: st) {
    mp[x] = ++c;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = mp[a[i]];
    // cout << a[i] << ' ';
  }
  // cout << '\n';
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    if (a[i] != 1) {
      int mx = query(1, 1, N, 1, a[i] - 1);
      // for (int j = 1; j < i; j++) {
      //   if (a[i] > a[j]) {
      //     mx = max(mx, dp[j]);
      //   }
      // }
      mx++;
      dp[i] = max(mx, dp[i]);
    }
    upd(1, 1, N, a[i], dp[i]);
    // cout << dp[i] << ' ';
  }
  // cout << '\n';
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  // test 
  solve(k++);

  return 0;
}
