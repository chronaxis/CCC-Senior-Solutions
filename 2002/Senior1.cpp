// This solution AC'd on DMOJ
#include <bits/stdc++.h>
using namespace std;

int main() {
    int pink, green, red, orange, amount, minimum, count = 0;
    scanf("%d\n%d\n%d\n%d\n%d", &pink, &green, &red, &orange, &amount);
    minimum = amount;

    for (int p = 0; p<=amount/pink; p++) {
        for (int g = 0; g<=amount/green; g++) {
            for (int r = 0; r<=amount/red; r++) {
                for (int o = 0; o<=amount/orange; o++) {
                    if (p*pink + g*green + r*red + o*orange == amount) {
                        printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n", p, g, r, o);
                        count++;
                        minimum = min(p+g+r+o, minimum);
                    }
                }
            }
        }
    }

    printf("Total combinations is %d.\n", count);
    printf("Minimum number of tickets to print is %d.\n", minimum);
}