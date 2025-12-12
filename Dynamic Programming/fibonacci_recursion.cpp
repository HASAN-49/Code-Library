#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int f[N];

int fibo(int n) {
    if (n < 2) return n;
    if (f[n] > 0) return f[n];
    f[n] = fibo(n - 1) + fibo(n - 2);
    return f[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    cout << fibo(20) << '\n';
    return 0;
}
