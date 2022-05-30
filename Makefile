# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:38:32 by rpoder            #+#    #+#              #
#    Updated: 2022/05/30 10:48:33 by rpoder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGNAME			=	push_swap

LIBFT				:=	./libftprintf/libftprintf.a

INCLUDEDIR			:=	./includes
SRCDIR				:=	./src

OBJDIR				:=	./obj

SRCS				:=	main.c \
						prints.c \
						setters.c \
						getters.c \
						reinitialisations.c \
						fillers.c \
						libft_addons.c \
						moves/push.c \
						moves/rotate.c \
						moves/rrotate.c \
						moves/swap.c \
						pre_sort.c \
						main_sort.c \
						calculate_rotates.c \

CC					:=	cc
RM					:=	rm

#CCFLAGS				:=	-Wall -Wextra -Werror -g3
#OPTIMISATION_FLAG	:=	-O3

NAME				:=	$(PROGNAME)

OUTDIR				:=	$(OBJDIR)

$(OUTDIR)/%.o		:	$(SRCDIR)/%.c | $(OUTDIR)
	$(CC) -c $(CCFLAGS) -I $(INCLUDEDIR) -I $(dir $(LIBFT))includes $< -o $@

$(NAME)				:	$(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) $(LIBFT)
	$(CC) $(CCFLAGS) $(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) $(LIBFT) -o $(NAME)

all					:	$(NAME)

bonus				:	$(NAME)

ifdef LIBFT
$(LIBFT)			:
	$(MAKE) -C $(dir $(LIBFT)) all
endif

$(OUTDIR)			:
	mkdir $(OUTDIR)
	mkdir $(OUTDIR)/moves
	mkdir $(OUTDIR)/checks

clean				:
ifdef LIBFT
	$(MAKE) -C $(dir $(LIBFT)) fclean
endif
	$(RM) -rf $(OBJDIR)

fclean				:	clean
	$(RM) -f $(PROGNAME)

re					:	fclean $(NAME)

norm				:
	norminette

push				:
	$(MAKE) fclean
	git add *
	git status
	git commit -m "$m"
	git push origin master

.PHONY				:	all clean fclean re norm push