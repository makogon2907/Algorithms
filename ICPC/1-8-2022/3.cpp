#include <iostream>

using namespace std;
using ll = long long;

const ll inf = 1000000;

int solve(string s) {
    int sum = 0;
    int six = 0, nine = 0;
    for (int i = 0; i < s.size(); ++i) {
        int a = s[i] - '0';
        six += (a == 6);
        nine += (a == 9);
        sum += a * (a != 6 && a != 9);
    }
    int ans = inf;
    for (int i = 0; i <= six; ++i) {
        if ((sum + 6 * (six - i)) % 9 == 0) {
            ans = min(ans, i);
        }
    }
    for (int i = 0; i <= nine; ++i) {
        if ((sum + 6 * i + 6 * six) % 9 == 0) {
            ans = min(ans, i);
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
