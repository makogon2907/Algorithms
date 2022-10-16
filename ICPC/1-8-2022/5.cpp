#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_set>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;

ll solve(ll a, ll b, ll c) {
    if (a + b + c == 0) {
        return 0;
    }

    if ((a > 0 && b > 0) || (a >= 2 && c > 0)) {
        return a + 2 * b + 3 * c;
    }

    if (a == 1) {
        return 2 * c + 1;
    }

    if (a > 0) {
        return a;
    }

    if (b >= 2 && c >= 2) {
        return a + 2 * b + 3 * c - 2;
    }

    if (b == 1) {
        return 2 * c + 1;
    }

    if (c == 1) {
        return 2 * b + 1;
    }

    if (b > 0) {
        return b;
    }
    if (c > 0) {
        return c;
    }
    return -1000;
}

ll slow_solve(ll a, ll b, ll c) {
    set<ll> res;
    for (ll i = 0; i <= a; i++) {
        for (ll j = 0; j <= b; j++) {
            for (ll k = 0; k <= c; k++) {
                res.insert(i + 2 * j + 3 * k);
            }
        }
    }
    res.erase(0);
    return res.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c) << endl;
    return 0;
}