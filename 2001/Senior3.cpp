// This solution AC'd on DMOJ
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

map<char, vector<char>> graph;

bool BFS(char ignoreV, char ignoreE) {
    map<char, bool> visited;
    queue<int> adjacent;
    visited['A'] = true;
    adjacent.push('A');

    while (!adjacent.empty()) {
        char vertex = adjacent.front();
        adjacent.pop();

        vector<char> neighbours = graph[vertex];
        for (char next : neighbours) {
            if (!visited[next]) {
                if (vertex == ignoreV && next == ignoreE) continue;
                if (vertex == ignoreE && next == ignoreV) continue;

                adjacent.push(next);
                visited[next] = true;
            }
        }
    }

    if (visited['B']) {
        return true;
    }

    return false;
}

int main() {
    int count = 0;
    char v, e;
    vector<vector<char>> exclude;

    while (true) {
        cin >> v >> e;
        if (v == '*') {
            break;
        }

        graph[v].push_back(e);
        graph[e].push_back(v);
        exclude.push_back({v, e});
    }

    exclude.push_back({'0','0'});
    int j = exclude.size()-1;
    for (int i = 0; i<j; i++) {
        exclude.pop_back();

        if (!BFS(exclude.back()[0], exclude.back()[1])) {
            cout << exclude.back()[0] << exclude.back()[1] << '\n';    
            count++;  
        }
    }

    cout << "There are " << count << " disconnecting roads." << "\n";
}