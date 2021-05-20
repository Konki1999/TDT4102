#include "Tile.h"

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const map<int, Color> minesToColor{{1, Color::blue},
								   {2, Color::red},
								   {3, Color::dark_green},
								   {4, Color::dark_magenta},
								   {5, Color::dark_blue},
								   {6, Color::dark_cyan},
								   {7, Color::dark_red},
								   {8, Color::dark_yellow}};

// For aa sette Tilelabel i henhold til state
const map<Cell, string> cellToSymbol{{Cell::closed, ""},
									 {Cell::open, ""},
									 {Cell::flagged, "@<"}};

void Tile::open()
{
	if(this->getState() == Cell::closed){
		static_cast<Fl_Button *>(pw)->set(); //Setter en button som trykket paa, tilsvarer aapnet rute
		state = Cell::open;
		if(this->getIsMine()){
			this->set_label("X");
			this->set_label_color(Color::red);
		}
	}
}

void Tile::flag(){
	if(this->getState() == Cell::flagged){
		state = Cell::closed;
	}
	else if(this->getState() == Cell::closed){
		state = Cell::flagged;
		this->set_label_color(Color::blue);
	}
	this->set_label(cellToSymbol.at(state));
}

void Tile::setIsMine(bool is){
	isMine = is;
}

bool Tile::getIsMine() const{
	return isMine;
}

void Tile::setAdjMines(int n){
	if(n == 0){
		this->set_label("");
	}
	else{
		this->set_label(to_string(n));
		this->set_label_color(minesToColor.at(n));
	}
}