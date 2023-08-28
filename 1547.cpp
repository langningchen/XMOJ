#include <bits/stdc++.h>

using namespace std;
int h[100005] = {0}, n, ans;
vector<int> g;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (i == 1 || h[i] > g[g.size() - 1]) {
            g.push_back(h[i]);
        } else {
            int j = lower_bound(g.begin(), g.end(), h[i]) - g.begin();
            g[j] = h[i];
        }
    }
    cout << g.size() << endl;
    return 0;
}

