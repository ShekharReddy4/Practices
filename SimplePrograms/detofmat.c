#include <stdio.h>

*int minor(int i, int *mat, int o){


}

int determinant(int *matr, int ord){
  int *smatr, sum=0;
  if (ord>2) {
    for (i = 0; i < ord; i++) {
      if ((i%2)!=0) {
        sum= sum - (matr+(0*order*sizeof(int))+(i*sizeof(int)))*determinant(minor(i, *matr, ord), (ord--));
      }
      else{
        sum= sum + (matr+(0*order*sizeof(int))+(i*sizeof(int)))*determinant(minor(i, *matr, ord), (ord--));
      }
    }
    return sum;
  }
  else{
    for (i = 0; i < ord; i++) {

      
    }

  }

}

void main() {
  // code to find the rank, determinant, and inverse of a given matrix
  int *matrix;
  int i,j;
  int order;
  int det;
  printf("enter the order of the matrix\n");
  scanf("%d",&order );
  matrix = (int *)malloc((sizeof(int))*order*order);
  printf("enter the elements in the matrix\n" );
  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {
      scanf("%d",matrix+(i*order*sizeof(int))+(j*sizeof(int)));
    }
  }
  printf("the matrix you have entered is:\n" );

  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {
      printf("%d   ",*(matrix+(i*order*sizeof(int))+(j*sizeof(int))));
    }
    printf("\n" );
  }



  printf("determinant of your matrix is: %d \n",det);
}
