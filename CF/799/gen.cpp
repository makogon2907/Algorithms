#include <iostream>

using namespace std;

int main() {
    int n = 200000;

    cout << 1 << endl << n << endl;
    for (int i = 0; i < n; i++) {
        cout << rand() % 1000 << " ";
    }
    cout << endl;
    return 0;
}