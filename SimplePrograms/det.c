#include <stdio.h>

struct array{
  int matrix[3][3];
};

struct array2{
  int matrix[2][2];
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

int minor(struct array mat, int order, int row, int col){
  struct array2 mat2;
  int i,j,kr = 0,kc=0;

  for ( i = 0,; i < order; i++) {
    for ( j = 0; j < order; j++) {
        if (i != row) {
          if (j != col) {
          }
          else{
            mat2.matrix[kr][kc] = mat.matrix[i][j];
            if (kc < 2) {
              kc++;
            }
            else{
              kc = 0;
              kr++;
            }
          }
        }
    }
  }

  for (i = 0; i < 2; i++) {
    for ( j = 0; j < 2; j++) {
      mat2[i][j];
    }
  }

  return ((mat2[0][0]*mat2[1][1]) - (mat2[0][1]*mat2[1][0]));

}

struct array adjoint(struct array omat, order){
  struct array radjmat;
  int i,j,k;
  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {
        radjmat.matrix[i][j] = ;
    }
  }
}


int determinant(struct array matric, int order){
  int sum = 0;
  int i;
  if (order != 2) {
    for ( i = 0; i < order; i++) {
      sum = sum + (matric.matrix[0][i] * determinant(minor(i, 0, matric, order)));
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
  int order=3, detofmatrix;
  struct array tpointer,mat,adjmat,invmatrix;
  int i,j;

  printf("enter the elements in the matrix\n" );
  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {
      scanf("%d",&mat.matrix[i][j]);
    }
  }

  //transpose of the given matrix
  printf("transpose of the given matrix is : \n");
  tpointer = transpose_matrix(mat, 3);

  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {
      printf("%d    ", tpointer.matrix[i][j]);
    }
    printf("\n");
  }


  //determinant of a given matrix
  printf("determinant of the given matrix is :  %d", detofmatrix);
  detofmatrix = determinant(mat,order);

  //adjoint of the given matrix
  adjmat = adjoint(mat, order);
  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {
      printf("%d    ", adjmat.matrix[i][j]);
    }
    printf("\n");
  }

  //inverse of the given matrix
  if (detofmatrix!=0) {
    for ( i = 0; i < order; i++) {
      for ( j = 0; j < order; j++) {
          invmatrix.matrix[i][j] = (adjmat.matrix[i][j]/detofmatrix);
      }
      printf("\n");
    }
  }

  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {
      printf("%d    ", invmatrix.matrix[i][j]);
    }
    printf("\n");
  }

}
