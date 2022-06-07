// this solution AC'd on DMOJ
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, g, totalV = 0;
    string p1, p2, p3;
    map<string, vector<string>> together, apart;

    cin >> x;
    for (int i = 0; i<x; i++) {
        cin >> p1 >> p2;
        together[p1].push_back(p2);
    }

    cin >> y;
    for (int i = 0; i<y; i++) {
        cin >> p1 >> p2;
        apart[p1].push_back(p2);
    }

    totalV = x;
    cin >> g;
    for (int i = 0; i<g; i++) {
        cin >> p1 >> p2 >> p3;
        if (together.count(p1)) {
            for (int k = 0; k<together[p1].size(); k++) {
                if (together[p1][k] == p2 || together[p1][k] == p3) {
                    totalV--;
                } 
            }
        }

        if (together.count(p2)) {
            for (int k = 0; k<together[p2].size(); k++) {
                if (together[p2][k] == p1 || together[p2][k] == p3) {
                    totalV--;
                } 
            }
        }

        if (together.count(p3)) {
            for (int k = 0; k<together[p3].size(); k++) {
                if (together[p3][k] == p1 || together[p3][k] == p2) {
                    totalV--;
                } 
            }
        }
        if (apart.count(p1)) {
            for (int k = 0; k<apart[p1].size(); k++) {
                if (apart[p1][k] == p2 || apart[p1][k] == p3) {
                    totalV++;
                } 
            }
        }

        if (apart.count(p2)) {
            for (int k = 0; k<apart[p2].size(); k++) {
                if (apart[p2][k] == p1 || apart[p2][k] == p3) {
                    totalV++;
                } 
            }
        }

        if (apart.count(p3)) {
            for (int k = 0; k<apart[p3].size(); k++) {
                if (apart[p3][k] == p1 || apart[p3][k] == p2) {
                    totalV++;
                } 
            }
        }
    }

    cout << totalV;
}