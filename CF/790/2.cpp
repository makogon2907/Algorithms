#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

const ll inf = (1LL << 60);

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        ll m = inf;
        ll sum = 0;
        for (auto& el : a) {
            cin >> el;
            m = min(el, m);
            sum += el;
        }
        cout << sum - n * m << "\n";
    }
    return 0;
}