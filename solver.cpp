#include "solver.h"
#include "mazetile.h"

Solver::Solver(QObject *parent) : QObject(parent)
{
    colFiller.setRgb(255, 0, 0);
    colFloor.setRgb(132, 132, 132);
    colWalls.setRgb(52, 12, 52);
    colTarget.setRgb(0, 255, 0);
    ptStart.setX(506);
    ptStart.setY(2413);

    counter = 0;
}

bool Solver::loadMaze(QString filePath)
{
    return imgMaze.load(filePath);
}

Tiletype Solver::getType(QPoint pos)
{
    QRgb pixel = imgMaze.pixel(pos);
    if (pixel == colFloor.rgb())
        return FLOOR;
    if (pixel == colWalls.rgb())
        return WALL;
    if (pixel == colTarget.rgb())
        return TARGET;

    return UNKNOWN;
}

void Solver::setPixel(QPoint pos, QRgb color)
{
    imgMaze.setPixel(pos, color);
}

void Solver::saveImage(QString filepath)
{
    imgMaze.save(filepath);
}

void Solver::startProcessing()
{
    startTile = new mazetile(this, DIR_LEFT, ptStart, NULL);
}
