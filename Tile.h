#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#ifndef CHESSPIECES_H
#ifndef TILE_H
#define CHESSPIECES_H
#define TILE_H

using namespace std;

class Piece;

class tile //structure for array used to simulate board.
{
    public:
    tile();
    int piecetype;
    Piece* link;
};
#endif
#endif