#include<math.h>
#include<stdio.h>

int main()
{
    double x0, v0, tmax;
    int M;
    int i = 0;
    FILE *fp;
    fp = fopen("ossillator.dat", "w");
    int j = 0;
    printf("\nEnter the x0, v0, tmax and steps M: ");
    fprintf(fp,"     t       numeric x    exact x     numeric v     exact v  \n");
    scanf("%lf %lf %lf %d", &x0, &v0, &tmax, &M);
    double dt, halfdt, vt[2], xt[2];
    double ve[2], xe[2],globalerror;
    globalerror = 0;
    vt[0] = v0;
    xt[0] = x0;
    dt = tmax / M;
    halfdt = dt / 2;
    for(i=0;i< M;i++)
    {
        ve[0] = -x0*sin(dt*i) + v0*cos(dt*i);
        xe[0] = x0*cos(dt*i) + v0*sin(dt*i);
        vt[1] =vt[0] - halfdt*xt[0];
        xt[1] =xt[0] + halfdt*vt[0];
        xe[1] = x0*cos(dt*i+halfdt) + v0*sin(dt*i+halfdt);
        ve[1] = -x0*sin(dt*i+halfdt) + v0*cos(dt*i+halfdt);
        for(j=0;j<2;j++)
        {
            //fprintf(fp,"\n for t = %lf, the numric xt = %lf, vt = %lf", dt*i+halfdt*j, xt[j], vt[j]);
            fprintf(fp,"%10.8lf  %10.8lf  %10.8lf  %10.8lf  %10.8lf\n", dt*i+halfdt*j, xt[j], xe[j], vt[j], ve[j]);
            //fprintf(fp,"\n for t = %lf, the exact xt = %lf, vt = %lf\n", dt*i+halfdt*j, xe[j], ve[j]);
            globalerror += (xt[j] - xe[j])*(xt[j]-xe[j])*halfdt;
        }
        vt[0] += -dt*xt[1];
        xt[0] +=  dt*vt[1];
    }
    xe[0] = x0*cos(tmax) + v0*sin(tmax);
    ve[0] = -x0*sin(tmax) + v0*cos(tmax);
    globalerror += (xt[0]-xe[0])*(xt[0]-xe[0])*halfdt;
    globalerror = pow(globalerror/tmax,0.5);

    //fprintf(fp,"\n for t = %lf, the numric xt = %lf, vt = %lf", dt*i, xt[0], vt[0]);
    fprintf(fp,"%10.8lf  %10.8lf  %10.8lf  %10.8lf  %10.8lf\n", dt*i+halfdt*j, xt[0], xe[0], vt[0], ve[0]);
    //fprintf(fp,"\n for t = %lf, the exact xt = %lf, vt = %lf\n", dt*i, xe[0], ve[0]);
    fprintf(fp,"\n The globalerror is %le\n",globalerror);
    fclose(fp);
    return 0;
}
