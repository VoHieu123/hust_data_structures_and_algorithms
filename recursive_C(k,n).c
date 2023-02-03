#include <stdio.h>
#include <math.h>

int C(int k, int n)
{
    if (k == 0 || k == n) return 1;
    return C(k, n-1) + C(k-1, n-1);
}

double process(int p, int k, int n)
{
    double sum = 0;
    for (; k <= n; k++){
        sum += pow(p, k)*pow(1 - p, n - k)*C(k, n);
    }
    return sum;
}

void main()
{
    double k, n;
    double p;

    scanf("%lf %lf %lf", &k, &n, &p);
    printf("%lf", process(p, k, n));
}