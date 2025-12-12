// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int inv(int x) {
	int res = 1, b = mod - 2;
	while(b > 0) {
		if(b&1) res = 1LL * res * x % mod;
		x = 1 * x * x % mod;
		b = b >> 1;
	}
	return res;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 3;
  int ans = inv(k);
  cout << ans << '\n';

  return 0;
}
