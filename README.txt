CONSOLE CHESS V0.1(alpha):
A terminal (or cmd) based chess game.
Currently implemented for 1 player as white side.
Authored by Andrew Parkhurst in 2018.
Compiled with gcc v5.4

THIS PROGRAM IS STILL UNDER DEVELOPMENT AND CONTAINS BUGS.

KNOWN BUGS:
	input parser broken
	

HOW TO PLAY:
	This program is capable of playing single player checkers(coming soon) or chess.
	To play, enter the coordinates of the piece you would like to move,
	Then enter the coordinates you would like to move it to.
	Code 99 will exit the program.
	Input must be in the form (letternumber) with no spaces. letter must come before number
	Rules are the same as chess, though special moves such as Castling and En Passent are not implemented
	Pieces are represented with the first ASCII character in their name (e.g. pawn is P or p)
		Black pieces are upper case, white are lower case
		Knights are represented by L, since K was in use for King
	The game (should) end when either king is removed from the board

Current methods of exiting the game are:
	-Win
	-Lose
	-Enter code 99 when declaring a move


To Do List:

	move piece selection and move selection to own function(s) and out of main

	change 99 from exit program to return to piece select

	add non-capital letter input capability

	upgrade input parser to handle wierd formatting

	NOTE: ROOKS AND MAYBE OTHER PIECES ARE CURRENTLY CAPABLE OF DEFYING THE RULES
		Specifically, Rooks are currently capable of moving over pawns, possibly other pieces (error is likely in getmoves)

	add ability for 2 player game or 2 computer game (move computer turn code and player turn code to seperate functions)

	make computer player smarter than a chimp
		play rather than simply moving random pieces

	for checkmatecheck:
		start by finding king of chosen color
		call getmoves for each piece of opposite color, then check if the king is in a spot in one of those spaces
		if so, warn the upcoming player (or computer)
			for computer, make it move the king
		tell the player where they are being checked from

Reference Material:

	pieces:
	white lower case
	black upper case

	. (46) is empty space

	white:
	pawn=112
	rook=114
	knight=108
	bishop=98
	king=107
	queen=113

	black:
	pawn=80
	rook=82
	knight=76
	bishop=66
	king=75
	queen=81

	white is 0, black is 1 (constructors)