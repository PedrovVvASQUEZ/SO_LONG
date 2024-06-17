# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 19:44:38 by pgrellie          #+#    #+#              #
#    Updated: 2024/06/13 18:22:51 by pgrellie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################################
# TERMINAL COLORS OP ##

NORMAL = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

##########################################################
##### FOLDERS PATH ####

SRCS_DIR = ./srcs_mandatory/
OBJS_DIR = ./Objs/
LIBS_DIR = ./Libraries/
BIN_DIR = ./bin/
HEADER_DIR = ./include/

#########################################################
###### ARGUMENTS ######

NAME = $(BIN_DIR)so_long
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -lpedro_lib -lmlx -lmlx_Linux -lXext -lX11 -lm
COMP = cc
RM = rm -rf
MKDIR = mkdir -p

##########################################################
### LIBRARIES PATH ####

LIBFT_DOSS = $(LIBS_DIR)pedro_lib/
LIBFT_MAKE_COMMAND = make -s -C $(LIBFT_DOSS) --no-print-directory
LIBFT_PATH = $(LIBFT_DOSS)pedro_lib.a

MLX_DOSS = $(LIBS_DIR)mlx/
GCL_MLX = git clone git@github.com:42Paris/minilibx-linux.git $(MLX_DOSS)
MLX_MAKE_COMMAND = make -s -C $(MLX_DOSS) --no-print-directory
MLX_PATH = $(MLX_DOSS)libmlx.a

##########################################################
###### INCLUDES  ######

INCLUDES = -I $(LIBFT_PATH) -I $(MLX_PATH)
PATH_OF_THE_LIBS = -L $(LIBFT_DOSS) -L $(MLX_DOSS)

##########################################################
######  SOURCES  ######
SRCS_FILES = so_long.c\
				map_check_functions.c\
				get_the_map.c\
				map_utils.c\
				parsing_args.c\
				displayer.c\
				ignite_game.c\
				dl_pics.c\
				moves.c\
				destroyer.c\
				animations.c\
				exit_game.c\
				closer.c\
				map_checker.c\

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))

##########################################################
######  OBJECTS  ######

OBJS_FILES = $(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))

##########################################################
######   RULES   ######

all: $(NAME)

call_mlx:
	
	@if [ ! -d "$(MLX_DOSS)" ]; then \
		echo "$(YELLOW)\nCloning the MLX Library via SSH ...\n$(NORMAL)"; \
		$(GCL_MLX); \
		echo "$(GREEN)\n<<< MLX has been succesfully cloned >>>\n$(NORMAL)"; \
		echo "$(GREEN)░▒▓██████████████▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░$(NORMAL)"; \
    	echo "$(GREEN)░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░$(NORMAL)"; \
    	echo "$(GREEN)░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░$(NORMAL)"; \
    	echo "$(GREEN)░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░       ░▒▓██████▓▒░$(NORMAL)"; \
    	echo "$(GREEN)░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░$(NORMAL)"; \
    	echo "$(GREEN)░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░$(NORMAL)"; \
    	echo "$(GREEN)░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░$(NORMAL)"; \
	else \
		echo "$(CYAN)\n<<< MLX already available >>>\n$(NORMAL)"; \
	fi

rm_mlx:
	@$(RM) $(MLX_DOSS)
	@echo "$(MAGENTA)\n<<< MLX directory has been removed >>>\n$(NORMAL)"
	
$(NAME) : $(OBJS_DIR) $(OBJS_FILES)
	@echo "$(GREEN)\n<<< Done >>>\n$(NORMAL)"
	@echo "$(YELLOW)\nBuilding project ...\n$(NORMAL)"
	$(MKDIR) $(BIN_DIR)
	$(LIBFT_MAKE_COMMAND)
	$(MLX_MAKE_COMMAND)
	$(COMP) $(CFLAGS) $(OBJS_FILES) -o $(NAME) $(PATH_OF_THE_LIBS) $(LDFLAGS)
	@echo "$(GREEN)\n<<< [SO_LONG] has been compiled >>>\n" 
	@echo "$(WHITE)                                       /!\/!\/!\/!\/!\/!\ \n$(NORMAL)" 
	@echo "$(WHITE) Use this command in the root folder to launch the game : ./bin/so_long maps/<map_name>.ber\n$(NORMAL)" 
#	@echo "$(GREEN)	                .--.--.         $(WHITE)                             $(RED)                                            $(NORMAL)"
#	@echo "$(GREEN)	               /  /    ..       $(WHITE)                        ,---,$(RED)                                            $(NORMAL)"
#	@echo "$(GREEN)	              |  :  /.. /       $(WHITE)            ,---,     ,---..|$(RED)  __  ,-.   ,---.                           $(NORMAL)"
#	@echo "$(GREEN)	              ;  |  |--.        $(WHITE)        ,-+-. /  |    |   | :$(RED),. ,./ /|  .   ,.\                          $(NORMAL)"
#	@echo "$(GREEN)	              |  :  ;_      ,--.$(WHITE)--.    ,--..|.   |    |   | |$(RED).  | |. | /   /   |                         $(NORMAL)"
#	@echo "$(GREEN)	               \  \    ..  /    $(WHITE)   \  |   |  ,. |  ,--.__| ||$(RED)  |   ,..   ; ,. :                          $(NORMAL)"
#	@echo "$(GREEN)	                .----.   \.--.  $(WHITE).-. | |   | /  | | /   ,.   |$(RED).  :  /  .   | |: :                         $(NORMAL)"
#	@echo "$(GREEN)	                __ \  \  | \__\/$(WHITE): . . |   | |  | |.   .  /  |$(RED)|  | .   .   | .; :                         $(NORMAL)"
#	@echo "$(GREEN)	               /  /.--.  / ,. .-$(WHITE)-.; | |   | |  |/ .   ; |:  |$(RED);  : |   |   :    |                         $(NORMAL)"
#	@echo "$(GREEN)	              .--..     / /  /  $(WHITE),.  | |   | |--.  |   | ./  .$(RED)|  , ;    \   \  /                          $(NORMAL)"
#	@echo "$(GREEN)	                .--.---. ;  :   $(WHITE)..   \|   |/      |   :    :|$(RED) ---.      .----.                           $(NORMAL)"
#	@echo "$(GREEN)	                         |  ,   $(WHITE)  .-./.---.        \   \  /  $(RED)                                            $(NORMAL)"
#	@echo "$(GREEN)	                          .--.--$(WHITE)-.                  .----.   $(RED)                                            $(NORMAL)"
#	@echo "$(GREEN)	                                $(WHITE)                         ___  $(RED)                                            $(NORMAL)"
#	@echo "$(GREEN)	                 ,---,          $(WHITE)                       ,--..|_$(RED)                                            $(NORMAL)"
#	@echo "$(GREEN)	               ,---..|          $(WHITE)               ,---,   |  | :,$(RED).          ,--,  __  ,-.                    $(NORMAL)"
#	@echo "$(GREEN)	               |   | :     .---.$(WHITE)           ,-+-. /  |  :  : . $(RED):        ,._ /|,. ,./ /|          .--.--.   $(NORMAL)"
#	@echo "$(GREEN)	  ,--.--.      |   | |   /.  ./|$(WHITE)   ,---.  ,--..|.   |.;__,.  /$(RED)    .--. |  | :.  | |. | ,---.   /  /    .  $(NORMAL)"
#	@echo "$(GREEN)	 /       \   ,--.__| | .-. . . |$(WHITE)  /     \|   |  ,. ||  |   |  $(RED) ,._ /| :  . ||  |   ,./     \ |  :  /..    $(NORMAL)"
#	@echo "$(GREEN)	 \__\/: . ..   .  /  |.   \  . .$(WHITE)     . / |   | |  | |  .  : |_$(RED)_ |  | . |  | ||  | . .    . / | \  \    .. $(NORMAL)"
#	@echo "$(GREEN)	 ,. .--.; |.   ; |:  | \   \   .$(WHITE)    ;   /|   | |  |/   |  | ..$(RED).|:  | : ;  ; |;  : | .   ;   /|  .----.   \$(NORMAL)"
#	@echo "$(GREEN)	/  /  ,.  ||   | ./  .  \   \  .$(WHITE)    |  / |   | |--.    ;  :   $(RED) ;.  :  .--.   \  , ; .   |  / | /  /.--.  /$(NORMAL)"
#	@echo "$(GREEN)	;  :   ..   \   :    :|   \   \ $(WHITE) |   :    |   |/        |  ,  $(RED) / :  ,      .-./---. .|   :    |.--..     /$(NORMAL)"
#	@echo "$(GREEN)	|  ,     .-./\   \  /      .---.$(WHITE)  \   \  /.---.          ---.-$(RED)    .--.----.           \   \  /   .--.---. $(NORMAL)"
#	@echo "$(GREEN)	 .--.---.     .----.            $(WHITE)   .----.                     $(RED)                         .----.         \n\n$(NORMAL)"

#Creer le repertoire 'Objs' et compiles C source files into object files
$(OBJS_DIR):
	@echo "$(YELLOW)\nProcessing c files into o files ...\n$(NORMAL)"
	$(MKDIR) $(OBJS_DIR)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(COMP) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

#Clean objects files and dependencies
clean:
	$(RM) $(OBJS_DIR)
	@make clean -C $(LIBFT_DOSS) --no-print-directory
	@make clean -C $(MLX_DOSS) --no-print-directory
	@echo "$(MAGENTA)\n<<< Object files have been removed >>>\n$(NORMAL)"

#Cleans everething generated by the Makefile
fclean: clean
	$(RM) $(NAME) $(BIN_DIR) $(OBJS_DIR)
	@make fclean -C $(LIBFT_DOSS) --no-print-directory
	@echo "$(MAGENTA)\n<<< Executable files, object files and Directories have been removed >>>\n$(NORMAL)"

#Remake	
re: fclean all

.PHONY: all clean fclean re libpedro_lib mlx