/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:11:51 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/30 19:58:56 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/******************************************************************************\
 * WINDOW
\******************************************************************************/

// Dell
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
// # define WIN_WIDTH 800
// # define WIN_HEIGHT 800

// iMac
// # define WIN_WIDTH 1300
// # define WIN_HEIGHT 1300

/******************************************************************************\
 * NAVIGATION
\******************************************************************************/

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

/******************************************************************************\
 * COLOR MODES
\******************************************************************************/

# define ZERO 65438
# define ONE 65436
# define TWO 65433
# define THREE 65435

/******************************************************************************\
 * SHOW POSSIBLE PARAMS (MENU)
\******************************************************************************/

# define SEP		"================================="
# define HEADER		" HELP MENU "
# define ARG_HEADER	"=  ARGS  ="
# define INTRO1		"How to explore the "
# define INTRO2		"fantastic world of fractals:\n\n"
# define M_ARG1		"Mandelbrot\t\t"
# define M_ARG2		"-->\t./fractol mandelbrot\n"
# define J_ARGS1	"Julia\t\t\t"
# define J_ARGS2	"-->\t./fractol julia [double] [double]\n\n"
# define EX_HEADER	" EXAMPLES "
# define EXAMPLE_MSG "\n\nExamples of Julia's set:\n\n"

// # define EXAMPLE(x1, x2) RESET "-->\t./fractol julia " #x1 " " #x2

/******************************************************************************\
 * COLORS
\******************************************************************************/

void	rainbow_txt(const char *str);

# define DEFAULT 0x38040E

# define SALMON 0xFA8072
# define ORANGE_RED 0xFF4500
# define SEA_GREEN 0x2E8B57
# define LIGHT_SEA_GREEN 0x20B2AA
# define LAVENDER 0xE6E6FA
# define INDIGO 0x4B0082
# define DARK_MAGENTA 0x8B008B

# define DEEP_PINK_PSYCHE 0xFF1493
# define PINK_PSYCHE 0xFF83FA

# define HOT_PINK 0xFF69B4

#endif