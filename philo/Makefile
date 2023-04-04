# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laprieur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 09:45:27 by laprieur          #+#    #+#              #
#    Updated: 2023/04/03 15:48:51 by laprieur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_NAME	:=	philo

#-------------------------------#
#          INGREDIENTS          #
#-------------------------------#

MANDATORY		:=	src/main.c				\
					src/parsing.c			\
					src/philosophers_utils.c\

MANDATORY_OBJS	:=	$(MANDATORY:%.c=.build/%.o)
DEPS			:=	$(MANDATORY_OBJS:%.o=%.d)

CC				:=	clang
CFLAGS			:=	-Wall -Wextra -Werror -g -pthread -Ofast
CPPFLAGS		:=	-MP -MMD -Iinclude

#----------------------------#
#          UTENSILS          #
#----------------------------#

MAKEFLAGS		+= --silent --no-print-directory

#---------------------------#
#          RECIPES          #
#---------------------------#

all: $(MANDATORY_NAME)

$(MANDATORY_NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) -o $(MANDATORY_NAME)
	$(info CREATED $(MANDATORY_NAME))

.build/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $(CPPFLAGS) $< -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	rm -rf .build

fclean: clean
	rm -rf $(MANDATORY_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#------------------------#
#          SPEC          #
#------------------------#

.PHONY: all clean fclean re
.DELETE_ON_ERROR:
