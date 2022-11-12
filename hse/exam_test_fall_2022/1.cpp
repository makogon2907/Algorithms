#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    map<char, int> cnta;
    map<char, int> cntb;

    int bulls = 0;
    int cows = 0;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            bulls++;
        } else {
            cnta[a[i]]++;
            cntb[b[i]]++;
        }
    }

    for (char x = '0'; x <= '9'; x++) {
        cows += min(cnta[x], cntb[x]);
    }

    cout << bulls << endl;
    cout << cows << endl;
    return 0;
}