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

SRCS= main.c

HEADERS_DIR=include
DEPEDENCIES=
HEADERS_FILES=
INCLUDES= $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))

SRCS_DIR=srcs/

OBJS_DIR=objs/
OBJS= $(addprefix $(OBJS_DIR), $(SRCS:%.c=%.o))

RESOURCES=resources
RESOURCES_TAR=resources.tar

PATH = $(shell find srcs -type d)
vpath %.c $(foreach dir, $(PATH), $(dir))
DEP_FLAGS= -lGL -lglfw -lm
ERRORS_FLAGS= -Wall -Wextra



ALL_FLAGS= $(DEP_FLAGS) $(ERRORS_FLAGS)

SHELL=/bin/zsh
CC=/usr/bin/clang
RM=/usr/bin/rm
ECHO=/usr/bin/echo
MKDIR=/usr/bin/mkdir

COMPILED=\[$(vertclair)COMPILED$(neutre)\]
DELETED=\[$(rouge)DELETED$(neutre)\]

all: $(NAME)

$(NAME): $(INCLUDES) $(OBJS_DIR) $(OBJS) $(RESOURCES)
	@$(CC) $(ALL_FLAGS) $(OBJS) -o $(NAME)
	@echo $(COMPILED) $(NAME)
	@echo \[$(vertclair)ready to use$(neutre)\] $(NAME)

$(OBJS_DIR):
	@$(MKDIR) -p objs
	@echo  \[$(vertclair)OK$(neutre)\]  Object directory created

$(RESOURCES) : $(RESOURCES_TAR)
	@/usr/bin/tar -xvf $(RESOURCES_TAR)
	@echo  \[$(vertclair)OK$(neutre)\]  Resources extracted

print:
	@echo \[$(rose)oui$(neutre)\]
	@echo \[$(rose)oui\]


$(OBJS_DIR)%.o : %.c
	@$(CC) $(ERRORS_FLAGS) -c $< -o $@
	@echo $(COMPILED) $@ 

clean :
	@$(RM) -rf $(OBJS)
	@echo $(DELETED) $(OBJS)

fclean: clean
	@$(RM) -rf $(NAME)
	@$(RM) -rf $(RESOURCES)
	@echo $(DELETED) $(NAME)

re: fclean all

.PHONY: re fclean all clean
