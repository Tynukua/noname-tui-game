#include "background.h"

void drowRoad()//int TERM_MAX_X, int MAX_X)
{
    int y = TERM_MAX_Y-6;
    int x = 0;
    int tmpchar, i;
    int roadcount = TERM_MAX_X / 16 +1;
    FILE * road;
    for(i = 0; i<roadcount;i++)
    {
        road = fopen("./resource/background/road.txt","r");
        tmpchar =fgetc(road);
        while(tmpchar != EOF){
            if (tmpchar=='\n'){
                tmpchar =fgetc(road);
                x=0+i*16;
                y++;
            }
            mvaddch(y,x, tmpchar);
            tmpchar =fgetc(road);
            
            x++;
        
        }
        fclose(road);
        y = TERM_MAX_Y-6;
    }
    return; 
}

