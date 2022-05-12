#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int ans = 0;
        int counter = 2;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                counter++;
                continue;
            } else {
                ans += max(0, 2 - counter);
                counter = 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}