NAME	= MutantStack
SRCS	= main.cpp

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic

all:		${NAME}

${NAME}:
			${CC} ${SRCS} ${FLAGS} -o ${NAME} 

docker:
	docker run -ti -v $(PWD):/test memory-test:0.1 bash -c "cd /test/; make re && valgrind --leak-check=full ./${NAME} 12"

exe:
	docker run -ti -v $(PWD):/test memory-test:0.1 bash -c "cd /test/; ./${NAME} 12"

leaks:
	make re
	leaks --fullStacks --atExit -- ./${NAME}

fclean:	
			rm -f ${NAME}

re:			fclean all

.PHONY:		re fclean all