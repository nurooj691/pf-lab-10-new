#include <stdio.h>
int memo[1000];
int maxPieces(int n) {
    if (n == 0) {
        return 0;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    int cut1 = (n >= 1) ? maxPieces(n - 1) : -1;
    int cut2 = (n >= 2) ? maxPieces(n - 2) : -1;
    int cut3 = (n >= 3) ? maxPieces(n - 3) : -1;
    int maxCut = (cut1 > cut2 ? cut1 : cut2);
    maxCut = (maxCut > cut3 ? maxCut : cut3);
    memo[n] = maxCut + 1;
    return memo[n];
}
int main() {
    int n;
    printf("Enter the length of the rope: ");
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    int result = maxPieces(n);
    printf("The maximum number of pieces the rope can be cut into is: %d\n", result);

    return 0;
}

