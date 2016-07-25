// PROGRAM TO FIND DETERMINANT,INVERSE AND RANK OF A 3X3 MATRIX

#include<stdio.h>
#include<stdlib.h>
float determinant(float a[][3]);
float inverse(float a[][3]);
float rank(float mat[][3]);
void print(float a[][3]);

main()
{
	char z;
	
	do
	{
	
		float mat[3][3];
		printf("This program only handles 3X3 matrix.\nPlease enter the elements:\n");
		int a;
		float det;
	
		for(int i=0;i<3;i++)
			{
	     		printf("\n");
	    		for(int j=0;j<3;j++)
		      		{
		          		printf("a[%d%d]=",i+1,j+1);
	              		scanf("%f",&mat[i][j]);
		      		}
	   		}
	 
		system("cls");
		printf("The given MATRIX is :\n\n");
		print(mat);
		printf("\n\nFind\n1]Determinant\n2]Inverse\n3]Rank\n\nEnter a number: ");
		scanf("%d",&a);
	
		if(a==1)
		   {
	     		system("cls");
	        	det=determinant(mat);
	        	printf("\nThe determinant of the martix = %.0f",det);
	   	   }
	   
		else if(a==2)
	   		{
	 	    	system("cls");
	        	inverse(mat);
	   		}
	
		else
	   		{
	    		system("cls");
	    		printf("The given matrix:\n");
		    	print(mat);
	    		rank(mat);
       		}
       		
    	printf("\nWant to run one more time ?\ty/n");
    	scanf("%c",&z);
    	
   } while(z=='y');
	
	return(0);
}

//This function finds determinant of matrix 

float determinant(float a[][3])                           
{
	float det;
	det=0;
	printf("The given matrix is: \n");
	print(a);
	
	for(int i=0;i<3;i++)
	   det=det+(a[0][i]*((a[1][(i+1)%3]*a[2][(i+2)%3])-(a[1][(i+2)%3]*a[2][(i+1)%3])));
	   
	return (det);
}

//This function finds inverse of matrix 

float inverse(float a[][3])
{
	float b[3][3];
	float deter;
	deter=determinant(a);
	printf("\nThe determinant of the martix = %.0f\n",deter);
	
	if(deter==0)
	    printf("Matrix is not invertible.\nInverse doesnot exist");
	    
	else
     	{
	       for(int i=0;i<3;i++)                                                  //cofactor
	          {
                 for(int j=0;j<3;j++)
                     b[i][j]=((a[(i+1)%3][(j+1)%3] * a[(i+2)%3][(j+2)%3]) - (a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]));
              }
    
	       printf("\ncofactor matrix is:\n");
           print(b);
           float c[3][3];
           
           for(int i=0;i<3;i++)                                                  //Adjoint
	          {
                 for(int j=0;j<3;j++)
                     c[j][i]=(b[i][j]);
	          }
	          
	       printf("Adjoint matrix: \n");
	       print(c);
	       printf("Inverse of the given MATRIX is\n\n");
	   
	       for(int i=0;i<3;i++)                                                  //inverse
	          {
                  for(int j=0;j<3;j++)
                      printf("\t%.2f",((c[i][j])/deter));
                      
                  printf("\n\n");
	          }
        }
    
}

//This function finds rank of matrix 

float rank(float mat[][3])
{
    int i,j,r,c,row1,col1;
    col1=3;
    row1=3;
    for(r=0;r<col1;r++)
    {
        if(mat[r][r])                                //If diagonal element is not zero
        for(c=0;c<row1;c++)
            if(c>r)
            {
                float ratio=mat[c][r]/mat[r][r];     //Making all the elements below the current principal diagonal element zero 
                for(i=0;i<col1;i++)
                    mat[c][i]-=ratio*mat[r][i];
            }

            else
                printf("\n");
                                                     //If principal Diagonal elment is zero 

        else
        {
            for(c=r+1;c<row1;c++)
                if (mat[c][r])
                {
                	int r1,r2,col;                   //Swapping elements of rows
                	r1=r;
                	r2=c;
                	col=col1;
                    for(i=0;i<col;i++)
    					{
    						 int temp = mat[r1][i];
       						 mat[r1][i] = mat[r2][i];
       						 mat[r2][i] = temp;
    					}					
	                break;
                }

            if(c==row1)
            {
                --col1;

                for(c=0;c<row1;c++)
                    mat[c][r]=mat[c][col1];
            }
            --r;
        }
    }
    printf("The reduced matrix: \n\n");
    print(mat);
    printf("Rank of the given matrix: %d",col1);
}

//This function prints the matrix 

void print(float a[][3])
{
	
	for(int i=0;i<3;i++)
	 {
		for(int j=0;j<3;j++)
		 {
			printf("\t%.0f",a[i][j]);
		 }
		printf("\n\n");
	 }
}


