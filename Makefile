# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/18 16:56:08 by adu-pelo          #+#    #+#              #
#    Updated: 2016/10/18 17:45:38 by adu-pelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC	= ft_bzero.c \
	  ft_isdigit.c \
	  ft_memalloc.c \
	  ft_memset.c \
	  ft_printc.c \
	  ft_printf.c \
	  ft_printwc.c \
	  ft_strchr.c \
	  ft_putchar.c \
	  ft_putnnbr.c \
	  ft_nbrlen_base.c \
	  ft_putnnbr_base.c \
	  ft_putstr.c \
	  ft_strlen.c \
	  ft_strnstr.c \
	  ft_nwstrlen.c \
	  ft_wstrlen.c \
	  ft_nstrlen.c \
	  ftp_putnchar.c \
	  ftp_prints.c \
	  ftp_printwc.c \
	  ftp_printws.c \
	  ftp_printc.c \
	  ftp_printx.c \
	  ftp_printe.c \
	  ftp_printo.c \
	  ftp_printu.c \
	  ftp_printp.c \
	  ftp_printi.c \
	  get_flag.c \
	  get_length.c \
	  get_precision.c \
	  get_type.c \
	  get_width.c \
	  prefix.c \
	  padding.c

WFLAGS	= -Wall -Werror -Wextra
IFLAGS	= -I /includes/

OBJ	= $(SRC:.c=.o)

DIR_SRC	= ./sources/
DIR_OBJ	= ./objects/
DIR_INC	= ./includes/

SRCS	= $(addprefix $(DIR_SRC), $(SRC))
OBJS	= $(addprefix $(DIR_OBJ), $(OBJ))
INCS	= $(addprefix $(DIR_INC), $(INC))

all: $(NAME)


$(OBJS): $(SRCS)
	gcc $(WFLAGS) -c $(SRCS) $(IFLAGS)
	mkdir -p $(DIR_OBJ)
	mv $(OBJ) $(DIR_OBJ)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS) $(DIR_OBJ)

fclean: clean
	rm -rf $(NAME) $(OBJS) $(DIR_OBJ)

re: fclean all

.PHONY: all clean fclean re
