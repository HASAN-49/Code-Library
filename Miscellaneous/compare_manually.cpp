// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

/*=====================================================================*/
// Compare set and reverse sort by length
struct hasan {
  int first, second;
};
bool cmp(const hasan &a, const hasan &b) {
  int lena = a.second - a.first + 1;
  int lenb = b.second - b.first + 1;
  if (lena == lenb) return a.first < b.first;
  return lena > lenb;
}

/*=====================================================================*/
// Compare a pair
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}

void solve(int tc) {
  set<hasan, bool(*)(const hasan&, const hasan&)> se(cmp);
   
	// both are correct
	vector<pair<int, int>> vp;
	vector<pair<int, int>> vpp;
	sort(vpp.begin(), vpp.end(), [&] (const pair<int, int> &a, const pair<int, int> &b) {return a.second > b.second;});
}

/*=====================================================================*/
// String Compare
bool cmp(const string &a, const string &b) {
  return a + b < b + a;
}

void solve1() {
  int n; cin >> n;
  vector<string> s;
  for (int i = 0; i < n; i++) {
    string a; cin >> a;
    s.push_back(a);
  }
  sort(s.begin(), s.end(), cmp);
  for (auto x: s)
    cout << x;
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  test 
  solve(k++);

  return 0;
}