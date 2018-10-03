#include <stdio.h>
#include <string.h>

int main()
{
	char key[100]={'\0'};
	char pt[1000]={'\0'};
	char ct[1000]={'\0'};
	int num[100];
	
	int a,i,j,k,l,m,n,o,p,hahaha;
	
	printf("enter your key word:");
	scanf("%s",key);
	
	for(i=0,hahaha=0;i<100;i++)
	{
		if (key[i]=='\0')
		{
			break;
		}
		
		hahaha++;
		
		
	}
	

	
	for (i=0;i<hahaha;i++)
	{
		num[i]=key[i]-97;
		
	}
	
	printf("enter your plaintext:");
	scanf("%s",pt);
	
	for(i=0,j=0;i<1000;i++)
	{
		if (pt[i]=='\0')
		{
			break;
		}
		
		j++;
	}
	

	o=j;
	i=0;
	
	


   printf("ciphertext:"); 
	
	while(j>=hahaha)
	{
		
		for (k=0;k<hahaha;k++)
		{
			l=num[k]%(j);
			
			
			
			if(pt[l]!='0')
			{
			ct[i]=pt[l];
			pt[l]='0';
			}else if(pt[l]=='0')
			{
			ct[i]=pt[l+1];
			pt[l+1]='0';
			}
			
			i++;
			
		}
	
		
		
		for (m=0;m<j;m++)
		{
		  
			if (pt[m]=='0')
			{
				for (n=m;n<j-1;n++)
				{
					pt[n]=pt[n+1];
					
				}
				
				for (p=j;p>=j&&p<o;p++)
				{
					pt[p]='1';
				}
				
			     	j--;
					
					m=0;
			}
		    
		}
		

		
		
		
	}
    strcat(ct,pt);
    
    for (i=0;i<1000;i++)
    {
    	if (ct[i]=='0')
    	{
    		break;
		}else if(ct[i]=='1')
		{
			break;
		}
		
		printf("%c",ct[i]);
	}
	 
	 return 0;
} 
