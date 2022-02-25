##_*_*_*_*_*_*_*_*_*_*_*_*_Makefile_ft_printf_*_*_*_*_*_*_*_*_*_*_*_*_###
## Pour compiler les bonus, si il y a en a, d/commenter les lignes B_SRCS_FILES,
## B_SRCS_DIR, B_SRCS et dans les instructions de la ligne OBJS_FILES,
## décommenter $(B_SRCS_FILES:.c=.o)

###-------------------------# VARIABLES ##-------------------------###
NAME = lib_pipe.a

SRCS_FILES 		=	ft_fork.c \
					ft_give_path.c \
					ft_make_cmd.c \
					pipe.c \

INCLUDE_FILES	= 	lib_pipe.h

#B_SRCS_FILES	= 	 \

## Nommer les fichiers objets
OBJS_FILES 	= $(SRCS_FILES:.c=.o) #$(B_SRCS_FILES:.c=.o) # Utilise les noms de fichier de la variable SRCS_FILES et modifie le suffix .c en .o

### Repertoires ###

SRCS_DIR = srcs/
#B_SRCS_DIR 	= bonus_srcs/
OBJS_DIR	= objs/
INCLUDE_DIR = include/

SRCS 		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
#B_SRCS 	= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
OBJS 		= $(addprefix $(OBJS_DIR), $(OBJS_FILES))
INCLUDE 	= $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))
VPATH 		= $(SRCS_DIR) $(B_SRCS_DIR)

### Compilations et archivage ###
CC 			= gcc
CFLAGS 		= -Wall -Werror -Wextra
AR 			= ar -cr
OEXEC		= -o pipex

### Autres Fonctions ###

RM 			= rm -rf
NORMINETTE 	= norminette

### Colour var ###

END			= \033[0m
BOLD		= \033[1m
ITALIC		= \033[3m
URL			= \033[4m
BLINK		= \033[5m
BLINK2		= \033[6m
SELECTED	= \033[7m

BLACK		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
VIOLET		= \033[35m
BEIGE		= \033[36m
WHITE		= \033[37m


###--------------------------## REGLES ##--------------------------###

all: obj $(NAME)

$(OBJS_DIR)%.o:%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ -c $< 

#	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ -c $<   (FAIT DES FICHIERS .o) et la librairie
	
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "${OBJS} ${GREEN} ${BOLD}\n\nObjects files are added to the archive libftprintf.a correctly\n${END}"

bonus: ${NAME} ${BONUS_OBJS}
	@${ARCHIVE} ${NAME} ${BONUS_OBJS}
	@echo "${BONUS_OBJS} ${GREEN} ${BOLD}\n\nObjects files And bonus objects files are added to the archive libftprintf.a correctly\n${END}"

exec:
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -o test ${SRCS}

test: norm
	${CC} ${FLAGS} -Og -o test ${SRCS_FILES}
	valgrind ./test
obj:
	@mkdir -p $(OBJS_DIR)

#main in rule
pipex:
	${CC} ${CFLAGS} ${SRCS_FILES} $(OEXEC)
	@echo "${BONUS_OBJS} ${VIOLET} ${BOLD}\n\n-X-- PIPEX executable created --X-\n${END}"
	@echo "${BONUS_OBJS} ${GREEN} Use as follow : ${VIOLET} ./pipex ${YELLOW}input_text.txt ${RED}CMD CMD ${YELLOW}output_text.txt \n${white} && ${RED}CAT ${YELLOW}output_text.txt\n${END}"

norm:
	$(NORMINETTE)

clean:
	$(RM) $(OBJS) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME) $(OBJS_DIR) test pipex
	@echo "${BONUS_OBJS} ${RED} ${BOLD}\nObjects files And possibly bonus objects files are deleted to the archive correctly\n${END}"

re: fclean all

repip: fclean pipex

phony: norm comp
