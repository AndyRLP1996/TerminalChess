
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "Tile.h"
#include "Chesspieces.h"

using namespace std;

void printBoard(tile board[8][8]);
void fillchessboard(tile board[8][8]);
void fillcheckersboard(tile board[8][8]);
int turn(tile board[8][8],int x1, int y1, int x2, int y2);
bool checkmatecheck(int color, tile board[8][8]);
void playerSelect();
void compSelect();
int inputParser(string input);

int main()
{
    tile board[8][8];
    int gameOver=0;
    string input;
    int move;
    int choice=0;
    srand(time(NULL));
    Piece* selected=NULL;
    cout<<"Choose a game:"<<endl<<"1.Chess"<<endl<<"2.Checkers"<<endl<<"0.Quit"<<endl;
    cin>>choice;
    cout<<endl;
    int x1,y1,x2,y2;
    int tempx1, tempy1, tempx2, tempy2;//used by computer for finding piece and tile to move to
    int blackWin=0;
    int whiteWin=0;
    if(choice==1)
    {
        fillchessboard(board);
    }
    if(choice==2)
    {
        fillcheckersboard(board);
    }
    if(choice==0)
    {
        return 0;
    }
    cout<<endl<<endl<<"Start the Game:"<<endl<<endl;
    //actual game occurs in here
    while(gameOver!=1)
    {
        bool validpiece=0;
        bool validmove=0;
        cout<<"current game state is:"<<endl;
        printBoard(board);
        cout<<"white's turn:"<<endl;
        while(validpiece!=1)
        {
            cout<<endl<<"please enter the coordinates of the piece you would like to move(or 99 to exit the game): "<<endl;
            cin.ignore();
            cin>>input;
            //insert input parser here:
            move=inputParser(input);
            x1=move/10;
            y1=move%10;
            cout<<endl<<"_"<<x1<<"_"<<y1<<"_"<<input<<endl;
            if(move==99)
            {
                cout<<"\n \n"<<"Thanks for Playing"<<"\n \n";
                return 0;
            }
            //insert check for input being in realm of array
            if(x1>-1&&x1<7&&y1>-1&&y1<7)
            {
                if(board[x1][y1].piecetype!=46 && board[x1][y1].link->color==0)
                {
                    selected=board[x1][y1].link;
                    validpiece=1;
                }
                else
                {
                    cout<<endl<<"Invalid entry, please try again.";
                }
            }
            else
            {
                cout<<endl<<"Invalid entry, please try again.";
            }
        }
        //insert call to getmoves for specified peice here
        selected->getMoves(x1,y1,board); //check for available moves for selected piece
        while(validmove!=1)
        {
            cout<<endl<<"please enter the coordinates you would like to move the piece to(or 99 to exit): "<<endl;
            cin.ignore();
            cin>>input;
            move=inputParser(input);
            x2=move/10;
            y2=move%10;
            cout<<endl<<"_"<<x2<<"_"<<y2<<"_"<<input<<endl;
            if(move==99)
            {
                cout<<"\n \n"<<"Thanks for Playing"<<"\n \n";
                return 0;
            }
            for(int i=0;i<selected->pmoves.size();i++)
            {
                cout<<"_"<<selected->pmoves[i]<<endl;
                if(((10*x2)+y2)==selected->pmoves[i])
                {
                    validmove=1;
                    //add move confirmation here
                }
            }
            if(validmove==0)
            {
                cout<<endl<<"Invalid entry, please try again.";
            }
        }
        whiteWin=turn(board,x1,y1,x2,y2);//actually moves pieces on board
        if(whiteWin==1)
        {
            cout<<"\n \n"<<"GAME OVER, WHITE WINS!!!"<<"\n \n";
            return 0;
        }
        //check for checkmate here
        cout<<"current game state is:"<<endl;
        //checkmatecheck(1,board);//checks if black is losing        
        printBoard(board);
        cout<<"black's turn:"<<endl;
        //black's turn here
        validpiece=0;
        validmove=0;
        while(validpiece!=1)//for computer turn a random number is generated, then the game checks if a valid piece lies in that space
        {
            tempx1=rand()%8;
            tempy1=rand()%8;
            if(tempx1>-1&&tempx1<7&&tempy1>-1&&tempy1<7)
            {
                if(board[tempx1][tempy1].piecetype!=46 && board[tempx1][tempy1].link->color==1)
                {
                    selected=board[tempx1][tempy1].link;
                    validpiece=1;
                }
            }
        }
        selected->getMoves(tempx1,tempy1,board);
        while(validmove!=1)
        {
            tempx2=rand()%8;
            tempy2=rand()%8;
            if(tempx2>-1&&tempx2<7&&tempy2>-1&&tempy2<7)
            {
                for(int i=0;i<selected->pmoves.size();i++)
                {
                    if(((10*tempx2)+tempy2)==selected->pmoves[i])
                    {
                        validmove=1;
                    }
                }
            }
        }
        blackWin=turn(board,tempx1,tempy1,tempx2,tempy2);//actually moves pieces on board
        if(blackWin==1)
        {
            cout<<"\n \n"<<"GAME OVER, BLACK WINS!!!"<<"\n \n";
            return 0;
        }
        //check for checkmate here
        //checkmatecheck(0,board);//check if white is losing
        printBoard(board);
        //return 3;
    }
}

void printBoard(tile board[8][8])//done
{
    for(int j=0;j<8;j++)
    {
        cout<<" +-+-+-+-+-+-+-+-+"<<endl;
        for(int i=0;i<8;i++)
        {
        	if(i==0)
        	{
        		cout<<(j+1);
        	}
            cout<<"|"<<(char)board[i][j].piecetype;
        }
        cout<<"|";
        cout<<endl;
    }
    cout<<" +-+-+-+-+-+-+-+-+"<<endl;
    cout<<"  A B C D E F G H "<<endl;
}

void fillchessboard(tile board[8][8])//done
{  
    //generate black rooks
        board[0][0].piecetype=82;
        board[0][0].link=new Rook(1);
        board[7][0].piecetype=82;
        board[7][0].link=new Rook(1);
    //generate white rooks
        board[0][7].piecetype=114;
        board[0][7].link=new Rook(0);
        board[7][7].piecetype=114;
        board[7][7].link=new Rook(0);
    //generate black knights
        board[1][0].piecetype=108;
        board[1][0].link=new Knight(1);
        board[6][0].piecetype=108;
        board[6][0].link=new Knight(1);
    //generate white knights
        board[1][7].piecetype=76;
        board[1][7].link=new Knight(0);
        board[6][7].piecetype=76;
        board[6][7].link=new Knight(0);
    //generate black bishops
        board[2][0].piecetype=66;
        board[2][0].link=new Bishop(1);
        board[5][0].piecetype=66;
        board[5][0].link=new Bishop(1);
    //generate white bishops
        board[2][7].piecetype=98;
        board[2][7].link=new Bishop(0);
        board[5][7].piecetype=98;
        board[5][7].link=new Bishop(0);
    //generate black queen
        board[4][0].piecetype=81;
        board[4][0].link=new Queen(1);
    //generate white queen
        board[3][7].piecetype=113;
        board[3][7].link=new Queen(0);
    //generate black king
        board[3][0].piecetype=75;
        board[3][0].link=new King(1);
    //generate white king
        board[4][7].piecetype=107;
        board[4][7].link=new King(0);
    //generate black pawns
	for(int i=0;i<8;i++)
    {
    	board[i][1].piecetype=80;
    	board[i][1].link=new Pawn(1);
    }
    //generate white pawns
    for(int i=0;i<8;i++)
    {
    	board[i][6].piecetype=112;
    	board[i][6].link=new Pawn(0);
    }
}

void fillcheckersboard(tile board[8][8])//NOT DONE
{
    cout<<"\n \n"<<"THIS FEATURE IS STILL UNDER CONSTRUCTION"<<"\n \n";
}

int turn(tile board[8][8], int x1, int y1, int x2, int y2)//should be done
{
    //Piece* mover=board[x1][y1].link;
    Piece* temp=board[x2][y2].link;
    int kingCheck;
    int temp1=107;
    int temp2=75;
    //case if move is to the same space as an enemy piece
    if(temp!=NULL)
    {
        kingCheck=temp->type;
        //add stattracking here
        board[x2][y2].piecetype=board[x1][y1].piecetype;
        board[x1][y1].piecetype=46;
        board[x2][y2].link=board[x1][y1].link;
        board[x1][y1].link=NULL;

        delete temp;
        if(kingCheck==temp1||kingCheck==temp2)
        {
            return 1;
        }
        return 0;
    }
    //case if move is to blank space
    else
    {
        board[x2][y2].piecetype=board[x1][y1].piecetype;
        board[x1][y1].piecetype=46;
        board[x2][y2].link=board[x1][y1].link;
        board[x1][y1].link=NULL;
    }
    //cout<<"turn complete";
}

bool checkmatecheck(int color, tile board[8][8])//not done//returns true if the side inputted is in check
{//takes board, color checking for, and x and y position of that side's king as input
    Piece* king;
    vector <Piece*> enemies;
    vector<int> enemyLocations;
    vector<int> checkLocations;
    int checkx, checky, tempx, tempy;
    int temp, temp2, kingInput;
    bool checked=0;
    for(int x=0;x<8;x++)//find the king
    {
        for(int y=0;y<8;y++)
        {
            if(board[x][y].link->color==color&&(board[x][y].piecetype==107||board[x][y].piecetype==75))
            {
                king=board[x][y].link;
                checkx=x;
                checky=y;
            }
        }
    }
    for(int x=0;x<8;x++)//find all the enemies
    {
        for(int y=0;y<8;y++)
        {
            if(board[x][y].link!=NULL)
            {
                if(board[x][y].link->color!=color)
                {
                    enemies.push_back(board[x][y].link);
                    enemyLocations.push_back((10*x)+y);
                }
            }
        }
    }
    //add conditional for if no enemies are in sight of the king
    temp=enemies.size();
    for(int i=0;i<temp;i++)
    {
        tempx=enemyLocations[i]/10;
        tempy=enemyLocations[i]%10;
        enemies[i]->getMoves(tempx,tempy,board);
    }
    kingInput=(10*checkx)+checky;

    for(int i=0;i<temp;i++)//runs through list of enemy team
    {
        temp2=enemies[i]->pmoves.size();
        for(int j=0;j<temp2;j++)//runs through possible moves of each piece on enemy team
        {
            if(kingInput==enemies[i]->pmoves[j])
            {
                checked=1;
                checkLocations.push_back(enemyLocations[i]);
            }
        }
    }
}

int inputParser(string input)//should be done//X will be a letter between A and H, Y will be an int between 1 and 8, 99 is the exit code
{
    int x, y, z;
    x=(int)input[0];
    x=x-65;
    y=(int)input[1];
    y=y-49;
    z=(10*x)+y;
    cout<<"z:"<<z;
    if(z==-72)
    {
        z=99;
    }
    return z;//move returned as an int between 11 and 88, which is then converted to 2 ints between 0 and 7
}
