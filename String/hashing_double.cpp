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

#define __lcm(a, b) ((a / __gcd(a, b)) * b)
#define pi 3.14159265358979323846

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;

const int N = 1e5 + 9;

pair<int, int> pw[N];
void prec() {
    pw[0].first = pw[0].second = 1;
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i-1].second * p2 % mod2;
    }
}

pair<int, int> string_hash(string s) {
    int n = s.size();
    pair<int, int> hs({0, 0});
    for (int i = 0; i < n; i++) {
        hs.first += 1LL * pw[i].first * s[i] % mod1;
        hs.first %= mod1;
        hs.second += 1LL * pw[i].second * s[i] % mod2;
        hs.second %= mod2;
    }
    return hs;
}

void solve(int tc) {
    prec();
    
    string a, b;
    cin >> a >> b;

    cout << (string_hash(a) == string_hash(b)) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k = 1;
    // test 
    solve(k++);

    return 0;
}
