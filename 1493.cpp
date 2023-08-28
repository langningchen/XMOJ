#include <bits/stdc++.h>

using namespace std;

int main() {
    int f[200][200] = {{0}}, dp[200][200] = {{0}}, n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &f[i][j]);
        }
    }
    __attribute__((unused)) auto printDebug = [&]() {
        ofstream csv("dp.csv");
        for (int i = 1; i <= n; ++i) {
            bool f = true;
            for (int j = 1; j <= n; ++j) {
                if (!f) csv << ',';
                f = false;
                csv << dp[i][j];
            }
            csv << endl;
        }
    };
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1) {
                dp[i][j] = f[i][j];
            } else if (i == 1) {
                dp[i][j] = dp[i][j - 1] + f[i][j];
            } else if (j == 1) {
                dp[i][j] = dp[i - 1][j] + f[i][j];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + f[i][j];
            }
        }
    }
    //printDebug();
    cout << dp[n][n] << endl;
    return 0;
}

