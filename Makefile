rose='\033[1;31m'
violetfonce='\033[0;35m'
violetclair='\033[1;35m'
neutre='\033[0m'
cyanfonce='\033[0;36m'
cyanclair='\033[1;36m'
vertfonce='\033[0;32m'
vertclair='\033[1;32m'
rouge='\033[31m'

NAME= scop

SRCS= main.c ft_strlen.c extract_shader.c render.c vertexBuffer.c window_control.c \
		extract_object.c get_next_line.c print_object.c matrices.c m_operations.c vector.c \
		mvp_init.c shader_init.c

HEADERS_DIR=include
DEPEDENCIES=
HEADERS_FILES= scop.h matrix.h libft.h
INCLUDES= $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))

SRCS_DIR=srcs/

OBJS_DIR=objs/
OBJS= $(addprefix $(OBJS_DIR), $(SRCS:%.c=%.o))

RESOURCES=resources
RESOURCES_TAR=resources.tar

SRCS_PATH = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(SRCS_PATH), $(dir))

DEP_FLAGS= -lGL -lglfw -lm -lGLEW
ERRORS_FLAGS= -Wall -Wextra

LIBFT = lib/libft.a
LIBS = $(LIBFT)

SAN=-g
ALL_FLAGS= $(DEP_FLAGS) $(ERRORS_FLAGS)

SHELL=/bin/zsh
CC=/usr/bin/clang
RM=rm
ECHO=/usr/bin/echo
MKDIR=/usr/bin/mkdir

COMPILED=\[$(vertclair)COMPILED$(neutre)\]
DELETED=\[$(rouge)DELETED$(neutre)\]

all: $(NAME)

$(NAME): $(LIBFT) $(INCLUDES) $(RESOURCES) $(OBJS_DIR) $(OBJS)
	@$(CC) $(ALL_FLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo $(COMPILED) $(NAME)
	@echo \[$(vertclair)ready to use$(neutre)\] $(NAME)

$(OBJS_DIR):
	@$(MKDIR) -p objs
	@echo  \[$(vertclair)OK$(neutre)\]  Object directory created

$(LIBFT):
	@/usr/bin/make -C libft

$(RESOURCES) : $(RESOURCES_TAR)
	@tar -xvf $(RESOURCES_TAR)
	@echo  \[$(vertclair)OK$(neutre)\]  Resources extracted

$(OBJS_DIR)%.o : %.c
	@$(CC) $(ERRORS_FLAGS) -I$(HEADERS_DIR) -c $< -o $@
	@echo $(COMPILED) $@ 

debug: extend_flag re

extend_flag:
	$(eval ALL_FLAGS += $(SAN))
	$(eval ERRORS_FLAGS += $(SAN))

clean :
	@$(RM) -rf $(OBJS)
	@/usr/bin/make -C libft clean 
	@echo $(DELETED) OBJECTS

fclean: clean
	@$(RM) -rf $(NAME)
	@$(RM) -rf $(RESOURCES)
	@/usr/bin/make -C libft fclean 
	@echo $(DELETED) $(NAME)

re: fclean all

.PHONY: re fclean all clean
