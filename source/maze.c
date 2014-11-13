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
  
  int maze[MAZE_HEIGHT][MAZE_WIDTH]; read_in(maze);
  struct Coordinate position    = { .horizontal = STARTING_HORIZONTAL_POSITION, .vertical = STARTING_VERTICAL_POSITION }; // http://stackoverflow.com/questions/330793/how-to-initialize-a-struct-in-ansi-c
  struct Coordinate destination = { .horizontal = ENDING_HORIZONTAL_POSITION, .vertical = ENDING_VERTICAL_POSITION };
  FILE *log_file = fopen(DEBUG_FILENAME, "w");
  char step_validness = VALID;
  char destination_reached = NOT_REACHED;
  int steps;
  
  for(steps=1; (steps <= SOLVER_LIMIT) &&
    (step_validness == VALID) &&
    (destination_reached != REACHED); steps++) {
    fprintf(log_file, "step: %d\n", steps);
    fprintf(log_file, "position.horizontal: %d, position.vertical: %d\n", position.horizontal, position.vertical);
    // I find passing arrays to functions and working directly on the array more intuitive and easier to read,
    // but I want to highlight the fact that returning pointers from functions is also an option
    // http://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm
    int *possible_steps = available_steps_at(position, maze); // possible_steps points to an array of 4 elements (int possible_steps[4])
    int next_step = solver(possible_steps,
      position,
      destination,
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
      destination_reached = check(&position, &destination);
    }
  }
  if (step_validness == VALID) {
    fprintf(log_file, "Maze solved!");
    remove_extraneous(&steps);
  } else {
    steps = CRASHED_INTO_WALL;
  }
  
  fclose(log_file);
  output_results(steps);
  remove(DEBUG_FILENAME);
  
  return 0;
}