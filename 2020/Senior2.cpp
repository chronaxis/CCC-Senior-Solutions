// this solution AC'd on DMOJ
#include <bits/stdc++.h>
using namespace std;

int grid[1001][1001], vis[1001][1001];
vector<pair<int,int>> adj[1000001];

void dfs(int r, int c) {
    if (vis[r][c]) return;

    vis[r][c] = 1;
    for (auto i : adj[grid[r][c]]) {
        dfs(i.first, i.second);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int m, n, a;  


    cin >> m >> n;
    for (int i = 1; i<=m; i++) {
        for (int j = 1; j<=n; j++) {
            cin >> a;
            grid[i][j] = a;
            adj[i*j].push_back({i,j});
        }
    } 

    dfs(1,1);
    if (vis[m][n]) {
        cout << "yes";
    } else {
           cout << "no"; 
    }
}
