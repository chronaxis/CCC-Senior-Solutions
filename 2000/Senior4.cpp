// This solution AC'd on DMOJ

// Strategy
// Dynamic Programming
// Get all clubs
// Calculate the lowest amount of clubs for each distance from 1 to t
// the amount of clubs needed for a distance x = min(clubs for x, clubs for x - club distance + 1)
// if t has been reached it will be smaller than the max value set

#include <bits/stdc++.h>
using namespace std;

int dp[5281];

int main() {
    int t, c, d;
    vector<int> clubs;

    scanf("%d\n%d", &t, &c);
    for (int i = 0; i<c; i++) {
        scanf("%d", &d);
        clubs.push_back(d);
    }

    dp[0] = 0;
    for (int i = 1; i<=t; i++) {
        dp[i] = 999999999;
        for (auto j : clubs) {
            if (i-j>=0) {
                dp[i] = min(dp[i], dp[i-j]+1);
            }
        }
    }

    if (dp[t]<999999999){
        printf("Roberta wins in %d strokes.", dp[t]);
    } else {
        printf("Roberta acknowledges defeat.");
    }
}
