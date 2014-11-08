void read_in(int maze[MAZE_HEIGHT][MAZE_WIDTH]);

int *available_steps_at(struct Coordinate position, int maze[MAZE_HEIGHT][MAZE_WIDTH]);
int *decode(int possible_steps_code);
int it_is_possible_to_go(int direction, int possible_steps_code);
void add_to_possible_steps(int direction, int possible_steps[MAX_POSSIBLE_STEPS]);
int strip_off_north(int possible_steps_code);
int strip_off_east(int possible_steps_code);
int strip_off_west(int possible_steps_code);
    
void remove_extraneous(int *steps_pointer);
void output_results(int steps_int);
void copy_logs_to_results(FILE *results);