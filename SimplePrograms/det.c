#include <stdio.h>

struct array{
  int matrix[3][3];
};

struct array transpose_matrix(struct array matri, int order){
  struct array tmatrix;
  int i,j;
  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {
        tmatrix.matrix[j][i] = matri.matrix[i][j];
    }
  }
  return tmatrix;
}

/*int* minor(int i, int *mat, int ord){
  ord--;

}
*/

int determinant(int *matrix, int order){
  int sum = 0;
  int i;
  if (order != 2) {
    for ( i = 0; i < order; i++) {
      sum = sum + (matrix[0][i] * determinant(minor(i, 0, matrix, order)));
    }
    order--;
    return sum;
  }
  else{
    int mul = (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
    return mul;
    }
  }
}


void  main() {
  int order=3;
  struct array tpointer,mat;
  int i,j;

  printf("enter the elements in the matrix\n" );
  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {
      scanf("%d",&mat.matrix[i][j]);
    }
  }
  //detofmatrix = determinant(matrix,order);
  //printf("determinant of the given matrix is :  %d", detofmatrix);

  printf("transpose of the given matrix is : \n");
  tpointer = transpose_matrix(mat, 3);
  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {

      printf("%d    ", tpointer.matrix[i][j]);
    }
    printf("\n");

  }

}
