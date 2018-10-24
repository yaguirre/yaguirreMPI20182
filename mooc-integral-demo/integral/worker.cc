#include "library.h"
#include <mpi.h>

double ComputeIntegral(const int n, const double a, const double b, const int rank, const int nRanks) {
  
  const int stepsPerProcess = double(n-1)/double(nRanks);  //De cuantos pasos de integración es responsable cada procesador
  const int iStart = int (stepsPerProcess*rank); //Primer valor por el que es responsable el rank
  const int iEnd = int(stepsPerProcess*(rank+1)); //Ultimo valor por el que es responsable

  
  const double dx = (b - a)/n;
  double I_partial = 0.0;

#pragma omp parallel for simd reduction(+: I_partial)
  for (int i = iStart; i < iEnd; i++) {

    const double xip12 = a + dx*(double(i) + 0.5);
    const double yip12 = BlackBoxFunction(xip12);
    const double dI = yip12*dx;
    I_partial += dI; //Este valor se almacena en la memoria de cada procesador

  }

  double I = 0.0;
  MPI_Allreduce(&I_partial, &I, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  //Agrega resultados parciales de multiples procesos
  //Y propaga el resultado a través de estos procesos
  //Un procesador sabe la respuesta final

  return I;
}
