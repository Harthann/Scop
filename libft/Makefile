rose='\033[1;31m'
violetfonce='\033[0;35m'
violetclair='\033[1;35m'
neutre='\033[0m'
cyanfonce='\033[0;36m'
cyanclair='\033[1;36m'
vertfonce='\033[0;32m'
vertclair='\033[1;32m'
rouge='\033[31m'

NAME = ../lib/libft.a
GNL = gnl

SRC_FILE =	ft_atoi.c ft_bzero.c ft_calloc.c ft_find_char.c \
			ft_itoa.c ft_memcmp.c ft_memcpy.c ft_memset.c \
			ft_ralloc.c ft_search.c ft_strchr.c ft_strdup.c \
			ft_strjoin.c ft_strjoin_free.c ft_strlen.c \
			ft_strncmp.c ft_substr.c ft_strfloat.c

OBJ_DIR=objs/

SRCS		= ${SRC_FILE}
OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

INCLUDE = ../include/
HEADER_NAME = libft.h
HEADER = ${addprefix ${INCLUDE}, ${HEADER_NAME}}
FLAGS = -Wall -Werror -Wextra

SHELL =/bin/zsh
ECHO = echo
AR = /usr/bin/ar
CC = /usr/bin/clang
RM = /bin/rm
MKDIR = /bin/mkdir
RANLIB = /usr/bin/ranlib

COMPILED=\[$(vertclair)COMPILED$(neutre)\]
PENDING=\[$(violetfonce)PENDING$(neutre)\]
DELETED=\[$(rouge)DELETED$(neutre)\]

all : $(NAME)

$(NAME) : $(OBJ_DIR) ${OBJS} ${HEADER}
	@${ECHO} $(PENDING) ${NAME}
	@${MKDIR} -p ../lib
	@${AR} rc ${NAME} ${OBJS}
	@${RANLIB} ${NAME}
	@$(ECHO) $(COMPILED) $(NAME)

$(OBJ_DIR)%.o: %.c
	@${CC} $(FLAGS) -I ${INCLUDE} -c $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean :
	@${ECHO} $(DELETED) OBJECTS
	@${RM} -f ${OBJS}

fclean : clean
	@${ECHO} $(DELETED) ${NAME}
	@${RM} -f $(NAME)

re : fclean all

.PHONY : all clean fclean re ../lib/libft

