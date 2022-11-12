#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> cnt;

    for (int i = 0; i < n; i++) {
        vector<string> names(3);
        for (auto& name : names) {
            cin >> name;
        }
        sort(names.begin(), names.end());
        string res = names[0];
        res += " ";
        res += names[1];
        res += " ";
        res += names[2];
        cnt[res]++;
    }

    int ans = 0;
    for (const auto& [key, counter] : cnt) {
        ans = max(ans, counter);
    }

    cout << ans << endl;
    return 0;
}