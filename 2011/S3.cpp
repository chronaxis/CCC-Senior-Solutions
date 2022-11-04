#include <bits/stdc++.h>
using namespace std;

int zoom(int x, int y, int mag) {
    if (mag < 1) return 0;
    int quad = pow(5, mag)/5;

    if (x>quad && x<=quad*4 && y<=quad) {
        return 1;
    } 

    if (x>quad*2 && x<=quad*3 && y<=quad*2) {
        return 1;
    }

    if (!(x>quad && x<=quad*4 && y<=quad*2) && !(x>quad*2 && x<=quad*3 && y<=quad*3)) {
        return 0;
    }

    return zoom(x%quad, y%quad, mag-1);
}

int main() {
    int t, m, x, y; 
    cin >> t;
    for (int i = 0; i<t; i++) {
        cin >> m >> x >> y;
        if (zoom(x+1, y+1, m)) {
            cout << "crystal" << "\n";
        } else {
            cout << "empty" << "\n";
        }
    }
}