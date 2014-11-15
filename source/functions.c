#include "maze.h"

void read_in(int maze[MAZE_HEIGHT][MAZE_WIDTH], char maze_name[]) {
  char maze_filename[MAX_FILENAME] = "mazes/";
  int row, column;
  strcat(maze_filename, maze_name);
  strcat(maze_filename, ".maze");
  FILE *input_file_pointer = fopen(maze_filename, "r");
  
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

int *available_steps_at(struct Coordinate position, int maze[MAZE_HEIGHT][MAZE_WIDTH]) {
  int possible_steps_code = maze[position.vertical+ARRAY_OFFSET][position.horizontal+ARRAY_OFFSET];
  return decode(possible_steps_code);
}

int *decode(int possible_steps_code) {
  static int possible_steps[MAX_POSSIBLE_STEPS];
  reset(possible_steps);
  
  if (it_is_possible_to_go(NORTH, possible_steps_code)) {
    add_to_possible_steps(NORTH, possible_steps);
  }
  if (it_is_possible_to_go(EAST, possible_steps_code)) {
    add_to_possible_steps(EAST, possible_steps);
  }
  if (it_is_possible_to_go(WEST, possible_steps_code)) {
    add_to_possible_steps(WEST, possible_steps);
  }
  if (it_is_possible_to_go(SOUTH, possible_steps_code)) {
    add_to_possible_steps(SOUTH, possible_steps);
  }
  return possible_steps;
}

void reset(int possible_steps[MAX_POSSIBLE_STEPS]) {
  int counter;
  for (counter=1; counter<=4; counter++) {
    possible_steps[counter+ARRAY_OFFSET] = NO_MOVES;
  }
}

int it_is_possible_to_go(int direction, int possible_steps_code) {
  int direction_is_valid;
  switch (direction) {
    case NORTH:
      if (possible_steps_code >= XOOO) {
        direction_is_valid = TRUE;
      } else {
        direction_is_valid = FALSE;
      }
      break;
    case EAST:
      possible_steps_code = strip_off_north(possible_steps_code); // ensures 0xyz
      if (possible_steps_code >= OXOO) {
        direction_is_valid = TRUE;
      } else {
        direction_is_valid = FALSE;
      }
      break;
    case WEST:
      possible_steps_code = strip_off_north(possible_steps_code); // ensures 0xyz
      possible_steps_code = strip_off_east(possible_steps_code);  // ensures 00yz
      if (possible_steps_code >= OOXO) {
        direction_is_valid = TRUE;
      } else {
        direction_is_valid = FALSE;
      }
      break;
    case SOUTH:
      possible_steps_code = strip_off_north(possible_steps_code); // ensures 0xyz
      possible_steps_code = strip_off_east(possible_steps_code);  // ensures 00yz
      possible_steps_code = strip_off_west(possible_steps_code);  // ensures 000z
      if (possible_steps_code == OOOX) {
        direction_is_valid = TRUE;
      } else {
        direction_is_valid = FALSE;
      }
      break;
    default:
      printf("An unrecognized direction was found\n");
      break;
  }
  return direction_is_valid;
}

void add_to_possible_steps(int direction, int possible_steps[MAX_POSSIBLE_STEPS]) {
  switch (direction) {
    case NORTH:
      possible_steps[NORTH] = NORTH;
      break;
    case EAST:
      possible_steps[EAST] = EAST;
      break;
    case WEST:
      possible_steps[WEST] = WEST;
      break;
    case SOUTH:
      possible_steps[SOUTH] = SOUTH;
      break;
    default:
      // do nothing
      break;
  }
}

int strip_off_north(int possible_steps_code) {
  return possible_steps_code % XOOO; // 1xyz -> 0xyz
}

int strip_off_east(int possible_steps_code) {
  return possible_steps_code % OXOO; // x1yz -> x0yz
}

int strip_off_west(int possible_steps_code) {
  return possible_steps_code % OOXO; // xy1z -> xy0z
}

void remove_extraneous(int *steps_pointer) {
  (*steps_pointer)--; // to account for the extra increment after for loop completion
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

char check(struct Coordinate *position, struct Coordinate *destination) {
  char destination_reached = NOT_REACHED;
  if (((*position).horizontal == (*destination).horizontal) &&
    ((*position).horizontal == (*destination).horizontal)) {
    destination_reached = REACHED;    
  }
  return destination_reached;
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