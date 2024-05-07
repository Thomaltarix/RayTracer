##
## EPITECH PROJECT, 2024
## RayTracer
## File description:
## Makefile
##

# Sources
SRC		=	Sphere.cpp		\
			getInstance.cpp \
			../APrimitive.cpp	\

HEADER	=	Sphere.hpp		\

# Path to the plugin directory
PLUGINS	=	../../../../plugins/

# Path to the include directory to copy the header
INCLUDE	=	../../../../include/plugins/

# Objects
OBJ		=	$(SRC:.cpp=.o)

# Binary
NAME	=	sphere.so

# Flags
CXXFLAGS	=	-W -Wall -Wextra -I./include -std=c++17

CXXFLAGS	+=	-I../ 						\
				-I../../../../include 		\
				-I../../../../include/math 	\
				-I../../../../include/transformations	\

CXXFLAGS	+=	-fPIC

# Compiler
CXX		=	g++

# Rules
.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CXX) -shared -o $(NAME) $(OBJ) $(CXXFLAGS)
	@mv $(NAME) $(PLUGINS)
	@cp $(HEADER) $(INCLUDE)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(PLUGINS)$(NAME)
	@rm -f $(INCLUDE)$(HEADER)

re:	fclean all
