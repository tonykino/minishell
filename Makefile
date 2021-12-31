# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgeny <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 15:58:20 by rgeny             #+#    #+#              #
#    Updated: 2021/12/31 21:54:11 by rgeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# ************************************ cmd *********************************** #
# **************************************************************************** #

RM				= rm -rf
NEW_DIR			= mkdir -p
VALGRIND		= valgrind
VALGRINDF		= --trace-children=yes --suppressions=./ignoreliberror --leak-check=full --show-leak-kinds=all
ENV				= env -i

# **************************************************************************** #
# ********************************* Minishell ******************************** #
# **************************************************************************** #

CC				= clang
FLAG			= $(DEPF) $(BUILTINF) #-g -Wall -Werror -Wextra
LIBF			= -lreadline
DEPF			= -MMD
INCLUDES		= -I$(INCLUDES_DIR)

SRC_DIR			= srcs/
ENV_DIR			= $(SRC_DIR)env/
MEM_DIR			= $(SRC_DIR)mem/
STR_DIR			= $(SRC_DIR)str/
UTILS_DIR		= $(SRC_DIR)utils/
OBJ_DIR			= objs
INCLUDES_DIR	= includes/

VPATH			= $(SRC_DIR) $(ENV_DIR) $(MEM_DIR) $(STR_DIR) $(UTILS_DIR)

SRC_STR			= $(addsuffix .c, $(addprefix str_, cmp len ndup split join free))
OBJ_STR			= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_STR))
SRC				= $(addsuffix .c,		main \
					$(addprefix env_,	del find init new print assign switch new_) \
					$(addprefix utils_,	bzero calloc min itoa atoi) \
					$(addprefix mem_,	cpy set) \
					$(SRC_BUILTIN))

OBJ				= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC)) $(OBJ_STR)
DEP				= $(OBJ:.o=.d)

EXE				= minishell

# **************************************************************************** #
# ********************************** Builtin ********************************* #
# **************************************************************************** #

BUILTINF		= -D BUILTIN_PATH=\"$(PATH_DIR)$(BUILTIN_DIR)\"

PATH_DIR		= $(shell /usr/bin/pwd)/
BUILTIN_DIR		= builtin
SRC_BUILTIN_DIR	= $(SRC_DIR)builtin/

VPATH			+= $(SRC_BUILTIN_DIR)

SRC_BUILTIN		= $(addprefix builtin_, export unset)
SRC_ENV			= builtin_env.c
OBJ_ENV			= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_ENV))
SRC_ECHO		= $(addsuffix .c,builtin_echo str_cmp str_len)
OBJ_ECHO		= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_ECHO))
OBJ_BUILTIN		= $(OBJ_ENV)

EXE_ENV			= $(BUILTIN_DIR)/env
EXE_ECHO		= $(BUILTIN_DIR)/echo

# **************************************************************************** #
# ******************************* Compilation ******************************** #
# **************************************************************************** #

all				: $(EXE) builtin

$(EXE)			: $(OBJ)
				$(CC) $(FLAG) $^ -o $@ $(LIBF)

builtin			: $(OBJ_ENV) $(OBJ_ECHO)
				$(NEW_DIR) $(BUILTIN_DIR)/
				$(CC) $(FLAG) $(OBJ_ENV) -o  $(EXE_ENV)
				$(CC) $(FLAG) $(OBJ_ECHO) -o $(EXE_ECHO)

$(OBJ_DIR)/%.o	: %.c
				$(NEW_DIR) $(OBJ_DIR)
				$(CC) $(FLAG) -c $< $(INCLUDES) -o $@

valgrind		: all
				$(VALGRIND) $(VALGRINDF)  ./$(EXE)

envi			: all	
				$(ENV) $(VALGRIND) $(VALGRINDF) ./$(EXE)

clean			:
				$(RM) $(OBJ_DIR)

fclean			: clean
				$(RM) $(EXE) $(BUILTIN_DIR)

re				: fclean all

-include $(DEP)

.PHONY	: all valgrind envi clean fclean re
