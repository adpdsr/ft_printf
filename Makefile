##
## HEADER
##

NAME	= libftprintf.a

SRC	= ft_bzero.c \
	  ft_isdigit.c \
	  ft_memalloc.c \
	  ft_memset.c \
	  ft_printc.c \
	  ft_printf.c \
	  ft_printwc.c \
	  ft_putchar.c \
	  ft_putnnbr.c \
	  ft_nbrlen_base.c \
	  ft_putnnbr_base.c \
	  ft_putstr.c \
	  ft_strlen.c \
	  ft_strnstr.c \
	  ftp_prints.c \
	  ftp_printx.c \
	  get_flag.c \
	  get_length.c \
	  get_precision.c \
	  get_type.c \
	  get_width.c

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

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(SRCS)
	gcc $(WFLAGS) -c $(SRCS) $(IFLAGS)
	mkdir -p $(DIR_OBJ)
	mv $(OBJ) $(DIR_OBJ)

clean:
	rm -rf $(OBJS) $(DIR_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
