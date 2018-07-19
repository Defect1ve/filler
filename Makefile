# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikotvits <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 17:44:05 by ikotvits          #+#    #+#              #
#    Updated: 2018/07/17 17:44:06 by ikotvits         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

VISUAL = visual

NAME = ikotvits.filler

FLAGS_VIS = -lmlx -framework OpenGL -framework AppKit -lm

FLAGS = -Wall -Wextra -Werror

LIB_DIR = libft/
RED='\033[0;31m'

NC='\033[0m'

SRCS = filler.c algorithm.c manage.c

VIS = visualization.c extra_vis.c get_map.c

DIR = filler_dir/

SRC = $(addprefix $(DIR), $(SRCS))

VIS_SRC = $(addprefix $(DIR), $(VIS))

OBJ = $(SRC:.c=.o)

VIS_OBJ = $(VIS:.c=.o)

all: $(NAME) $(VISUAL)

$(NAME): $(OBJ) $(addprefix $(DIR), filler.h)
	make -C $(LIB_DIR)
	gcc $(OBJ) -o $(NAME) -L $(LIB_DIR) -lft
	tput setaf 1; echo "<=======|==o Your bot is ready to fight o==|=======>"

$(VISUAL): $(VIS_OBJ) $(addprefix $(DIR), visualization.h)
	gcc $(FLAGS_VIS) $(FLAGS) $(VIS_OBJ) -o $(VISUAL) -L $(LIB_DIR) -lft
	tput setaf 2; echo "<=======|==o You can visualize your filler o==|=======>"

%.o: $(DIR)%.c
	gcc -c $(FLAGS) -o $@ -c $< -I $(DIR)

clean:
	rm -f $(OBJ)
	rm -f $(VIS_OBJ)
	make -C ./libft clean
	tput setaf 3; echo All object files have been deleted

fclean: clean
	rm -f $(NAME)
	rm -f $(VISUAL)
	make -C ./libft fclean
	tput setaf 3; echo Bot has been deleted

re: fclean all