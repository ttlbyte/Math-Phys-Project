#include<math.h>
#include<stdio.h>

int main()
{
    double x0, v0, tmax;
    int M;
    int i = 0;
    int j = 0;
    printf("\nEnter the x0, v0, tmax and steps M: ");
    scanf("%lf %lf %lf %d", &x0, &v0, &tmax, &M);
    double dt, halfdt, vt[2], xt[2];
    double ve[2], xe[2],globalerror;
    globalerror = 0;
    vt[0] = v0;
    xt[0] = x0;
    dt = tmax / M;
    halfdt = dt / 2;
    for(;i< M;i++)
    {
        ve[0] = -x0*sin(dt*i) + v0*cos(dt*i);
        xe[0] = x0*cos(dt*i) + v0*sin(dt*i);
        vt[1] =vt[0] - halfdt*xt[0];
        xt[1] =xt[0] + halfdt*vt[0];
        xe[1] = x0*cos(dt*i+halfdt) + v0*sin(dt*i+halfdt);
        ve[1] = -x0*sin(dt*i+halfdt) + v0*cos(dt*i+halfdt);
        for(j=0;j<2;j++)
        {
            printf("\n for t = %lf, the numric xt = %lf, vt = %lf", dt*i+halfdt*j, xt[j], vt[j]);
            printf("\n for t = %lf, the exact xt = %lf, vt = %lf\n", dt*i+halfdt*j, xe[j], ve[j]);
            globalerror += (xt[j] - xe[j])*(xt[j]-xe[j]);
        }
        vt[0] += -dt*xt[1];
        xt[0] +=  dt*vt[1];
    }
    xe[0] = x0*cos(tmax) + v0*sin(tmax);
    ve[0] = -x0*sin(tmax) + v0*cos(tmax);
    globalerror += (xt[0]-xe[0])*(xt[0]-xe[0]);
    globalerror = pow(globalerror/tmax,0.5);

    printf("\n for t = %lf, the numric xt = %lf, vt = %lf", dt*i, xt[0], vt[0]);
    printf("\n for t = %lf, the exact xt = %lf, vt = %lf\n", dt*i, xe[0], ve[0]);
    printf("\n The globalerror is %lf\n",globalerror);
    return 0;
}
