#ifndef MAZETILE_H
#define MAZETILE_H

#include <QPoint>
#include "misc.h"

class Solver;

class mazetile
{
public:
    mazetile(Solver* solver, Direction from, QPoint pos, mazetile* parent = NULL);
    mazetile* parent;
    Solver* pSolver;
    QPoint position;

private:
    mazetile* tile_up;
    mazetile* tile_right;
    mazetile* tile_down;
    mazetile* tile_left;

    Direction came_from;
    Tiletype type;

    void paintLastpixel();
};

#endif // MAZETILE_H
