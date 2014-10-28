#include "maze.h"

int initialize(int maze[MAZE_HEIGHT][MAZE_WIDTH]) {
  printf("Initializing maze solver...\n");  
  return 0;
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
}