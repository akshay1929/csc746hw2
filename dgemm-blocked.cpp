#include <iostream>
const char *dgemm_desc = "Blocked dgemm.";

/* This routine performs a dgemm operation
 *  C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values. */
void square_dgemm_blocked(int n, int block_size, double *A, double *B, double *C)
{
   for (int a = 0; a < n; a += block_size) {
      for (int b = 0; b < n; b += block_size) {
         for (int c = 0; c < n; c += block_size) { 
            for (int i = a; i < a + block_size; i++) {
               for (int j = b; j < b + block_size; j++) {
                  for (int k = c; k < c + block_size; k++) {
                     C[j * n + i] += A[k * n + i] * B[j * n + k];
                  }
               }
            }
         }
      }
   }
}
