#include "maze.h"

void initialize(int maze[MAZE_HEIGHT][MAZE_WIDTH]) {
  printf("Initializing maze solver...\n");  
  read_in(maze);
}

void read_in(int maze[MAZE_HEIGHT][MAZE_WIDTH]) {
  int row, column;
  FILE *input_file_pointer = fopen("mazes/maze.input", "r");
  
  if (input_file_pointer != NULL) {
    for (row=1; row<=MAZE_HEIGHT; row++) {
      for (column=1; column<=MAZE_WIDTH; column++) {
        fscanf(input_file_pointer, "%d", &maze[row+ARRAY_OFFSET][column+ARRAY_OFFSET]);
      }
    }
    fclose(input_file_pointer);
  } else {
    printf("maze file failed to open\n");
  }
}

void output_results(int steps_int) {
  char steps_string[SOLVER_LIMIT_DIGITS];
  snprintf(steps_string, MAX_FILENAME, "%d", steps_int);  
  char filename[SOLVER_LIMIT_DIGITS];
  strcat(filename, steps_string);
  strcat(filename, ".result");
  
  FILE *results = fopen(filename, "w");
  copy_logs_to_results(results);
  fclose(results);
}

void copy_logs_to_results(FILE *results) {
  FILE *logs = fopen(DEBUG_FILENAME, "r");
  char temp[LINE_MAX];
  while (fgets(temp, sizeof temp, logs) != NULL) {
    fputs(temp, results);
  }
  fclose(logs);
}