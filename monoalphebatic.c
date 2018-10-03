#include <stdio.h>

int main ()
{
     char alphb[100]={"abcdefghijklmnopqrstuvwxyz"};
     char ciphb[100]={"\0"};
	 char key[100]={"\0"};
	 char ct[1000]={"\0"};
	 char pt[1000]={"\0"};
	 int i,j,k,num,choice;
	 
	 //building cipherbet
	 printf("enter the key:");
	 
	 scanf("%s",key);
	  
	 for(i=0,j=0;i<100;i++)
	 {
	 	if (key[i]=='\0')
		 {
	 		break;
		 }
		 
		 j++;
	 }
	 
	 
	 for(i=0;i<j;i++)
	 {
	 	ciphb[i]=key[i];
	 }
	 
	 
	for(k=j;k<=25;k++)
    {
    	
		if (ciphb[k-1]+1<=122)
		{
    		ciphb[k]=ciphb[k-1]+1;
    		for(i=0;i<j;i++)
    		{
    			if(ciphb[i]==ciphb[k])
    			{
    				ciphb[k]+=1;
				 } 
			}
		}else{
			ciphb[k]=ciphb[k-1]-25;
			
			for(i=0;i<j;i++)
    		{
    			if(ciphb[i]==ciphb[k])
    			{
    				ciphb[k]+=1;
				 } 
			}
		}
	} 
	printf("%s\n",alphb);
	printf("%s\n",ciphb);
	
	//encrypt and decrypt
	
	printf("1 encypt\n2 decrypt\nenter your choice:");
	scanf("%d",&choice);
	
	if (choice==1)
{
	printf("enter your plaintext:");
	
	scanf("%s",pt);
	printf("ciphertext:");
	for(i=0;i<1000;i++)
	{
		
		if(pt[i]!='\0')
		{
		num=pt[i]-97;
		printf("%c",ciphb[num]);
	
		}else{
			break;
		}
	}
}
	
	else if (choice==2)
	{
		printf("enter your ciphertext:");
		scanf("%s",ct);
	
		
		for (i=0;i<1000;i++)
		{
				if(ct[i]!='\0')
		 	{
			   for(j=0;j<=25;j++)
			   {
			   	 if (ct[i]==ciphb[j])
			   	 printf("%c",alphb[j]);
			   }
		
			}else{
				break;
			}
		}
			
		
	}
	
	
	 

	return 0;
 } 
