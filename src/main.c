#include "helicopter.h"
#include "background.h"

int TERM_MAX_X, TERM_MAX_Y;

int main()
{
    char isbacking=0; 
    helicopter_t helicopter= {10,10,0};
    initscr();
    curs_set(0);
    noecho();
    halfdelay(1);
    keypad(stdscr, TRUE);

    
 
    for (;;)
    {
        if(helicopter.propelerstatenum == 4)
            isbacking = 1;
        else if (helicopter.propelerstatenum == 0)
            isbacking =0;
        helicopter.propelerstatenum+= isbacking?-1:1;

        drowRoad();
        writePropeler(helicopter);
        writeHelicopter(helicopter);

        TERM_MAX_X = getmaxx(stdscr);
        TERM_MAX_Y = getmaxy(stdscr);
        move(0,0);
        printw("%d:%d", TERM_MAX_X, TERM_MAX_Y);
        move(1,0);
        printw("%d:%d", helicopter.x, helicopter.y);
        int ch = getch();
        if (ch == KEY_DOWN)  helicopter.y++;
        if (ch == KEY_UP)    helicopter.y--;
        if (ch == KEY_LEFT)  helicopter.x--;
        if (ch == KEY_RIGHT) helicopter.x++;
        clear();
        refresh();
    }
    endwin();
}
