#include <iostream>
#include <vector>
#include <set>
#include <chrono>

using namespace std;

int main() {
    srand(time(NULL));

    int n = rand() % 20 + 2;
    int m = rand() % 100;

    m = min(m, n * (n - 1) / 2);

    vector<pair<int, int>> edges;

    cout << n << " " << m << endl;

    return 0;
}