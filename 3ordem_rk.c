//EDO:	 y' ' ' + 2 y ' ' - y ' - 2y = exp(t) 0< t < 3, y(0) = 1, y ' (0) = 2, y' '(0) = 0.
//Sol:	 y(t) = 43/36 exp(t) + 1/4 exp(-t) - 4/9 exp(-2t) + 1/6 t exp(t) 

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 3
#define NP 10

//y[0]=y; y[1]=y'; y[2]=y'';

typedef double (*sistfunc)();

double f1(double y[], double t)
{
	return y[1];
}

double f2(double y[], double t)
{
	return y[2];
}

double f3(double y[], double t)
{
	return exp(t) - 2*y[2] + y[1] + 2*y[0];
}

double rk(sistfunc func[], double y[], double t, double h)
{
	double k1[N], k2[N], k3[N], k4[N], k5[N], k6[N], k7[N], yp[N];
	int i;
	
	for( i=0; i<N; i++) 
	{	k1[i] = func[i](y,t);	}

	for( i=0; i<N; i++) 
	{	yp[i]=y[i]+(k1[i]*(h/2));	}

	for( i=0; i<N; i++) 
	{	k2[i] = func[i](yp,t + (h/2));	}	
	
	for( i=0; i<N; i++) 
	{	yp[i]=y[i]+(k2[i]*(h/2));	}
	
	for( i=0; i<N; i++) 
	{	k3[i] = func[i](yp,t + (h/2));	}
	for( i=0; i<N; i++) 
	{	yp[i] = y[i]+(k3[i]*h);		}
	
	for( i=0; i<N; i++)
	{	k4[i] = func[i](yp,t + h);	}	
	
	for( i=0; i<N; i++) 
	{	y[i] = y[i] + (h/6.0)*(k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);	}
		
	return y[0];
}

void main()
{	double a, b, h, t, y[N]={1.,2.,0.}, ys[NP+1];  	
	sistfunc equacoes_H[N]={f1, f2, f3};
        int i, j;
	FILE *arquivo;
	arquivo =  fopen("pontos.dat", "w");
	
	//extremos do intervalo a e b
	a=0.;
	b=3.;
	h=(b-a)/NP; 
	
	t=a;
	i=1;
	ys[0] = 1;
	do
	{   
		ys[i]=rk(equacoes_H, y, t, h);
		t = t + h;
		i++;
	}
	while(t<b);

	//guardando os pontos no arquivo
	t=a;
	for(i=0;i<=NP;i++)
	{
		fprintf(arquivo, "%lf \t %.2lf \n", t, ys[i]);	
		t = t + h;
	}
		
}	
