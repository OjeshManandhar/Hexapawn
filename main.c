#include "config.h"
#include "header.h"

position_detail scr_size = {30, 120};

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

    fill_board();

    put_pieces();

    player_turn();

    return 0;
}
