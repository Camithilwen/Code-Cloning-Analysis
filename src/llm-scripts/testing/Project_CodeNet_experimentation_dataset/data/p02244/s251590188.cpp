#include <iostream>
#include <vector>
//---------------------------------------------------------------------------

enum TSquareState
{
	ssPlaceable,
	ssAttacked,
	ssQueen
};

typedef std::vector<std::vector<TSquareState> > TBoard;
//---------------------------------------------------------------------------

TBoard PutQueen(const TBoard& PreBoard, int Row, int Col)
{
	TBoard Board = PreBoard;

	for(int i = 0; i < 8; ++i){
		Board[Row][i] = ssAttacked;
	}
	for(int i = 0; i < 8; ++i){
		Board[i][Col] = ssAttacked;
	}
	for(int i = Row, j = Col; i < 8 && j < 8; ++i, ++j){
		Board[i][j] = ssAttacked;
	}
	for(int i = Row, j = Col; i >= 0 && j >= 0; --i, --j){
		Board[i][j] = ssAttacked;
	}
	for(int i = Row, j = Col; i < 8 && j >= 0; ++i, --j){
		Board[i][j] = ssAttacked;
	}
	for(int i = Row, j = Col; i >= 0 && j < 8; --i, ++j){
		Board[i][j] = ssAttacked;
	}
	Board[Row][Col] = ssQueen;
	return Board;
}
//---------------------------------------------------------------------------

bool PutQueens(TBoard& Board, int QueenCount)
{
	if(QueenCount == 0) return true;
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			TBoard TempBoard = PutQueen(Board, i, j);
			if(Board[i][j] == ssPlaceable && PutQueens(TempBoard, QueenCount - 1)){
				Board = TempBoard;
				return true;
			}
		}
	}
	return false;
}
//---------------------------------------------------------------------------

void OutputEightQueens(const TBoard& Board, std::ostream& Stream)
{
	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 8; ++j){
			char Square = Board[i][j] == ssQueen ? 'Q' : '.';
			Stream << Square;
		}
		Stream << std::endl;
	}
}
//---------------------------------------------------------------------------

int main()
{
	int Count;
	std::cin >> Count;
	
	TBoard Board(8, std::vector<TSquareState>(8, ssPlaceable));
	for(int i = 0; i < Count; ++i){
		int Row, Col;
		std::cin >> Row >> Col;
		Board = PutQueen(Board, Row, Col);
	}
	PutQueens(Board, 8 - Count);
	OutputEightQueens(Board, std::cout);
	return 0;
}