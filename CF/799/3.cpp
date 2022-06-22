#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int fsize = 8;

int main() {
    int test;
    cin >> test;

    while (test--) {
        vector<int> cnt(fsize, 0);
        vector<int> pos(fsize, -1);
        for (int i = 0; i < fsize; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < fsize; j++) {
                if (s[j] == '#') {
                    cnt[j]++;
                    if (pos[j] == -1) {
                        pos[j] = i;
                    }
                }
            }
        }

        for (int i = 1; i < fsize - 1; i++) {
            if (cnt[i] == 1 && cnt[i - 1] == 2 && cnt[i + 1] == 2) {
                cout << pos[i] + 1 << " " << i + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}