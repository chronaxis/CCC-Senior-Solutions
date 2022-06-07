// This solution AC'd on DMOJ (kinda slow though, 0.83s with 1 second limit :/)
#include <iostream>
#include <vector>
using namespace std;

const long long max_size = 10000001;
vector<long long> isPrime(max_size, true);
vector<long long> primes;
vector<long long> SPF(max_size);
vector<int> a;
vector<int> b;

void getPrimes(int n) {
    isPrime[0] = isPrime[1] = false;

    for (long long i = 0; i<n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);    
            SPF[i] = i;
        }

        for (long long j = 0; j<primes.size() && i*primes[j]<n && primes[j]<=SPF[i]; j++) {
            isPrime[i*primes[j]] = false;
            SPF[i*primes[j]] = primes[j];
        }
    }
}

void getPair(int n) {
    for (int i = 2; i<=n; i++) {
        if (isPrime[i]) {
            if (isPrime[(2*n-i)]) {
                a.push_back(i);
                b.push_back((2*n-i));
                return;
            }
        }
    }
}

int t, num;
int main() {
    getPrimes(2000000);

    cin >> t;
    for (int i = 0; i<t; i++) {
        cin >> num;
        getPair(num);
    }

    for (int i = 0; i<a.size(); i++) {
        cout << a[i] << " " << b[i] << '\n';
    }
}