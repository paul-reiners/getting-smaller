#include <stdio.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h>
#include <time.h>

/*
  gsl_matrix_printf prints a matrix as a column vector.  This function
  prints a matrix in block form.
*/
void pretty_print(const gsl_matrix * M)
{
  // Get the dimension of the matrix.
  int rows = M->size1;
  int cols = M->size2;
  // Now print out the data in a square format.
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      printf("%f ", gsl_matrix_get(M, i, j));
    }
    printf("\n");
  }
  printf("\n");
}

int run_svd(const gsl_matrix * a) {
  // Need to transpose the input
  gsl_matrix *a_transpose = gsl_matrix_alloc(a->size2, a->size1);
  gsl_matrix_transpose_memcpy(a_transpose, a);
  printf("a_matrix'\n");
  pretty_print(a_transpose);

  int m = a->size1;
  gsl_matrix * V = gsl_matrix_alloc(m, m);
  gsl_vector * S = gsl_vector_alloc(m);
  gsl_vector * work = gsl_vector_alloc(m);

  gsl_linalg_SV_decomp(a_transpose, V, S, work);
  printf("U\n");
  pretty_print(V); printf("\n");
  printf("V\n");
  pretty_print(a_transpose); printf("\n");
  printf("S\n");
  gsl_vector_fprintf(stdout, S, "%g");

  gsl_matrix_free(V);
  gsl_vector_free(S);
  gsl_vector_free(work);

  return 0;
}
