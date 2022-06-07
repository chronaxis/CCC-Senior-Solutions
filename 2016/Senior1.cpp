// this solution AC'd on DMOJ
#include <bits/stdc++.h>
using namespace std;

map<char, int> aCount;
map<char, int> bCount;

int main() {
    string a, b;
    cin >> a >> b;

    for (int i = 0; i<a.size(); i++) {
        aCount[a[i]]++;
    }

    for (int i = 0; i<b.size(); i++) {
        bCount[b[i]]++;
    }

    int starCount = bCount['*'];
    for (int i = 0; i<a.size(); i++) {
        if (bCount[a[i]]>aCount[a[i]]) {
            cout << "N";
            return 0;
        }

        if (aCount[a[i]]>bCount[a[i]]) {
            starCount -= aCount[a[i]] - bCount[a[i]];
            aCount[a[i]] = 0;
            bCount[a[i]] = 0;
        }

        if (starCount<0) {
            cout << "N";
            return 0;
        }
    }

    cout << 'A';
}