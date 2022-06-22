#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int fsize = 8;

bool is_pal(int h, int m) {
    return h == (((m % 10) * 10) + (m / 10));
}

pair<int, int> get_next(int h, int m, int inter) {
    return {(h + (m + inter) / 60) % 24, (m + inter) % 60};
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;
        vector<int> cnt(10);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x % 10]++;
        }
        bool answered = false;
        for (int a = 0; a < 10; a++) {
            if (cnt[a] >= 3 && ((3 * a) % 10 == 3)) {
                answered = true;
                break;
            }
            for (int b = 0; b < 10; b++) {
                if (a == b) {
                    continue;
                }
                if (cnt[a] >= 2 && cnt[b] >= 1 && ((2 * a + b) % 10 == 3)) {
                    answered = true;
                    break;
                }
                for (int c = 0; c < 10; c++) {
                    if (c == a || c == b) {
                        continue;
                    }
                    if (answered) {
                        break;
                    }
                    if (cnt[a] == 0 || cnt[b] == 0 || cnt[c] == 0) {
                        continue;
                    }
                    if ((a + b + c) % 10 == 3) {
                        answered = true;
                        break;
                    }
                }
            }
        }
        if (!answered) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}