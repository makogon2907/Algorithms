#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

ll cnt_go_to(int pos, int target, int left, int right) {
    if (pos <= target) {
        return target - pos;
    }
    return right - pos + target - left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    map<char, vector<int>> letter_positions;
    for (int i = 0; i < n; i++) {
        letter_positions[s[i]].push_back(i);
    }

    int q;
    cin >> q;
    while (q--) {
        // cerr << "case : " << q << endl;
        int left, right;
        cin >> left >> right;
        left--;
        int curpos = left;
        ll answer = 0;
        for (char next_symbol = 'a'; next_symbol <= 'z'; next_symbol++) {
            auto& positions = letter_positions[next_symbol];
            int first_pos_idx =
                lower_bound(positions.begin(), positions.end(), left) - positions.begin();
            if (first_pos_idx == positions.size() || positions[first_pos_idx] >= right) {
                continue;
            }
            int first_pos = positions[first_pos_idx];
            int last_pos_idx =
                (lower_bound(positions.begin(), positions.end(), right) - positions.begin()) - 1;

            int last_pos = positions[last_pos_idx];
            // cerr << next_symbol << " " << first_pos << " " << last_pos << endl;

            answer += cnt_go_to(curpos, first_pos, left, right);
            // cerr << "first step : " << answer << endl;
            curpos = first_pos;
            answer += cnt_go_to(curpos, last_pos, left, right);
            // cerr << "second step : " << answer << endl;
            curpos = last_pos;
        }
        cout << answer << "\n";
    }

    return 0;
}