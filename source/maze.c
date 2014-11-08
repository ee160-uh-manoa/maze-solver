#include "maze.h"

char check(struct Coordinate *position, struct Coordinate *destination) {
  char destination_reached = NOT_REACHED;
  if (((*position).horizontal == (*destination).horizontal) &&
    ((*position).horizontal == (*destination).horizontal)) {
    destination_reached = REACHED;    
  }
  return destination_reached;
}

char verify(int next_step, int possible_steps[MAX_POSSIBLE_STEPS]) {
  int step_found = NOT_FOUND;
  int counter;
  for (counter=1; counter<=MAX_POSSIBLE_STEPS; counter++) {
    if (possible_steps[counter+ARRAY_OFFSET] == next_step) {
      step_found = FOUND;
    }
  }
  return step_found;
}

void perform(int next_step, struct Coordinate *position) {
  switch (next_step) {
    case NORTH:
      (*position).vertical--;
      break;
    case EAST:
      (*position).horizontal++;
      break;
    case WEST:
      (*position).horizontal--;
      break;
    case SOUTH:
      (*position).vertical++;
      break;
  }
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
    printf("position.horizontal: %d, position.vertical: %d\n", position.horizontal, position.vertical);
    // I find passing arrays to functions and working directly on the array more intuitive and easier to read,
    // but I want to highlight the fact that returning pointers from functions is also an option
    // http://www.tutorialspoint.com/cprogramming/c_return_arrays_from_function.htm
    int *possible_steps = available_steps_at(position, maze); // possible_steps points to an array of 4 elements (int possible_steps[4])
    int next_step = solver(possible_steps,
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
      printf("VALID\n");
      perform(next_step, &position);
      destination_reached = check(&position, &destination);
    } else {
      printf("NOT VALID\n");
    }
  }
  remove_extraneous(&steps);
  
  fclose(log_file);
  output_results(steps);
  remove(DEBUG_FILENAME);
  
  return 0;
}