#include <math.h>
#include <stdio.h>
#include <omp.h>
#include <string.h>
double dot(int n, double *a, int m, double *b){
  int i;

  double sum = 0.0;
  for (i=0; i<n; i++){
    sum += a[i]*b[i];
  }
  return sum;
}

void arange(int size, double *arr){
  int i;

  for (i=0; i<size; i++)
    arr[i] = i;
}

int heat_transfer(int argc)
{

// Problem parameters
double q = 0;
double k = 1;
int n = 500;
double Delta = 1.0/(n-1);

// Initialize T arrays
double T[n*n];
double T_old[n*n];
double swap[n*n];
for (int i = 0; i < n; ++i)
{
  for (int j = 0; j < n; ++j)
  {
    T_old[i*n + j] = 0.0;
    T[i*n+j] = 0.0;
  }
}
// BC's
for (int i = 0; i < n; ++i)
{
  T[i*n + n-1] = 1.0;
  T_old[i*n + n-1] = 1.0;
}
// Jacobi iterations until r = ||T-T_old|| is small enough
//double jacobi_et = omp_get_wtime();
double r;
int it = 0;
do
{
  it += 1;

  double coef = Delta*Delta/k/4.0;
  for (int i = 1; i < n-1; ++i)
  {
    for (int j = 1; j < n-1; ++j)
    {
       T[i*n+j] =  0.25*(T_old[(i+1)*n+j] + T_old[(i-1)*n+j] + T_old[i*n+j+1] + T_old[i*n+j-1]) + coef*q;
    }
  }

  // Compute r = ||T-T_old||
  r = 0.0;
  for (int i = 0; i < n*n; ++i)
      r += pow(T[i]-T_old[i], 2);
  r = sqrt(r);

  // Save T to T_old.  Note, this is *not* a copy!
  memcpy(swap, T_old, sizeof(swap));
  memcpy(T_old, T, sizeof(swap));
  memcpy(T, swap, sizeof(swap));


  if (it % 500 == 0)
  {
    printf("iter %i,  error %8.3e\n", it, r);
      //printf("r=%i\n", r);
  }
}
while ((it > 1e-4)&&(it < 10000));

return 0;
}
