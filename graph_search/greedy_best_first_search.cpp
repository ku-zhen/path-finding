//
// Created by ku-zhen on 2023/4/16.
//

#include "../headers/SquareGridMap.h"
#include "../headers/Priority_Queue.h"
#include <cstdlib>

/*启发式函数*/
int heuristic(Position2D a,Position2D b){
    // Manhattan distance
    return std::abs(a.x-b.x)+std::abs(a.y-b.y);
}

std::unordered_map<Position2D,Position2D,PositionHash>
        greedy_first_best_search(SquareGridMap &map,Position2D &start,Position2D &goal){
    Priority_Queue<Position2D,int> frontiers;
    frontiers.put(start,0);

    std::unordered_map<Position2D,Position2D,PositionHash> came_from;
    came_from[start]=start;

    while(!frontiers.empty()){
        Position2D current=frontiers.get();

        if(current==goal){
            break;
        }

        for (const auto & next:map.neighbors(current)) {
            if (came_from.find(next)==came_from.end()){
                int priority= heuristic(next,goal);
                frontiers.put(next,priority);
                came_from[next]=current;
            }
        }

    }
    return came_from;
}