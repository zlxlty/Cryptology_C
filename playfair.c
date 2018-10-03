#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* find(char a,char b,char p[6][6]);

int main()
{
	char grid[6][6];
	char key[6];
	int i,j,m,n,pos,cipos,size,deci;
	char alphb[26]={"abcdefghiklmnopqrstuvwxyz"};
	char plaint[1000];
	char ciphet[1000];

    //Pre-set
	for (i=0;i<=4;i++)
	{
		for (j=0;j<=4;j++)
		{
			grid[i][j]='\0';
		}
	 } 
	 
	// Get Key input
	printf("enter key:");
	scanf("%s",grid);
	
	
	// Find key in the alphb and replace the correspond letter with 'j'
	for(m=0;m<6;m++)
	{
		for (n=0;n<26;n++)
		{
			if (grid[0][m]!='\0')
	    	{
			if (grid[0][m]==alphb[n])                     
			alphb[n]='j';
	    	}
		}
		
	}
	
	
	// check whether the replacement works
	printf("%s\n",alphb); 
		
	// reset the position
	m=1;
	n=0;
	
	
	//make the grid
	for(i=0;i<=25;i++)
	{
		if(alphb[i]!='j')     // eliminate letters appeared in the key
		{
			if(n==5)         
			{
				m++;          // change row
				n=0;
			}
			grid[m][n]=alphb[i];
			n++;              // change column           
			
			
		}
	}
	 
	// print the grid
	for (i=0;i<=4;i++)
	 {
	 	for (j=0;j<=4;j++)
	 	{
	 		printf("%c",grid[i][j]);
	 		
	 		if(j==4)
	 		{
	 		    printf("\n");
			 }
		 }
	 }
	 
	 
	 printf(" Enter your choice: 1 encrypt, 2 decrypt:");
	 scanf("%d",&deci);
	 
	 
	 if ( deci==1 )
	 {
	 	
		// get plaintext
		 printf("enter the plaintext:");
		 scanf("%s",plaint);
		 
		// get the length of the plaintext
		size=strlen(plaint);
		printf("size:%d\n",size);
		 
		 
		 
		// pick a pair of numbers from the beginning 
		for( cipos=0 , pos=0 ; pos<=size-1 ; pos=pos+2 , cipos=cipos+2 )
		{
		    
		    // get the position of a pair of letters in the grid
		 	int* addr;
		    if(plaint[pos]=='\0')   // determine whether pos has cross the border
		    {
		    	
		    	break;
		    	
			}else if(plaint[pos+1]=='\0')   // if there is only one letter at the end, add an 'x' at the end
			{
				
				addr=find(plaint[pos],'x',grid);   //encypt the letter with pos and 'x'
				
			}
			if(plaint[pos]!=plaint[pos+1])    // normal situation
		 	{
		 		
		 		addr=find(plaint[pos],plaint[pos+1],grid);
		 		
			 }else if(plaint[pos]==plaint[pos+1])  //if two letters are the same
			 {
			 	
			 	addr=find(plaint[pos],'x',grid);   //encrypt the former letter with 'x' 
			 	pos--;                             //and let the pos point to latter letter
			 	
			 }
			 
			//    first row -> addr[0]
			//    first column -> addr[1]
			//    second row -> addr[2]
			//    second colume -> addr[3]
			
			
			// two letters in the same row
			if(addr[0]==addr[2])  
			{
				
				if(addr[1]+1<=4)  // no letter cross the right border  (1)
				{
					
					ciphet[cipos]=grid[addr[0]][addr[1]+1];   //shift column to the right   (2)
					
				}
				else if(addr[1]+1>4)   // return to the beginning if cross the border   (3)
				{
					
					ciphet[cipos]=grid[addr[0]][0];   // reset the column to the beginning;    (4)
					
				}
				
				if(addr[3]+1<=4)  //(1)
				{
					
					ciphet[cipos+1]=grid[addr[0]][addr[3]+1];   //(2)
					
				}else if(addr[1]+1>4)    //(3)
				{
					
					ciphet[cipos+1]=grid[addr[0]][0];    //(4)
					
				}
				
			}
			
			// two letter in the same column
			else if(addr[1]==addr[3])
			{
				
				if(addr[0]+1<=4)     //no letter cross the bottom border
				{
					
					ciphet[cipos]=grid[addr[0]+1][addr[1]];    // shift to the lower row
					
				}
				else if(addr[0]+1>4)
				{
					ciphet[cipos]=grid[0][addr[1]];     //reset the row position
				}
				
				if(addr[2]+1<=4)
				{
					ciphet[cipos+1]=grid[addr[2]+1][addr[1]];
				}else if(addr[2]+1>4)
				{
					ciphet[cipos+1]=grid[0][addr[1]];
				}
				
				
			}else
			{
				
				ciphet[cipos]=grid[addr[0]][addr[3]];
				ciphet[cipos+1]=grid[addr[2]][addr[1]];    // shift to the opposite corners
				
	//			addr[0]addr[1] -------- addr[0]addr[3]              
	//			      |                       |
	//			      |                       | 
	//			      |                       |
	//                |                       |
	//                |                       |
	//			      |                       |
	//			addr[2]addr[1] -------- addr[2]addr[3]
				
			}
		
		 }
		
		printf("cipher text is:%s",ciphet);
		 	
	 }else if ( deci ==2 )
	 {
	 	
	 	// get ciphertext
		 printf("enter the ciphertext:");
		 scanf("%s", ciphet );
		 
		// get the length of the ciphertext
		size=strlen(ciphet);
		printf("size:%d\n", ciphet);
		
		// pick a pair of numbers from the beginning 
		for( cipos=0 , pos=0 ; pos<=size-1 ; pos=pos+2 , cipos=cipos+2 )
		{
		    
		    // get the position of a pair of letters in the grid
		 	int* addr;
		    if(ciphet[pos]=='\0')   // determine whether pos has cross the border
		    {
		    	
		    	break;
		    	
			}else if(ciphet[pos]!=ciphet[pos+1])    // normal situation
		 	{
		 		
		 		addr=find(ciphet[pos],ciphet[pos+1],grid);
		 		
			 }
			 
			//    first row -> addr[0]
			//    first column -> addr[1]
			//    second row -> addr[2]
			//    second colume -> addr[3]
			
			
			// two letters in the same row
			if(addr[0]==addr[2])  
			{
				
				if(addr[1]-1>=0)  // no letter cross the left border  (1)
				{
					
					plaint[cipos]=grid[addr[0]][addr[1]-1];   //shift column to the right   (2)
					
				}
				else if(addr[1]-1<0)   // return to the beginning if cross the border   (3)
				{
					
					plaint[cipos]=grid[addr[0]][4];   // reset the column to the beginning;    (4)
					
				}
				
				if(addr[3]-1>=0)  //(1)
				{
					
					plaint[cipos+1]=grid[addr[0]][addr[3]-1];   //(2)
					
				}else if(addr[1]-1<0)    //(3)
				{
					
					plaint[cipos+1]=grid[addr[0]][4];    //(4)
					
				}
				
			}
			
			// two letter in the same column
			else if(addr[1]==addr[3])
			{
				
				if(addr[0]-1>=0)     //no letter cross the upper border
				{
					
					plaint[cipos]=grid[addr[0]-1][addr[1]];    // shift to the lower row
					
				}
				else if(addr[0]-1<0)
				{
					plaint[cipos]=grid[4][addr[1]];     //reset the row position
				}
				
				if(addr[2]-1>=0)
				{
					plaint[cipos+1]=grid[addr[2]-1][addr[1]];
				}else if(addr[2]-1<0)
				{
					plaint[cipos+1]=grid[4][addr[1]];
				}
				
				
			}else
			{
				
				plaint[cipos]=grid[addr[0]][addr[3]];
				plaint[cipos+1]=grid[addr[2]][addr[1]];    // shift to the opposite corners
				
	//			addr[0]addr[1] -------- addr[0]addr[3]              
	//			      |                       |
	//			      |                       | 
	//			      |                       |
	//                |                       |
	//                |                       |
	//			      |                       |
	//			addr[2]addr[1] -------- addr[2]addr[3]
				
			}
		
		 }
		
		printf("plain text is:%s",plaint);
		 	
	 	
	 }else
	 {
	 	
	 	printf(" choice error ");
	 	
	 }
	 
	
	return 0;  
 } 
 
 
 
 
 // m: first letter , n: second letter
 int* find(char m,char n,char grid[6][6])
 {
 	
 	int addr[4];
 	int i,j;
 
 	for(i=0;i<=4;i++)
 	{
 		for (j=0;j<=4;j++)
 		{
 			if (m==grid[i][j])
 			{
 				
 				addr[0]=i;  // put the row number of the first in the addr[0]
 				
 				addr[1]=j;  // put the column number of the first in the addr[1]
 				
			 }
		 }
	 }

	 for(i=0;i<=4;i++)
 	{
 		for (j=0;j<=4;j++)
 		{
 			if (n==grid[i][j])
 			{
 				
 				addr[2]=i;  // put the row number of the second in the addr[2]
 				
 				addr[3]=j;  // put the column number of the second in the addr[3]
 				
			 }
		 }
	 }
	 
	
	 return addr;
 }
