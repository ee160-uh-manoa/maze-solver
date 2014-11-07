#include "maze.h"

void available_steps_at(struct Coordinate position, char possible_steps[MAX_POSSIBLE_MOVES]) {
  printf("available_steps_at()");
}

char verify(char next_step, char possible_moves[MAX_POSSIBLE_MOVES]) {
  printf("verify()");
  return VALID;
}

void perform(char next_step, struct Coordinate *position) {
  printf("perform");
}

int main() {
  int       int_array[ARRAY_MAX];
  char     char_array[ARRAY_MAX];
  float   float_array[ARRAY_MAX];
  double double_array[ARRAY_MAX];
  int       int_table[MAZE_HEIGHT][MAZE_WIDTH];
  char     char_table[MAZE_HEIGHT][MAZE_WIDTH];
  float   float_table[MAZE_HEIGHT][MAZE_WIDTH];
  double double_table[MAZE_HEIGHT][MAZE_WIDTH];
  
  int maze[MAZE_HEIGHT][MAZE_WIDTH]; read_in(maze);
  struct Coordinate position = { .x = STARTING_X_POSITION, .y = STARTING_Y_POSITION };
  FILE *log_file = fopen(DEBUG_FILENAME, "w");
  char step_validness = VALID;
  int steps;
  
  for(steps=1; (steps <= SOLVER_LIMIT) && (step_validness == VALID); steps++) {
    fprintf(log_file, "step: %d\n", steps);
    char possible_steps[MAX_POSSIBLE_MOVES]; available_steps_at(position, possible_steps);
    char next_step = solver(possible_steps,
           int_array,
           char_array,
           float_array,
           double_array,
           int_table,
           char_table,
           float_table,
           double_table,
           log_file);
           
    step_validness = verify(next_step, possible_steps);
    if (step_validness == VALID) {
      perform(next_step, &position);
    }
  }
  remove_extraneous(&steps);
  
  fclose(log_file);
  output_results(steps);
  remove(DEBUG_FILENAME);
  
  return 0;
}