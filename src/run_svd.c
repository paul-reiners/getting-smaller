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
}

int run_svd(int n) {
  clock_t start, end;
  double cpu_time_used;

  // Set the data for our matrix.
  double* a_ptr = (double *) malloc(n * n * sizeof(double));

  if (a_ptr == NULL) {
    printf("Memory not allocated.\n");
    exit(0);
  } else {
      // Memory has been successfully allocated
      printf("Memory successfully allocated using malloc.\n");

      // Get the elements of the array
      for (int i = 0; i < n * n; ++i) {
          a_ptr[i] = i + 1;
      }

      // Print the elements of the array
      printf("The elements of the array are: ");
      for (int i = 0; i < n * n; ++i) {
          printf("%f, ", a_ptr[i]);
      }
      printf("\n\n");
  }

  start = clock();
  // Now create a matrix structure using this data.
  gsl_matrix_view A = gsl_matrix_view_array(a_ptr, n, n);

  gsl_matrix * V = gsl_matrix_alloc(n, n);
  gsl_vector * S = gsl_vector_alloc(n);
  gsl_vector * work = gsl_vector_alloc(n);

  /*
    From the gsl documentation: The gsl_linalg_SV_decomp function
    factorizes the M-by-N matrix A into the singular value
    decomposition A = U S V^T for M >= N. On output the matrix A is
    replaced by U. The diagonal elements of the singular value matrix
    S are stored in the vector S. The singular values are non-negative
    and form a non-increasing sequence from S_1 to S_N. The matrix V
    contains the elements of V in untransposed form. To form the
    product U S V^T it is necessary to take the transpose of V. A
    workspace of length N is required in work.
  */
  gsl_linalg_SV_decomp(&A.matrix, V, S, work);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("gsl_linalg_SV_decomp() took %f seconds to execute \n\n", cpu_time_used);

  //  gsl_matrix_fprintf (stdout, &A.matrix, "%g"); cout<<"\n";
  pretty_print(&A.matrix); printf("\n");
  //  gsl_matrix_fprintf (stdout, V, "%g"); cout<<"\n";
  pretty_print(V); printf("\n");
  gsl_vector_fprintf(stdout, S, "%g");

  free(a_ptr);

  gsl_matrix_free(V);
  gsl_vector_free(S);
  gsl_vector_free(work);

  return 0;
}
