#include "mazetile.h"
#include "solver.h"
#include <stdio.h>

mazetile::mazetile(Solver* solver, Direction from, QPoint pos, mazetile *parent)
{
    came_from = from;
    pSolver = solver;
    position = pos;

    this->parent = parent;

    pSolver->counter++;

    type = pSolver->getType(pos);

    if (type == TARGET)
    {
        // trace back
        mazetile* cur_tile = this;
        QRgb yellow = QColor(255, 255, 0).rgb();

        while (cur_tile)
        {
            pSolver->setPixel(cur_tile->position, yellow);

            int x = cur_tile->position.x();
            int y = cur_tile->position.y();

            switch(cur_tile->came_from)
            {
            case DIR_UP:
                y--;
                break;
            case DIR_RIGHT:
                x++;
                break;
            case DIR_DOWN:
                y++;
                break;
            case DIR_LEFT:
                x--;
                break;
            }

            pSolver->setPixel(x, y, yellow);

            cur_tile = cur_tile->parent;
        }

        pSolver->saveImage("final.png");

        quick_exit(0);
    }

    if (type != WALL && type != UNKNOWN)
    {
        paintLastpixel();

        if (pSolver->counter % 10000 == 0)
        {
            //pSolver->saveImage("state.png");
            qDebug("Current: %i     Position: %ix%i", pSolver->counter, pos.x(), pos.y());

        }


        if (from != DIR_UP && pos.y() > 2)
            tile_up = new mazetile(solver, DIR_DOWN, QPoint(pos.x(), pos.y() - 2), this);
        if (from != DIR_RIGHT)
            tile_right = new mazetile(solver, DIR_LEFT, QPoint(pos.x() + 2, pos.y()), this);
        if (from != DIR_DOWN)
            tile_down = new mazetile(solver, DIR_UP, QPoint(pos.x(), pos.y() + 2), this);
        if (from != DIR_LEFT && pos.x() > 2)
            tile_left = new mazetile(solver, DIR_RIGHT, QPoint(pos.x() - 2, pos.y()), this);
    }

}

void mazetile::paintLastpixel()
{
    QRgb red = QColor(255, 0, 0).rgb();
    int x = position.x();
    int y = position.y();

    pSolver->setPixel(position, QColor(0, 255, 0).rgb());

    switch(came_from)
    {
    case DIR_UP:
        y--;
        break;
    case DIR_RIGHT:
        x++;
        break;
    case DIR_DOWN:
        y++;
        break;
    case DIR_LEFT:
        x--;
        break;
    }

    pSolver->setPixel(x, y, red);

    switch(came_from)
    {
    case DIR_UP:
        y--;
        break;
    case DIR_RIGHT:
        x++;
        break;
    case DIR_DOWN:
        y++;
        break;
    case DIR_LEFT:
        x--;
        break;
    }

    pSolver->setPixel(x, y, red);
}
