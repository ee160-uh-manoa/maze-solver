maze-solver
===========
to create a solver function for this challenge:
```shell
                                      #create your solver file (e.g. solvers/your_name_or_id.solver)
make SOLVER=zhaol_12345678            #build the program with your solver 
./maze_solver                         #run the program
                                      #the program will output a file named [number_of_steps].result
                                      #if your solver crashed into a wall in the maze, the number of steps will be -1
                                      #if your solver takes more than 999 steps to solve the maze, then number of steps will be 999
```

example command to use during development:
```shell
rm maze_solver;rm -- *.result;make clean;make SOLVER=zhaol_12345678; ./maze_solver simple
```