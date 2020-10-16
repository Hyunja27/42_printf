NAME = libftprintf.a
LIBFT = libft.a

LIBFT_DIR = ./libft
LIBFT_INC_DIR = $(LIBFT_DIR)/includes

INC_DIR = ./includes


CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f
AR = ar crs
OBJS = $(addsuffix .o, $(SRC_FILES))
SRC_FILES = ft_printf ft_print_int ft_width_detecter
SRCS = $(addprefix ./sources/, $(addsuffix .c, $(SRC_FILES)))

all : $(NAME)

$(NAME) : $(OBJS)
	@(make -C $(LIBFT_DIR))
	@(cp $(LIBFT_DIR)/$(LIBFT) .)
	@(mv $(LIBFT) $(NAME))
	@($(AR) $(NAME) $(OBJS))

$(OBJS) :
	@$(CC) $(CFLAGS) -I $(LIBFT_INC_DIR) -I $(INC_DIR) -c $(SRCS)

clean :
	@(make -C $(LIBFT_DIR) clean)
	@($(RM) $(RMFLAGS) $(OBJS))

fclean : clean
	@($(RM) $(RMFLAGS) $(LIBFT_DIR)/$(LIBFT))
	@($(RM) $(RMFLAGS) $(NAME))

re : fclean
	$(name)

test : $(NAME)
	@($(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) test.c  $(SRCS)  -I $(INC_DIR) -I $(LIBFT_INC_DIR))
	@echo "<프린트f 테스트>"
	@./a.out
	@rm a.out
	@make fclean

.PHONY: clean fclean
