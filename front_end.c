#include "config.h"
#include "header.h"

void draw_board()
{
    uint8_t i, j;
    unsigned char ch;

    top.row = ROW_POS;
    top.col = COL_POS;
    bot.row = top.row + LENGTH - 1;
    bot.col = top.col + BREADTH - 1;

    system("cls || clear");

    for (i = 0; i < LENGTH; i++)
        for (j = 0; j < BREADTH; j++)
        {
            if (i == 0)             //top line
            {
                if (j == 0)             //left line
                    ch = 201;
                else if (j == BREADTH - 1)              //right line
                    ch = 187;
                else if (j%10 == 0)         //line separating col i.e. intersection point of vertical and horizontal lines
                    ch = 203;
                else
                    ch = 205;
            }
            else if (i == LENGTH - 1)               //bottom line
            {
                if (j == 0)
                    ch = 200;
                else if (j == BREADTH - 1)
                    ch = 188;
                else if (j%10 == 0)
                    ch = 202;
                else
                    ch = 205;
            }
            else if (i%4 == 0)              //line separating rows
            {
                if (j == 0)
                    ch = 204;
                else if (j == BREADTH - 1)
                    ch = 185;
                else if (j%10 == 0)
                    ch = 206;
                else
                    ch = 205;
            }
            else
            {
                if ((j == 0) || (j == BREADTH - 1))
                    ch = 186;
                else if (j%10 == 0)
                    ch = 186;
                else
                    ch = ' ';
            }

            gotoxy(top.row + i, top.col + j);
            printf("%c", ch);
        }
}

void put_pieces()
{
    uint8_t i, j;

    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
        {
            gotoxy(top.row + TO_ROW(i), top.col + TO_COL(j));
            printf("%c", board[i][j]);
        }
}

void draw_box_around_piece(const uint8_t row, const uint8_t col, unsigned short int type)
{
    /*
    Type:
    1 => draw box
    0 => remove box
    */

    struct position_detail temp_top, temp_bot;

    if (type == 0)
        type = ' ';

    temp_top.row = top.row;
    temp_top.col = top.col;
    temp_bot.row = bot.row;
    temp_bot.col = bot.col;

    top.row = temp_top.row + row*4 + 1;
    top.col = temp_top.col + col*10 + 2;
    bot.row = top.row + 2;
    bot.col = top.col + 6;

    print_box(type, 0, 0, 0);

    top.row = temp_top.row;
    top.col = temp_top.col;
    bot.row = temp_bot.row;
    bot.col = temp_bot.col;
}
