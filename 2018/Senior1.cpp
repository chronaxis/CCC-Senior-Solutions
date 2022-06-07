// This solution AC'd on DMOJ
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double v, smallest = INFINITY;
    vector<double> villages;
    cin >> n;

    for (int i = 0; i<n; i++) {
        cin >> v;
        villages.push_back(v);
    }

    sort(villages.begin(), villages.end());

    for (int i = 1; i<n-1; i++) {  
        double left = (villages[i]-villages[i-1])/2;
        double right = (villages[i+1]-villages[i])/2;
        smallest = min(left+right, smallest);
    }

    printf("%.1f", smallest);
}
