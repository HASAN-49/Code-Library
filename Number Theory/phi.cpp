// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

vector<int> phi_1_to_n(int n) {
  vector<int> phi(n + 1);
  for (int i = 0; i <= n; i++)
    phi[i] = i;

  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i)
        phi[j] -= phi[j] / i;
    }
  }
  return phi;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 10;
  auto phi = phi_1_to_n(n);
  for (int i = 1; i <= n; i++) {
  	cout << phi[i] << ' ';
  }
  cout << '\n';

  return 0;
}