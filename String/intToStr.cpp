// بسم الله الرحمن الرحيم
#include<bits/stdc++.h>
using namespace std;

string intToStr(int num) {
  //sending a number as a stream into output string
  ostringstream str1; // header <sstream> : int --> string
  str1 << num;

  // str() converts number into string
  return str1.str();
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  string s = intToStr(k);
  cout << s << '\n';

    return 0;
}