# Multithread N-Particle Simulation

The scope of this project is to simulate **N-body physics** using the **Verlet velocity algorithm** to master the following topics:
* High-performance C++ code
* Multithread programming using the **OpenMP** library
* Object-oriented programming


## How to Run the Program

The simulation can be built and run using the provided shell scripts:

### 1. Build the Executable

Use the `build.sh` script to create the necessary CMake files and compile the project. This command will create a `build` directory, configure CMake, and build the executable named `ParticleSimulation`.

```
./build.sh
```
### 2. Run the Simulation

Use the run.sh script to execute the simulation. By default, this script explicitly sets the OpenMP environment variable to run the simulation with 10 threads.
# Sets OMP_NUM_THREADS to 10 and runs the executable

```
./run.sh
```

To change the number of threads, modify the export ```OMP_NUM_THREADS``` line in ```run.sh```.


### Results

At first, I tried with ```N=10``` particles using both a single thread and ten threads. I perceived almost no difference between the two simulations.

Then I tried with ```N=1000```. In this case, the ```O(N2)``` loop sensibly increased the number of iterations. The simulation run with a single thread seemed almost static, while with ten threads, the particles' motions were clearly visible.

### Possible Further Implementations

    *It would be possible to use a ***DOP (Data-Oriented Programming)*** paradigm to achieve even better performance.

    *It would be possible to try to accelerate the simulation by exploiting a ***GPU with CUDA*** acceleration.

    *Implement better and more quantitative performance metrics, though this is not that interesting right now.