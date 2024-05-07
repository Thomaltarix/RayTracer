##
## EPITECH PROJECT, 2024
## RayTracer
## File description:
## Makefile
##

# Sources
SRC		=	src/main.cpp						\
			src/math/Point3D.cpp				\
			src/math/Vector3D.cpp				\
			src/math/Rectangle3D.cpp			\
			src/math/Ray.cpp					\
			src/math/QuadraticEquation.cpp		\
			src/math/MathError.cpp				\
			src/core/Camera.cpp					\

TESTS	=	tests/test.cpp

# Plugins
PLUGINS	=	src/plugins/

# Objects
OBJ		=	$(SRC:.cpp=.o)

# Binary
NAME	=	raytracer

# Flags
CXXFLAGS	=	-W -Wall -Wextra -I./include -std=c++17
CXXFLAGS	+=	-I./include -I./include/math

# Optional flags
SFML		=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Compiler
CXX		=	g++

# Rules
.PHONY:	all clean fclean re tests_run clean_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)
	#@make -sC $(PLUGINS)

clean:
	@rm -f $(OBJ)
	@make clean -sC $(PLUGINS)

fclean:	clean clean_tests
	@rm -f $(NAME)
	@make fclean -sC $(PLUGINS)

re:	fclean all

tests_run:
	@$(CXX) -o unit_tests $(TESTS) $(CXXFLAGS) -lcriterion --coverage
	@./unit_tests
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branches

clean_tests:
	@rm -f unit_tests
	@rm -f *.gcda
	@rm -f *.gcno
