#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "Tile.h"
#include "Chesspieces.h"

using namespace std;

//Tile Functions
    tile::tile()
    {
        piecetype=46;
        link=NULL;
    }
     //done

//Base Class for Piece Functions //done
    Piece::Piece()
    {
        color=2;
        type=0;
    }
    Piece::Piece(const Piece& pc)
    {
    	color=pc.color;
    	type=pc.type;
    }
    //virtual int Piece::getMoves() //takes board as input and returns possible moves for a piece to move,
    //{}//moves handled externally
    void Piece::getMoves(int x, int y, tile board[8][8])
    {}

//Pawn Functions //done
    Pawn::Pawn(int temp)
    {
        if(temp==0)
        {
            type=112;
            color=0;
        }
        else
        {
            type=80;
            color=1;
        }
        first=0;
    }

    void Pawn::getMoves(int x, int y, tile board[8][8])//returns an array containing possible moves in the form xy
    {
        pmoves.clear();
        if(color==1)//black move case
        {
            if(first==0)
            {
                pmoves.push_back((10*x)+y+2);
                first=1;
            }
            if(board[x][y+1].link==NULL)
            {
                pmoves.push_back((10*x)+y+1);
            }
            if(board[x-1][y+1].link!=NULL && board[x-1][y+1].link->color!=0)
            {
                pmoves.push_back((10*(x+1))+y+1);
            }
            if(board[x+1][y+1].link!=NULL && board[x+1][y+1].link->color!=0)
            {
                pmoves.push_back((10*(x+1))+y+1);
            }
        }
        else//white move case
        {
            if(first==0)
            {
                pmoves.push_back((10*x)+y-2);
                first=1;
            }
            if(board[x][y-1].link==NULL)
            {
                pmoves.push_back((10*x)+y-1);
            }
            if(board[x-1][y-1].link!=NULL && board[x-1][y-1].link->color==0)
            {
                pmoves.push_back((10*(x+1))+y-1);
            }
            if(board[x+1][y-1].link!=NULL && board[x+1][y-1].link->color==0)
            {
                pmoves.push_back((10*(x+1))+y-1);
            } 
        }
    }

//Rook Functions //done
    Rook::Rook(int temp)
    {
        if(temp==0)
        {
            type=114;
            color=0;
        }
        else
        {
            type=82;
            color=1;
        }
    }
    void Rook::getMoves(int x, int y, tile board[8][8])
    {
        pmoves.clear();
        int tempx1,tempx2,tempy1,tempy2=0;
        for(int i=x-1;0<=i;i--)//from piece to left edge of board
        {
            if(board[i][y].link==NULL && tempx1==0)
            {
                pmoves.push_back((10*i)+y);
            }
            if(board[i][y].link!=NULL)
            {
                if(board[i][y].link->color!=color)
                {
                    pmoves.push_back((10*i)+y);
                }
                else
                {
                    tempx1=1;
                }
            }
        }
        for(int i=x+1;i<=7;i++)//from piece to right edge of board
        {
            if(board[i][y].link==NULL && tempx2==0)
            {
                pmoves.push_back((10*i)+y);
            }
            if(board[i][y].link!=NULL)
            {
                if(board[i][y].link->color!=color)
                {
                    pmoves.push_back((10*i)+y);
                }
                else
                {
                    tempx2=1;
                }
            }
        }
        for(int i=y-1;0<=i;i--)//from piece to top edge of board
        {
            if(board[x][i].link==NULL && tempy1==0)
            {
                pmoves.push_back((10*x)+i);
            }
            if(board[x][i].link!=NULL)
            {
                if(board[x][i].link->color!=color)
                {
                    pmoves.push_back((10*x)+i);
                }
                else
                {
                    tempy1=1;
                }
            }
        }
        for(int i=y+1;i<=7;i++)//from piece to bottom edge of board
        {
            if(board[x][i].link==NULL && tempy2==0)
            {
                pmoves.push_back((10*x)+i);
            }
            if(board[x][i].link!=NULL)
            {
                if(board[x][i].link->color!=color)
                {
                    pmoves.push_back((10*x)+i);
                }
                else
                {
                    tempy2=1;
                }
            }
        }
        //return pmoves;
    }

//Knight Functions //maybe done
    Knight::Knight(int temp)//done
    {
        if(temp==0)
        {
            type=108;
            color=0;
        }
        else
        {
            type=76;
            color=1;
        }
    }
    void Knight::getMoves(int x, int y, tile board[8][8])//MAYBE done
    {
        pmoves.clear();
        //x is 1, y is 2
            if(board[x+1][y+2].link==NULL)
            {
                pmoves.push_back((10*(x+1))+(y+2));
            }
            else if(board[x+1][y+2].link->color!=color)
            {
                pmoves.push_back((10*(x+1))+(y+2));
            }
        //x is 2, y is 1
            if(board[x+2][y+1].link==NULL)
            {
                pmoves.push_back((10*(x+2))+(y+1));
            }
            else if(board[x+2][y+1].link->color!=color)
            {
                pmoves.push_back((10*(x+2))+(y+1));
            }
        //x is -1, y is -2
            if(board[x-1][y-2].link==NULL)
            {
                pmoves.push_back((10*(x-1))+(y-2));
            }
            else if(board[x-1][y-2].link->color!=color)
            {
                pmoves.push_back((10*(x-1))+(y-2));
            }
        //x is -2, y is -1
            if(board[x-2][y-1].link==NULL)
            {
                pmoves.push_back((10*(x-2))+(y-1));
            }
            else if(board[x-2][y-1].link->color!=color)
            {
                pmoves.push_back((10*(x-2))+(y-1));
            }
        //x is 1, y is -2
            if(board[x+1][y-2].link==NULL)
            {
                pmoves.push_back((10*(x+1))+(y-2));
            }
            else if(board[x+1][y-2].link->color!=color)
            {
                pmoves.push_back((10*(x+1))+(y-2));
            }
        //x is -1, y is 2
            if(board[x-1][y+2].link==NULL)
            {
                pmoves.push_back((10*(x-1))+(y+2));
            }
            else if(board[x-1][y+2].link->color!=color)
            {
                pmoves.push_back((10*(x-1))+(y+2));
            }
        //x is 2, y is -1
            if(board[x+2][y-1].link==NULL)
            {
                pmoves.push_back((10*(x+2))+(y-1));
            }
            else if(board[x+2][y-1].link->color!=color)
            {
                pmoves.push_back((10*(x+2))+(y-1));
            } 
        //x is -2, y is 1
             if(board[x-2][y+1].link==NULL)
            {
                pmoves.push_back((10*(x-2))+(y+1));
            }
            else if(board[x-2][y+1].link->color!=color)
            {
                pmoves.push_back((10*(x-2))+(y+1));
            }
    }

//Bishop Functions //done
    Bishop::Bishop(int temp)//done
    {
        if(temp==0)
        {
            type=98;
            color=0;
        }
        else
        {
            type=66;
            color=1;
        }
    }
    void Bishop::getMoves(int x, int y, tile board[8][8])//done
    {
        pmoves.clear();
        int tempx1=0;
        int tempx2=0;
        int tempy1=0;
        int tempy2=0;
        int j1,j2,j3,j4;
        j1,j2=y-1; //j1 and j2 are used for top side of board (above piece)
        j3,j4=y+1;//j3 and j4 are used for bottom side of board (below the piece)
        for(int i=x-1;0<=i;i--)//from piece to top left corner (or as far as piece can go)
        {
            if(0<=j1)
            {
            	if(board[i][j1].link==NULL && tempx1==0)
	            {
	                pmoves.push_back((10*i)+j1);
	            }
	            if(board[i][j1].link!=NULL)
            	{
	                if(board[i][j1].link->color!=color)
	                {
	                    pmoves.push_back((10*i)+j1);
	                }
	                else
	                {
	                    tempx1=1;
	                }
	            }
            }
            j1--;
        }
        for(int i=x+1;i<=7;i++)//from piece to top right corner (or as far as piece can go)
        {
        	if(0<=j2)
            {
            	if(board[i][j2].link==NULL && tempx2==0)
	            {
	                pmoves.push_back((10*i)+j2);
	            }
	            if(board[i][j2].link!=NULL)
            	{
	                if(board[i][j2].link->color!=color)
	                {
	                    pmoves.push_back((10*i)+j2);
	                }
	                else
	                {
	                    tempx2=1;
	                }
	            }
            }
            j2--;
        }
        for(int i=x-1;0<=i;i--)//from piece to bottom left (or as far as piece can go)
        {
            if(j3<=7)
            {
            	if(board[i][j3].link==NULL && tempy1==0)
	            {
	                pmoves[i+8]=(10*i)+j3;
	            }
	            if(board[i][j3].link!=NULL)
            	{
	                if(board[i][j3].link->color!=color)
	                {
	                    pmoves[i+8]=(10*i)+j3;
	                }
	                else
	                {
	                    tempy1=1;
	                }
	            }
            }
            j3++;
        }
        for(int i=x+1;i<=7;i++)//from piece to bottom right (or as far as piece can go)
        {
        	if(j4<=7)
            {
            	if(board[i][j4].link==NULL && tempy2==0)
	            {
	                pmoves[i+8]=(10*i)+j4;
	            }
	            if(board[i][j4].link!=NULL)
            	{
	                if(board[i][j4].link->color!=color)
	                {
	                    pmoves[i+8]=(10*i)+j4;
	                }
	                else
	                {
	                    tempy2=1;
	                }
	            }
            }
            j4++;
        }
        //return pmoves;
    }

//King Functions //done
    King::King(int temp)//done
    {        
        if(temp==0)
        {
            type=107;
            color=0;
        }
        else
        {
            type=75;
            color=1;
        }
    }
    void King::getMoves(int x, int y, tile board[8][8])//done
    {
        pmoves.clear();
    	if(board[x+1][y].link==NULL || board[x+1][y].link->color!=color)
    	{
    		pmoves.push_back(10*(x+1)+y);
    	}
    	if(board[x-1][y].link==NULL || board[x-1][y].link->color!=color)
    	{
    		pmoves.push_back(10*(x-1)+y);
    	}
    	if(board[x][y+1].link==NULL || board[x][y+1].link->color!=color)
    	{
    		pmoves.push_back((10*x)+y+1);
    	}
    	if(board[x][y-1].link==NULL || board[x][y-1].link->color!=color)
    	{
    		pmoves.push_back((10*x)+y-1);
    	}
    	//return pmoves;
    }

//Queen Functions //maybe done
    Queen::Queen(int temp)//done
    {
        if(temp==0)
        {
            type=113;
            color=0;
        }
        else
        {
            type=81;
            color=1;
        }
    }
    void Queen::getMoves(int x, int y, tile board[8][8])//MAYBE DONE
    {
        pmoves.clear();
        int tempx1=0;
        int tempx2=0;
        int tempx3=0;
        int tempx4=0;
        int tempy1=0;
        int tempy2=0;
        int tempy3=0;
        int tempy4=0;
        int j1,j2,j3,j4;
        j1,j2=y-1; //j1 and j2 are used for top side of board (above piece)
        j3,j4=y+1;//j3 and j4 are used for bottom side of board (below the piece)
        for(int i=x-1;0<=i;i--)//from piece to top left corner (or as far as piece can go)
        {
            if(0<=j1)
            {
            	if(board[i][j1].link==NULL && tempx1==0)
	            {
	                pmoves.push_back((10*i)+j1);
	            }
	            if(board[i][j1].link!=NULL)
            	{
	                if(board[i][j1].link->color!=color)
	                {
	                    pmoves.push_back((10*i)+j1);
	                }
	                else
	                {
	                    tempx1=1;
	                }
	            }
            }
            j1--;
        }
        for(int i=x+1;i<=7;i++)//from piece to top right corner (or as far as piece can go)
        {
        	if(0<=j2)
            {
            	if(board[i][j2].link==NULL && tempx2==0)
	            {
	                pmoves.push_back((10*i)+j2);
	            }
	            if(board[i][j2].link!=NULL)
            	{
	                if(board[i][j2].link->color!=color)
	                {
	                    pmoves.push_back((10*i)+j2);
	                }
	                else
	                {
	                    tempx2=1;
	                }
	            }
            }
            j2--;
        }
        for(int i=x-1;0<=i;i--)//from piece to bottom left (or as far as piece can go)
        {
            if(j3<=7)
            {
            	if(board[i][j3].link==NULL && tempy1==0)
	            {
	                pmoves[i+8]=(10*i)+j3;
	            }
	            if(board[i][j3].link!=NULL)
            	{
	                if(board[i][j3].link->color!=color)
	                {
	                    pmoves[i+8]=(10*i)+j3;
	                }
	                else
	                {
	                    tempy1=1;
	                }
	            }
            }
            j3++;
        }
        for(int i=x+1;i<=7;i++)//from piece to bottom right (or as far as piece can go)
        {
        	if(j4<=7)
            {
            	if(board[i][j4].link==NULL && tempy2==0)
	            {
	                pmoves[i+8]=(10*i)+j4;
	            }
	            if(board[i][j4].link!=NULL)
            	{
	                if(board[i][j4].link->color!=color)
	                {
	                    pmoves[i+8]=(10*i)+j4;
	                }
	                else
	                {
	                    tempy2=1;
	                }
	            }
            }
            j4++;
        }
        //return pmoves;
         for(int i=x-1;0<=i;i--)//from piece to left edge of board
        {
            if(board[i][y].link==NULL && tempx3==0)
            {
                pmoves.push_back((10*i)+y);
            }
            if(board[i][y].link!=NULL)
            {
                if(board[i][y].link->color!=color)
                {
                    pmoves.push_back((10*i)+y);
                }
                else
                {
                    tempx3=1;
                }
            }
        }
        for(int i=x+1;i<=7;i++)//from piece to right edge of board
        {
            if(board[i][y].link==NULL && tempx4==0)
            {
                pmoves.push_back((10*i)+y);
            }
            if(board[i][y].link!=NULL)
            {
                if(board[i][y].link->color!=color)
                {
                    pmoves.push_back((10*i)+y);
                }
                else
                {
                    tempx4=1;
                }
            }
        }
        for(int i=y-1;0<=i;i--)//from piece to top edge of board
        {
            if(board[x][i].link==NULL && tempy3==0)
            {
                pmoves.push_back((10*x)+i);
            }
            if(board[x][i].link!=NULL)
            {
                if(board[x][i].link->color!=color)
                {
                    pmoves.push_back((10*x)+i);
                }
                else
                {
                    tempy3=1;
                }
            }
        }
        for(int i=y+1;i<=7;i++)//from piece to bottom edge of board
        {
            if(board[x][i].link==NULL && tempy4==0)
            {
                pmoves.push_back((10*x)+i);
            }
            if(board[x][i].link!=NULL)
            {
                if(board[x][i].link->color!=color)
                {
                    pmoves.push_back((10*x)+i);
                }
                else
                {
                    tempy4=1;
                }
            }
        }
    }

//Checkers Functions //not done
    Checker::Checker(int temp)
    {

    }
    void Checker::getMoves(int x, int y, tile board[8][8])
    {
        pmoves.clear();

    }
