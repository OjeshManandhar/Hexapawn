#include "config.h"
#include "header.h"

struct Character computer, player;

char board[ROW][COL];

void set_initial_data()
{
    uint8_t i;

    computer.sign = 'X';
    player.sign = 'O';

    for (i = 0; i < COL; i++)
    {
        computer.piece[i].status = Alive;
        computer.piece[i].position.row = 0;
        computer.piece[i].position.col = i;

        player.piece[i].status = Alive;
        player.piece[i].position.row = ROW - 1;
        player.piece[i].position.col = i;
    }
}

void fill_board()
{
    uint8_t i;

    for (i = 0; i < COL; i++)
    {
        if (computer.piece[i].status == Alive)
            board[computer.piece[i].position.row][computer.piece[i].position.col] = computer.sign;

        if (player.piece[i].status == Alive)
            board[player.piece[i].position.row][player.piece[i].position.col] = player.sign;
    }
}
