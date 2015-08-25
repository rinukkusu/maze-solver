#ifndef SOLVER_H
#define SOLVER_H

#include <QObject>
#include <QImage>
#include <QColor>
#include "misc.h"

class mazetile;

class Solver : public QObject
{
    Q_OBJECT
public:
    explicit Solver(QObject *parent = 0);
    bool loadMaze(QString filePath);
    Tiletype getType(QPoint pos);
    mazetile* startTile;

    void setPixel(QPoint pos, QRgb color);
    void setPixel(int x, int y, QRgb color) { setPixel(QPoint(x, y), color); }
    void saveImage(QString filepath);

    void startProcessing();

    uint counter;

private:
    QImage  imgMaze;
    QColor  colWalls;
    QColor  colFloor;
    QPoint  ptStart;
    QColor  colFiller;
    QColor  colTarget;

signals:

public slots:
};

#endif // SOLVER_H
