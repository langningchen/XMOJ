#include <bits/stdc++.h>

using namespace std;
map<long long, long long> fab;

long long f(int n) {
    if (n == 1 || n == 2) return 1;
    if (!fab.count(n)) {
        fab[n] = (f(n - 1) % 1000000007 + f(n - 2) % 1000000007) % 1000000007;
    }
    return fab[n];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << f(p) << endl;
    }
    return 0;
}

