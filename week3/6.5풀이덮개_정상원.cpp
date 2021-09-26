const int count = 0;

void next(int* x, int* y, int row)
{
	if(x* == row)
	{
		*x = 0;
		*y = *y + 1;
	}
	else
	{
		*x = *x + 1;
	}
}

bool inRange(int x, int y, int row, int column)
{
	if(x < 0 && x >= row)
		return false;
	if(y < 0 && y >= column)
		return false;

	return true;
}

void letscount(int startX, int startY,  vector<vector<int> & board)
{
	int curX = startX;
	int curY = startY;
	bool completed = true;
	int column = board.size();
	int row;
	for(; curY < column; curY++)
	{
		row = board[curY].size();

		for(; curX < row; curX++)
		{
			if(board[curY][curX] == 0)
			{
				completed = false;
				break;
			}

		}
		
		if(!completed)
			break;
	}

	if(completed)
	{
		count++;
		return;
	}
	board[curY][curX] = 1;

	if(inRange(curX + 1, curY, row , column) && inRange(curX, curY + 1, row, column)
		&& board[curY][curX + 1] == 0 && board[curY + 1][curX] == 0)
	{
		board[curY][curX + 1] = 1;
		board[curY + 1][curX] = 1;
		int nextX = curX + 1;
		int nextY = curY;
		next(nextX, nextY);
		letsCount(nextX, nextY, board);
		board[curY][curX + 1] = 0;
		board[curY + 1][curX] = 0;
	}

	if(inRange(curX + 1, curY, row , column) && inRange(curX + 1, curY + 1, row, column)
		&& board[curY][curX + 1] == 0 && board[curY + 1][curX + 1] == 0)
	{
		board[curY][curX + 1] = 1;
		board[curY + 1][curX + 1] = 1;
		int nextX = curX + 1;
		int nextY = curY;
		next(nextX, nextY);
		letsCount(nextX, nextY, board);
		board[curY][curX + 1] = 0;
		board[curY + 1][curX + 1] = 0;
	}

	if(inRange(curX, curY + 1, row , column) && inRange(curX + 1, curY + 1, row, column)
		&& board[curY + 1][curX] == 0 && board[curY + 1][curX + 1] == 0)
	{
		board[curY + 1][curX] = 1;
		board[curY + 1][curX + 1] = 1;
		int nextX = curX;
		int nextY = curY;
		next(nextX, nextY);
		letsCount(nextX, nextY, board);
		board[curY  + 1][curX] = 0;
		board[curY + 1][curX + 1] = 0;
	}
	
	if(inRange(curX, curY + 1, row , column) && inRange(curX - 1, curY + 1, row, column)
		&& board[curY + 1][curX] == 0 && board[curY + 1][curX - 1] == 0)
	{
		board[curY + 1][curX] = 1;
		board[curY + 1][curX - 1] = 1;
		int nextX = curX + 1;
		int nextY = curY;
		next(nextX, nextY);
		letsCount(nextX, nextY, board);
		board[curY + 1][curX] = 0;
		board[curY + 1][curX - 1] = 0;
	}
	

	board[curY][curX] = 0;
}