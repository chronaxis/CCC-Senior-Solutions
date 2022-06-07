// this solution AC'd on DMOJ
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a = 0;
    cin >> n;
    while (n>0) {
        if (n%5<1) a++;
        n-=4;
        if (n==0) {
            a++;
            break;
        }
    }

    cout << a;
}