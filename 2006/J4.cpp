// this solution AC'd on DMOJ
#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> toDO;
map<int, int> state;
stack<int> order;
bool cycle = false;

// topological sort
void getOrder(int node, stack<int> path) {
    if (state[node] == 2) return;
    if (state[node] == 1) {
        cycle = true;
        return;
    }
    
    path.push(node);
    if (toDO[node].empty()) {
        while (!path.empty()) {
            state[path.top()] = 2;
            order.push(path.top());                                                                                                                                                        
            path.pop();
        }
        return;
    }

    state[node] = 1;

    for (int i = 0; i<toDO[node].size(); i++) {
        if (state[toDO[node][i]] < 2) {
            getOrder(toDO[node][i], path);
            return;
        }
    }
    
    while (!path.empty()) {
        state[path.top()] = 2;
        order.push(path.top());                                                                                                                                                        
        path.pop();
    }
}

int main() {
    // while we are using to-do-before as the keys, since we are using stack & starting from 7 the order is reversed anyway 
    int n1, n2;
    toDO[1].push_back(7);
    toDO[1].push_back(4);
    toDO[2].push_back(1);
    toDO[3].push_back(4);
    toDO[3].push_back(5);

    while (true) {
        cin >> n1 >> n2;
        if (n1 == 0 && n2 == 0) break;
        toDO[n1].push_back(n2);
    }

    stack<int> temp;
    for (int i = 7; i >=1; i--) {
        getOrder(i, temp);
    }

    if (cycle) {
        cout << "Cannot complete these tasks. Going to bed.";
    } else {
        while (!order.empty()) {
            cout << order.top() << " ";
            order.pop();
        }
    }
}
