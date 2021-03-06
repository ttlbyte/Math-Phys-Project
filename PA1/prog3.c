#include<stdio.h>
#include<math.h>

int main()
{
    double I, a, b;
    I = 0.0;
    int N;
    printf("Computing the integration of f(x) = cos(x^2)\n");
    printf("Enter the lower and upper limit : ");
    scanf("%lf %lf", &a, &b);
    N = 2333;
    double integrand(double, double, int);
    N = 1 + 800*b*(b-a);
    I = integrand(a, b, N);
    printf("The result is: %lf \n", I);
}


double integrand(double a, double b, int N)
{
    double dx;
    double tmp;
    double I;
    int i;
    dx = (b - a)/(N - 1);
    for(i = 1; i < N-1; i++){
        tmp = dx*cos(pow((a + i * dx),2.0));
        I = I + tmp;
    }
    I = I + 0.5*dx*(cos(a*a) + cos(b*b));
    return I;

}

