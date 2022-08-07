#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<int, vector<int>> lifts;
    for (int i = 0; i < n; i++) {
        int s, f;
        cin >> s >> f;
        lifts[s].push_back(f);
    }
    map<int, int> ans;

    for (auto it = lifts.rbegin(); it != lifts.rend(); ++it) {
        auto& level = it->first;
        auto& next_levels = it->second;
        for (auto next_level : next_levels) {
            ans[level] = max(ans[level], ans[next_level] + 1);
        }
    }

    int answer = 0;
    for (auto& [l, cur_answer] : ans) {
        answer = max(answer, cur_answer);
    }
    cout << answer << endl;
    return 0;
}