# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/22 12:40:42 by yuliano           #+#    #+#              #
#    Updated: 2026/03/24 22:24:39 by yuliano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++ -g
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = serializer
SRC = Serializer.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all