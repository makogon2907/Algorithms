#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);

    for (auto& el : h) {
        cin >> el;
    }
    for (int i = 0; i < h.size() - 2; i++) {
        if (h[i] < h[i + 1] && h[i + 1] > h[i + 2]) {
            cout << i + 2 << endl;
            return 0;
        }
    }
    return 0;
}