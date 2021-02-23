#include <stdlib.h>

#include "../include/run_svd.h"

int main(int argc, char* argv[]) {
  int n = atoi(argv[1]);

  run_svd(n);

  return 0;
}
