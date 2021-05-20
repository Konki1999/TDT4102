#include "MinesweeperWindow.h"
#include <cmath>
#include <time.h>

int main()
{
	srand(time(0));
	
	Fl::background(200, 200, 200);
	constexpr int width = 10;
	constexpr int height = 10;
	constexpr int mines = 20;

	Point startPoint{ 200,300 };
	MinesweeperWindow mw{ startPoint, width, height, mines, "Minesweeper" };
	return gui_main();
}
