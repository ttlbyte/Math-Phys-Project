#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define Y 0.3

int main(int argc, char **argv)
{
    double i = 0.0;
    int j, k;
    double x, y;
    if (argc !=2)
        printf("Usage: ./a.out N\n");
    sscanf(argv[1],"%d", &j);
    srand48(time(NULL));
    for (k=0; k<j; k++)
    {
       x = drand48();
       y = drand48()*Y;
       if(y < x*(1.0-x))
           i = i+1.0;
    }
    i = 0.3*i/j;
    printf("the integration is %lf \n", i);
}

