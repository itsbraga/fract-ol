/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: art3mis <art3mis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:11:51 by annabrag          #+#    #+#             */
/*   Updated: 2024/04/08 22:36:05 by art3mis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/******************************************************************************\
 * WINDOW
\******************************************************************************/

// Dell
# define WIN_WIDTH 800
# define WIN_HEIGHT 800

// iMac
// # define WIN_WIDTH 1300
// # define WIN_HEIGHT 1300

/******************************************************************************\
 * NAVIGATION
\******************************************************************************/

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MUP_MSG "Scroll up:\tIncreasing the zoom (+)\n"
# define MDOWN_MSG "Scroll down:\tDecreasing the zoom (-)\n"

# define A 97
# define W 119
# define D 100
# define S 115

/******************************************************************************\
 * KEYS TO CHANGE COLOR MODES
\******************************************************************************/

# define Y 121
# define U 117
# define I 105
# define O 111
# define P 112

/******************************************************************************\
 * SHOW POSSIBLE PARAMS (MENU)
\******************************************************************************/

# define FIRST_HEADER1 "======================================="
# define FIRST_HEADER2 "======================================\n"

# define SEP		"================================="
# define HEADER		" HELP MENU "
# define ARG_HEADER	"=  ARGS  ="

# define INTRO1		"How to explore the "
# define INTRO2		"fantastic world of fractals:\n"

# define M_ARG1		"Mandelbrot\t\t"
# define M_ARG2		"-->\t./fractol mandelbrot\n"

# define J_ARGS1	"Julia\t\t\t"
# define J_ARGS2	"-->\t./fractol julia [double] [double]\n"

# define B_ARG1		"Burningship\t\t"
# define B_ARG2		"-->\t./fractol burningship\n"

# define MX_ARG1	"Mandelbox\t\t"
# define MX_ARG2	"-->\t./fractol mandelbox\n\n"

# define EX_HEADER	" EXAMPLES "
# define EXAMPLE_MSG "\n\nExamples of Julia's set:\n\n"

# define EXAMPLE(x1, x2) RESET "-->\t./fractol julia " #x1 " " #x2

/******************************************************************************\
 * COLORS
\******************************************************************************/

void	rainbow_txt(const char *str);
void	rainbow_txt_nonl(const char *str);

# define DEFAULT 0x38040E

# define PINK_PSYCHE 0xFF83FA
# define DEEP_PINK_PSYCHE 0xFF1493
# define HOT_PINK 0xFF69B4

# define SALMON 0xFA8072
# define LAVENDER 0xE6E6FA

# define CANARY 0xFFE62D

#endif