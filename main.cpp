#include <QCoreApplication>
#include <QImage>
#include "solver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Solver solver;
    bool success = solver.loadMaze("maze.gif");
    solver.startProcessing();
    solver.saveImage("new.png");

    if (argc == 1) {
        if (argv[1]) {
            Solver solver;
            solver.loadMaze("maze.gif");



        }
    }

    return 0;

    return a.exec();
}
