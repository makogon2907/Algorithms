#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

int main() {

    int test;
    cin >> test;
    while (test--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto& el : a) {
            cin >> el;
        }
        set<int> used_indexes = {0};
        int h = a[0];
        for (size_t i = 1; i < a.size(); i++) {
            if (a[i] < h) {
                h = a[i];
                used_indexes.insert(i);
            }
        }
        while (m--) {
            int k, d;
            cin >> k >> d;
            k--;
            if (d == 0) {
                cout << used_indexes.size() << " ";
                continue;
            }

            int new_h = a[k] - d;
            auto right_closest = used_indexes.lower_bound(k);
            while (right_closest != used_indexes.end() && a[*right_closest] >= new_h) {
                auto old = right_closest;
                right_closest++;
                used_indexes.erase(old);
            }
            a[k] -= d;
            if (right_closest == used_indexes.begin()) {
                used_indexes.insert(k);
            } else {
                right_closest--;
                if (a[*right_closest] > a[k]) {
                    used_indexes.insert(k);
                }
            }
            for (auto el : used_indexes) {
                cerr << el << " ";
            }
            cerr << endl;
            cout << used_indexes.size() << " ";
        }
        cout << "\n";
    }

    return 0;
}