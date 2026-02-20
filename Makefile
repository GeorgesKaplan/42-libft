NAME = libft.a
CC = cc
AR = ar crs
HEADER = libft.h
SRCS_DIR = srcs/
INCLUDES = -Iincludes
SRCS = $(addprefix $(SRCS_DIR), \
		libft_char_checker1.c libft_char_checker2.c \
		libft_str_checker1.c \
		libft_converters1.c \
		libft_list_utils1.c libft_list_utils2.c \
		libft_memory_utils1.c libft_memory_utils2.c \
		libft_put_fd.c \
		libft_split.c libft_split_keep.c libft_split_keep_utils.c\
		libft_string_utils1.c libft_string_utils2.c libft_string_utils3.c \
		libft_string_utils4.c \
		libft_printf_utils1.c libft_printf_utils2.c libft_printf_utils3.c \
		libft_gnl.c) # 		libft_printers1.c
OBJS_DIR = objs/
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)
	@echo "libft.a created!"

$(NAME): $(OBJS)
	@echo "Creating libft archive..."
	@$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@echo "Compiling libft .c files..."
	@mkdir -p $(@D)
	@$(CC) $(INCLUDES) -c $< -o $@

clean:
	@echo "Removing libft .o files."
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing libft archive."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
