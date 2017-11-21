// resolver y'= 1+(x-y)², 2<=x<=3, com y(2)=1 e N=10 pontos.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
double f(double x, double y)
{ 
    return(1+ pow(x-y,2));
}

main()
{   
    double a, b, h, xi, yi, k1, k2, k3, k4;
    int i ;
    FILE *arquivo;
    
//Intervalo :
	a= 2.;
	b= 3.;

//Espaçamento:
	h=(b-a)/N;
	
	xi= 2.;
	yi= 1.;
	
	arquivo = fopen("dadosrunge.dat", "w");
	
	for(i=0;i<=N;i++)
	{   
	    fprintf(arquivo, "%lf\t %lf\t \n", xi,yi);
	    
	    k1 = f(xi , yi);
	    k2 = f( xi + (h/2.) , yi+(h/2.)*k1);
	    k3 = f(xi + (h/2) , yi+(h/2.)*k2);
	    k4 = f(xi + h, yi + h+k3);  
	    
	    yi = yi + (h/6.)*(k1 + 2*k2 + 2*k3 + k4);
	    xi = xi + h;
	    
	} 
	
	
}	   
	
	
    
