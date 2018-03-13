#include<stdio.h>
int main()
{
    FILE *fp;
    fp = fopen("data.txt","w");
    fprintf(fp,"    t     nR(t)       nF(t)\n");
    printf("\n Enter rho tmax and the step M:");
    double rho, tmax, M;
    scanf("%lf %lf %lf", &rho, &tmax, &M);

}
