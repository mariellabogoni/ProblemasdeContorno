// resolver y" - 3y'+2y = 6e^-t, 0<=x<=1, com y(0)=y'(0)=2 e N=10 pontos.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10
double f(double x, double y, double z)
{   //z=y';
   
    return(3*z - 2*y + 6*exp(-x));
}
double g(double t, double z)
{   
		return z;
}
main()
{   
    double a, b, h, xi, yi, z, k1, k2, k3, k4, l1, l2, l3, l4;
    int i ;
    FILE *arquivo;
    
//Intervalo :
	a= 0.;
	b= 1.;

//Espaçamento:
	h=(b-a)/N;
	
	xi= 0.;
	yi= 2.;
	z = 2;
	arquivo = fopen("dados2runge.dat", "w");
	
	for(i=0;i<=N;i++)
	{   
	    fprintf(arquivo, "%lf\t %lf\t \n", xi,yi);
	    
	    l1 = g(xi,z);
	    k1 = f(xi , yi ,z);
	    
	    l2 = g(xi + (h/2.) , z+(h/2.)*l1) ;
	    k2 = f( xi + (h/2.) , yi+(h/2.)*k1, z + (h/2.)*l1);
	    
	    l3 = g(xi + (h/2.) , z+(h/2.)*l2) ;
	    k3 = f(xi + (h/2) , yi+(h/2.)*k2, z + (h/2.)*l2);
	    
	    l4 = g(xi + h , z + h*l3 );
	    k4 = f(xi + h, yi + h+k3, z + h*l3);  
	    
	    yi = yi + (h/6.)*(k1 + 2*k2 + 2*k3 + k4);
	    z = z + (h/6.)*(l1 + 2*l2 + 2*l3 + l4);
	    xi = xi + h;
	    
	} 
	
	
}	
