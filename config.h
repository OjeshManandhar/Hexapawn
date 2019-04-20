#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

//Including Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#include <basic_func.h>

//Size of board => Always 3x3
//But can be changed
//========== Working in AI with 3x3 size only ==========
#define ROW 3
#define COL 3

//To find the length and breadth of the box depending upon the size of board
#define LENGTH (4*ROW + 1)
#define BREADTH (10*COL + 1)

//To find the centre of the screen to draw the box
#define ROW_POS ((scr_size.row - LENGTH)/2)
#define COL_POS ((scr_size.col - BREADTH)/2)

//To find the screen position of the matrix/board
#define TO_ROW(i) (4*i + 2)
#define TO_COL(j) (10*j + 5)

//Local Variables
enum Box_Status             //For checking whether a piece is selected or not
{
    selected = 0, blank = 0
};

struct Box
{
    enum Box_Status status;
    struct position_detail positin;
};

enum Piece_Status
{
    dead = 0, alive = 1
};

struct Pieces
{
    enum Piece_Status status;
    struct position_detail position;
};

struct Character
{
    unsigned char sign;
    struct Pieces piece[COL];
};

//Global Variables Declaration
extern struct position_detail scr_size;         //console size

extern char board[ROW][COL];            //pointer to store the board matrix/array

extern struct Character computer, player;

extern struct Box box;

#endif // CONFIG_H_INCLUDED
