/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:49:33 by rhadiats          #+#    #+#             */
/*   Updated: 2017/08/23 19:50:31 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

/*
** Colorize an output of printf
*/

# define RESET		"\033[0m"
# define RED		"\033[1;31m"
# define YELLOW		"\033[1;33m"
# define WHITE		"\033[1;37m"
# define GREEN		"\033[1;32m"
# define BLUE    	"\x1b[34m"
# define MAGENTA 	"\x1b[35m"
# define CYAN    	"\x1b[36m"
# define BLACK   	"\x1b[37m"

/*
** ----------------------------
*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

# include "../libft/libft.h"

typedef struct		s_temp_data
{
	char				*name;
	int					x;
	int					y;
	char				*key;
}					t_temp_data;

typedef struct		s_valid
{
	unsigned int		start : 1;
	unsigned int		end : 1;
	unsigned int		links : 1;
	unsigned int		is_ants: 1;
	int					ants;
}					t_valid;

typedef struct		s_links
{
	int					init;
	struct s_rooms		*room;
	struct s_links		*next;
}					t_links;

typedef struct		s_rooms
{
	int					init;
	int					id;
	char				*name;
	int					x_coord;
	int					y_coord;
	unsigned int		is_empty : 1;
	unsigned int		is_start : 1;
	unsigned int		is_end : 1;
	struct s_links		*link;
	struct s_rooms		*next;
}					t_rooms;

typedef struct		s_ant_list
{
	int					init;
	int					id;
	struct s_rooms		*room;
	struct s_ant_list	*next;
}					t_ant_list;

typedef struct		s_to_print
{
	char				*text;
	struct s_links		*path;
}					t_to_print;

int					ft_printf(const char *format, ...);
int					error_message(int number);
void				print_debug_valid(t_valid *valid);
void				print_links_list(t_links *links);
void				print_rooms_list(t_rooms *rooms);
void				print_temp_data(t_temp_data *data);
void				print_path_list(t_links *path);
void				reset_valid_struct(t_valid *valid);
t_rooms				*initial_rooms_list(void);
t_links				*initial_links_list(void);
t_temp_data			*initial_temp_data(char *name, int x, int y, char *key);
t_to_print			*initial_to_print(void);
void				rooms_list_added(t_rooms *rooms, t_temp_data *data);
void				links_list_added(t_links *links, t_rooms *room);
int					valid_and_parsing(t_rooms *rooms, t_valid *valid, \
	t_to_print *to_print);
int					switch_route_of_parse(t_rooms *rooms, t_valid *valid, \
	char *line, t_to_print *to_print);
int					parse_ants(t_valid *valid, char *line, \
	t_to_print *to_print);
int					parse_start(t_valid *valid, t_rooms *rooms, char *line, \
	t_to_print *to_print);
int					parse_end(t_valid *valid, t_rooms *rooms, char *line, \
	t_to_print *to_print);
int					parse_room(t_valid *valid, t_rooms *rooms, char *line);
void				parse_links(t_rooms *rooms, char *name1, char *name2);
int					count_symbol(char *line, char symbol);
int					get_room_list_size(t_rooms *rooms);
int					valid_links(t_valid *valid, t_rooms *rooms, char *line);
void				delete_split(char **split);
void				delete_temp_data(t_temp_data *data);
int					get_num_split(char **split);
int					check_to_match(t_rooms *rooms, char *name1, char *name2);
char				*get_start_room_name(t_rooms *rooms);
char				*get_end_room_name(t_rooms *rooms);
int					is_start_is_end_loop(t_rooms *rooms, char *start_name, \
	char *end_name);
int					valid_start_end_links(t_rooms *rooms);
int					check_to_dublicate_link(t_links *link, char *name);
int					check_dublicate_coord(t_rooms *rooms, int x, int y);
int					check_dublicate_names(t_rooms *rooms, char *name);
int					check_identification(t_rooms *rooms);
t_rooms				*get_room_pointer(t_rooms *rooms, char *name);
void				set_id(t_rooms *rooms);
char				*lem_in_strjoin(const char *s1, const char *s2);
void				writing_text_file(char *line, t_to_print *to_print);
void				writing_text_file_valid_loop(char *line, \
	t_to_print *to_print);
int					valid_start_line(t_valid *valid, t_rooms *rooms, \
	char **split, char *line);
int					valid_end_line(t_valid *valid, t_rooms *rooms, \
	char **split, char *line);
void				delete_links_list(t_links *links);
void				delete_rooms_list(t_rooms *rooms);
void				finding_path(t_to_print *to_print, t_rooms *rooms);
void				path_list_added(t_links **path, t_rooms *room);

t_ant_list			*initial_ant_list(void);
void				ant_list_added(t_ant_list *ant, int id, t_rooms *room);
void				setting_ant_list(t_ant_list *ant_list, int ant_count, \
	t_rooms *rooms);
void				print_ant_list(t_ant_list *ant);

#endif
