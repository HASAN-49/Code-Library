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

#define pi 3.14159265358979323846
const int mod = 1e9 + 7;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int ask(int l, int r) {
  cout << "? " << l << ' ' << r << '\n';
  cout.flush();
  int x; cin >> x;
  return x;
}

void solve(int tc) {
  int n; cin >> n;
  int a[n+2] = {0};
  int x = ask(1, 3);
  int y = ask(1, 2);
  int z = ask(2, 3);
  a[1] = x - z, a[3] = x - y;
  a[2] = x - a[1] - a[3];
  for (int i = 3; i < n; i++) {
      x = ask(i, i + 1);
      a[i+1] = x - a[i];
  }
  cout << "!";
  for (int i = 1; i <= n; i++) {
      cout << ' ' << a[i];
  }
  cout << '\n';
  cout.flush();
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  // test 
  solve(k++);

  return 0;
}