// This solution AC'd on DMOJ
#include <stdio.h>
using namespace std;

int main() {
    int numerator, denominator, mixed = 0, highest = 1;
    scanf("%d\n%d", &numerator, &denominator);

    if (numerator>denominator) {
        mixed = numerator/denominator;
        printf("%d", mixed);
    }

    numerator = numerator - (mixed*denominator);

    if (numerator == 0) {
        if (mixed == 0){
            printf("0");
        }
        printf("\n");
        return 0;   
    } else if (mixed!=0) {
        printf(" ");
    }

    for (int i = 2; i<denominator; i++) {
        if (numerator%i==0 && denominator%i == 0) {
            highest = i;
        }
    }

    numerator = numerator/highest;
    denominator = denominator/highest;

    printf("%d/%d\n", numerator, denominator);
}