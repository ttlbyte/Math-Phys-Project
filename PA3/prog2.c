#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int
main()
{
	double *p, *l, *d, *u, *r, x, dx;
    double lambda_k, lambda_p;
//	double exact(double, double, double);

	int n, i;
	int td_solve(double*, double*, double*, double*, double*, int);
	FILE *fp;

	printf("Enter lambda_p lambda_k:");
	scanf("%le %le",&lambda_p, &lambda_k);

	printf("Enter N: ");
	scanf("%d", &n);

	p = (double*)malloc(n*sizeof(double));
	l = (double*)malloc(n*sizeof(double));
	d = (double*)malloc(n*sizeof(double));
	u = (double*)malloc(n*sizeof(double));
	r = (double*)malloc(n*sizeof(double));

	dx = 1.0/(n-1);


	for (i = 0; i <= n-1; i++) {

		x =-0.5 + i*dx;
        r[i] = 0;
        l[i] = pow(2.0*x/dx,2.0)-4.0*x/dx;
        d[i] = -8.0*pow(x/dx,2.0)-1.0/pow(lambda_k,2);
        u[i] = pow(2.0*x/dx,2.0)+4.0*x/dx;


	}
    u[0] += l[0];
    d[0] -= 2.0*dx*l[0]/lambda_p;
    r[0] -= l[0]*2.0*dx/lambda_p;
    l[n-1] += u[n-1];
    d[n-1] -= 2.0*dx*u[n-1]/lambda_p;
    r[n-1] -= 2.0*u[n-1]*dx/lambda_p;

   /* for (i=0; i<=n-1;i++){
    printf("l %le ,d %le ,u %le ,r %le\n",l[i], d[i],u[i],r[i]);
    }
*/

	if (td_solve(l, d, u, r, p, n) != 0) {
		fprintf(stderr, "td_solve() failed!\n");
		exit(2);
	}

	fp = fopen("prog2.dat", "w");

	for (i = 0; i < n; i++) {

		x = -0.5 + i*dx;

		fprintf(fp, "%le %le\n", x, p[i]);
	}

	fclose(fp);
	exit(0);
}

/*double
exact(double x, double phi, double L)
{
	return phi*cosh(x)/(phi*cosh(L/2)+sinh(L/2));
}

*/


int
td_solve(double *l, double *d, double *u, double *r, double *y, int n)
{
    int i;

/*
 * do Gaussian elimination:
 */
    for (i = 1; i < n; i++) {

        if (d[i-1] == 0.0) return 1;

        d[i] -= l[i]*u[i-1]/d[i-1];
        r[i] -= l[i]*r[i-1]/d[i-1];

    }

/*
 * do back-substitution:
 */
    if (d[n-1] == 0.0) return 2;

    y[n-1] = r[n-1]/d[n-1];

    for (i = n-2; i >= 0; i--) {

        if(d[i] == 0.0) return 2;

        y[i] = (r[i] - u[i]*y[i+1])/d[i];
    }

    return 0;
}
