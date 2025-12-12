#include <bits/stdc++.h>
using namespace std;

#define test int t; for(cin >> t; t; t--)

struct Trie {
  struct Node {
    int next[26];
    bool flg;
    Node() {
      memset(next, -1, sizeof next);
      flg = false;
    }
  };

  vector<Node> trie;
  Trie() {
    trie.push_back(Node()); // root
  }

  void insert(const string &s) { // O(s.size())
    int n = 0; // current node
    for (auto ch: s) {
      int c = ch - 'a';
      if (trie[n].next[c] == -1) {
        trie[n].next[c] = trie.size();
        trie.push_back(Node());
      }
      n = trie[n].next[c];
    }
    trie[n].flg = true;
  }

  bool search(const string &s) { // O(s.size())
    int n = 0;
    for (auto ch: s) {
      int c = ch - 'a';
      n = trie[n].next[c];
      if (n == -1) return false;
    }
    return trie[n].flg;
  }

  bool starts_with(const string &s) { // O(s.size())
    int n = 0;
    for (auto ch: s) {
      int c = ch - 'a';
      n = trie[n].next[c];
      if (n == -1) return false;
    }
    return true;
  }

  // Optional: Clear trie for multiple test cases
  void clear() {
    trie.clear();
    trie.emplace_back();
  }
};

void solve(int tc) {
  Trie trie;
  int n; cin >> n; // number of strings
  for (int i = 0; i < n; i++) { // O(n * L), L = length of string
    string s; cin >> s;
    trie.insert(s);
  }
  int q; cin >> q;
  while (q--) { // (q * L)
    string s; cin >> s;
    if (trie.search(s)) cout << "Found\n";
    else if (trie.starts_with(s)) cout << "Prefix only\n";
    else cout << "Not Found\n";
  }
  // Total time complexity = O(n * L + q * L)
  // Space complexity = O(t * (26 + 1)), 26 char + 1 boolean ==> (t), t = total number of nodes
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k = 1;
  // test 
  solve(k++);

  return 0;
}