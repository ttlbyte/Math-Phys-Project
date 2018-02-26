#include<stdio.h>

int main()
{
    double I, a, b, tmp;
    tmp = 0.0;
    I = 0.0;
    double dx;
    int N;
    int i;
    printf("Computing the integration of f(x) = 1 + x^2 + x^3:\n");
    printf("Enter the lower and upper limit and number of points: ");
    scanf("%lf %lf %d", &a, &b, &N);
    dx = (b - a)/(N - 1);
    double func(double);
    for(i = 1; i < N-1; i++){
        tmp = dx*func(a + i * dx);
        I = I + tmp;
    }
    I = I + 0.5*dx*(func(a) + func(b));
    printf("The result is: %lf \n", I);
}

double func(double x)
{
    return 1 + x*x + x*x*x;
}
