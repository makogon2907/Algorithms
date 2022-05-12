#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

ll mod = 998244353;

int main() {
    int t;
    cin >> t;
    const int maxn = 2000;
    vector<ll> dp(maxn);

    dp[0] = 1;
    for (int i = 1; i < maxn; i++) {
        dp[i] = (dp[i - 1] * i) % mod;
    }

    while (t--) {
        int n;
        cin >> n;
        if (n & 1) {
            cout << 0 << "\n";
        } else {
            cout << (dp[n / 2] * dp[n / 2]) % mod << "\n";
        }
    }

    return 0;
}