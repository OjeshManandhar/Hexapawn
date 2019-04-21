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
    uint8_t i, j;

    //Filing board with spaces
    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            board[i][j] = ' ';

    //Substituting spaces with pieces
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
    uint8_t i, seleccted_piece;
    char temp_piece, new_position;

    do
    {
        if (box.status == blank)
        {
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
                if (board[box.position.row][box.position.col] == 'O')
                {
                    box.status = selected;

                    new_position = 0;

                    temp_piece = board[box.position.row][box.position.col];
                    for (i = 0; i < COL; i++)
                        if ((player.piece[i].position.row == box.position.row) && (player.piece[i].position.col == box.position.col))
                        {
                            seleccted_piece = i;
                            break;
                        }

                    board[box.position.row][box.position.col] = ' ';
                }
                break;
            default:
                break;
            }
        }
        else if (box.status == selected)
        {
            while (!kbhit())
            {
                draw_box_around_piece(0);
                gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                printf(" ");
                gotoxy(scr_size.row - 1, scr_size.col - 1);
                delay(400);

                draw_box_around_piece(1);
                gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                printf("%c", temp_piece);
                gotoxy(scr_size.row - 1, scr_size.col - 1);
                delay(400);
            }
            fflush(stdin);

            key = get_key();

            switch (key)
            {
            case UP:
                if (box.position.row != 0 && board[box.position.row - 1][box.position.col] == ' ' && new_position == 0)
                {
                    draw_box_around_piece(0);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf(" ");

                    box.position.row--;

                    draw_box_around_piece(1);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf("%c", temp_piece);

                    new_position = 'u';
                }
                break;
            case DOWN:
                if (new_position == 'u')
                {
                    draw_box_around_piece(0);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf(" ");

                    box.position.row++;

                    draw_box_around_piece(1);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf("%c", temp_piece);

                    new_position = 0;
                }
                else if (new_position == 'l' || new_position == 'r')
                {
                    draw_box_around_piece(0);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf(" ");

                    box.position.row++;

                    if (new_position == 'l')
                        box.position.col++;
                    else if (new_position == 'r')
                        box.position.col--;

                    draw_box_around_piece(1);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf("%c", temp_piece);

                    new_position = 0;
                }
                break;
            case LEFT:
                if (new_position == 0 && box.position.col != 0 && box.position.row != 0 && board[box.position.row - 1][box.position.col - 1] == 'X')
                {
                    draw_box_around_piece(0);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf(" ");

                    box.position.row--;
                    box.position.col--;

                    draw_box_around_piece(1);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf("%c", temp_piece);

                    new_position = 'l';
                }
                else if (new_position == 'u' && box.position.col != 0 && board[box.position.row][box.position.col - 1] == 'X')
                {
                    draw_box_around_piece(0);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf(" ");

                    box.position.col--;

                    draw_box_around_piece(1);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf("%c", temp_piece);

                    new_position = 'l';
                }
                else if (new_position == 'r')
                {
                    draw_box_around_piece(0);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf(" ");

                    box.position.col--;

                    draw_box_around_piece(1);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf("%c", temp_piece);

                    new_position = 'u';
                }
                break;
            case RIGHT:
                if (new_position == 0 && box.position.col != COL - 1 && box.position.row != 0 && board[box.position.row - 1][box.position.col + 1] == 'X')
                {
                    draw_box_around_piece(0);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf(" ");

                    box.position.row--;
                    box.position.col++;

                    draw_box_around_piece(1);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf("%c", temp_piece);

                    new_position = 'r';
                }
                else if (new_position == 'u' && box.position.col != COL - 1 && board[box.position.row][box.position.col + 1] == 'X')
                {
                    draw_box_around_piece(0);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf(" ");

                    box.position.col++;

                    draw_box_around_piece(1);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf("%c", temp_piece);

                    new_position = 'r';
                }
                else if (new_position == 'l')
                {
                    draw_box_around_piece(0);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf(" ");

                    box.position.col++;

                    draw_box_around_piece(1);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf("%c", temp_piece);

                    new_position = 'u';
                }
                break;
            case ENTER:
                box.status = blank;

                player.piece[seleccted_piece].position.row = box.position.row;
                player.piece[seleccted_piece].position.col = box.position.col;

                fill_board();

                break;
            }
        }
    }while (key != ESC);
}
