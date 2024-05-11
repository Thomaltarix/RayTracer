##
## EPITECH PROJECT, 2024
## RayTracer
## File description:
## Makefile
##

.PHONY: all clean fclean re

SRC		=	sphere/			\
			plane/			\
			cylinder/		\
			cone/			\

HEADER	=	APrimitive.hpp	\
			3DAxis.hpp		\

INCLUDE =	../../../include/plugins/

all:
	@for dir in $(SRC); do \
		$(MAKE) -C $$dir; \
	done
	@cp $(HEADER) $(INCLUDE)

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
