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
    int constrian();
    N = constrian();
/*    dx = (b - a)/(N - 1);
    for(i = 1; i < N; i++){
        tmp = dx*cos(pow((a + i * dx),2.0));
        I = I + tmp;
    }
    I = I + 0.5*dx*(cos(a*a) + cos(b*b));
    */
    double integral(double, double, int);
    N = N * b;
    I = integral(a, b, N);
    printf("The result is: %lf \n", I);
}

int constrian()
{
    int i = 10;
    double tmp;
    for(;;i++)
    {
        tmp = integral(0.0,1.0,i) - 0.904524;
        tmp = fabs(tmp);
        if(tmp<0.0000005) break;
    }
    return i;
}

double integral(double a, double b, int N)
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

