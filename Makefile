NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
RM = rm -rf

#	----------OBJS----------

OBJS_DIR = objs
OBJS_PATH = ./$(OBJS_DIR)/
OBJS_DIR_BONUS = objs_bonus
OBJS_PATH_BONUS = ./$(OBJS_DIR_BONUS)/

#	-----------SRCS---------

SRCS_DIR = srcs
SRCS_PATH = ./$(SRCS_DIR)/
SRCS_DIR_BONUS = srcs_bonus
SRCS_PATH_BONUS = ./$(SRCS_DIR_BONUS)/
FILES =	main \
		parsing \
		parsing_utils \
		init_philo \
		init_controller \
		philo \
		philo_action \
		sleep_philo \
		parent_process
FILES_BONUS =	main
SRCS = $(addprefix $(SRCS_PATH), $(addsuffix .c, $(FILES)))
SRCS_O = $(addprefix $(OBJS_PATH), $(addsuffix .o, $(FILES)))
SRCS_OR = $(addsuffix .o, $(FILES))
SRCS_BONUS = $(addprefix $(SRCS_PATH_BONUS), $(addsuffix .c, $(FILES_BONUS)))
SRCS_BONUS_O = $(addprefix $(OBJS_PATH_BONUS), $(addsuffix .o, $(FILES_BONUS)))
SRCS_BONUS_OR = $(addsuffix .o, $(FILES_BONUS))

#	----------UTILS---------

UTILS_DIR = utils
UTILS_PATH = $(SRCS_PATH)$(UTILS_DIR)/
UTILS_PATH_O = $(OBJS_PATH)$(UTILS_DIR)/
UTILS_PATH_BONUS = $(SRCS_PATH_BONUS)$(UTILS_DIR)/
UTILS_PATH_BONUS_O = $(OBJS_PATH_BONUS)$(UTILS_DIR)/
FILES_UTILS =	utils \
				utils2 \
				utils3 \
				ft_usleep
UTILS = $(addprefix $(UTILS_PATH), $(addsuffix .c, $(FILES_UTILS)))
UTILS_O = $(addprefix $(UTILS_PATH_O), $(addsuffix .o, $(FILES_UTILS)))
UTILS_OR = $(addsuffix .o, $(FILES_UTILS))
UTILS_BONUS = $(addprefix $(UTILS_PATH_BONUS), $(addsuffix .c, $(FILES_UTILS)))
UTILS_BONUS_O = $(addprefix $(UTILS_PATH_BONUS_O), $(addsuffix .o, $(FILES_UTILS)))
UTILS_BONUS_OR = $(addsuffix .o, $(FILES_UTILS))

#	-----------ALL----------

ALL_SRCS = $(SRCS) $(UTILS)
ALL_OBJS = $(SRCS_O) $(UTILS_O)
ALL_OBJS_R = $(SRCS_OR) $(UTILS_OR)
ALL_DIR_O = $(OBJS_DIR) $(OBJS_PATH)$(UTILS_DIR)

ALL_SRCS_BONUS = $(SRCS_BONUS) $(UTILS_BONUS)
ALL_OBJS_BONUS = $(SRCS_BONUS_O) $(UTILS_BONUS_O)
ALL_OBJS_BONUS_R = $(SRCS_BONUS_OR) $(UTILS_BONUS_OR)
ALL_DIR_BONUS_O = $(OBJS_DIR_BONUS) $(OBJS_PATH_BONUS)$(UTILS_DIR)

#	----------BONUS---------

BONUS_NAME = philo_bonus

#	----------CMDS----------

all : $(NAME)

bonus :$(BONUS_NAME)

$(NAME) : $(ALL_SRCS) $(ALL_DIR_O)
	$(CC) $(CFLAGS) -c $(ALL_SRCS)
	mv $(SRCS_OR) $(OBJS_PATH)
	mv $(UTILS_OR) $(UTILS_PATH_O)
	$(CC) $(CFLAGS) $(ALL_OBJS) -o $@

$(BONUS_NAME) : $(ALL_SRCS_BONUS) $(ALL_DIR_BONUS_O)
	$(CC) $(CFLAGS) -c $(ALL_SRCS_BONUS)
	mv $(SRCS_BONUS_OR) $(OBJS_PATH_BONUS)
	mv $(UTILS_BONUS_OR) $(UTILS_PATH_BONUS_O)
	$(CC) $(CFLAGS) $(ALL_OBJS_BONUS) -o $(BONUS_NAME)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)
$(OBJS_PATH)$(UTILS_DIR) :
	mkdir $(OBJS_PATH)$(UTILS_DIR)
$(OBJS_DIR_BONUS) :
	mkdir $(OBJS_DIR_BONUS)
$(OBJS_PATH_BONUS)$(UTILS_DIR) :
	mkdir $(OBJS_PATH_BONUS)$(UTILS_DIR)

clean : $(ALL_DIR) $(ALL_DIR_BONUS)
	$(RM) $(OBJS_DIR) $(OBJS_DIR_BONUS)

fclean : clean
	$(RM) $(NAME) $(BONUS_NAME)

re : fclean $(NAME)