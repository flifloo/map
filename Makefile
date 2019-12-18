CC=gcc
FLAGS= -Wall
NAME=map
SRC=map.c

OBJ=$(SRC:.c=.o)

HEADER=map.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ)

%.o: %.c
	$(CC) -o $@ $(FLAGS) -c $<

clean:
	rm -f *.o
	rm -f */*.o

fclean: clean
	rm -f $(NAME)