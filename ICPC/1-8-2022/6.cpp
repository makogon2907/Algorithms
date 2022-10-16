#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_set>

#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;

void print_vector(vector<int> a) {
    for (auto el : a) {
        cout << el << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    map<char, int> cnt;

    for (auto el : s) {
        cnt[el]++;
    }

    vector<int> rst(4, 0);
    for (auto [el, count] : cnt) {
        rst[count % 4]++;
    }

    int best_ans = s.size() + 10;
    int ssize = s.size();

    for (int a = 1; a * a <= ssize; a++) {
        vector<int> rest = rst;

        if (ssize % a != 0) {
            continue;
        }
        int b = ssize / a;

        int have_1 = ((a & 1) & (b & 1));
        int have_2 = (((a & 1) * b + (b & 1) * a) - have_1) / 2;

        if (rest[1] + rest[3] > have_1) {
            continue;
        }
        rest[0] += rest[1];
        rest[2] += rest[3];
        rest[1] = 0;
        rest[3] = 0;
        have_1 -= (rest[1] + rest[3]);

        if (rest[2] > have_2) {
            continue;
        }

        best_ans = min(best_ans, a + b);
    }

    if (best_ans == s.size() + 10) {
        cout << -1 << endl;
        return 0;
    }

    cout << best_ans << endl;
    return 0;
}