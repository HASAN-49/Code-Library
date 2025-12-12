// بسم الله الرحمن الرحيم
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;

// Print __int128
void print128(lll x) {
  if (x == 0) {
    cout << "0";
    return;
  }
  if (x < 0) {
    cout << "-", x = -x;
  }
  string s;
  while (x > 0) {
    s.push_back('0' + (x % 10));
    x /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s;
}

// Read __int128 safely
lll read128() {
  string s;
  cin >> s;
  lll res = 0;
  bool neg = false;
  int i = 0;
  if (s[0] == '-') {
    neg = true;
    i++;
  }
  for (; i < s.size(); i++) {
    res = res * 10 + (s[i] - '0');
  }
  return neg ? -res : res;
}

// Cross product: (p2 - p1) × (p3 - p1)
lll cross(lll x1, lll y1, lll x2, lll y2, lll x3, lll y3) {
  return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

// Check if point q lies on segment pr
bool onSegment(lll px, lll py, lll qx, lll qy, lll rx, lll ry) {
  if (min(px, rx) <= qx && qx <= max(px, rx) && min(py, ry) <= qy && qy <= max(py, ry)) {
    return true;
  }
  return false;
}

// Proper line segment intersection
bool doIntersect( lll x1, lll y1, lll x2, lll y2, lll x3, lll y3, lll x4, lll y4) {
  lll d1 = cross(x3, y3, x4, y4, x1, y1);
  lll d2 = cross(x3, y3, x4, y4, x2, y2);
  lll d3 = cross(x1, y1, x2, y2, x3, y3);
  lll d4 = cross(x1, y1, x2, y2, x4, y4);

  // General case
  if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
    return true;
  }

  // Special cases (collinear)
  if (d1 == 0 && onSegment(x3, y3, x1, y1, x4, y4)) return true;
  if (d2 == 0 && onSegment(x3, y3, x2, y2, x4, y4)) return true;
  if (d3 == 0 && onSegment(x1, y1, x3, y3, x2, y2)) return true;
  if (d4 == 0 && onSegment(x1, y1, x4, y4, x2, y2)) return true;

  return false;
}

void solve() {
  lll x1 = read128(), y1 = read128();
  lll x2 = read128(), y2 = read128();
  lll x3 = read128(), y3 = read128();
  lll x4 = read128(), y4 = read128();

  if (doIntersect(x1, y1, x2, y2, x3, y3, x4, y4)) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t; cin >> t;
  while (t--) solve();
  
  return 0;
}
