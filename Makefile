
all: Chess

Chess: Chesspieces.o Chess.o 
	g++ -o Chess Chess.o Chesspieces.o 

Chess.exe: Chesspieces.o Chess.o 
	g++ -o Chess.exe Chess.o Chesspieces.o 

Chess.o: Chess.cpp Chesspieces.o Tile.h Chesspieces.h
	g++ -c Chess.cpp

Chesspieces.o: Chesspieces.cpp Tile.h Chesspieces.h
	g++ -c Chesspieces.cpp

clean:
	rm -f Chess *.o Chess.exe