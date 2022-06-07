// This solution AC'd on DMOJ
// Man, I should have read the problem more clearly... wasted so much time
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, f1, f2;
    map<int, int> friends;

    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> f1 >> f2;
        friends[f1] = f2;
    }
    
    while (true) {
        cin >> f1 >> f2;
        if (f1 == 0 && f2==0) break;

        int temp = f1;
        int d = 0;
        bool circle = false;
        bool in = false;

        while (temp !=0) {
            temp = friends[temp];
            if (temp == f2) in = true;
            if (temp == f1) {
              circle = true;
              break;
            } 

            if (!in) d++;
        }

        if (circle && in) {
            cout << "Yes" << " " << d << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}