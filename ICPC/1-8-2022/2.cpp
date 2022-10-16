#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define all(x) x.begin(), x.end()

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> parts(4);
    for (auto &el : parts) {
        cin >> el;
    }

    sort(all(parts));

    do {
        bool triangle = (parts[0] + parts[1] > parts[2] + parts[3]) &&
                        (parts[0] + parts[2] + parts[3] > parts[1]) &&
                        (parts[1] + parts[2] + parts[3] > parts[0]);

        bool biss = (parts[0] * parts[3] == parts[1] * parts[2]);

        if (triangle && biss) {
            cout << 1 << endl;
            return 0;
        }

    } while (next_permutation(all(parts)));

    cout << 0 << endl;
    return 0;
}