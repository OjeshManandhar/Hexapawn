#include "config.h"
#include "header.h"

//extern Variables
uint8_t round_no;
char board[ROW][COL];
Character computer, player;
Box box;

//Global Variables
char temp_board[ROW][COL] = {0};

//Function used only in this file
char check_piece(char board_type, int8_t row, int8_t col)
{
    char return_value;

    if (board_type == 'b')
    {
        if (board[box.position.row + row][box.position.col + col] >= 'a' && board[box.position.row + row][box.position.col + col] <= 'z')
            return_value =  'X';
        else if (board[box.position.row + row][box.position.col + col] >= '0' && board[box.position.row + row][box.position.col + col] <= '9')
            return_value =  'O';
        else if (board[box.position.row + row][box.position.col + col] == ' ')
            return_value =  ' ';
    }
    else if (board_type == 't')
    {
        if (temp_board[box.position.row + row][box.position.col + col] >= 'a' && temp_board[box.position.row + row][box.position.col + col] <= 'z')
            return_value =  'X';
        else if (temp_board[box.position.row + row][box.position.col + col] >= '0' && temp_board[box.position.row + row][box.position.col + col] <= '9')
            return_value =  'O';
        else if (temp_board[box.position.row + row][box.position.col + col] == ' ')
            return_value =  ' ';
    }

    return return_value;
}

//Function that are used in other files
void set_initial_data()
{
    uint8_t i;

    computer.sign = 'X';
    player.sign = 'O';

    for (i = 0; i < COL; i++)
    {
        computer.piece[i].id = 'a' + i;
        computer.piece[i].status = alive;
        computer.piece[i].position.row = 0;
        computer.piece[i].position.col = i;

        player.piece[i].id = '0' + i;
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
            board[computer.piece[i].position.row][computer.piece[i].position.col] = computer.piece[i].id;

        if (player.piece[i].status == alive)
            board[player.piece[i].position.row][player.piece[i].position.col] = player.piece[i].id;
    }
}

void player_turn()
{
    unsigned int key;
    uint8_t i, j, selected_piece;
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
                if (check_piece('b', 0, 0) == 'O')
                {
                    box.status = selected;

                    new_position = 0;

                    selected_piece = board[box.position.row][box.position.col];

                    for (i = 0; i < ROW; i++)
                        for (j = 0; j < COL; j++)
                            temp_board[i][j] = board[i][j];

                    temp_board[box.position.row][box.position.col] = ' ';
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
                printf("%c", player.sign);
                gotoxy(scr_size.row - 1, scr_size.col - 1);
                delay(400);
            }
            fflush(stdin);

            key = get_key();            //Pressed key

            switch (key)
            {
            case UP:
                if (box.position.row != 0 && check_piece('t', -1, 0) == ' ' && new_position == 0)
                {
                    draw_box_around_piece(0);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf(" ");

                    box.position.row--;

                    draw_box_around_piece(1);
                    gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                    printf("%c", player.sign);

                    new_position = 'u';
                }
                break;
            case DOWN:
                if (new_position != 0)
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
                    printf("%c", player.sign);

                    new_position = 0;
                }
                break;
            case LEFT:
                draw_box_around_piece(0);
                gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                printf(" ");

                if (new_position == 0 && box.position.col != 0 && box.position.row != 0 && check_piece('t', -1, -1) == 'X')
                {
                    box.position.row--;
                    box.position.col--;
                    new_position = 'l';
                }
                else if (new_position == 'u' && box.position.col != 0 && check_piece('t', 0, -1) == 'X')
                {
                    box.position.col--;
                    new_position = 'l';
                }
                else if (new_position == 'r' )
                {
                    if (check_piece('t', 0, -1) != 'O')
                    {
                        box.position.col--;
                        new_position = 'u';
                    }
                    else if ((int8_t)box.position.col - 2 >= 0 && check_piece('t', 0, -2) == 'X')
                    {
                        box.position.col -= 2;
                        new_position = 'l';
                    }
                }

                draw_box_around_piece(1);
                gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                printf("%c", player.sign);

                break;
            case RIGHT:
                draw_box_around_piece(0);
                gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                printf(" ");

                if (new_position == 0 && box.position.col != COL - 1 && box.position.row != 0 && check_piece('t', -1, 1) == 'X')
                {
                    box.position.row--;
                    box.position.col++;
                    new_position = 'r';
                }
                else if (new_position == 'u' && box.position.col != COL - 1 && check_piece('t', 0, 1) == 'X')
                {
                    box.position.col++;
                    new_position = 'r';
                }
                else if (new_position == 'l' )
                {
                    if (check_piece('t', 0, 1) != 'O')
                    {
                        box.position.col++;
                        new_position = 'u';
                    }
                    else if ((int8_t)box.position.col + 2 <= COL - 1 && check_piece('t', 0, 2) == 'X')
                    {
                        box.position.col += 2;
                        new_position = 'r';
                    }
                }

                draw_box_around_piece(1);
                gotoxy(top.row + TO_ROW(box.position.row), top.col + TO_COL(box.position.col));
                printf("%c", player.sign);

                break;
            case ENTER:
                box.status = blank;

                for (i = 0; i < COL; i++)
                    if (player.piece[i].id == selected_piece)
                    {
                        player.piece[i].position.row = box.position.row;
                        player.piece[i].position.col = box.position.col;

                        break;
                    }

                fill_board();

                break;
            }
        }
    }while (key != ESC);
}
