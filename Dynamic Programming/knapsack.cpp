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
#define M 1e9 + 7;
#define Mm 998244353

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int N = 105;
int n, W, a[N], v[N];
long long dp[N][100005];

long long rec(int i, int weight) {
  if (i >= n) return 0;
  if (dp[i][weight] != -1) return dp[i][weight];
  long long ans = rec(i+1, weight);
  if (weight + a[i] <= W) ans = max(ans, rec(i+1, weight + a[i]) + v[i]);
  return dp[i][weight] = ans;
}

void solve(int tc) {
  memset(dp, -1, sizeof dp);
  cin >> n >> W;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> v[i];
  }
  long long ans = rec(0, 0);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int k = 1;
  // test 
  solve(k++);

  return 0;
}