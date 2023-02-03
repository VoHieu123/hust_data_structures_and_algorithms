#include<stdio.h>
#include<string.h>

int fibonacci (int val)
{
    if(val<0)
        return -1;
    else if(val == 0 || val == 1)
        return val;
    else
        return fibonacci(val - 1)+ fibonacci(val - 2);

}
int main()
{
    float n;
    int i;
    printf("Nhap n= ");
    scanf("%f",&n);

    for(i = 0; i <= n; i++)
        printf("%d %f\n", i, fibonacci(i));
    return 0;
}
