#include <stdio.h>

void crack(int a,int j,char ct[1000],char pt[1000]);
int measure(char ct[1000]);

int main()
{
	char ct[1000]={'\0'};
    char pt[1000]={'\0'};
	
	int i,j,k,a;
	
	printf("inter your ciphertext:");
	
	scanf("%s",ct);
	
	for(a=1;a<=25;a++)
	{
		crack(a,measure(ct),ct,pt);
	}
	
		printf("key:");
		scanf("%d",&a);
		
		crack(a,j,ct,pt);
		
	while(true)
	{
			printf("enter again:");
			
			scanf("%s",ct);
		
		    crack(a,measure(ct),ct,pt);
	}
	
	return 0;
}
	

void crack(int a,int j,char ct[1000],char pt[1000])
{
	int i,k;
		
	for (i=0;i<=j;i++)
	    {
		
			k=ct[i]-a;
			if (k>=97)
			{
		
			pt[i]=ct[i]-a;
			
		    }
		    
		    if (k<97)
		    {
		    
		    pt[i]=ct[i]-a+26;
		    
		    }
	    }
		printf("%d %s\n",a,pt);
		
} 

int measure(char ct[1000])

{
	
	int i,j;
	
	for (i=0,j=0;i<100;i++)
	{
		if(ct[i+1]!='\0')
		{
				j++;
		}
	
	}
	
	return j;
}
	
		
