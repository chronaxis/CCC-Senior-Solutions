// This solution AC'd on DMOJ

// Strategy
// Simple Math
// 1 will always be a divisor, so start the sum at 1
// Find all divisors from 2 to the square root (rounded down) of n with modulus
// If the n%i == 0 then the number is divisible by i
// We end at the square root beacuse we can find the other divisor by dividing n by i
// add the divisors to the sum
// Make sure not to add the square root twice (if there is one)
// Then at the end print out answer according to the sum

#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc, n;
    cin >> tc;
    for (int t = 0; t<tc; t++) {
        cin >> n;
        int sum = 1;
        for (int i = 2; i<=(int)sqrt(n); i++) {
            if (n%i<1) {
                if (n/i != i) {
                    sum += n/i + i;
                } else {
                    sum += i;
                }
            }
        }

        if (sum<n) {
            cout << n << " is a deficient number.\n";
        } else if (sum==n) {
            cout << n << " is a perfect number.\n";
        } else {
            cout << n << " is an abundant number.\n";
        }
    }
}