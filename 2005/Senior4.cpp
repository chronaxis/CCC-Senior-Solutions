// This solution AC'd on DMOJ
// THE INPUT MAN I WAS SO DUMB
#include <bits/stdc++.h>
using namespace std;

int n, m, d;
map<string, vector<string>> g;
map<string, int> occur;
string hold[101];
void dfs(string node, int depth) {
    cout << node << " ";
    if (g[node].empty()) return;
    depth++;
    for (auto i : g[node]) {
        dfs(i, depth);
    }
    d = max(d, depth);
}

int main() {
    string z;
    cin >> m;
    for (int i = 0; i<m; i++) {
        cin >> n;
        d = 0;
        g.clear();
        occur.clear();
        for (int j = 1; j<=n; j++) {
            cin >> z;
            hold[j] = z;
        }

        for (int j = n; j>1; j--) {
            if (occur[hold[j-1]] > 0) continue;
            g[hold[j]].push_back(hold[j-1]);
            occur[hold[j]]++;
        }
        
        dfs(hold[n], 0);
        cout << n*10 - d*20 << '\n';
    }
}

/*
1
8
Alfred
Cindy
Alfred
Dennis
Alfred
Home
Betty
Home

1
12
f
d
k
i
k
d
f
e
f
j
f
g
*/