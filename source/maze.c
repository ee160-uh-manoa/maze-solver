#include "maze.h"

int main() {
  int       int_array[ARRAY_MAX];
  char     char_array[ARRAY_MAX];
  float   float_array[ARRAY_MAX];
  double double_array[ARRAY_MAX];
  int       int_table[MAZE_HEIGHT][MAZE_WIDTH];
  char     char_table[MAZE_HEIGHT][MAZE_WIDTH];
  float   float_table[MAZE_HEIGHT][MAZE_WIDTH];
  double double_table[MAZE_HEIGHT][MAZE_WIDTH];
  
  char possible_moves[MAX_POSSIBLE_MOVES] = { NO_MOVES };  
  int maze[MAZE_HEIGHT][MAZE_WIDTH]; read_in(maze);
  struct Coordinate position = { .x = STARTING_X_POSITION, .y = STARTING_Y_POSITION };
  FILE *log_file = fopen(DEBUG_FILENAME, "w");
  int steps;
  
  for(steps=1; steps <= SOLVER_LIMIT; steps++) {
    fprintf(log_file, "step: %d\n", steps);
    int next_step = solver(possible_moves,
           int_array,
           char_array,
           float_array,
           double_array,
           int_table,
           char_table,
           float_table,
           double_table,
           log_file);
  }
  remove_extraneous(&steps);
  
  fclose(log_file);
  output_results(steps);
  remove(DEBUG_FILENAME);
  
  return 0;
}