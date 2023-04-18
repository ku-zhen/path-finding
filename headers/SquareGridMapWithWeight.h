//
// Created by ku-zhen on 2023/4/16.
//

#ifndef PATH_FINDING_SQUAREGRIDMAPWITHWEIGHT_H
#define PATH_FINDING_SQUAREGRIDMAPWITHWEIGHT_H

#include "SquareGridMap.h"

/*weighted map*/
class SquareGridMapWithWeight:public SquareGridMap{
protected:
    int weight; //额外加权的栅格，其他栅格默认为 1

public:
    SquareGridMapWithWeight(int width,int height);

    void setWeight(Position2D node_,int weight_);

    void setWeight(int x, int y, int width_, int height_,int weight_);

    int cost(Position2D from_node_,Position2D to_node_);

    bool isForest(int x, int y){
        return nodes[Position2D{x,y}]==FOREST;
    }

    void drawWith(Position2D *start = nullptr, Position2D *goal = nullptr, std::unordered_map<Position2D, Position2D, PositionHash> *came_from = nullptr, std::vector<Position2D> *path = nullptr) override;
};



#endif //PATH_FINDING_SQUAREGRIDMAPWITHWEIGHT_H
