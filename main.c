#include "config.h"
#include "header.h"

position_detail scr_size = {30, 120};

Character computer;

int main()
{
    char screen_size[30];

    //setting max console size
    sprintf(screen_size, "mode con:cols=%u lines=9999", scr_size.col);          //120 cols and 9999 rows
    system(screen_size);            //120 cols and 30 rows
    //setting required console size
    adjust_console_size(scr_size);

    draw_board();

    set_initial_data();

    computer.piece[0].position.row = 1;
    computer.piece[2].position.row = 1;

    fill_board();

    put_pieces();

    player_turn();

    return 0;
}
