#include <bits/stdc++.h>
using namespace std;

int grid[101][101];
int dp[101][101];
int visited[101][101];
int main() {
    int m, n, v;
    char o;
    while (true) {
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        memset(grid, '.', sizeof(grid));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i<=m; i++) {
            for (int j = 1; j<=n; j++) {
                cin >> o;   
                v = o - '0';
                if (o == '.') v = 0;
                if (o == '*') v = -1;
                grid[i][j] = v;
            }
        }

        // setup as start has edge case
        dp[m][1] = grid[m][1];
        for (int r = m; r>0; r--) {
            if (grid[r][1] < 0) break;
            visited[r][1] = 1;
            dp[r][1] = dp[r+1][1] + grid[r][1];
        }
        
        for (int c = 2; c<=n; c++) {
            for (int r = 1; r<=m; r++) {
                if (grid[r][c] < 0) continue;
                if (c == n && r == m) continue;
                if (!visited[r][c-1]) continue;

                // go upwards
                int from = dp[r][c-1];
                for (int tr = r; tr<=m; tr++) {
                    if (grid[tr][c] < 0) break;
                    from += grid[tr][c];
                    dp[tr][c] = max(from, dp[tr][c]);
                    visited[tr][c] = 1;
                }

                // go downwards
                from = dp[r][c-1] + grid[r][c];
                for (int tr = r-1; tr>0; tr--) {
                    if (grid[tr][c] < 0) break;
                    from += grid[tr][c];
                    dp[tr][c] = max(from, dp[tr][c]);
                    visited[tr][c] = 1;
                }
            }
        }

        // check for edge case at toadstool destination
        dp[m][n] = max(dp[m][n-1], dp[m][n]);
        cout << dp[m][n] << "\n";
    }
}
