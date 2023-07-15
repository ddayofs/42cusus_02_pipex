# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 16:34:18 by donglee2          #+#    #+#              #
#    Updated: 2023/07/15 16:05:23 by donglee2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

MANDATORY_DIRS = ./mandatory_files

MANDATORY_SRCS = $(MANDATORY_DIRS)/pipex.c\
$(MANDATORY_DIRS)/path.c\
$(MANDATORY_DIRS)/path_helper.c\
$(MANDATORY_DIRS)/exec_cmd.c\
$(MANDATORY_DIRS)/init_variable.c\
$(MANDATORY_DIRS)/get_next_line.c\
$(MANDATORY_DIRS)/get_next_line_utils.c\
$(MANDATORY_DIRS)/libft.c\
$(MANDATORY_DIRS)/libft_ft_split.c\


BONUS_DIRS = ./bonus_files

BONUS_SRCS = $(BONUS_DIRS)/pipex_bonus.c\
$(BONUS_DIRS)/path_bonus.c\
$(BONUS_DIRS)/path_helper_bonus.c\
$(BONUS_DIRS)/exec_cmd_bonus.c\
$(BONUS_DIRS)/init_variable_bonus.c\
$(BONUS_DIRS)/get_next_line_bonus.c\
$(BONUS_DIRS)/get_next_line_utils_bonus.c\
$(BONUS_DIRS)/libft_bonus.c\
$(BONUS_DIRS)/libft_ft_split_bonus.c\

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -rf

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJS)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS)
	touch $@

clean:	
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS) bonus
 
fclean: clean
	$(RM) $(NAME)
 
re: fclean all