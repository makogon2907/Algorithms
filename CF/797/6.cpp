#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using ll = long long;

string get_next(const string& s, const vector<int>& p) {
    string ans = s;
    for (size_t i = 0; i < ans.size(); i++) {
        ans[i] = s[p[i]];
    }
    return ans;
}

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll nok(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll min_len_cycle(const string& given) {
    string_view s(given);

    for (size_t len = 1; len <= s.size() / 2; len++) {
        bool success = true;
        if (s.size() % len != 0) {
            continue;
        }
        for (size_t start = len; start < s.size(); start += len) {
            if (s.substr(start, len) != s.substr(0, len)) {
                success = false;
                break;
            }
        }

        if (success) {
            return len;
        }
    }

    return s.size();
}

int main() {

    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        string s;
        vector<int> p(n);
        cin >> s;
        for (auto& el : p) {
            cin >> el;
            el--;
        }
        ll ans = 1;
        vector<bool> used(n);
        vector<vector<int>> cycles;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = true;
                cycles.push_back({i});
                while (!used[p[cycles.back().back()]]) {
                    cycles.back().push_back(p[cycles.back().back()]);
                    used[cycles.back().back()] = true;
                }
            }
        }
        for (const auto& cycle : cycles) {
            string t;
            for (auto el : cycle) {
                t += s[el];
            }
            ans = nok(ans, min_len_cycle(t));
        }
        cout << ans << "\n";
    }

    return 0;
}