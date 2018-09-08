#include <stdio.h>
#include<stdlib.h>  //system()

using namespace std;
long long c[105][105];
const int mod = 1000000007;
void init() {  //杨辉三角
    c[0][0] = 1;
    for (int i = 1; i <= 100; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= 100; j++)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
}
int main() {
    int k, a, b, x, y;
    long long ans = 0;
    init();
    scanf_s("%d", &k);
    scanf_s("%d%d%d%d", &a, &x, &b, &y);
    for (int i = 0; i <= x; i++) {
        if (i * a <= k && (k - a * i) % b == 0 && (k - a * i) / b <= y)
            ans = (ans + (c[x][i] * c[y][(k - a * i) / b]) % mod) % mod;
    }
    printf("%lld\n", ans);
    system("pause");
    return 0;
}