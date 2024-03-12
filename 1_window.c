#include "includes/so_long.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h> // for exit()

// static void get_nbr_rows(char *map_file, t_mlx_data *game)
// {
//     int     cnt;
//     int     map_fd;
//     char    *tmp;

//     cnt = 0;
//     map_fd = open(map_file, O_RDONLY);
//     if (map_fd == -1)
//     {
//         printf("line44");
// 		    notify(game, OPEN_MAP_FILE_ERR);
//     }
//     tmp = get_next_line(map_fd);
//     while (tmp)
//     {
//         cnt += 1;
//         free(tmp);
//         tmp = get_next_line(map_fd);
//         printf("here");
//     }
//     if (cnt == 0)
//     {
//         printf("line57");
// 		    notify(game, EMPTY_MAP_FILE);
//     }
//     game->map.rows = cnt;
//     close(map_fd);
//     printf("%s", map_file);
// }

// void get_lines(char *map_file, t_mlx_data *game)
// {
//     int map_fd;
//     int i;

//     map_fd = open(map_file, O_RDONLY);
//     if (map_fd == -1)
//     {
//         printf("line72");
// 		    notify(game, OPEN_MAP_FILE_ERR);
//     }
//     i = 0;
//     while (i < game->map.rows)
//     {
//         game->map.map[i++] = get_next_line(map_fd);
//         if (game->map.map[i] == NULL)
//         {
//             printf("line81");
//             notify(game, EMPTY_MAP_FILE);
//         }
//         i += 1;
//     }
//     game->map.map[i] = '\0';
//     close(map_fd);
//     i = 0;
//     while (i < (game->map.rows - 1))
//     {
//         game->map.map[i] = ft_strtrim(game->map.map[i], "\n");
//         if (game->map.map[i])
//         {
//             printf("line94");
// 		      	notify(game, MALLOC_ERR);
//         }
//         i += 1;
//     }
//     game->map.columns = ft_strlen(game->map.map[0]);
//     printf("here");
// }

// void    get_map(char *map_file, t_mlx_data *game)
// {
// 	if (!is_ber_file(map_file))
//   {
//       printf("line22");
// 	  	notify(game, INVALID_MAP_FILE);
//   }
//   get_nbr_rows(map_file, game);
// 	game->map.map = malloc((game->map.rows + 1) * sizeof(char *));
// 	if (!game->map.map)
// 	  	notify(game, MALLOC_ERR);
// 	get_lines(map_file, game);
//   printf("%s", map_file);
// }


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// #define TILE_SIZE 64
// #define IMAGE_SIZE 64
// #define MAP_WIDTH 4
// #define MAP_HEIGHT 4

// typedef struct s_vars {
//     void *mlx;
//     void *win;
//     void *images[256]; // Assuming ASCII characters up to 255
//     char *map[MAP_HEIGHT];
//     int width;
//     int height;
//     int x;
//     int y;
// } t_vars;

// void draw_map(t_vars *vars)
// {
//     int row = 0;
//     while (row < vars->height)
//     {
//         int col = 0;
//         while (col < vars->width)
//         {
//             unsigned char element = vars->map[row][col];

//             if (element < 256 && vars->images[element] != NULL)
//             {
//                 mlx_put_image_to_window(vars->mlx, vars->win, vars->images[element], col * 64, row * 64);
//             }

//             col++;
//         }
//         row++;
//     }
// }

// int load_images(t_vars *vars)
// {
//     char *imagePaths[] = {
//         "img/wall.xpm",  // Element 0
//         "img/floor.xpm", // Element 1
//         // Add more paths for other elements
//     };

//     int i = 0;
//     while (i < sizeof(imagePaths) / sizeof(imagePaths[0]))
//     {
//         vars->images[i] = mlx_xpm_file_to_image(vars->mlx, imagePaths[i], 64, 64);
//         if (vars->images[i] == NULL)
//         {
//             printf("Error: Cannot load image %d.\n", i);
//             return 0;
//         }
//         i++;
//     }
//     return 1;
// }

// void load_map(t_vars *vars)
// {
//     vars->width = MAP_WIDTH;
//     vars->height = MAP_HEIGHT;

//     // Example map with 4 rows
//     vars->map[0] = "0010";
//     vars->map[1] = "1120";
//     vars->map[2] = "0100";
//     vars->map[3] = "0003";
// }

// void initialize_vars(t_vars *vars)
// {
//     vars->mlx = mlx_init();
//     vars->win = mlx_new_window(vars->mlx, TILE_SIZE * MAP_WIDTH, TILE_SIZE * MAP_HEIGHT, "MiniLibX Example");
//     vars->x = 0;
//     vars->y = 0;
// }

// int main(void)
// {
//     t_vars vars;

//     initialize_vars(&vars);

//     if (!load_images(&vars))
//     {
//         printf("not loading");
//         return 1;
//     }

//     load_map(&vars);
//     draw_map(&vars);

//     mlx_loop(&vars);

//     // cleanup(&vars);

//     return 0;
// }

//!using .ber output

// typedef struct s_vars {
//     void *mlx;
//     void *win;
//     char **map;
//     int width;
//     int height;
// } t_vars;

// void draw_map(t_vars *vars)
// {
//     int x, y;

//     for (y = 0; y < vars->height; y++)
//     {
//         for (x = 0; x < vars->width; x++)
//         {
//             // Assuming characters in the map represent different elements
//             char element = vars->map[y][x];

//             // Adjust the drawing based on the element
//             if (element == 'W') // Wall
//                 mlx_pixel_put(vars->mlx, vars->win, x * TILE_SIZE, y * TILE_SIZE, 0xFFFFFF);
//             else if (element == 'P') // Player
//                 mlx_pixel_put(vars->mlx, vars->win, x * TILE_SIZE, y * TILE_SIZE, 0xFF0000);
//             // Add more conditions for other elements
//         }
//     }
// }

// int read_map_from_file(char *filename, t_vars *vars)
// {
//     FILE *file = fopen(filename, "r");
//     if (file == NULL)
//     {
//         printf("Error: Cannot open file.\n");
//         return 0;
//     }

//     // Read map dimensions
//     fscanf(file, "%d %d\n", &vars->width, &vars->height);

//     // Allocate memory for the map
//     vars->map = (char **)malloc(vars->height * sizeof(char *));
//     for (int i = 0; i < vars->height; i++)
//     {
//         vars->map[i] = (char *)malloc((vars->width + 1) * sizeof(char));

//         // Read one line character by character
//         for (int j = 0; j < vars->width; j++)
//         {
//             int ch = fgetc(file);
//             if (ch == EOF || ch == '\n')
//                 break;

//             vars->map[i][j] = (char)ch;
//         }
//         vars->map[i][vars->width] = '\0'; // Null-terminate the string
//     }

//     fclose(file);
//     return 1;
// }

// int main(int argc, char **argv)
// {
//     if (argc != 2)
//     {
//         printf("Usage: %s <map.ber>\n", argv[0]);
//         return 1;
//     }

//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 800, 600, "MiniLibX Example");

//     if (!read_map_from_file(argv[1], &vars))
//         return 1;

//     draw_map(&vars);

//     mlx_loop(vars.mlx);

//     return 0;
// }

//!draw xpm key press WASD

// typedef struct s_vars {
//     void *mlx;
//     void *win;
//     void *img;
//     char *addr;
//     int bits_per_pixel;
//     int line_length;
//     int endian;
//     int x;
//     int y;
// } t_vars;

// void draw_image(t_vars *vars)
// {
//     mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
// }

// int key_press(int keycode, t_vars *vars)
// {
//     mlx_clear_window(vars->mlx, vars->win);

//     if (keycode == 53) // Escape key
//         exit(0);
//     else if (keycode == W) // Left arrow key
//         vars->x -= 10;
//     else if (keycode == D) // Right arrow key
//         vars->x += 10;
//     else if (keycode == S) // Down arrow key
//         vars->y += 10;
//     else if (keycode == A) // Up arrow key
//         vars->y -= 10;

//     draw_image(vars);
//     return (0);
// }

// int main(void)
// {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 800, 600, "MiniLibX Example");
//     vars.img = mlx_xpm_file_to_image(vars.mlx, "img/coin.xpm", &vars.x, &vars.y);
//     vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
//     vars.x = 100;
//     vars.y = 100;

//     mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);

//     draw_image(&vars);

//     mlx_loop(vars.mlx);

//     return (0);
// }

/*//! move with press WASD*/

typedef struct s_vars {
    void *mlx;
    void *win;
    int x;
    int y;
} t_vars;

void draw_square(t_vars *vars)
{
    int i, j;

    i = 0;
    while (i < 50)
    {
        j = 0;
        while (j < 50)
        {
            mlx_pixel_put(vars->mlx, vars->win, vars->x + i, vars->y + j, 0xFFFFFF);
            j++;
        }
        i++;
    }
}

int key_press(int keycode, t_vars *vars)
{
    mlx_clear_window(vars->mlx, vars->win);

    if (keycode == 53) // Escape key
        exit(0);
    else if (keycode == W) // Left arrow key
        vars->x -= 10;
    else if (keycode == D) // Right arrow key
        vars->x += 10;
    else if (keycode == S) // Down arrow key
        vars->y += 10;
    else if (keycode == A) // Up arrow key
        vars->y -= 10;

    draw_square(vars);
    return (0);
}

int main(void)
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 600, "MiniLibX Example");
    vars.x = 100;
    vars.y = 100;

    mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);

    draw_square(&vars);

    mlx_loop(vars.mlx);

    return (0);
}

/*//! draw square*/

// typedef struct s_vars {
//     void *mlx;
//     void *win;
//     void *img;
//     char *addr;
//     int bits_per_pixel;
//     int line_length;
//     int endian;
//     int x;
//     int y;
// } t_vars;

// void draw_square(t_vars *vars)
// {
//     int i, j;
//     int color = 0xFFFFFF;

//     i = 0;
//     while (i < 50)
//     {
//         j = 0;
//         while (j < 50)
//         {
//             *(int *)(vars->addr + (vars->bits_per_pixel / 8) * (i + vars->x) + vars->line_length * (j + vars->y)) = color;
//             j++;
//         }
//         i++;
//     }
// }

// void update_position(t_vars *vars)
// {
//     // Update the position (example: move to the right)
//     vars->x += 2;
//     if (vars->x > 750) // Reset position if it goes beyond the window width
//         vars->x = 0;
// }

// int main(void)
// {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 800, 600, "MiniLibX Example");
//     vars.img = mlx_new_image(vars.mlx, 800, 600);
//     vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length, &vars.endian);
//     vars.x = 100;
//     vars.y = 100;

//     while (1)
//     {
//         mlx_clear_window(vars.mlx, vars.win);

//         update_position(&vars);
//         draw_square(&vars);

//         mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
//         mlx_do_sync(vars.mlx); // Synchronize with the X server

//         usleep(16000); // Sleep for a short duration to control the speed of movement
//     }

//     mlx_loop(vars.mlx);

//     return (0);
// }

//! bits auto change position

// typedef struct s_vars {
//     void *mlx;
//     void *win;
//     int x;
//     int y;
//     int bits_per_pixel;
//     char    *addr;
//     int line_length;
// } t_vars;

// void draw_square(t_vars *vars)
// {
//     int i, j;

//     i = 0;
//     j = 0;
//     while (i < 50 && j < 50) // i is HEiGHT
//     {
//         mlx_pixel_put(vars->mlx, vars->win, vars->x + i, vars->y + j, 0xFFFFFF);
//         j++;
//     }
//     i++;
// }

// void update_position(t_vars *vars)
// {
//     // Update the position (example: move to the right)
//     vars->x += 1;
//     if (vars->x > 800) // Reset position if it goes beyond the window width
//         vars->x = 100;
//     // Update the position (example: move to the left)
//     // vars->x -= 2;
//     // if (vars->x < 100)
//     //     vars->x = 800;
// }

// int main(void)
// {
//     t_vars vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 800, 600, "MiniLibX Example");
//     vars.x = 100;
//     vars.y = 100;

//     while (1)
//     {
//         mlx_clear_window(vars.mlx, vars.win);

//         update_position(&vars);
//         draw_square(&vars);

//         mlx_do_sync(vars.mlx); // Synchronize with the X server

//         usleep(10000); // Sleep for a short duration to control the speed of movement
//     }
//     mlx_loop(vars.mlx);

//     return (0);
// }

// //!/*put 1 color when press botton*/

// typedef struct s_img
// {
//     void    *img_ptr;
//     char    *img_pixel_ptr;
//     int     bits_per_pixel;
//     int     endian;
//     int     line_len;
// }           t_img;

// typedef struct s_var
// {
//     void    *mlx_ptr;
//     void    *win_ptr;
//     t_img   img;
// }           t_var;

// void    my_pixel_put(t_img *img, int x, int y, int color)
// {
//     int offset;

//     offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
//     *((unsigned int *)(offset + img->img_pixel_ptr)) = color;
// }

// void    color_screen(t_var *data, int color)
// {
//     for (int y = 0; y < SiDE_LEN; ++y)
//     {
//         for (int x = 0; x < SiDE_LEN; ++x)
//         {
//             my_pixel_put(&data->img, x, y, color);
//         }
//     }
// }

// int f(int keysym, t_var *data)
// {
//     if (keysym == XK_r)
//         color_screen(data, 0xff0000);
//     if (keysym == XK_g)
//         color_screen(data, 0xff00);
//     if (keysym == XK_b)
//         color_screen(data, 0xff);
//     else if (keysym == XK_Escape)
//         exit(1);
//     mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
//     return (0);
// }

// int main()
// {
//     t_var   vars;

//     vars.mlx_ptr = mlx_init();
//     vars.win_ptr = mlx_new_window(vars.mlx_ptr, SiDE_LEN, SiDE_LEN, "my win");
//     vars.img.img_ptr = mlx_new_image(vars.mlx_ptr, SiDE_LEN, SiDE_LEN);
//     vars.img.img_pixel_ptr = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, &vars.img.line_len, &vars.img.endian);

//     printf("line_len %d <-> SiDE_LEN %d\n" "bpp %d\n" "endian %d\n", vars.img.line_len, SiDE_LEN, vars.img.bits_per_pixel, vars.img.endian);
//     mlx_key_hook(vars.win_ptr, f, &vars);
//     mlx_loop(vars.mlx_ptr);
//     return (0);
// }

//!/*string ranning*/
// // Global variable to track the position of a rectangle
// int rect_x = 50;

// // Function to draw a rectangle
// void draw_rectangle(void *mlx, void *win) 
// {
//     mlx_clear_window(mlx, win); // Clear the window

//     // Draw a rectangle at the updated position
//     mlx_string_put(mlx, win, rect_x, 100, 0xFFFFFF, "mai");
// }

// // Loop hook callback function
// int loop_hook(void *param)
// {
//     void **mlx_and_win = (void **)param;
//     void *mlx = mlx_and_win[0];
//     void *win = mlx_and_win[1];

//     // Update the position of the rectangle
//     rect_x = (rect_x + 5) % (WiDTH - 50);

//     // Call the function to draw the rectangle
//     draw_rectangle(mlx, win);

//     return 0;
// }

// int main()
// {
//     void *mlx;
//     void *win;
//     void *mlx_and_win[2];

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, WiDTH, HEiGHT, "MiniLibX Loop Hook");

//     // Set up the loop hook
//     mlx_and_win[0] = mlx;
//     mlx_and_win[1] = win;
//     mlx_loop_hook(mlx, &loop_hook, mlx_and_win);

//     // Call the initial draw
//     draw_rectangle(mlx, win);
//     mlx_hook(data->win_ptr, DESTROY_NOTiFY_EVENT, (1L << 17),
// 		quit_game, game);
//     // Main loop
//     mlx_loop(mlx);

//     return 0;
// }

//!/*clik mouse handle*/

// int handle_key_press(int key, void *param)
// {
//     (void)param;

//     if (key == XK_Escape)
//     {
//         printf("Escape key pressed. Exiting...\n");
//         exit(0);  // or perform other actions as needed
//     }
//     return 0;
// }

// int handle_mouse_press(int button, int x, int y, void *param)
// {
//     (void)param; 

//     if (button == 1 && x >= WiDTH - 20 && x <= WiDTH && y >= 0 && y <= 20)
//     {
//         // X button clicked (from x = WiDTH - 20 to x = WiDTH, and y = 0 to y = 20)
//         printf("X button clicked. Exiting...\n");
//         exit(0);  // or perform other actions as needed
//     }

//     return 0;
// }

// int main()
// {
//     void *mlx;
//     void *win;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, WiDTH, HEiGHT, "MiniLibX responding to buttons");

//     // Set up the hook for the KeyPress event
//     mlx_key_hook(win, &handle_key_press, NULL);

//     // Set up the hook for the MousePress event
//     mlx_mouse_hook(win, &handle_mouse_press, NULL);

//     // Main loop
//     mlx_loop(mlx);

//     return 0;
// }

//!/*clik mouse*/

// int handle_mouse_press(int button, int x, int y, void *param)
// {
//     (void)param;  // To silence the unused parameter warning

//     if (button == 1)
//     {
//         // Left mouse button (X button on both macOS and Linux)
//         printf("Left mouse button pressed at (%d, %d)\n", x, y);
//     }
//     else if (button == 2)
//     {
//         // Middle mouse button
//         printf("Middle mouse button pressed at (%d, %d)\n", x, y);
//     }
//     else if (button == 3)
//     {
//         // Right mouse button
//         printf("Right mouse button pressed at (%d, %d)\n", x, y);
//     }
//     else if (button == 4)
//     {
//         printf("Scroll mouse up button at (%d, %d)\n", x, y);
//     }
//     else if (button == 5)
//     {
//         printf("Scroll mouse down button at (%d, %d)\n", x, y);
//     }
//     return 0;
// }

// int main()
// {
//     void *mlx;
//     void *win;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, WiDTH, HEiGHT, "MiniLibX Window");

//     // Set up the hook for the MousePress event
//     mlx_mouse_hook(win, &handle_mouse_press, NULL);

//     // Main loop
//     mlx_loop(mlx);

//     return 0;
// }

//!/*put color in window*/

// int main()
// {
//     void *mlx;
//     void *win;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, WiDTH, HEiGHT, "MiniLibX Colored Window");

//     // Draw a red rectangle
//     int x, y;
//     int rect_width = 200;
//     int rect_height = 150;

//     // Set color values (Red, Green, Blue)
//     int color = 0xFF0000; // Red color in hexadecimal

//     for (x = 0; x < rect_width; x++)
//     {
//         for (y = 0; y < rect_height; y++)
//         {
//             mlx_pixel_put(mlx, win, WiDTH / 2 - rect_width / 2 + x, HEiGHT / 2 - rect_height / 2 + y, color);
//         }
//     }
//     // Run the main loop
//     mlx_loop(mlx);

//     return 0;
// }

//!/*put image in window*/

// int main()
// {
//     void *mlx;
//     void *win;
//     void *image;
//     int width, height;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, WiNDOW_WiDTH, WiNDOW_HEiGHT, "MiniLibX image Example");

//     // Load the XPM image
//     image = mlx_xpm_file_to_image(mlx, "img/Furnitures_v1.xpm", &width, &height);

//     if (image == NULL)
//     {
//         // Handle error if image loading fails
//         printf("Error: Could not load the image.\n");
//         return -1;
//     }

//     // Draw the image on the window
//     mlx_put_image_to_window(mlx, win, image, 0, 0);

//     // Run the main loop
//     mlx_loop(mlx);

//     return 0;
// }

//!/*exit press ESC bottom press X on tap window*/

// typedef struct s_mlx_data
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// }			t_mlx_data;

// int	quit_game(t_mlx_data *game)
// {
//     printf("the %p key has been pressed in function quit_game\n\n", game);
// 	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
// 	mlx_destroy_display(game->mlx_ptr);
//     free(game->mlx_ptr);
// 	exit(1);
// }

// int	handle_input(int keysym, t_mlx_data *data)
// {
// 	if (keysym == XK_Escape)
// 	{
// 		printf("the %d key (esc) has been pressed\n\n", keysym);
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		mlx_destroy_display(data->mlx_ptr);
// 		free(data->mlx_ptr);
// 		exit(1);
// 	}
// 	printf("the %d key has been pressed\n\n", keysym);
// 	return(0);
// }
// void	hook_n_run(t_mlx_data *game)
// {
// 	// mlx_hook(game->win_ptr, KEYPRESS_EVENT, (1L << 0), on_press, game);
// 	mlx_hook(game->win_ptr, DESTROY_NOTiFY_EVENT, (1L << 17),
// 		quit_game, game);
// 	mlx_loop(game->mlx_ptr);
// }

// int main()
// {
// 	t_mlx_data	data;

// 	data.mlx_ptr = mlx_init();
// 	if (data.mlx_ptr == NULL)
// 		return (0);
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, 
//                                 WiDTH, 
//                                 HEiGHT,
//                                 "My first window!");
//     if (data.win_ptr == NULL)
//     {
//         mlx_destroy_display(data.mlx_ptr);
//         free(data.mlx_ptr);
//         return (0);
//     }
// 	mlx_key_hook(data.win_ptr, 
//                 handle_input, 
//                 &data);
//     hook_n_run(&data);
//     mlx_loop(data.mlx_ptr);
//     return(0);
// }

//!/*multi window*/

// int main()
// {
// 	void	*mlx_connection;
// 	void	*window1;
// 	void	*window2;

// 	mlx_connection = mlx_init();
// 	if (NULL == mlx_connection)
// 		return (0);
	
// 	window1 = mlx_new_window(mlx_connection, WiDTH, HEiGHT, "window_1");
// 	if (NULL == window1)
// 	{
// 		mlx_destroy_display(mlx_connection);
// 		free(mlx_connection);
// 		return (0);
// 	}

// 	window2 = mlx_new_window(mlx_connection, WiDTH, HEiGHT, "window_2");
// 	if (NULL == window2)
// 	{
// 		mlx_destroy_window(mlx_connection, window1);
// 		mlx_destroy_display(mlx_connection);
// 		free(mlx_connection);
// 		return (0);
// 	}

// 	mlx_loop(mlx_connection);

// 	return (0);
// }
