	CC	=	c++
ifdef DEBUG
	CFLAGS	=	-std=c++98 -g3 -fsanitize=address
else ifdef LEAKS
	CFLAGS	=	-std=c++98 -g
else
	CFLAGS	=	-std=c++98 -Wall -Wextra -Werror
endif

NAME		=	a.out
FOLDER		=	./
HEADER		=	./
SRC_LIST	=	main.cpp Base.cpp
SRC			=	$(addprefix $(FOLDER), $(SRC_LIST))
OBJ			=	$(SRC:%.cpp=%.o)

%.o	:	%.cpp
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean
	make all

.PHONY: debug
debug:
	make DEBUG=1 all

.PHONY: leaks
leaks:
	make LEAKS=1 all