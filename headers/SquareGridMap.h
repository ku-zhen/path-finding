//
// Created by ku-zhen on 2023/4/16.
//

#ifndef PATH_FINDING_SQUAREGRIDMAP_H
#define PATH_FINDING_SQUAREGRIDMAP_H

#include "Position2D.h"

#include <array>
#include <vector>

enum Status{
    FREE,
    OBSTACLE,
    FOREST
};

/*implications of square grid map*/
class SquareGridMap {
protected:
    static std::array<Position2D, 4> DIRS;
    int width, height;
    std::unordered_map<Position2D, Status> nodes;

public:
    SquareGridMap(int width_, int height_);

    ~SquareGridMap() = default;

    void setObstacles(int x, int y, int width_, int height_);

    void setObstacles(Position2D pos, int width_, int height_);

    bool isBound(int x, int y);

    bool isObstacle(int x, int y);

    bool isBound(Position2D pos);

    bool isObstacle(Position2D pos);

    std::vector<Position2D> neighbors(int x, int y);

    std::vector<Position2D> neighbors(Position2D pos);

    // draw the map
    virtual void drawWith(Position2D *start = nullptr, Position2D *goal = nullptr,
                  std::unordered_map<Position2D, Position2D> *came_from = nullptr,
                  std::vector<Position2D> *path = nullptr);

    std::vector<Position2D> reconstructPath(Position2D &start, Position2D &goal,
                                            std::unordered_map<Position2D, Position2D> &came_from);
};
#endif // PATH_FINDING_SQUAREGRIDMAP_H
