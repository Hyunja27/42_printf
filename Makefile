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
SRC_FILES = ft_printf ft_print_int ft_width_detecter ft_pharse_str ft_precision_detecter
SRCS = $(addprefix ./sources/, $(addsuffix .c, $(SRC_FILES)))

GREEN = \033[32m
PURPLE = \033[35m
MINT = \033[36m
RED = \033[31m

BLINK = \033[5m
BOLD = \033[1m
BACKGRAY = \033[100m
NO_COLOR = \e[0m

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "${GREEN}[${RED} Makefile${GREEN} :starting.. ]"
	@(make -C $(LIBFT_DIR))
	@(cp $(LIBFT_DIR)/$(LIBFT) .)
	@(mv $(LIBFT) $(NAME))
	@($(AR) $(NAME) $(OBJS))
	@echo "${MINT}making Done."

$(OBJS) :
	@$(CC) $(CFLAGS) -I $(LIBFT_INC_DIR) -I $(INC_DIR) -c $(SRCS)

clean :
	@echo "${PURPLE}[${RED} cleaning ${PURPLE} : erase objects file.]"
	@(make -C $(LIBFT_DIR) clean)
	@($(RM) $(RMFLAGS) $(OBJS))
	@echo "${MINT}cleaning Done."
fclean : clean
	@echo "${PURPLE}[${RED} fcleaning ${PURPLE} : erase objects & lib.a file.]"
	@($(RM) $(RMFLAGS) $(LIBFT_DIR)/$(LIBFT))
	@($(RM) $(RMFLAGS) $(NAME))
	@echo "${MINT}fcleaning Done."

re : fclean all

test : $(NAME)
	@($(CC) $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) test.c  $(SRCS)  -I $(INC_DIR) -I $(LIBFT_INC_DIR))
	@echo "${GREEN}${BOLD}${BLINK}<프린트f 테스트>"
	@./a.out
	@rm a.out
	@make fclean

.PHONY: clean fclean
