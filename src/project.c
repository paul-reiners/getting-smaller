#include <stdlib.h>

#include "../include/run_svd.h"

int main(int argc, char* argv[]) {
  long m = 1 << atoi(argv[1]);
  long n = 1 << atoi(argv[2]);

  run_svd(m, n);

  return 0;
}
