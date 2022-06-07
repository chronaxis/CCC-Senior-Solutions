// This solution AC'd on DMOJ
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x = 1, y = 1;
    map<int, vector<int>> slides;
    
    cin >> n;
    while (x>0 && y>0) {
        cin >> x >> y;
        slides[x].push_back(y);
    } 

    map<int, int> ways;
    ways[1] = 1;
    for (int i = 0; i<n; i++) {
        for (auto s : slides[i]) {
            ways[s] += ways[i];
        }
    }

    cout << ways[n];
}