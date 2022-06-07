// This solution AC'd on DMOJ
#include <bits/stdc++.h>
using namespace std;

int main() {
    long a, b, n, d, l = 14;
    vector<long> m = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    cin >> a >> b >> n;
    for (int i = 0; i<n; i++) {
        cin >> d;
        m.push_back(d);
    }

    sort(m.begin(), m.end());

    l+=n;
    map<long, long> ways;
    ways[0] = 1; 
    for (long i = 0; i<l; i++) {
        for (long j = i+1; j<l; j++) {
            if (m[j]-m[i]<=b && m[j]-m[i]>=a) {
                ways[j]+=ways[i];
            }
        }
    }

    cout << ways[l-1] << "\n";
}
