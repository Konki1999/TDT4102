#include "MinesweeperWindow.h"

MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize, title}, width{width}, height{height}, mines{mines}
	//Initialiser medlemsvariabler, bruker konstruktoren til Windowsklassen
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.push_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize, cb_click });
			attach(tiles.back());
		}
	}

	//Legg til miner paa tilfeldige posisjoner
	std::vector<int> placed(mines); //Lokasjon til allerede plasserte miner
	int counter{0};
	while(counter < mines){
		int index = rand()%(tiles.size());
		if(std::find(placed.begin(),placed.end(),index) == placed.end()){
			placed[counter] = index;
			counter++;
			tiles[index].setIsMine(true);
		}
	}
	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}


vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

int MinesweeperWindow::countMines(vector<Point> coords) const{
	int mineCount{0};
	for(Point xy : coords){
		if(at(xy).getIsMine()){
			mineCount++;
		}
	}
	return mineCount;
}

void MinesweeperWindow::openTile(Point xy) {
	Tile& t = at(xy);
	t.open();
	if(!at(xy).getIsMine()){
		vector<Point> neighbours = adjacentPoints(xy);
		int mineCount = countMines(neighbours);
		at(xy).setAdjMines(mineCount);
		
		vector<Point> neighboursToCheck;
		for(Point q : neighbours){
			if(at(q).getState() == Cell::closed){
				neighboursToCheck.push_back(q);
			}
		}
		if(mineCount == 0){
			for(Point p : neighboursToCheck){
				openTile(p);
			}
		}
	}
}

void MinesweeperWindow::flagTile(Point xy) {
	Tile& t = at(xy);
	t.flag();
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	Point xy{Fl::event_x(), Fl::event_y()};

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	if (!inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}

	flush();
}
