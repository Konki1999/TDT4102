#include "utilities.h"
#include <cstdlib>

int randomWithLimits(int lower, int upper){
    return lower + rand()%(upper-lower+1);
}