#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "header.h"

struct position_detail scr_size = {30, 120};

//Initial positions of pieces
char board[3][3] = {
                        {'X', 'X', 'X'},
                        {' ', ' ', ' '},
                        {'O', 'O', 'O'}
                   };


int main()
{
    char screen_size[30];

    //setting max console size
    sprintf(screen_size, "mode con:cols=%u lines=9999", scr_size.col);          //120 cols and 9999 rows
    system(screen_size);            //120 cols and 30 rows
    //setting required console size
    adjust_console_size(scr_size);

    draw_board();

    return 0;
}
