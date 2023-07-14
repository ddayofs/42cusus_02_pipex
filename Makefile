# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 16:34:18 by donglee2          #+#    #+#              #
#    Updated: 2023/07/14 20:47:59 by donglee2         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L./00libft -lft

MANDATORY_DIRS = ./mandatory_files

MANDATORY_SRCS = $(MANDATORY_DIRS)/pipex.c\
$(MANDATORY_DIRS)/path.c\
$(MANDATORY_DIRS)/path_helper.c\
$(MANDATORY_DIRS)/exec_cmd.c\
$(MANDATORY_DIRS)/init_variable.c\

BONUS_DIRS = ./bonus_files

BONUS_SRCS = $(BONUS_DIRS)/pipex_bonus.c\
$(BONUS_DIRS)/path_bonus.c\
$(BONUS_DIRS)/path_helper_bonus.c\
$(BONUS_DIRS)/exec_cmd_bonus.c\
$(BONUS_DIRS)/init_variable_bonus.c\

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
RM = rm -rf

MAKE = make

LIBFT = libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./00libft bonus

$(NAME): $(MANDATORY_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJS) $(LDFLAGS)

bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJS) $(LDFLAGS)
	touch $@

clean:	
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS) bonus
	$(MAKE) -C ./00libft clean

fclean: clean
	$(RM) $(NAME)
	$(RM) 00libft/$(LIBFT)
	
re: fclean all
