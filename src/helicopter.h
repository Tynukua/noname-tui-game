#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>




typedef struct structhelicopter
{
    int x;
    int y;
    int propelerstatenum;
} helicopter_t;

void writePropeler(helicopter_t instant);

void writeHelicopter(helicopter_t instant);