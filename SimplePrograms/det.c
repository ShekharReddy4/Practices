int* minor(int i, int *mat, int ord){
  ord--;

}


int determinant(int *matrix, int order){

  if (order!=2) {
    for ( i = 0; i < order; i++) {
      sum = sum + determinant(minor(i, matrix, order));
    }
    order--;
    return sum;

  }
  else{

    for (i = 0; i < order; i++) {
      
    }
  }

}




void  main() {

  int order=3;
  int matrix[3][3];
  printf("enter the elements in the matrix\n" );
  for ( i = 0; i < order; i++) {
    for ( j = 0; j < order; j++) {
      scanf("%d",matrix[i][j]);
    }
  }

  printf("determinant of the given matrix is :  %d", determinant(matrix,order));

}
