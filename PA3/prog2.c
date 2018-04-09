#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int
main()
{
	double *p, *l, *d, *u, *r, x, dx, xL, xR, pL, pR, phi, L;
    double D_zero;
    double k;
//	double exact(double, double, double);

	int n, i;
	int td_solve(double*, double*, double*, double*, double*, int);
	FILE *fp;

	printf("Enter D_zero,k, L, p: ");
	scanf("%le %le %le %le",&D_zero, &k, &L, &pL);

    xL=-L/2;
    xR=L/2;
	printf("Enter N: ");
	scanf("%d", &n);
    pL = D_zero/(pL*L);

	p = (double*)malloc(n*sizeof(double));
	l = (double*)malloc(n*sizeof(double));
	d = (double*)malloc(n*sizeof(double));
	u = (double*)malloc(n*sizeof(double));
	r = (double*)malloc(n*sizeof(double));

	dx = L/(n-1);

	for (i = 0; i <= n-1; i++) {

		x =-L/2 + i*dx;
        r[i] = 0;
        l[i] = 4*(x/dx)*(x/dx) - 4*x/dx;
        d[i] = -8*(x/dx)*(x/dx) -k*L*L/D_zero;
        u[i] = 4*(x/dx)*(x/dx) + 4*x/dx;

	}
    u[0] += l[0];
    d[0] -= -2*dx*l[0]/pL;
    r[0] = -l[0]*2*dx/pL;
    l[n-1] += u[n-1];
    d[n-1] -= 2*dx*u[n-1]/pL;
    r[n-1] = -u[n-1]*2*dx/pL;

    for (i=0; i<=n-1;i++){
    printf("l %le ,d %le ,u %le ,r %le\n",l[i], d[i],u[i],r[i]);
    }


	if (td_solve(l, d, u, r, p, n) != 0) {
		fprintf(stderr, "td_solve() failed!\n");
		exit(2);
	}

	fp = fopen("2pt.out", "w");

	for (i = 0; i < n; i++) {

		x = -L/2 + i*dx;

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
