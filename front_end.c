#include <stdio.h>

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
            if (i == 0)
            {
                if (j == 0)
                    ch = 201;
                else if (j == BREADTH - 1)
                    ch = 187;
                else if (j%8 == 0)
                    ch = 209;
                else
                    ch = 205;
            }
            else if (i == LENGTH - 1)
            {
                if (j == 0)
                    ch = 200;
                else if (j == BREADTH - 1)
                    ch = 188;
                else if (j%8 == 0)
                    ch = 207;
                else
                    ch = 205;
            }
            else if (i%4 == 0)
            {
                if (j == 0)
                    ch = 199;
                else if (j == BREADTH - 1)
                    ch = 182;
                else if (j%8 == 0)
                    ch = 197;
                else
                    ch = 196;
            }
            else
            {
                if ((j == 0) || (j == BREADTH - 1))
                    ch = 186;
                else if (j%8 == 0)
                    ch = 179;
                else
                    ch = ' ';
            }

            gotoxy(top.row + i, top.col + j);
            printf("%c", ch);
        }
}
