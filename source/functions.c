#include "maze.h"

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

void remove_extraneous(int *steps_pointer) {
  (*steps_pointer)--; // to account for the extra increment after for loop completion
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