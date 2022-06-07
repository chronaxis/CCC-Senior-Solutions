// 2D dynamic programming... woah
#include <bits/stdc++.h>
using namespace std;

int dp[500][30001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, k, w;

    cin >> t;
    for (int tc = 0; tc<t; tc++) {
        cin >> n >> k >> w;

        memset(dp, 0, sizeof dp);
        vector<int> pins(n), sum(n);
        for (int i = 0; i<n; i++) {
            cin >> pins[i];
            sum[i] = pins[i];
        }

        vector<int> sums(n);
        for (int i = 0; i<n; i++) {
            for (int j = i; j<w+i && j<n; j++) {
                sums[i]+=pins[j];
            }
        }

        for (int i = 1; i<=k; i++) {
            for (int j = n-1; j>=0; j--) {
                if (i > n-w) {
                    dp[i][j] = sum[j];
                } else {
                    dp[i][j] = max(dp[i][j+1], dp[i-1][j+w]+sums[j]);
                }
            }
        }

        cout << dp[k][0] << "\n";
    }
}

/*
n = 9, k = 2, w = 3 
Pins: 2   8   5   1   9   6   9   3   2
Sums: 15  14  15  16  24  18  14  5   2

1
9 2 3
2
8
5
1
9
6
9
3
2
*/