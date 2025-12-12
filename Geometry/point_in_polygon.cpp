// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

struct PT {
  long long x, y;
  PT(): x(0), y(0) {}
  PT(long long x, long long y): x(x), y(y) {}
  PT operator+(const PT& b) const { return PT{x+b.x, y+b.y}; }
  PT operator-(const PT& b) const { return PT{x-b.x, y-b.y}; }
  long long operator*(const PT& b) const { return (long long) x * b.y - (long long) y * b.x; }
  void operator+=(const PT& b) { x += b.x; y += b.y; }
  void operator-=(const PT& b) { x -= b.x; y -= b.y; }
  void operator*=(const int k) { x *= k; y *= k; }
};

int orientation(PT p, PT q, PT r) {
  long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0; // collinear
  return (val > 0) ? 1 : 2; // clockwise or counterclockwise
}

void solve() {
  int n, m; cin >> n >> m;
  vector<PT> pts(n);
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  while (m--) {
    long long x, y; cin >> x >> y;
    bool ok = false;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int j = (i + 1) % n;

      if (orientation(pts[i], pts[j], PT(x, y)) == 0 && min(pts[i].x, pts[j].x) <= x && max(pts[i].x, pts[j].x) >= x && min(pts[i].y, pts[j].y) <= y && max(pts[i].y, pts[j].y) >= y) ok = true;
      
      if (pts[i].x <= x && pts[j].x > x && orientation(pts[i], pts[j], PT(x, y)) == 1) cnt++;
      if (pts[j].x <= x && pts[i].x > x && orientation(pts[j], pts[i], PT(x, y)) == 1) cnt++;
    }
    if (ok) cout << "BOUNDARY\n";
    else if (cnt & 1) cout << "INSIDE\n";
    else cout << "OUTSIDE\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
