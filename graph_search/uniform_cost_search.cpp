//
// Created by ku-zhen on 2023/4/16.
//

#include "../headers/SquareGridMapWithWeight.h"
#include "../headers/Priority_Queue.h"

std::unordered_map<Position2D,Position2D>
uniform_cost_search(SquareGridMapWithWeight &map,Position2D &start,Position2D& goal){

    Priority_Queue<Position2D,int> frontiers;
    frontiers.put(start,0);

    std::unordered_map<Position2D,Position2D> came_from;
    came_from[start]=start;

    std::unordered_map<Position2D,int> cost_so_far;
    cost_so_far[start]=0;

    while(!frontiers.empty()){
        Position2D current=frontiers.get();

        if(current==goal){
            break;
        }

        for (auto next:map.neighbors(current)) {
            int new_cost=cost_so_far[current]+map.cost(current,next);
            if(came_from.find(next)==came_from.end()
            ||new_cost<cost_so_far[next]){
                frontiers.put(next,new_cost);
                came_from[next]=current;
                cost_so_far[next]=new_cost;
            }
        }
    }
    return came_from;
}