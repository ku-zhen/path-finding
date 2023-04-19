//
// Created by ku-zhen on 2023/4/17.
//

#include "../headers/SquareGridMapWithWeight.h"
#include "../headers/Priority_Queue.h"

/*启发式函数*/
int heuristic1(Position2D a,Position2D b){
    // Manhattan distance
    return std::abs(a.x-b.x)+std::abs(a.y-b.y);
}

std::unordered_map<Position2D,Position2D>
a_star(SquareGridMapWithWeight &map,Position2D &start,Position2D& goal){

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
                cost_so_far[next]=new_cost;
                int priority=new_cost+ heuristic1(next,goal);
                frontiers.put(next,priority);
                came_from[next]=current;
            }
        }
    }
    return came_from;
}