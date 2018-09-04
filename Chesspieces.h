#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
//#ifndef TILE_H
//#ifndef CHESSPIECES_H
#define TILE_H
#define CHESSPIECES_H

using namespace std;

class tile;

class Piece //parent class for both all pieces, done
{
    public:
    Piece();
    Piece(const Piece& pc);
    virtual void getMoves(int x, int y, tile board[8][8]);
    //virtual void getMoves(); //takes board as input and returns possible moves for a piece to move,
   	//moves handled externally
    int color;
    int type;
        vector<int> pmoves;
};

class Pawn : public Piece//done
{
    public:
    Pawn(int temp);
    void getMoves(int x, int y, tile board[8][8]);//returns an array containing possible moves in the form xy
    int first;
};

class Rook : public Piece//done
{
    public:
    Rook(int temp);
    void getMoves(int x, int y, tile board[8][8]);
};

class Knight : public Piece//done
{
    public:
    Knight(int temp);//done
    void getMoves(int x, int y, tile board[8][8]);
};

class Bishop : public Piece//done
{
    public:
    Bishop(int temp);//done
    void getMoves(int x, int y, tile board[8][8]);//done
};

class King : public Piece//done
{
    public:
    King(int temp);//done
    void getMoves(int x, int y, tile board[8][8]);//done
};

class Queen : public Piece//done
{
    public:
    Queen(int temp);//done
    void getMoves(int x, int y, tile board[8][8]);
};

class Checker : public Piece//done
{
    public:
    Checker(int temp);
    void getMoves(int x, int y, tile board[8][8]);
};

//#endif
//#endif