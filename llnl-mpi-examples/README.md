# mpi20182

* this lab is based on: https://computing.llnl.gov/tutorials/mpi/exercise.html

* some scripts were adapted for running on EAFIT DCA MPI Cluster

* compile all mpi examples:

        $ cd llnl-mpi-examples/mpi
        $ make -f Makefile.MPI.c

* compile all serial examples:

        $ cd llnl-mpi-examples/serial
        $ make -f Makefile.Ser.c

* run mpi examples:

        $ cd llnl-mpi-examples/mpi
        $ mpirun -f ../../hosts_mpi -n 4 ./mpi_array
        $
        $ mpirun -f ../../hosts_mpi -n 4 ./mpi_latency