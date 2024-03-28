/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:15:48 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 21:42:14 by annabrag         ###   ########.fr       */
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

typedef	struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct	s_complex
{
	double	r;
	double	i;
}				t_complex;

/*	x represents the real values (complex)	
	y represents the imaginary ones			
	
	They are the image pixel coordinates in the range of -2 ; 2
*/
typedef struct	s_view
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zoom;
}				t_view;

typedef	struct	s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	char		*name;
	t_view		idx;
	double		max_it;
	t_complex	julia_c;
	int			color;
	int			esc_value;
}				t_data;

/******************************************************************************\
 * MANDATORY
\******************************************************************************/

double		atodbl(char *s);
bool		global_check_successful(char **argv);
void		*memset4struct(void *s, int c, size_t n);

void		julia_examples(void);
void		tutorial(void);
void		help_menu(void);

int			esc_key_hook(int keycode, t_data *f);
int			mouse_hook(int button, int x, int y, t_data *f);
double		scale(double n, double new_min, double new_max, double old_max);
void		view(t_view *v);

void    	del_win(t_data *f);
void    	del_img(t_data *f);
int			clean(t_data *f);

t_complex	z_square(t_complex z);
t_complex	sum(t_complex z, t_complex c);

void		init_data(t_data *f);
void		draw(t_data *f);
int			mandelbrot(char **argv, t_data *f, t_complex c);
int			julia(char **argv, t_data *f, t_complex z);

/******************************************************************************\
 * BONUS
\******************************************************************************/

int			keypress(int keycode, t_data *f);

#endif