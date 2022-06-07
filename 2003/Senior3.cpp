// this solution AC'd on DMOJ
#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> floorplan;
map<pair<int, int>, bool> visited;
vector<int> sizes;

void exploreRoom(int row, int col) {
    if (visited[{row, col}] || floorplan[row][col] == 'I') {
        return;
    }

    int h = floorplan.size();
    int w = floorplan[0].size();

    int s = 0;
    queue<pair<int, int>> adjacent;
    adjacent.push({row, col});

    while (!adjacent.empty()) {
        int x = adjacent.front().first;
        int y = adjacent.front().second;
        adjacent.pop();

        if (x < 0 || y < 0 || x >= h || y >= w || visited[{x, y}]) continue;
        if (floorplan[x][y] == 'I') continue;

        s++;
        adjacent.push({x, y-1});
        adjacent.push({x, y+1});
        adjacent.push({x-1, y});
        adjacent.push({x+1, y});  
        
        visited[{x, y}] = true;
    }

    sizes.push_back(s);
}

int main() {
    int m, r, c, rooms = 0;
    char t;
    vector<char> temp;
    cin >> m >> r >> c;
    for (int i = 0; i<r; i++) {
        for (int k = 0; k<c; k++) {
            cin >> t;
            temp.push_back(t);
        }
        floorplan.push_back(temp);
        temp.clear();
    }
    
    for (int i = 0; i<r; i++) {
        for (int k = 0; k<c; k++) {
            exploreRoom(i, k);
        }
    }

    sort(sizes.begin(), sizes.end());
    int s = sizes.size();

    for (int i = 0; i<s; i++) {
        if (m - sizes[s-(i+1)]>=0) {
            rooms++;
            m-= sizes[s-(i+1)];
        } else break;
    }

    if (rooms!=1) {
        cout << rooms << " rooms, " << m << " square metre(s) left over";
    } else {
        cout << rooms << " room, " << m << " square metre(s) left over";
    }
}