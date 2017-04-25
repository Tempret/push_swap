/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:54:01 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 18:46:04 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <mlx.h>
# include <math.h>

# define FIRST(x)		(*x)->val
# define SECOND(x)		(*x)->next->val
# define THIRD(x)		(*x)->next->next->val
# define CURR_OP		iter->inst
# define NEXT_OP		iter->next->inst
# define MAX_INT		2147483647
# define MIN_INT		-2147483648
# define SAYOK			"\e[32m\e[5m[OK]\e[39m\n"
# define SAYKO			"\e[91m\e[5m[KO]\e[39m\n"
# define WINSIZE		2000
# define DELIMCOLOR1	130, 57, 0
# define DELIMCOLOR2	0, 179, 179
# define ENEBLE_VISUAL	1
# define DICEBLE_VISUAL	0
# define MLX			par->mlx
# define WIN			par->win

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef	struct		s_point
{
	double			x;
	double			y;
	t_rgb			color;
}					t_point;

typedef struct		s_stack
{
	int				val;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_inst
{
	char			*inst;
	struct s_inst	*next;
	struct s_inst	*prev;
}					t_inst;

typedef struct		s_param
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*visual;
	int				base_len;
	t_inst			*oper;
	t_inst			*next_oper;
	char			b_begin;
	void			*mlx;
	void			*win;
	int				flag_vis;
	double			win_x;
	double			win_y;
	double			max_val;
	int				item_width;
	double			koef;
	int				step;
	char			*item_value;
}					t_param;

/*
**  addition.c contain functions:
*/

void				dell_elem(t_inst **begin, t_inst **target);
void				del_stack(t_stack **target);
int					push_back(t_stack **begin, int val);
int					sort_check(t_stack *stack);

/*
**  checker.c contain functions:
*/

int					do_instr(t_param *par);

/*
**  get_pivot.c contain functions:
*/

int					get_pivot(t_stack *begin, int len);

/*
**  init.c contain functions:
*/

void				init_param(t_param *par, int base_len);

/*
**  make_instructions.c contain functions:
*/

int					make_instruction(char *line, t_param *par, int rev);
int					do_next_visual_instr(t_param *par, int visual);
int					do_prev_visual_instr(t_param *par);

/*
**  optimisation.c contain functions:
*/

void				oper_optimization(t_inst **begin);

/*
**  recursion_fc.c contain functions:
*/

void				sorting_b(t_param *par, int len);
void				sorting_a(t_param *par, int len);

/*
**  simple_case_sort.c contain functions:
*/

void				do_simple_sort_3(t_stack **a, t_inst **oper, char name);
void				do_simple_sort_2a(t_stack **a, t_inst **oper);
void				do_simple_sort_2b(t_stack **a, t_stack **b, t_inst **oper);

/*
**  stack_manipulations.c contain functions:
*/

void				swap(t_stack *stack, t_inst **list, char *str);
void				push(t_stack **dest, t_stack **src, t_inst **list,
		char *str);
void				rotate(t_stack **stack, t_inst **list, char *str);
void				rev_rotate(t_stack **stack, t_inst **list, char *str);
void				push_instruction(t_inst **list, char *str);

/*
**  three_elem_sort_a.c contain functions:
*/

void				do_three_elem_sort_a(t_stack **a, t_inst **list);

/*
**  three_elem_sort_b.c contain functions:
*/

void				do_three_elem_sort_b(t_stack **a, t_stack **b,
		t_inst **list);

/*
**  validation.c contain functions:
*/

int					fill_stack(t_stack **a, char **av, t_param *par);
void				del_instr(t_inst **list);

/*
**  vis_addition.c contain functions:
*/

t_rgb				init_color(int r, int g, int b);
t_rgb				rgb_init(int color, int r, int g, int b);
void				swap_coord(t_point *a, t_point *b);
void				swap_color(t_rgb *a, t_rgb *b);
int					rgbtoi(t_rgb src);

/*
**  vis_delim_line.c contain functions:
*/

void				paint_delim_line(t_param *par);
t_rgb				calc_delta(t_rgb a, t_rgb b);

/*
**  vis_put_line.c contain functions:
*/

void				put_line(void *mlx, void *win, t_point a, t_point b);

/*
**  vis_init.c contain functions:
*/

int					visual_init(t_param *par);
void				free_param(t_param **par);

/*
**  visualisation.c contain functions:
*/

int					visualisation(t_param *par);

/*
**  vis_events.c contain functions:
*/

int					push_key_hook(int keykode, void *param);

#endif
