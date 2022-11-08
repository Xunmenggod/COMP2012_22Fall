#include "grass.h"
#include "helper.h"

/**
 * TODO: TASK 1
 * 
 * This function tries to set nextGrid's cell at position x, y to point to grass,
 * and returns a boolean of whether grass was placed successfully on nextGrid.
 * 
 * If the position is out of bounds or the cell is already pointing at another Entity,
 * grass should be deleted and the function returns false.
 * Otherwise, modify nextGrid accordingly and return true.
*/
bool putGrass(Grass* grass, Grid* nextGrid, const int x, const int y) {
    Entity* nextEntity = nextGrid->getCell(x,y);
    if (nextEntity || nextGrid->outOfBounds(x, y)) {
        delete grass;
        return false;
    }
    
    // modification
    nextGrid->setCell(grass, x, y);
    return true;
}

/**
 * TODO: TASK 1
 * 
 * Place a copy of this Grass onto nextGrid at the specified position.
 * 
 * You should use the copy constructor to create a Grass object representing this Grass in the next step.
 * You may use putGrass() implemented above. If the copy was placed successfully, call setNextSelf()
 * to properly link this Grass with the copy for deletion if necessary.
*/
void Grass::putSelf(Grid* nextGrid, const int x, const int y) {
    Grass* nextGrass = new Grass(*this);
    if (putGrass(nextGrass, nextGrid, x, y)) {
        setNextSelf(nextGrass);
    }
}

/**
 * TODO: TASK 1
 * 
 * Place a brand new Grass onto nextGrid at the specified position.
 * 
 * You should use the normal constructor to create a new Grass object.
 * You may use putGrass() implemented above.
*/
void Grass::putClone(Grid* nextGrid, const int x, const int y) const {
    Board* board = getBoard();
    Grass* newGrass = new Grass(board);
    putGrass(newGrass, nextGrid, x, y);
}

/**
 * TODO: TASK 1
 * 
 * Update the nextGrid according to the update rules of Grass. 
 * If the spread countdown is reached, spawn 4 Grasses onto the orthogonally adjacent tiles using putClone().
 * You may find the countdown() function in helper.cpp useful.
 * Otherwise, put a copy of this Grass onto this position using putSelf(). You don't need to worry about
 * checking if current cell has another Entity; it is done in putGrass().
*/
void Grass::update(Grid* nextGrid) {
    
    if (countdown(spreadCounter, SPREAD_COOLDOWN)) {
        putClone(nextGrid, getX(), getY() + 1);
        putClone(nextGrid, getX(), getY() - 1);
        putClone(nextGrid, getX() + 1, getY());
        putClone(nextGrid, getX() - 1, getY());
    }
    putSelf(nextGrid, getX(), getY());
}