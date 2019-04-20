#include "config.h"
#include "header.h"

uint8_t round_no;
char board[ROW][COL];
Character computer, player;
Box box;

void set_initial_data()
{
    uint8_t i;

    computer.sign = 'X';
    player.sign = 'O';

    for (i = 0; i < COL; i++)
    {
        computer.piece[i].status = alive;
        computer.piece[i].position.row = 0;
        computer.piece[i].position.col = i;

        player.piece[i].status = alive;
        player.piece[i].position.row = ROW - 1;
        player.piece[i].position.col = i;
    }

    box.status = blank;
    box.position.row = ROW - 1;
    box.position.col = 0;
}

void fill_board()
{
    uint8_t i;

    for (i = 0; i < COL; i++)
    {
        if (computer.piece[i].status == alive)
            board[computer.piece[i].position.row][computer.piece[i].position.col] = computer.sign;

        if (player.piece[i].status == alive)
            board[player.piece[i].position.row][player.piece[i].position.col] = player.sign;
    }
}

void player_turn()
{
    unsigned int key;

    do
    {
        if (box.status == selected)
        {
            while (!kbhit())
            {
                draw_box_around_piece(0);
                gotoxy(scr_size.row - 1, scr_size.col - 1);
                delay(500);
                draw_box_around_piece(1);
                gotoxy(scr_size.row - 1, scr_size.col - 1);
                delay(500);
            }
        }

        key = get_key();

        switch (key)
        {
        case UP:
            if (box.position.row != 0)
            {
                draw_box_around_piece(0);
                box.position.row--;
                draw_box_around_piece(1);
            }
            break;
        case DOWN:
            if (box.position.row != ROW - 1)
            {
                draw_box_around_piece(0);
                box.position.row++;
                draw_box_around_piece(1);
            }
            break;
        case LEFT:
            if (box.position.col != 0)
            {
                draw_box_around_piece(0);
                box.position.col--;
                draw_box_around_piece(1);
            }
            break;
        case RIGHT:
            if (box.position.col != COL - 1)
            {
                draw_box_around_piece(0);
                box.position.col++;
                draw_box_around_piece(1);
            }
            break;
        case ENTER:
            if (box.status == selected)
                box.status = blank;
            else if (box.status == blank)
                box.status = selected;
        }
    }while (key != ESC);
}
