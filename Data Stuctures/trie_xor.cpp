// // Binary Trie for XOR Problems

// // A Binary Trie is an optimized data structure used for solving problems related to XOR operations on binary numbers. It is particularly useful for solving problems like:

// // Maximum XOR Pair: Given a set of integers, find two numbers such that their XOR is maximized.

// // Maximum XOR with a value: Given a set of integers and a query number, find the maximum XOR of the query with any number in the set.

// // Subarray XOR problems: Where you compute the XOR of various subarrays and need to maximize or minimize it.

// // -------------------------------------------------------------------------------------------------------------------------------------

// // Binary Trie Structure

// // Trie Node: Each node represents a bit (0 or 1).

// // Insert a number: Convert the number to a binary string, and insert it bit-by-bit into the trie.

// // Maximum XOR Query: For each bit, try to take the opposite path (maximize the XOR result) and return the final XOR value.

// // -------------------------------------------------------------------------------------------------------------------------------------

// #include <bits/stdc++.h>
// using namespace std;

// struct BinaryTrie {
// 	struct Node {
// 		int next[2]; // To store the next 0 and 1
// 		Node() {
// 			memset(next, -1, sizeof next);
// 		}
// 	};
// 	vector<Node> trie;
// 	int mx_bits; // Max num of bits

// 	BinaryTrie() {
// 		trie.push_back(Node()); // root
// 	}

// 	void insert(int x) {
// 		int n = 0;
// 		for (int i = mx_bits - 1; i >= 0; i--) {
// 			int bit = x & (1 << i);
// 			if (trie[n].next[bit] == -1) {
// 				trie[n].next[bit] = trie.size();
// 				trie.push_back(Node());
// 			}
// 			n = trie[n].next[bit];
// 		}
// 	}

// 	int max_xor(int x) {
// 		int n = 0; 
// 		int ans = 0;
// 		for (int i = mx_bits - 1; i >= 0; i--) {
// 			int bit = x & (1 << i);
// 			int oop = 1 - bit;
// 			if (trie[n].next[oop] == -1) {
// 				ans |= (1 << i);
// 				n = trie[n].next[oop];
// 			}
// 			else if (trie[n].next[bit] == -1) {
// 				n = trie[n].next[oop];
// 			}
// 			else {
// 				return 0;
// 			}
// 		}
// 		return ans;
// 	}
// };

// void solve() {
// 	int n; cin >> n;
// 	vector<int> a(n);
// 	for (int i = 0; i < n; i++) {
// 		cin >> a[i];
// 	}

// 	BinaryTrie trie;
// 	int mx = 0;

// 	trie.insert(a[0]);

// 	for (int i = 1; i < n; i++) {
// 		int cur = trie.max_xor(a[i]);
// 		mx = max(mx, cur);
// 		trie.insert(a[i]);
// 	}

// 	cout << "Max xor of 2 numbers = " << mx << '\n';
// }

// int32_t main() {
// 	ios_base::sync_with_stdio(false);
//   cin.tie(NULL);

//   solve();

// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct BinaryTrie {
    struct Node {
        int next[2];
        Node() { next[0] = next[1] = -1; }
    };

    vector<Node> trie;
    int max_bits = 32;

    BinaryTrie() {
        trie.push_back(Node()); // root
    }

    void insert(int x) {
        int v = 0;
        for (int i = max_bits - 1; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (trie[v].next[bit] == -1) {
                trie[v].next[bit] = trie.size();
                trie.push_back(Node());
            }
            v = trie[v].next[bit];
        }
    }

    int max_xor(int x) {
        int v = 0;
        int ans = 0;
        for (int i = max_bits - 1; i >= 0; --i) {
            int bit = (x >> i) & 1;
            int opp = 1 - bit;
            if (trie[v].next[opp] != -1) {
                ans |= (1 << i);
                v = trie[v].next[opp];
            } else if (trie[v].next[bit] != -1) {
                v = trie[v].next[bit];
            } else {
                return 0; // shouldn't happen if trie is not empty
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    BinaryTrie trie;
    int max_result = 0;

    // Insert first number (no pair yet)
    trie.insert(arr[0]);

    // For each subsequent number, query max XOR with existing ones
    for (int i = 1; i < n; i++) {
        int current_max_xor = trie.max_xor(arr[i]);
        max_result = max(max_result, current_max_xor);
        trie.insert(arr[i]);
    }

    cout << "Maximum XOR of any two numbers in the array: " << max_result << endl;

    return 0;
}