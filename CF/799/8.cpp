#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct hasher {
    size_t operator()(const int& x) const {
        return x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;
        vector<pair<int, vector<int>>> pos;
        map<int, int> number;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (!number.count(x)) {
                number[x] = pos.size();
                pos.push_back({x, {i}});
            } else {
                pos[number[x]].second.push_back(i);
            }
        }
        int ans = 1;
        int ansleft = pos.begin()->second[0];
        int ansright = pos.begin()->second[0];
        int ansval = pos.begin()->first;

        for (size_t t = 0; t < pos.size(); t++) {
            int key = pos[t].first;
            const vector<int>& positions = pos[t].second;

            int minpref = 0;
            int curpref = 0;
            int lpref = 0;
            curpref = -positions[0];
            minpref = curpref;
            lpref = positions[0];
            curpref++;
            for (size_t i = 1; i < positions.size(); i++) {
                curpref -= positions[i] - positions[i - 1] - 1;
                if (curpref < minpref) {
                    minpref = curpref;
                    lpref = positions[i];
                }
                curpref++;
                if (curpref - minpref > ans) {
                    ans = curpref - minpref;
                    ansleft = lpref;
                    ansright = positions[i];
                    ansval = key;
                }
            }
        }
        cout << ansval << " " << ansleft + 1 << " " << ansright + 1 << "\n";
    }
    return 0;
}