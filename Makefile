##
## EPITECH PROJECT, 2024
## RayTracer
## File description:
## Makefile
##

# Sources
SRC		=	src/main.cpp
TESTS	=	tests/test.cpp

# Plugins
# This part is in empty since there's no plugin compilable in the project
# The plugins will be list like this:
# src/plugins/Sphere/    (for the Sphere plugin)
# You will also need to update the rules for the plugins
PLUGINS	=

# Objects
OBJ		=	$(SRC:.cpp=.o)

# Binary
NAME	=	raytracer

# Flags
CXXFLAGS	=	-W -Wall -Wextra -I./include -std=c++17
CXXFLAGS	+=	-I./include

# Optional flags
SFML		=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Compiler
CXX		=	g++

# Rules
.PHONY:	all clean fclean re tests_run clean_tests

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	@rm -f $(OBJ)

fclean:	clean clean_tests
	@rm -f $(NAME)

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
