// This solution has AC'd on DMOJ
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int tests, n, input, current;
vector<char> results;

int main() {
    cin >> tests;
    for (int i = 0; i<tests; i++) {
        stack<int> mountain, branch;
        current = 1;

        cin >> n;
        for (int k = 0; k<n; k++) {
            cin >> input;
            mountain.push(input);
        }

        while (current<n) {
            if (!mountain.empty()) {
                if (mountain.top() == current) {
                    current++;
                    mountain.pop();
                } else if (mountain.top() != current && branch.empty()) {
                    branch.push(mountain.top());
                    mountain.pop();
                } 
            }

            if (!branch.empty()) {
                if (branch.top() == current) {
                    current++;
                    branch.pop();
                } else if (mountain.empty() && branch.top() != current) {
                    results.push_back('N');
                    break;
                }
            }

            if (!mountain.empty() && !branch.empty()) {
                if (mountain.top() != current && branch.top() != current) {
                    branch.push(mountain.top());
                    mountain.pop();
                }                
            }
        }

        if (current >= n) {
            results.push_back('Y');
        }
    }

    for (char i : results) {
        cout << i << '\n';
    }
}

/*

2
4
2
3
1
4
4
4
1
3
2

*/