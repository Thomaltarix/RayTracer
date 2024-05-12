##
## EPITECH PROJECT, 2024
## RayTracer
## File description:
## Makefile
##

# Sources
SRC				=	src/main.cpp									\
					\
					src/core/Core.cpp								\
					src/core/Scene.cpp								\
					src/core/DLLoaderException.cpp					\
					src/core/SafePluginsLister.cpp					\
					src/core/CoreException.cpp						\
					src/core/SceneException.cpp						\
                    src/core/Camera.cpp                             \
                    src/core/Image.cpp                              \
					src/core/ArgsHandler.cpp						\
					src/core/ArgsHandlerException.cpp				\
					src/core/ImageBuilder.cpp						\
					\
					src/math/Point3D.cpp							\
					src/math/Vector3D.cpp							\
					src/math/Ray.cpp								\
					src/math/MathError.cpp							\
                    src/math/Rectangle3D.cpp                        \
                    src/math/QuadraticEquation.cpp                  \
					src/math/DegToRad.cpp							\
					\
					src/plugins/primitives/APrimitive.cpp			\
					src/plugins/primitives/3DAxis.cpp				\
					src/plugins/primitives/sphere/Sphere.cpp		\
					src/plugins/primitives/plane/Plane.cpp			\
					src/plugins/primitives/cylinder/Cylinder.cpp	\
					\
					src/plugins/materials/AMaterial.cpp				\
					src/plugins/materials/flatColor/FlatColor.cpp	\
					\
					src/plugins/lights/ALight.cpp		            \
					src/plugins/lights/ambiant/Ambiant.cpp	        \
					\
					src/interface/SFMLRenderer.cpp		            \
					src/interface/SFMLException.cpp		            \

TESTS			=	tests/test.cpp

# Plugins
PLUGINS_DIR		=	src/plugins/

# Objects
OBJ			=	$(SRC:.cpp=.o)

# Binary
NAME		=	raytracer

# Flags
CXXFLAGS	=	-W -Wall -Wextra -I./include -std=c++17 -g3
CXXFLAGS	+=	-I./include -I./include/math -lconfig++

# Optional flags
SFML		=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Compiler
CXX		=	g++

# Rules
.PHONY:	all clean fclean re tests_run clean_tests

all: 	plug $(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(SFML)

clean:
	@rm -f $(OBJ)
	@make clean -sC $(PLUGINS_DIR)

fclean:	clean clean_tests
	@rm -f $(NAME)
	@make fclean -sC $(PLUGINS_DIR)

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

plug:
	@make re -sC $(PLUGINS_DIR)
