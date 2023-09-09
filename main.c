#include <stdio.h>
#include <stdlib.h>

#define TABLE "*#v"
#define WIDTH 50
#define HEIGHT 30

typedef struct {
  int x;
  int y;
} turtle;

/*char *generate_grid(char grid[][WIDTH]);
void print_grid(char grid[][WIDTH]);
char *pen_down(char grid[][WIDTH], turtle *turt, int stroke_size);
char *pen_up(char grid[][WIDTH], turtle *turt, int stroke_size);
char *pen_left(char grid[][WIDTH], turtle *turt, int stroke_size);
char *pen_right(char grid[][WIDTH], turtle *turt, int stroke_size);
char *place_turtle(char grid[][WIDTH], turtle *turt);
*/
char *generate_grid(char grid[][WIDTH]){
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      grid[i][j] = TABLE[0];
    }
  }
  return *grid;
}

void print_grid(char grid[][WIDTH]){
  for(int i = 0; i < HEIGHT; i++){
    for(int j = 0; j < WIDTH; j++){
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
}

char (*pen_down(char grid[][WIDTH], turtle *turt, int stroke_size))[WIDTH]{
  for(int i = 0; i < stroke_size; i++){
    grid[turt->y][turt->x] = TABLE[1];
    turt->y += 1;
  }
  grid[turt->y][turt->x] = TABLE[2];
  return grid;
}

char (*pen_up(char grid[][WIDTH], turtle *turt, int stroke_size))[WIDTH]{
  for(int i = 0; i < stroke_size; i++){
    grid[turt->y][turt->x] = TABLE[1];
    turt->y -= 1;
  }
  grid[turt->y][turt->x] = TABLE[2];
  return grid;
}

char (*pen_left(char grid[][WIDTH], turtle *turt, int stroke_size))[WIDTH]{
  for(int i = 0; i < stroke_size; i++){
    grid[turt->y][turt->x] = TABLE[1];
    turt->x -= 1;
  }
  grid[turt->y][turt->x] = TABLE[2];
  return grid;
}

char (*pen_right(char grid[][WIDTH], turtle *turt, int stroke_size))[WIDTH]{
  for(int i = 0; i < stroke_size; i++){
    grid[turt->y][turt->x] = TABLE[1];
    turt->x += 1;
  }
  grid[turt->y][turt->x] = TABLE[2];
  return grid;
}

char *place_turtle(char grid[][WIDTH], turtle *turt){
  grid[turt->y][turt->x] = TABLE[2];
  return *grid;
}

void get_player_input(turtle *turt){
  char (*grid)[WIDTH] = malloc(sizeof(char) * WIDTH * HEIGHT);
  generate_grid(grid);
  place_turtle(grid, turt);
  system("clear");
  print_grid(grid);

  char *input = malloc(sizeof(char));
  while(*input != 'S'){
    scanf("%c", input);
    switch(*input){
      case 'U':
        grid = pen_up(grid, turt, 4);
        break;
      case 'D':
        grid = pen_down(grid, turt, 4);
        break;
      case 'L':
        grid = pen_left(grid, turt, 4);
        break;
      case 'R':
        grid = pen_right(grid, turt, 4);
        break;
    } 
    place_turtle(grid, turt);
    system("clear");
    
    print_grid(grid);
  }
  free(input);
}

int main(){
  turtle *turt = malloc(sizeof(turtle));
  turt->x = WIDTH/2;
  turt->y = HEIGHT/2;
  get_player_input(turt);

  free(turt);
  return 0;
}
