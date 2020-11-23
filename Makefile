NAME = libftprintf.a
LIBFT = libft.a

LIBFT_DIR = ./libft
OBJS_DIR = ./objs
LIBFT_INC_DIR = $(LIBFT_DIR)/includes

INC_DIR = ./includes


CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f
AR = ar crs
# OBJS = $(addsuffix .o, $(SRC_FILES))
OBJS = ./*.o
SRC_FILES = ft_printf \
			0_phaser/ft_width_detecter \
			0_phaser/ft_pharse_str \
			0_phaser/ft_precision_detecter \
			0_phaser/ft_wid_pre_seperater \
			0_phaser/ft_set_clear \
			1_divider/ft_printf_with_set \
			2_print_by_type/ft_printf_int \
			2_print_by_type/ft_printf_str \
			2_print_by_type/ft_printf_char \
			2_print_by_type/ft_printf_ptr \
			2_print_by_type/ft_printf_per \
			2_print_by_type/ft_printf_hex \
			2_print_by_type/ft_printf_oct \
			2_print_by_type/ft_printf_uni \
			2_print_by_type/ft_printf_double \
			2_print_by_type/ft_printf_double_g \
			2_print_by_type/ft_printf_double_e \
			3_flag_setter/ft_flag_setter \
			3_flag_setter/ft_flag_setter_double \
			4_body_setter/ft_body_setter_int \
			4_body_setter/ft_body_setter_str \
			4_body_setter/ft_body_setter_hex \
			4_body_setter/ft_body_setter_ptr \
			4_body_setter/ft_body_setter_double \
			5_left_setter/ft_left_setter \
			5_left_setter/ft_left_setter_hex \
			5_left_setter/ft_left_setter_plus \
			6_util/ft_dtoa \
			6_util/ft_dtoa_e \
			6_util/ft_dtoa_e_big \
			6_util/ft_zero_maker \
			6_util/ft_array_round \
			6_util/ft_manti_to_a_e \
			6_util/ft_manti_to_a \
			6_util/ft_e_manti_array \
			6_util/ft_expond_adder \
			6_util/ft_bigint \
			6_util/ft_space_adder \
			6_util/ft_minus_adder \
			6_util/ft_ilencal
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
	@echo "${PURPLE}[${RED} Makefile${PURPLE} :starting.. ]"
	@(make -C $(LIBFT_DIR))
	@echo "${PURPLE}->making libft.a , and add src.o.."
	@echo "${PURPLE}->resting.. drinking some coffee..."
	@(cp $(LIBFT_DIR)/$(LIBFT) .)
	@(mv $(LIBFT) $(NAME))
	@($(AR) $(NAME) $(OBJS))
	@make clean
	@echo "${MINT}making Done."

$(OBJS) : 
	@$(CC) $(CFLAGS) -g -I $(LIBFT_INC_DIR) -I $(INC_DIR) -c $(SRCS)

clean :
	@echo "${PURPLE}[${RED} cleaning ${PURPLE} : erase objects file.]"
	@(make -C $(LIBFT_DIR) clean)
	@echo "${PURPLE}->kill every objects, include libft objects.."
	@echo "${PURPLE}->clearing dead bodys..."
	@($(RM) $(RMFLAGS) $(OBJS))
	@echo "${MINT}cleaning Done."
fclean : clean
	@echo "${PURPLE}[${RED} fcleaning ${PURPLE} : erase objects & lib.a file.]"
	@echo "${PURPLE}->kill all lib.a files... bye bye!"
	@($(RM) $(RMFLAGS) $(LIBFT_DIR)/$(LIBFT))
	@($(RM) $(RMFLAGS) $(NAME))
	@echo "${MINT}fcleaning Done."

re : fclean all

test : $(NAME)
	@make re
	@($(CC) -g $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) test.c  $(SRCS)  -I $(INC_DIR) -I $(LIBFT_INC_DIR))
	@echo "${GREEN}${BOLD}${BLINK}\n<프린트f 테스트>\n"
	@./a.out
	# @rm a.out
	@rm -rf a.out.dSYM
	@make fclean

debug_test : $(NAME)
	$(CC) -g $(CFLAGS) $(LIBFT_DIR)/$(LIBFT) test.c -o test.out $(SRCS)  -I $(INC_DIR) -I $(LIBFT_INC_DIR)

.PHONY: clean fclean
