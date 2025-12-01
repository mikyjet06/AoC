//
// Created by mikyjet on 12/1/25.
//

#include <stdio.h>
#include <math.h>

int main() {
    char command;
    long long count = 0;
    long long move;
    long long tmp;
    long long lock = 50;
    while (scanf(" %c%lld", &command, &move) != EOF) {
        if (command == 'R') {
            lock += move;
            if (lock >= 100) {
                count += (lock - 1) / 100;
            }
            lock %= 100;
        } else if (command == 'L') {
            lock -= move;
            if (lock < 0) {
                count += (-lock - 1) / 100;
                if (lock + move != 0) {
                    count++;
                }
            }
            lock %= 100;
            if (lock < 0) {
                lock += 100;
            }
        }
        if (lock == 0) {
            count++;
        }
        printf("%lld\n", lock);
    }
    printf("%lld\n", count);
    return 0;
}