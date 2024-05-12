##
## EPITECH PROJECT, 2024
## RayTracer
## File description:
## Makefile
##

# Sources
SRC		=	Cone.cpp			\
			getInstance.cpp 	\
			../APrimitive.cpp	\
			../../../../src/math/Point3D.cpp	\
			../../../../src/math/MathError.cpp	\
			../../../../src/math/Vector3D.cpp	\
			../../../../src/math/QuadraticEquation.cpp	\
			../../../../src/math/Ray.cpp	\

HEADER	=	Cone.hpp		\

# Path to the plugin directory
PLUGINS	=	../../../../plugins/primitives/

# Path to the include directory to copy the header
INCLUDE	=	../../../../include/plugins/

# Objects
OBJ		=	$(SRC:.cpp=.o)

# Binary
NAME	=	libcone.so

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
	@$(CXX) $(CXXFLAGS) -shared -o $(NAME) $(OBJ)
	@mv $(NAME) $(PLUGINS)
	@cp $(HEADER) $(INCLUDE)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(PLUGINS)$(NAME)
	@rm -f $(INCLUDE)$(HEADER)

re:	fclean all
