#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {

    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<pair<int, int>> s;
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.push_back({x, i});
        }
        for (auto& el : f) {
            cin >> el;
        }
        sort(s.begin(), s.end());
        vector<int> ans(n);
        int prev_time_finish = -1;

        for (const auto [start_time, num] : s) {
            ans[num] = f[num] - max(start_time, prev_time_finish);
            prev_time_finish = f[num];
        }
        for (auto el : ans) {
            cout << el << " ";
        }
        cout << "\n";
    }

    return 0;
}