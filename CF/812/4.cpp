#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <vector>

using namespace std;

const int maxn = 1e9;

mt19937 rnd(239);

int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ans = 0;
    cin >> ans;
    if (ans == 1) {
        return a;
    } else if (ans == 2) {
        return b;
    } else {
        return -1;
    }
}
void answer(int a) {
    cout << "! " << a << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;

    while (test--) {
        int n;
        cin >> n;
        n = (1 << n);
        vector<int> candidates;
        for (int i = 1; i <= n; i++) {
            candidates.push_back(i);
        }
        if (candidates.size() == 2) {
            answer(ask(candidates[0], candidates[1]));
            continue;
        }
        while (candidates.size() > 2) {
            vector<int> next_candidates;
            for (int i = 0; i < (int)candidates.size() - 3; i += 4) {
                int best;
                if ((best = ask(candidates[i], candidates[i + 2])) == -1) {
                    next_candidates.push_back(ask(candidates[i + 1], candidates[i + 3]));
                } else {
                    if (best == candidates[i]) {
                        next_candidates.push_back(ask(candidates[i], candidates[i + 3]));
                    } else {
                        next_candidates.push_back(ask(candidates[i + 1], candidates[i + 2]));
                    }
                }
            }
            swap(candidates, next_candidates);
        }
        if (candidates.size() == 2) {
            answer(ask(candidates[0], candidates[1]));
        } else {
            answer(candidates[0]);
        }
    }
    return 0;
}