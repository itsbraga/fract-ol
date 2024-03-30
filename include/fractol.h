/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:15:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/30 18:42:13 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/******************************************************************************\
 * LIBRAIRIES
\******************************************************************************/

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "defines.h"

# include "../mlx/mlx.h"

# include "X11/X.h"
# include "X11/keysym.h"
# include <math.h>
# include <stdbool.h>

/******************************************************************************\
 * ABOUT MLX
\******************************************************************************/

/* Endianness : Big-endian (BE) + Little-endian (LE)
 * 
 * BE stores the big-end first (reading left->right)
 * LE stores the little-end first (reading right->left)
 * 
 * Least Significant Byte (LSbyte) : smallest position
 * Most Significant Byte (MSbyte) : most significant position
 * 
 * so...
 * BE stores data MSbyte first
 * LE stores data MSbyte last
*/

/******************************************************************************\
 * STRUCTS
\******************************************************************************/

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

/*	x represents the real values (complex)	
	y represents the imaginary ones			
	
	They are the image pixel coordinates in the range of -2 ; 2
*/
typedef struct s_view
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
}				t_view;

typedef enum e_fractaltype
{
	Mandelbrot = 1,
	Julia = 2
}				t_ftype;

typedef struct s_fractal
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_view		idx;
	double		max_it;
	t_complex	julia_c;
	int			color;
	int			esc_value;
	t_ftype		type;
}				t_fractal;

/******************************************************************************\
 * MANDATORY
\******************************************************************************/

double		atodbl(char *s);
bool		check_julia_args(char **argv);

void		julia_examples(void);
void		tutorial(void);
void		help_menu(void);

void		mouse_zoom(double zmult, t_fractal *f);
void		init_events(t_fractal *f);

double		scale(double n, double new_min, double new_max, double old_max);
void		init_img(t_fractal *f);

t_complex	z_square(t_complex z);
t_complex	sum(t_complex z, t_complex c);

void		init_fractal(char **argv, t_fractal *f);
int			draw(t_fractal *f);
int			mandelbrot(t_fractal *f, int x, int y);
int			julia(t_fractal *f, int x, int y);

void		del_win(t_fractal *f);
void		del_img(t_fractal *f);
int			clean(t_fractal *f);

/******************************************************************************\
 * BONUS
\******************************************************************************/

int			key_hook2(int keycode, t_fractal *f);
void		key_move(int keycode, double dist, t_fractal *f);
void		init_events2(t_fractal *f);

#endif