#include <stdio.h>

int main()

{
	
	char m,n;
	int a,choice;
	char ct[1000]={'\0'};
    char pt[1000]={'\0'};
	
	int i,j,k;
	printf("enter your key:");
	m=getchar();
	n=getchar();
	
	a=n-m;
	
	printf("1 encypt\n2 decrypt\nenter your choice:");
	scanf("%d",&choice);
	
	printf("Input:");
	scanf("%s",ct);
	
	for (i=0,j=0;i<1000;i++)
	{
		if(ct[i+1]=='\0'&&ct[i+2]=='\0')
		{
			break;
		}else{
		j++;	
		}
	    
	}
	

	if(choice==1)
	{
			for (i=0;i<=j;i++)
	

	{
		
		k=ct[i]+a;
		if (k<=122)
		{
	
		pt[i]=ct[i]+a;
		
	    }
	    
	    if (k>122)
	    {
	    
	    pt[i]=ct[i]+a-26;
	    
		}
	}
	
	printf("%s",pt);
	}
	else if(choice==2)
	{
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
	
	printf("Output:%s",pt);
	}

	
	return 0;
	
} 
