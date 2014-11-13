#include "maze.h"

char solver(int possible_steps[MAX_POSSIBLE_STEPS],
    struct Coordinate position,
    struct Coordinate destination,
    int       int_array[ARRAY_MAX],
    char     char_array[ARRAY_MAX],
    float   float_array[ARRAY_MAX],
    double double_array[ARRAY_MAX],
    int       int_table[MAZE_WIDT][MAZE_WIDTH],
    char     char_table[MAZE_WIDTH][MAZE_WIDTH],
    float   float_table[MAZE_WIDTH][MAZE_WIDTH],
    double double_table[MAZE_WIDTH][MAZE_WIDTH],
    FILE *log_file) {
  
  // the insides of this entire function should be rewritten
    
  fprintf(log_file, "deciding next step...\n"); // you can print out to a debug/log file if you need to
  int_array[0]++;
  int next_step = NORTH;
  
  // this switch is hardcoding the path for the simple maze and will fail for other mazes
  switch (int_array[0]) {
    case 1:
      next_step = EAST;
      break;
    case 2:
      next_step = SOUTH;
      break;
    case 3:
      next_step = EAST;
      break;
    case 4:
      next_step = SOUTH;
      break;
    case 5:
      next_step = SOUTH;
      break;
    case 6:
      next_step = SOUTH;
      break;
    case 7:
      next_step = WEST;
      break;
    case 8:
      next_step = WEST;
      break;
    case 9:
      next_step = SOUTH;
      break;
    case 10:
      next_step = SOUTH;
      break;
    case 11:
      next_step = EAST;
      break;
    case 12:
      next_step = EAST;
      break;
    case 13:
      next_step = SOUTH;
      break;
    case 14:
      next_step = SOUTH;
      break;
    case 15:
      next_step = EAST;
      break;
    case 16:
      next_step = EAST;
      break;
    case 17:
      next_step = NORTH;
      break;
    case 18:
      next_step = EAST;
      break;
    case 19:
      next_step = EAST;
      break;
    case 20:
      next_step = NORTH;
      break;
    case 21:
      next_step = NORTH;
      break;
    case 22:
      next_step = EAST;
      break;
    case 23:
      next_step = SOUTH;
      break;
    case 24:
      next_step = SOUTH;
      break;
    case 25:
      next_step = SOUTH;
      break;
    case 26:
      next_step = SOUTH;
      break;
    case 27:
      next_step = EAST;
      break;
    case 28:
      next_step = EAST;
      break;
  }
  return next_step;
}