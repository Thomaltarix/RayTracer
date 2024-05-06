##
## EPITECH PROJECT, 2024
## RayTracer
## File description:
## Makefile
##

.PHONY: all clean fclean re

SRC		=	sphere/			\
			plane/			\

all:
	@for dir in $(SRC); do \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SRC); do \
		$(MAKE) clean -C $$dir; \
	done

fclean:
	@for dir in $(SRC); do \
		$(MAKE) fclean -C $$dir; \
	done

re: fclean all
