#include <stdio.h>
#include <stdint.h>

unsigned int mask = 0; 
int main () {
    int arr[] = {2, 5, 6, 8, 9, 10};
    int k = 15;
    for (int i = 0; i < 6; i++) {
        mask |= (1 << arr[i]);
        for (int j = i + 1; j < 6; j++) {
            if (mask & (1 << (k - arr[j]))) {
                printf("(%d, %d), ", arr[i], arr[j]);
            }
        }
        mask = 0;
    }
}