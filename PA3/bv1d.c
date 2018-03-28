#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int
main()
{
	double *p, rho(double), *l, *d, *u, *r, x, dx, xL, xR, pL, pR;
	double exact(double);
	int n, i;
	int td_solve(double*, double*, double*, double*, double*, int);
	FILE *fp;

	printf("Enter xL, pL, xR, pR: ");
	scanf("%le %le %le %le", &xL, &pL, &xR, &pR);

	printf("Enter N: ");
	scanf("%d", &n);

	p = (double*)malloc(n*sizeof(double));
	l = (double*)malloc(n*sizeof(double));
	d = (double*)malloc(n*sizeof(double));
	u = (double*)malloc(n*sizeof(double));
	r = (double*)malloc(n*sizeof(double));

	dx = (xR-xL)/(n-1);

	for (i = 1; i <= n-2; i++) {

		x = xL + i*dx;

		r[i] = dx*dx*rho(x);
		d[i] = -2.0;
		l[i] = u[i] = 1.0;
	}

	r[1] -= pL;
	r[n-2] -= pR;

	p[0] = pL;
	p[n-1] = pR;

	if (td_solve(&l[1], &d[1], &u[1], &r[1], &p[1], n-2) != 0) {
		fprintf(stderr, "td_solve() failed!\n");
		exit(2);
	}

	fp = fopen("2pt.out", "w");

	for (i = 0; i < n; i++) {

		x = xL + i*dx;

		fprintf(fp, "%le %le %le\n", x, p[i], exact(x));
	}

	fclose(fp);
	exit(0);
}

double
exact(double x)
{
	return pow(x,4.0)/12 - pow(x,3.0)/6 + x/12;
}

double
rho(double x)
{
	return x*(x-1);
}

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
