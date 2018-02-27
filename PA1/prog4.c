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
    N = 230;
    double integrand(double, double, int);
    double f(double);
    N = 1 + N*b*(b-a);
    I = integrand(a, b, N);
    printf("The result is: %lf \n", I);
}

double f(double x)
{
return cos(x*x);
}

double integrand(double a, double b, int N)
{
    double dx;
    double tmp;
    double I;
    int i;
    I = 0.0;
    dx = (b - a)/(N - 1);
    for (i = 0; i < N - 1;i++)
    {
        tmp = dx/6 *(f(a + i*dx) + f(a+(i+1)*dx) + 4 * f(a + (i + 0.5)*dx));
        I = I + tmp;
    }

    return I;

}

