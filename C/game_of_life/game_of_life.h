
#ifndef GAME_OF_LIFE_H_
#define GAME_OF_LIFE_H_

/*
 * 		Defines the height and width of the grid and how many runs to performs.
 */

#define HEIGHT 50
#define WIDTH 100
#define RUNS 1000


/*
 * 		Function declarations. Function comments in source file.
 */

int dead_or_alive(int grid[HEIGHT][WIDTH], int i, int j);
void zero(int grid[HEIGHT][WIDTH]);
int check_height_top(int y);
int check_height_bottom(int y);
int check_width_left(int x);
int check_width_right(int x);
int live_neighbors(int grid[HEIGHT][WIDTH], int y, int x);
int dead_or_alive(int grid[HEIGHT][WIDTH], int i, int j);
void print_grid_update(int grid[HEIGHT][WIDTH], int tmp_grid[HEIGHT][WIDTH], int add);
void run_game(int grid[HEIGHT][WIDTH], int tmp_grid[HEIGHT][WIDTH]);
void fill_dead_alive(int grid[HEIGHT][WIDTH]);

#endif /* GAME_OF_LIFE_H_ */
