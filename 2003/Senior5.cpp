// this solution AC'd on DMOJ
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> cities[10001];
int isDc[10001], vis[10001];

int dcount;
void dfs(int cc, int w) {
    if (vis[cc]) return;
    vis[cc] = 1;
    if (isDc[cc]) dcount++;

    for (auto i : cities[cc]) {
        if (i.second >= w) dfs(i.first, w);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int c, r, d, x, y, w, dc, mw = 0;
    vector<int> weights;
    map<int, bool> added;
    cin >> c >> r >> d;

    for (int i = 0; i < r; i++) {
        cin >> x >> y >> w;
        cities[x].push_back({y,w});
        cities[y].push_back({x,w});

        if (added[w]) continue;
        added[w] = true;
        weights.push_back(w);
    }

    sort(weights.begin(), weights.end());

    for (int i = 0; i<d; i++) {
        cin >> dc;
        isDc[dc] = 1;
    }

    int a = 0, b = weights.size()-1;
    while (a<=b) {
        int k = (a+b)/2;
        dcount = 0;
        memset(vis, 0, sizeof(vis));

        dfs(1, weights[k]);

        if (dcount == d) {
            mw = max(weights[k], mw);
            a = k+1;
        } else {
            b = k-1;
        }
    }

    cout << mw;
}

/*
5 7 3
1 2 20
1 3 50
1 4 70
1 5 90
2 3 30
3 4 40
4 5 60
2
4
5
*/