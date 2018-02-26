#include<stdio.h>
#include<math.h>

int main()
{
    double I, a, b, tmp;
    tmp = 0.0;
    I = 0.0;
    double dx;
    int N;
    int i;
    printf("Computing the integration of f(x) = cos(x^2)\n");
    printf("Enter the lower and upper limit and number of points: ");
    scanf("%lf %lf %d", &a, &b, &N);
    dx = (b - a)/(N - 1);
    for(i = 1; i < N-1; i++){
        tmp = dx*cos(pow((a + i * dx),2.0));
        I = I + tmp;
    }
    I = I + 0.5*dx*(cos(a*a) + cos(b*b));
    printf("The result is: %lf \n", I);
}

