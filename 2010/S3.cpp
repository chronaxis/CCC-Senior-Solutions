#include <bits/stdc++.h>
using namespace std;

vector<int> house;
int check(int hoses, int length) {
    for (int i = 0; i < house.size(); i++) {
        int current = house[i];
        int h = hoses;
        for (int k = i + 1; k != i; k++) {
            if (k >= house.size()) {
                k = -1;
                continue;
            }

            int d = house[k]-current;
            if (current > house[k]) {
                d = (house[k]+1000000)-current;
            }

            if (d > length) {
                current = house[k];
                h -= 1;
            }
        }

        if (h >= 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    int h, k, low = 0, high = 1000000, d, l;
    cin >> h;

    for (int i = 0; i < h; i++) {
        cin >> d;
        house.push_back(d);
    }
    sort(house.begin(), house.end());
    cin >> k;

    while (low <= high) {
        int mid = (low + high)/2;

        if (check(k-1, mid*2)) {
            l = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << l;
}

/*
4
0
67000
68000
77000
2

3
5000
0
995000
1

9
10
0
1000
2000
3400
545
134
4500
20000
4
*/