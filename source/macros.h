#define TRUE 1
#define FALSE 0
#define ARRAY_OFFSET -1
#define MAX_FILENAME 100

#define SOLVER_LIMIT 999
#define SOLVER_LIMIT_DIGITS 3
#define DEBUG_FILENAME "results/debug.log"
#define LINE_MAX 100

#define MAZE_HEIGHT 10
#define MAZE_WIDTH 10
#define ARRAY_MAX MAZE_HEIGHT*MAZE_WIDTH
struct Coordinate {
  int horizontal;
  int vertical;
};

#define STARTING_HORIZONTAL_POSITION 1
#define STARTING_VERTICAL_POSITION 1
#define VALID 'y'
#define INVALID 'n'

#define MAX_POSSIBLE_STEPS 4
#define XOOO 1000 //1000
#define OXOO 100  //0100
#define OOXO 10   //0010
#define OOOX 1    //0001
enum Directions {
  NORTH,
  EAST,
  WEST,
  SOUTH,
  NO_MOVES
};