#ifndef POSITION_H
#define POSITION_H


struct Position{

    int x1_position;
    int x2_position;
    int y1_position;
    int y2_position;

    Position():x1_position(0),x2_position(0),y1_position(0),y2_position(0){}
    Position(int x1, int x2, int y1, int y2):x1_position(x1),x2_position(x2),y1_position(y1),y2_position(y2){}
};

#endif