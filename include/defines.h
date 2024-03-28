/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annabrag <annabrag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:11:51 by annabrag          #+#    #+#             */
/*   Updated: 2024/03/28 17:40:01 by annabrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/******************************************************************************\
 * WINDOW
\******************************************************************************/

# define WIN_WIDTH 1520
# define WIN_HEIGHT 1200

/******************************************************************************\
 * NAVIGATION
\******************************************************************************/

# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

/******************************************************************************\
 * SHOW POSSIBLE PARAMS (MENU)
\******************************************************************************/

# define SEP		"================================="
# define HEADER		" HELP MENU "
# define ARG_HEADER	"=  ARGS  ="
# define INTRO1		"How to explore the "
# define INTRO2		"fantastic world of fractals:\n\n"
# define M_ARG1		BOLD "Mandelbrot\t" RESET
# define M_ARG2		"-->\t./fractol mandelbrot\n"
# define J_ARGS1	BOLD "Julia\t\t" RESET
# define J_ARGS2	"-->\t./fractol julia [double] [double]\n\n"
# define EX_HEADER	" EXAMPLES "
# define EXAMPLE(x1, x2) RESET "-->\t./fractol julia " #x1 " " #x2
# define EXAMPLE_MSG "\n\nExamples of Julia's set:\n\n"

// # define EXAMPLE(x1, x2, x3) #x1 "\t\t-->\tARGS=\"" \
// 								#x2 " " #x3"\"; ./fractol julia \"$ARGS\"\n"
// # define EXAMPLE2(x1, x2, x3) #x1 "\t-->\tARGS=\"" \
// 								#x2 " " #x3"\"; ./fractol julia \"$ARGS\"\n"

/******************************************************************************\
 * COLORS
\******************************************************************************/

void	rainbow_txt(const char *str);

# define SALMON 0xFA8072
# define ORANGE_RED 0xFF4500

# define SEA_GREEN 0x2E8B57
# define LIGHT_SEA_GREEN 0x20B2AA

# define LAVENDER 0xE6E6FA

// # define INDIGO 0x4B0082
# define DARK_MAGENTA 0x8B008B
# define DEEP_PINK 0xFF1493
# define HOT_PINK 0xFF69B4
# define ORCHID 0xFF83FA

#endif