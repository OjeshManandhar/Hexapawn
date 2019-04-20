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

typedef struct position_detail position_detail;

//Local Variables
typedef enum Box_Status             //For checking whether a piece is selected or not
{
    selected = 0, blank = 0
} Box_Status;

typedef struct Box
{
    Box_Status status;
    position_detail position;
} Box;

typedef enum Piece_Status
{
    dead = 0, alive = 1
} Piece_Status;

typedef struct Pieces
{
    Piece_Status status;
    position_detail position;
} Pieces;

typedef struct Character
{
    unsigned char sign;
    Pieces piece[COL];
} Character;

//Global Variables Declaration
extern uint8_t round_no;

extern position_detail scr_size;         //console size

extern char board[ROW][COL];            //pointer to store the board matrix/array

extern Character computer, player;

extern Box box;

#endif // CONFIG_H_INCLUDED
