#include<math.h>
#include<stdio.h>

int main()
{
    double x0, v0, tmax;
    int M;
    int i = 0;
    printf("\nEnter the x0, v0, tmax and steps M: ");
    scanf("%lf %lf %lf %d", &x0, &v0, &tmax, &M);
    double dt, halfdt, vt, xt,halfvt,halfxt;
    double ve, xe,globalerror;
    globalerror = 0;
    vt = v0;
    xt = x0;
    dt = tmax / (M-1);
    halfdt = dt / 2;
    for(;i< M-1;i++)
    {
        printf("\n for t = %lf, the numric xt = %lf, vt = %lf", dt*i, xt, vt);
        ve = -x0*sin(dt*i) + v0*cos(dt*i);
        xe = x0*cos(dt*i) + v0*sin(dt*i);
        printf("\n for t = %lf, the exact xt = %lf, vt = %lf\n", dt*i, xe, ve);
        globalerror += halfdt*(xt - xe)*(xt - xe);
        halfvt =vt - halfdt*xt;
        halfxt =xt + halfdt*vt;
        printf("\n for t = %lf, the numric xt = %lf, vt = %lf", dt*i+halfdt, xt, vt);
        xe = x0*cos(dt*i+halfdt) + v0*sin(dt*i+halfdt);
        ve = -x0*sin(dt*i+halfdt) + v0*cos(dt*i+halfdt);
        globalerror += halfdt*(halfxt - xe)*(halfxt - xe);
        printf("\n for t = %lf, the exact xt = %lf, vt = %lf\n", dt*i+halfdt, xe, ve);
        vt += -dt*halfxt;
        xt+= dt*halfvt;
    }
    xe = x0*cos(tmax) + v0*sin(tmax);
    ve = -x0*sin(tmax) + v0*cos(tmax);
    globalerror += halfdt*(xt - xe)*(xt - xe);
    globalerror = pow(globalerror/2,0.5);

    printf("\n for t = %lf, the numric xt = %lf, vt = %lf", dt*i, xt, vt);
    printf("\n for t = %lf, the exact xt = %lf, vt = %lf\n", dt*i, xe, ve);
    printf("\n The globalerror is %lf\n",globalerror);
    return 0;
}
