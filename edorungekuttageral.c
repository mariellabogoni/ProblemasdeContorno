#include <stdio.h>
#include <stdlib.h>
#include <math.h>
FILE *arquivo;

typedef double (*sistfunc) ();

double f(double x, double y, double z)
{   //z=y';
   
    return(3*z - 2*y + 6*exp(-x));
}
double g(double t, double z)
{   
		return z;
}
double rk(sistfunc func, double y[], double x, double h, double N, double z)
{
    int i;
    double  z, k1[N], k2[N], k3[N], k4[N], l1[N], l2[N], l3[N], l4[N], aux;
    
    aux = x; 

    for(i=0;i<=N;i++)     
    {     
     
       l1[i] = g(x,z);
       
	    l2[i] = g(x + (h/2.) , z+(h/2.)*l1[i]) ;
	    
	    l3[i] = g(x + (h/2.) , z+(h/2.)*l2[i]) ;
	    
	    l4[i] = g(x + h , z + h*l3[i] );
	    
	    aux = aux + h;
	    
	}
	
   aux = x;
   
    for(i=0;i<=N;i++)
	 {  
	    
	    k1[i] = f(x , y[i] ,z);
	    
	    k2[i] = f( x + (h/2.) , y[i]+(h/2.)*k1, z + (h/2.)*l1[i]);
	    
	    k3[i] = f(x + (h/2) , y[i]+(h/2.)*k2, z + (h/2.)*l2[i]);
	    
	    k4[i] = f(x + h, y[i] + h+k3[i], z + h*l3[i]);  
	    
	    aux = aux + h;
	 }   
	    


}

main()
{   
    double a, b, h, x, z, yt, N,L,M;
    int i ;
    
    sistfunc equacoes[N]={f,g}; 
     
    //Intervalo :
	 printf("Informe o intervalo: ");
	 scanf("%lf, %lf", &a,&b);
	 
	 //Espaçamento
	 printf("Informe o número de equações e a ordem: ");
	 scanf("%lf,%lf", &L, &M); 
	 
	 N = M*L;
	  
	 h=(b-a)/N;
	
	 
	 x= 0.;
	 y= 2.;
	 z= 2.;
	
	yt = rk(equacoes, y, x, h, N, z);
	
}	

	
	
	
	
