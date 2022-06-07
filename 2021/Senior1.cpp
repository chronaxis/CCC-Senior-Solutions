// This code has AC'd on DMOJ
#include <iostream>
#include <vector>
using namespace std;

int n;
double area;
int main() {
    cin >> n;
    vector<double> heights(n+2);
    vector<double> widths(n+1);
    for (int i = 1; i<=n+1; i++) {
        cin >> heights[i];
    }

    for (int i = 1; i<=n; i++) {
        cin >> widths[i];
    }

    for (int i = 1; i<=n; i++) {
        area += (abs(heights[i] - heights[i+1]) * widths[i]/2);
        if (heights[i] < heights[i+1]) {
            area += heights[i] * widths[i];
        } else {
            area += heights[i+1] * widths[i];
        }
    }

    cout << fixed << area << "\n";
    return 0;
}  

/*
3
2 3 6 2
4 1 1

4
6 4 9 7 3
5 2 5 1
*/