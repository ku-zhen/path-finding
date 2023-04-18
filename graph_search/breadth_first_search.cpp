//
// Created by ku-zhen on 2023/4/16.
//
#include "../headers/SquareGridMap.h"
#include <queue>

std::unordered_map<Position2D,Position2D,PositionHash>
breadth_first_search( SquareGridMap &map, Position2D &start, Position2D &goal){
    std::queue<Position2D> frontiers;
    frontiers.push(start);

    std::unordered_map<Position2D,Position2D,PositionHash> came_from;
    came_from[start]=start;

    while (!frontiers.empty()){
        Position2D current=frontiers.front();
        frontiers.pop();

        // early exit
        if(current==goal){
            break;
        }

        // extend frontier
        for (auto next:map.neighbors(current)) {
            if(came_from.find(next)==came_from.end()){
                frontiers.push(next);
                came_from[next]=current;
            }
        }
    }
    return came_from;
}