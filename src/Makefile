FLAGS = -lcurses -Wall
OBJL = main.o helicopter.o background.o
PROGRAM = a.out

$(PROGRAM): $(OBJL)
	gcc -o $@ $(OBJL) $(FLAGS)

%.o: %.c
	gcc -c $< $(FLAGS)

