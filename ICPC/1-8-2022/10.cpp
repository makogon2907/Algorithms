#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> acc(n);
    int acc_val = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++acc_val;
        } else {
            --acc_val;
        }
        acc[i] = acc_val;
    }

    vector<int> zeros;
    for (int i = 0; i < n; ++i) {
        if (acc[i] == 0 || acc[i] == 1) {
            zeros.push_back(i);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        if (a == b) {
            cout << "Yes\n";
            continue;
        }

        if (a > b) {
            swap(a, b);
        }

        if (s[a] == s[b]) {
            cout << "Yes\n";
            continue;
        }

        if (s[a] == ')' && s[b] == '(') {
            cout << "Yes\n";
            continue;
        }

        int pos = lower_bound(zeros.begin(), zeros.end(), a) - zeros.begin();
        if (zeros[pos] < b) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
    }
}
