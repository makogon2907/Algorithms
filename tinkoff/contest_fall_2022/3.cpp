#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);

    for (auto& el : a) {
        cin >> el;
    }
    ll min_prib = 0;
    ll max_ub = 1;
    for (int i = 2; i < a.size(); i++) {
        if (i % 2 == 0) {
            if (a[min_prib] > a[i]) {
                min_prib = i;
            }
        } else {
            if (a[max_ub] < a[i]) {
                max_ub = i;
            }
        }
    }

    if (a[min_prib] < a[max_ub]) {
        swap(a[min_prib], a[max_ub]);
    }

    ll total = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            total += a[i];
        } else {
            total -= a[i];
        }
    }

    cout << total << endl;

    return 0;
}