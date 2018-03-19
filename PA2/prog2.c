#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;
    printf("\n Enter tmax and the step M:");
    double rho, tmax, M;
    scanf("%lf %lf", &tmax, &M);
    int i, l;
    double dt, halfdt;
    dt = tmax / M;
    halfdt = dt / 2.0;
    double j, k;
    double n[2]; //n[0] -- rabbit, n[1] -- fox
    double n1[2]; //for half dt
    for(i=1; i<5; i++)
    {
        rho = 0.2 * i;
        for(j=0.8;j<1.3;j=j+0.4)
        {
            n[0] = j;
            for(k=0.8;k<1.3;k=k+0.4)
            {
                n[1] = k;
                char filename[100];
                sprintf(filename,"rho_%.1lf_rabbit_%.1lf_fox_%.1lf.dat", rho, j, k);
                fp = fopen(filename,"w");
                fprintf(fp,"   t          nR        nF\n");
                fprintf(fp,"%8.6lf  %8.6lf  %8.6lf\n",0.0,n[0],n[1]);
                for(l=0; l<M; l++)
                {
                    n1[0] = n[0] + halfdt * n[0] * (1 - n[1]);
                    n1[1] = n[1] + halfdt * rho * n[1] * (n[0] - 1);
                    n[0] += dt * n1[0] * (1 - n1[1]);
                    n[1] += dt * rho * n1[1] * (n1[0] - 1);
                    fprintf(fp,"%8.6lf  %8.6lf  %8.6lf\n",l*dt+halfdt,n1[0],n1[1]);
                    fprintf(fp,"%8.6lf  %8.6lf  %8.6lf\n",(l+1)*dt,n[0],n[1]);
                }
                fclose(fp);
            }
        }
    }
    return 0;
}
