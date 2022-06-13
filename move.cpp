#include<iostream>
#include<string>
#include<algorithm>

char WALL = ((int)176);

using namespace std;

char board[10][10] = {
	{176,176,176,176,176,176,176,176,176,176},
	{176,' ',' ',' ',176,' ',' ',176,' ',176},
	{176,176,176,' ',176,' ',176,176,' ',176},
	{176,' ',' ',' ',176,' ',176,' ',' ',176},
	{176,' ',176,176,176,' ',' ',' ',176,176},
	{176,' ',' ',' ',176,' ',176,176,' ',176},
	{176,176,176,' ',176,' ',' ',176,' ',176},
	{176,' ',' ',' ',176,176,' ',176,' ',176},
	{176,' ',' ',' ',' ',' ',' ',176,' ',176},
	{176,176,176,176,176,176,176,176,176,176} };

int checkposition(int x, int y)
{
	if ( board[x][y] == ((char) 176) ) {
		cout << "tu jest sciana" << endl;
		return -1;
	}
	return 0;
}

void printTable(char board[10][10])
{
	int y, x;
	for (y = 0; y < 10; y++)
	{
		for (x = 0; x < 10; x++)
			std::cout << board[y][x] << board[y][x];
		std::cout << std::endl;

	}
}

int main()
{
	
	printTable(board);

	int xmove = 1;
	int ymove = 1;
	int xposition = 0;
	int yposition = 0;
	string choiceDirection = "";


	cout << checkposition(xposition, yposition);
	while (true)
	{
		cin >> choiceDirection;
		transform(choiceDirection.begin(), choiceDirection.end(), choiceDirection.begin(), ::toupper);



		if (choiceDirection == "N" || choiceDirection == "NORTH") {
			ymove--;
			
			if (checkposition(xmove,ymove) == 0)
				yposition = ymove;
		}

		if (choiceDirection == "S" || choiceDirection == "SOUTH") {
			ymove++;
			if (checkposition(xmove, ymove) == 0)
				yposition = ymove;
		}
		if (choiceDirection == "W" || choiceDirection == "WEST") {
			xmove--;
			if (checkposition(xmove, ymove) == 0)
				xposition = xmove;
		}
		if (choiceDirection == "E" || choiceDirection == "EAST") {
			xmove++;
			if (checkposition(xmove, ymove) == 0)
				xposition = xmove;
		}
		if (choiceDirection == "NE" || choiceDirection == "NORTHEAST")
		{
			ymove--;
			xmove--;
			if (checkposition(xmove, ymove) == 0)
				xposition = xmove;
				yposition = ymove;
		};
		if (choiceDirection == "NW" || choiceDirection == "NORTHWEST")
		{
			ymove--;
			xmove++;
			if (checkposition(xmove, ymove) == 0)
				xposition = xmove;
				yposition = ymove;
		}
		if (choiceDirection == "SW" || choiceDirection == "SOUTHEAST")
		{
			ymove++;
			xmove--;
			if (checkposition(xmove, ymove) == 0)
				xposition = xmove;
				yposition = ymove;
		}
		if (choiceDirection == "SE" || choiceDirection == "SOUTHWEST")
		{
			ymove++;
			xmove++;
			if (checkposition(xmove, ymove) == 0)
				xposition = xmove;
				yposition = ymove;
		}
		cout << xmove << "," << ymove;
	}
}
