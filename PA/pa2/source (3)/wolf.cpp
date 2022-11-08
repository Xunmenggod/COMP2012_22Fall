#include "wolf.h"
#include "sheep.h"
#include "grass.h"
#include "helper.h"

/**
 * TODO: TASK 4
 * 
 * Place a copy of this Wolf onto nextGrid at the specified position.
 * You may implement this similar to Sheep::putSelf().
*/
void Wolf::putSelf(Grid* nextGrid, const int x, const int y) {
    Wolf* wolfCopy = new Wolf(*this);
    if (putAnimal(wolfCopy, nextGrid, x, y)) {
        setNextSelf(wolfCopy);
    }
}

/**
 * TODO: TASK 4
 * 
 * Place a brand new Wolf onto nextGrid at the specified position.
 * You may implement this similar to Sheep::putClone().
*/
void Wolf::putClone(Grid* nextGrid, const int x, const int y) const {
    Wolf* newWolf = new Wolf(getBoard());
    putAnimal(newWolf, nextGrid, x, y);
}

/**
 * TODO: TASK 4
 * 
 * Implement this function similar to Sheep::eat().
 * The only difference is that Wolf eats Sheep instead of Grass.
*/
void Wolf::eat(Grid* nextGrid) {
    for (int i=0; i<9; ++i) {
        if (i == 4) continue;
        int adjX = getX() + getAdjX(i);
        int adjY = getY() + getAdjY(i);
        Entity* adjEntity = getBoard()->getGrid()->getCell(adjX, adjY);

        if (!adjEntity) {
            // Out of bounds or empty space, ignore
            continue;
        }

        // ?
        if (adjEntity->toChar() == 'S') {
            if (!adjEntity->isRemoved()) {
                adjEntity->removeSelf(nextGrid);
                setHungerCounter(WOLF_HUNGER_COOLDOWN);
                break;
            }
        }
    }
}

/**
 * TODO: TASK 4
 * 
 * Implement this function similar to Sheep::breed().
 * The only difference is that Wolf breeds by finding a Wolf instead of Sheep.
*/
void Wolf::breed(Grid* nextGrid) {
    for (int i=0; i<9; ++i) {
        if (i == 4) continue;
        int adjX = getX() + getAdjX(i);
        int adjY = getY() + getAdjY(i);
        Entity* adjEntity = getBoard()->getGrid()->getCell(adjX, adjY);

        if (!adjEntity) {
            // Out of bounds or empty space, ignore
            continue;
        }

        // ?
        if (adjEntity->toChar() == 'W') {
            int randomIndex = getRandomMovementIndex(nextGrid);
            if (randomIndex != -1) {
                putClone(nextGrid, getX() + getAdjX(randomIndex), getY() + getAdjY(randomIndex));
                setBreedCounter(WOLF_BREED_COOLDOWN);
                break;
            }
        }
    }
}

/**
 * TODO: TASK 4
 * 
 * If there is at least one Sheep on the board, Wolf tries to move towards it.
 * 
 * You should loop over the board in the same order as Board calling update(), 
 * calculate Euclidean distance to each cell containing a Sheep, and keep track of the shortest distance found.
 * Ignore sheeps that have been eaten (removed).
 * No need to keep track of Sheeps with the same distance as shortest one found so far.
 * 
 * If a Sheep is found, move to the adjacent cell closest to that Sheep. If that cell is occupied with another Animal,
 * the Wolf stays at its position.
 * 
 * If no Sheep is found, the Wolf moves randomly like a Sheep.
 * 
 * You may follow the structure below to implement the function.
*/
void Wolf::move(Grid* nextGrid) {
    // First, find a sheep to target
    float shortestDisatnce = 100000;
    Sheep* closetSheep = nullptr;
    // ?
    for (int x=0; x<BOARD_SIZE_W; ++x) {
        for (int y=0; y<BOARD_SIZE_H; ++y) {

            // ?
            
            Entity* entity = getBoard()->getGrid()->getCell(x, y);
            
            if (entity && entity->toChar() == 'S') {
                float distance = (getX() - x) * (getX() - x) + (getY() - y) * (getY() - y);
                if (distance < shortestDisatnce) {
                    shortestDisatnce = distance;
                    closetSheep = static_cast<Sheep*>(entity);
                }
            }

        }
    }

    if (closetSheep) { // Edit this line with the appropriate condition
        // If a sheep with the closest distance is found, try to move towards it
        int closetIndex = 0;
        float shortestIndex = 100000;
        for (int i = 0; i < 9; i++) {
            if (i == 4)
                continue;
            float distance = (getX() + getAdjX(i) - closetSheep->getX()) * (getX() + getAdjX(i) - closetSheep->getX()) + 
            (getY() + getAdjY(i) - closetSheep->getY()) * (getY() + getAdjY(i) - closetSheep->getY());
            if (distance < shortestIndex) {
                closetIndex = i;
                shortestIndex = distance;
            }
        }
        // ?
        // move to that adjcent cell
        Entity* adjCell = nextGrid->getCell(getX() + getAdjX(closetIndex), getY() + getAdjY(closetIndex));
        if (adjCell && adjCell->toChar() != '.' ) // has animal on that cell
            putSelf(nextGrid, getX(), getY());
            // std::cout<<"reach here \n";
        else
            putSelf(nextGrid, getX() + getAdjX(closetIndex), getY() + getAdjY(closetIndex));
        
    }
    else {
        // No sheep found, move randomly
        
        // ?
        int index = getRandomMovementIndex(nextGrid);
        if (index != -1) {
            putSelf(nextGrid, getX() + getAdjX(index), getY() + getAdjY(index));
        }else
        {
            putSelf(nextGrid, getX(), getY());
        }

    }
}