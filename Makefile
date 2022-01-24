NAME		:=	libft.a


CC_FLAGS	:=	-Wall -Wextra -Werror -Iincludes/ -O2
CC			:=	gcc $(CC_FLAGS)

HEADER_LIB	:=	$(addsuffix .h, $(addprefix includes/, libft get_next_line ft_printf))

FT_IS		:=	alnum alpha ascii count digit in print space spacenl where minmax
FT_LST 		:=	add_back add_front clear delone iter last map new size
FT_MATH		:=	abs nbrlen hexlen baselen power invsqrt degrad
FT_MEM 		:=	bzero calloc memccpy memchr memcmp memcpy memfree memmove memset intswap
FT_PUT 		:=	char endl nbr str char_fd endl_fd nbr_fd str_fd
FT_STR 		:=	chr cmp dup join lcat lcpy cpy len mapi ncmp nstr rchr trim iteri
FT_SUB 		:=	substr split split_str save_free linebreak
FT_TO 		:=	tolower toupper atoi itoa
FT_GNL 		:=	gnl utils_gnl
FT_PRINTF	:=	choose convert_c convert_d convert_p convert_pct convert_s convert_u \
				initializer parser_args parser_asterix parser place_bin printf uitoa_base
FT_SORT		:=	quick

SRC 		:= 	$(addsuffix .c, $(addprefix ft_is/ft_is, $(FT_IS)))					\
				$(addsuffix .c, $(addprefix ft_lst/ft_lst, $(FT_LST)))				\
				$(addsuffix .c, $(addprefix ft_math/ft_, $(FT_MATH)))				\
				$(addsuffix .c, $(addprefix ft_mem/ft_, $(FT_MEM)))					\
				$(addsuffix .c, $(addprefix ft_put/ft_put, $(FT_PUT)))				\
				$(addsuffix .c, $(addprefix ft_skip/ft_skip_, $(FT_SKIP)))			\
				$(addsuffix .c, $(addprefix ft_str/ft_str, $(FT_STR)))				\
				$(addsuffix .c, $(addprefix ft_str/ft_, $(FT_SUB)))					\
				$(addsuffix .c, $(addprefix ft_to/ft_, $(FT_TO)))					\
				$(addsuffix .c, $(addprefix ft_gnl/, $(FT_GNL)))					\
				$(addsuffix .c, $(addprefix ft_printf/ft_, $(FT_PRINTF)))			\
				$(addsuffix .c, $(addprefix ft_sort/ft_sort_, $(FT_SORT)))				\


OBJ_LIB		:= 	$(SRC:.c=.o)


# COLORS
COLOR=\033[0;45m
NC=\033[0m # No Color

.PHONY: all clean fclean re norm

all			:	$(NAME)

$(NAME)		:	$(OBJ_LIB)
	@$(AR) rcs $(NAME) $?
	@echo -e "${COLOR}MEGA LIBFT DONE${NC}"

%.o	:	%.c $(HEADER_LIB)
	@${CC} ${CС_FLAGS} -c $< -o $@

clean:
	@$(RM) -rf $(OBJ_LIB)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all

norm:
	@norminette $(SRC) $(HEADER)

