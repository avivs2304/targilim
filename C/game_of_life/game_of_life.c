#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "game_of_life.h"

/*
 * 		Function initializes the 2d array.
 */

void zero(int grid[HEIGHT][WIDTH]){
	int i;
	int j;
	for(i=0; i<HEIGHT; i++){
		for(j=0;j<WIDTH;j++){
			grid[i][j]=0;
		}
	}
}

/*
 * 		Function checks if the index above hits the border of the grid
 * 		if it does it returns the index of the bottom of the grid (circular 2d array)
 */

int check_height_top(int y){
	if(y-1 < 0){
		return (HEIGHT - 1);
	} else {
		return (y - 1);
	}
}

/*
 * 		Function checks if the index bellow hits the border of the grid
 * 		if it does it returns the index of the top of the grid (circular 2d array)
 */

int check_height_bottom(int y){
	if(y+1 >= HEIGHT){
		return 0;
	} else {
		return (y + 1);
	}
}

/*
 * 		Function checks if the index to the left hits the border of the grid
 * 		if it does it returns the index of the right of the grid (circular 2d array)
 */

int check_width_left(int x){
    if(x-1 < 0){
    	return (WIDTH - 1);
    } else {
        return (x - 1);
    }
}

/*
 * 		Function checks if the index to the right hits the border of the grid
 * 		if it does it returns the index of the left of the grid (circular 2d array)
 */

int check_width_right(int x){
	 if(x+1 >= WIDTH){
		return 0;
	 } else {
		return (x + 1);
	 }
}

/*
 * 		Function checks how many live neighbors there are to a specific cell and returns the value
 */

int live_neighbors(int grid[HEIGHT][WIDTH], int y, int x){
    int count_alive = 0;
    int tmpy = y;
    int tmpx = x;

    /* Get neighbor to the top */
    tmpy=check_height_top(y);
    if (grid[tmpy][x] == 1) count_alive++;
    /* Get neighbor to the bottom */
    tmpy=check_height_bottom(y);
    if (grid[tmpy][x] == 1) count_alive++;
    /* Get neighbor to the left */
    tmpx=check_width_left(x);
    if (grid[y][tmpx] == 1) count_alive++;
    /* Get neighbor to the right */
    tmpx=check_width_right(x);
    if (grid[y][tmpx] == 1) count_alive++;
    /* Get neighbor to the bottom-left */
    tmpy=check_height_bottom(y);
    tmpx=check_width_left(x);
    if (grid[tmpy][tmpx] == 1) count_alive++;
    /* Get neighbor to the bottom-right */
    tmpx=check_width_right(x);
    if (grid[tmpy][tmpx] == 1) count_alive++;
    /* Get neighbor to the top-right */
    tmpy=check_height_top(y);
    if (grid[tmpy][tmpx] == 1) count_alive++;
    /* Get neighbor to the top-left */
    tmpx=check_width_left(x);
    if (grid[tmpy][tmpx] == 1) count_alive++;
    return count_alive;

}

/*
 * 		Function returns 1 or 0 if the cell is alive or not.
 */

int dead_or_alive(int grid[HEIGHT][WIDTH], int i, int j){
	return grid[i][j];
}

/*
 * 		Function prints the grid and updates it with tmp_grid if add==1.
 */

void print_grid_update(int grid[HEIGHT][WIDTH], int tmp_grid[HEIGHT][WIDTH], int add){
	int i;
	int j;
	for(i=0; i<HEIGHT; i++){
		for(j=0; j<WIDTH; j++){
			if(add==1){
				grid[i][j]=tmp_grid[i][j];
			}
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*
 * 		Function runs the game, checks every cell of its neighbors and takes action according to
 * 		the rules of the game. It updates the grid after each run.
 */

void run_game(int grid[HEIGHT][WIDTH], int tmp_grid[HEIGHT][WIDTH]){
	int i;
	int j;
	int z;
	int neighbors=0;
	int am_alive=0;
	for(z=0; z<RUNS; z++){
		for(i=0; i<HEIGHT; i++){
			for(j=0; j<WIDTH; j++){
				neighbors = live_neighbors(grid, i, j);
				am_alive=dead_or_alive(grid, i, j);
				if(neighbors>3){
					tmp_grid[i][j]=0;
				} else {
					if(neighbors == 3 && am_alive==0){
						tmp_grid[i][j]=1;
					} else {
						if(neighbors < 2) {
							tmp_grid[i][j]=0;
						}
					}
				}
			}
		}
		print_grid_update(grid, tmp_grid, 1);
	}
}

/*
 * 		Function fills the grid with values of 1 or 0 (alive or dead) by random
 */

void fill_dead_alive(int grid[HEIGHT][WIDTH]){
	int i;
	int j;
	srand(0);
	for(i=0;i<HEIGHT;i++){
		for(j=0;j<WIDTH;j++){
			grid[i][j]=rand() % 2;
		}
	}

}
int main(int argc, char * argv[]){
	int grid[HEIGHT][WIDTH];
	int tmp_grid[HEIGHT][WIDTH];
	fill_dead_alive(grid);
	zero(tmp_grid);
	print_grid_update(grid, tmp_grid, 0);
	run_game(grid, tmp_grid);
	return 0;
}
