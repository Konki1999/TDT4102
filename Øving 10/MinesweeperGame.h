#include "MinesweeperWindow.h"

enum class GameState{won, lost, going};

class MinesweeperGame{
private:
    GameState gameState = GameState::going;
    int mines;
    int xTiles;
    int yTiles;
public:
    MinesweeperGame(int mines, int xTiles, int yTiles);
};