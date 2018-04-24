#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    if(argc !=5)
    {
        fprintf(stderr,"usage: ./mag N seed Step Temperature\n");
        exit(2);
    }
    int N, i, j, seed, step;
    double T;
    int **s;
    sscanf(argv[1],"%d", &N);
    sscanf(argv[3], "%d", &step);
    sscanf(argv[4], "%lf", &T);
    s=(int **)malloc(N*sizeof(int *));
    double monte(int **,int , int, double);
    int mod(int, int);
    for (i=0;i<N; i++)
        s[i] = (int *)malloc(N*sizeof(int *));
    sscanf(argv[2],"%d",&seed);
    srand48(seed);
    for (i=0; i<N; i++)
        for (j=0; j<N;j++)
            if(drand48()<0.5)
                s[i][j]=-1;
            else s[i][j]=1;
    double mag(int **, int);
    monte(s, N, step, T);
    return 0;
}

double mag(int **s, int n)
{
    double res;
    int i, j;
    res = 0;
    for (i=0;i<n;i++)
        for(j=0;j<n;j++)
            res += s[i][j];
    return res/(n*n);
}

double monte(int **s, int n, int step, double T)
{
   int i, j, t;
   int k, l, sum;
   double p1, p2;
   FILE *p;
   char filename[40];
   sprintf(filename,"mk_N_%d_T_%lf_Step_%d.dat",n, T, step);
   p=fopen(filename,"w");
   p1 = exp(-4.0/T);
   p2 = exp(-8.0/T);
   for(t=0; t<step;t++)
   {
       for (i=0;i<n;i++)
       {
           for (j=0;j<n;j++)
           {
               k=drand48()*n;
               l=drand48()*n;
               sum=s[mod(k-1,n)][mod(l-1,n)] +s[mod(k-1,n)][mod(l+1,n)] + s[mod(k+1,n)][mod(l-1,n)] + s[mod(k+1,n)][mod(l+1,n)];
               sum = -1*sum*s[k][l];
               switch(sum){
                   case -4: if (p2>drand48())
                                s[k][l] *= -1;
                            break;
                   case -2: if (p1>drand48())
                                s[k][l] *= -1;
                            break;
                   default: s[k][l] *= -1;
               }
           }
       }
       fprintf(p,"%d %lf\n",t, mag(s,n));
   }
}

int mod(int i, int n)
{
    if(i==-1) return n-1;
    else if(i==n) return 0;
    else return i;
}
