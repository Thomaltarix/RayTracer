##
## EPITECH PROJECT, 2024
## RayTracer
## File description:
## Makefile
##

.PHONY: all clean fclean re

SRC		=	ambiant/		\

HEADER	=	ALight.hpp		\

INCLUDE =	../../../include/plugins/

all:
	@for dir in $(SRC); do \
		$(MAKE) -C $$dir; \
	done
	@for header in $(HEADER); do \
		cp $$header $(INCLUDE); \
	done

clean:
	@for dir in $(SRC); do \
		$(MAKE) clean -C $$dir; \
	done

fclean:
	@for dir in $(SRC); do \
		$(MAKE) fclean -C $$dir; \
	done
	@for header in $(HEADER); do \
		rm -f $(INCLUDE)$$header; \
	done

re: fclean all
