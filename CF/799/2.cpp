#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;
        unordered_map<int, int> visited;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            visited[x]++;
        }
        int todel = 0;
        for (auto [k, cnt] : visited) {
            todel += (cnt - 1);
        }

        cout << n - (todel + (todel & 1)) << "\n";
    }
    return 0;
}