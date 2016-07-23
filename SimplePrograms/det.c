int* minor(int i, int *mat, int ord){
  ord--;

}

int* transpose_matrix(int *matrix, int order){
  int *tmatrix;
  int i,j,k;
  for ( i = 0; i < order; i++) {
    for ( j = 0; j < count; j++) {
        matrix[i][j] = tmatrix[j][i];
    }
  }
  return tmatrix;
}

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
  int matrix[3][3];
  int detofmatrix;
  int i,j;

  printf("enter the elements in the matrix\n" );
  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {
      scanf("%d",matrix[i][j]);
    }
  }
  detofmatrix = determinant(matrix,order);
  printf("determinant of the given matrix is :  %d", detofmatrix);
}
