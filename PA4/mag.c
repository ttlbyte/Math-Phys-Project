#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    if(argc !=3)
    {
        fprintf(stderr,"usage: ./mag N seed\n");
        exit(2);
    }
    int N, i, j, seed;
    int **s;
    double tot;
    sscanf(argv[1],"%d", &N);
    s=(int **)malloc(N*sizeof(int *));
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
    tot = mag(s,N);
    printf("Average magnetic moment is %lf\n", tot);
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
