#include <stdio.h>

int main() {
    int num, sum = 0;

    while (1) {
        printf("Input: ");
        scanf("%d", &num);
        
        if (num == 0) {
            break;  
        }

        sum += num;  
    }

    printf("Result: %d\n", sum);

    return 0;
}
