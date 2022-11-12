#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

using ll = long long;

int main() {

    string s;
    cin >> s;
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            break;
        }
        char symbol = s[left];
        while (left < right && s[left] == symbol) {
            left++;
        }
        while (left < right && s[right] == symbol) {
            right--;
        }
        if (left == right && s[left] == symbol) {
            left++;
        }
    }
    cout << right - left + 1 << endl;
    return 0;
}