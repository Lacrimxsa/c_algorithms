#include <stdio.h>

// Euclides algorithm is based on the fact that 
// if x is grater than y 
// then the greatest common divisor of x and y 
// is the same as the greatest common divisor of y and x - y.

int gcd(int u, int v) 
 {
    int t;
    while (u > 0)
    {
        if (v > u)
            { t=u; u=v; v=t; }
        u = u-v;
    }
    return v;
 }
 
int main(void)

 {
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF)
        if (x>0 && y>0)
            printf("%d %d %d\n", x, y, gcd(x,y));
 }
