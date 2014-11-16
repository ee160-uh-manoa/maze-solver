void read_in(int maze[MAZE_HEIGHT][MAZE_WIDTH], char maze_filename[]);

int *available_steps_at(struct Coordinate position, int maze[MAZE_HEIGHT][MAZE_WIDTH]);
int *decode(int possible_steps_code);
void reset(int possible_steps[MAX_POSSIBLE_STEPS]);
int it_is_possible_to_go(int direction, int possible_steps_code);
void add_to_possible_steps(int direction, int possible_steps[MAX_POSSIBLE_STEPS]);
int strip_off_north(int possible_steps_code);
int strip_off_east(int possible_steps_code);
int strip_off_west(int possible_steps_code);
    
char verify(int next_step, int possible_steps[MAX_POSSIBLE_STEPS]);
void perform(int next_step, struct Coordinate *position);
char check(struct Coordinate position, struct Coordinate destination);

void remove_extraneous(int *steps_pointer);
void output_results(int steps_int);
void copy_logs_to_results(FILE *results);