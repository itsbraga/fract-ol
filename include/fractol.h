/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:15:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/31 22:51:00 by annabrag         ###   ########.fr       */
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
	
	They are the image pixel coordinates in the range of [-2.0;2.0]
*/
typedef struct s_view
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
}				t_view;

typedef enum e_fractoltype
{
	Mandelbrot = 1,
	Julia = 2,
	Burningship = 3,
	Mandelbox = 4
}				t_ftype;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_view		idx;
	double		max_it;
	t_complex	julia_c;
	int			color;
	t_ftype		type;
}				t_fractol;

/******************************************************************************\
 * MANDATORY
\******************************************************************************/

double		atodbl(char *s);
bool		check_julia_args(char **argv);

void		tutorial(void);
void		julia_examples(void);
void		help_menu(void);

void		mouse_zoom(double zmult, t_fractol *f);
void		init_events(t_fractol *f);

double		scale(double n, double new_min, double new_max, double old_max);
void		init_img(t_fractol *f);

t_complex	z_square(t_complex z);
t_complex	sum(t_complex z, t_complex c);

void		init_fractal(char **argv, t_fractol *f);
int			draw(t_fractol *f);

int			mandelbrot(t_fractol *f, int x, int y);
int			julia(t_fractol *f, int x, int y);

void		del_win(t_fractol *f);
void		del_img(t_fractol *f);
int			clean(t_fractol *f);

/******************************************************************************\
 * BONUS
\******************************************************************************/

int			key_hook2(int keycode, t_fractol *f);
void		key_move(int keycode, double dist, t_fractol *f);
void		init_events2(t_fractol *f);

void		julia_examples_bonus(void);
void		help_menu_bonus(void);

int			burningship(t_fractol *f, int x, int y);
int			mandelbox(t_fractol *f, int x, int y);

#endif