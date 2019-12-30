#include "helicopter.h"
void writePropeler(helicopter_t instant)
{
    int x = instant.x;
    int y = TERM_MAX_Y - instant.y;
    int looperlen = 4+ instant.propelerstatenum*2;
    int position=0;
    for(int i =0; i< 24-looperlen;i++, position++);
    for(int i =0; i< looperlen*2+1;i++, position++)
        mvaddch(y,x+position, '_');
}


void writeHelicopter(helicopter_t instant)
{

    int x =  instant.x;
    int y = TERM_MAX_Y - instant.y;
    char tmpchar;
    FILE * body = fopen("./resource/holicopter/body.txt", "r");
    tmpchar =fgetc(body);

    while(tmpchar != EOF){

        if (tmpchar=='\n')
        {
            x = instant.x;
            y++;
            tmpchar =fgetc(body);
        } else if(tmpchar == 'P')
        {
            x++;
            tmpchar =fgetc(body);
            
        }
        else{
            mvaddch(y+1, x, tmpchar);
            tmpchar =fgetc(body);
            x++;
        }
    }
    fclose(body);
    // refresh();
    return; 
}