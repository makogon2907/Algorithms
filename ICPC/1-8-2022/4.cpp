#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_set>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    map<pair<int, int>, unordered_set<int>> f;

    for (int i = 0; i < 32; i++) {
        f[{((a >> i) & 1), ((b >> i) & 1)}].insert((c >> i) & 1);
    }

    for (const auto& [k, v] : f) {
        if (v.size() > 1) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << (1 << (4 - f.size())) << endl;
    return 0;
}