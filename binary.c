# include <stdio.h>


int main ()
{
	int g,p,a,b,A,B,i,m,j,n;
	
	printf("enter p g:");
	scanf("%d %d",&p,&g);
	printf("enter A:");
	scanf("%d",&A);
	printf("enter B:");
	scanf("%d",&B);
	for (i=1,a=1;i<p;i++)
	{
		
		a=a*g;
		
		m=a%p;
		
		printf("exponent:%d\n residue:%d\n",i,m);
		
		if (m==A)
		{
			printf("the right exponent is:%d\n",i);
			
			break;
		}
		
		
		
	}
	
	

	
	n=B;
	
	for	 (j=1;j<i;j++)
	
	{
		B=B*n;
	}
	
	m=B%p;
	
	printf("common key:%d",m);

    return 0;
	
	
}
