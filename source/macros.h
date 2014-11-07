#define SOLVER_LIMIT 999
#define SOLVER_LIMIT_DIGITS 3
#define DEBUG_FILENAME "results/debug.log"
#define LINE_MAX 100

#define MAZE_HEIGHT 10
#define MAZE_WIDTH 10
#define ARRAY_MAX MAZE_HEIGHT*MAZE_WIDTH
#define ARRAY_OFFSET -1

#define STARTING_X_POSITION 1
#define STARTING_Y_POSITION 1
#define VALID 'y'
#define INVALID 'n'

#define MAX_POSSIBLE_MOVES 4
#define NO_MOVES          'x'
#define NORTH             'n'
#define EAST              'e'
#define WEST              'w'
#define SOUTH             's'

#define MAX_FILENAME 100

struct Coordinate {
  int x;
  int y;
};
  