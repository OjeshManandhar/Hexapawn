#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

//front_end.c
void draw_board();
void put_pieces();
void draw_box_around_piece(unsigned short int type);

//back_end.c
void set_initial_data();
void fill_board();

#endif // HEADER_H_INCLUDED
