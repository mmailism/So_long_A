# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iammai <iammai@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/25 15:34:37 by kpueankl          #+#    #+#              #
#    Updated: 2024/03/12 13:53:22 by iammai           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalpha.c\
                ft_isdigit.c\
                ft_isalnum.c\
                ft_isascii.c\
                ft_isprint.c\
                ft_strlen.c\
                ft_memset.c\
                ft_toupper.c\
                ft_tolower.c\
                ft_strchr.c\
                ft_strrchr.c\
                ft_strncmp.c\
                ft_bzero.c\
                ft_memmove.c\
                ft_memchr.c\
                ft_memcpy.c\
                ft_memcmp.c\
                ft_strlcpy.c\
                ft_strlcat.c\
                ft_strnstr.c\
                ft_atoi.c\
                ft_calloc.c\
                ft_strdup.c\
                ft_substr.c\
                ft_strjoin.c\
                ft_strtrim.c\
                ft_split.c\
                ft_itoa.c\
                ft_strmapi.c\
                ft_putchar_fd.c\
                ft_putendl_fd.c\
                ft_putnbr_fd.c\
                ft_putstr_fd.c\
                ft_striteri.c\
                get_next_line.c\
                get_next_line_utils.c\

SRCSB			=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
					ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

NAME = libft.a

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	-rm -f $(OBJS)
	-rm -f $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJSB)
	ar rcs $(NAME) $(OBJSB)

.PHONY: all clean fclean re bonus
