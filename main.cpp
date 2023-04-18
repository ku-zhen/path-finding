#include "headers/SquareGridMap.h"
#include "headers/SquareGridMapWithWeight.h"

#include "graph_search/breadth_first_search.cpp"
#include "graph_search/uniform_cost_search.cpp"
#include "graph_search/greedy_best_first_search.cpp"
#include "graph_search/a_star.cpp"

#include <iostream>

int main() {
    Position2D start=Position2D{10,12};
    Position2D goal=Position2D{40,12};

    std::cout<<"\n宽度优先搜索、普通图（#为障碍,@为路径）："<<std::endl;
    {
        SquareGridMap map(50,20);
        map.setObstacles(5,5,5,5);
        map.setObstacles(30,8,8,5);
        map.setObstacles(20,5,3,12);
        map.setObstacles(14,12,6,3);

        auto came_from= breadth_first_search(map,start,goal);
        auto path = map.reconstructPath(start,goal,came_from);

        map.drawWith(&start,&goal, nullptr,&path);
    }

    std::cout<<"\nDijkstra 搜索、加权图（*为森林，行走的代价更高）："<<std::endl;
    {
        SquareGridMapWithWeight map(50,20);
        map.setObstacles(5,5,5,5);
        map.setObstacles(30,8,8,5);
        map.setWeight(20,5,3,12,2);
        map.setWeight(14,12,6,3,2);

        auto came_from= uniform_cost_search(map,start,goal);
        auto path = map.reconstructPath(start,goal,came_from);

        map.drawWith(&start,&goal, nullptr,&path);
    }
    {
        SquareGridMapWithWeight map(50,20);
        map.setObstacles(5,5,5,5);
        map.setObstacles(30,8,8,5);


        auto came_from= uniform_cost_search(map,start,goal);
        auto path = map.reconstructPath(start,goal,came_from);

        map.drawWith(&start,&goal, nullptr,&path);
    }

    std::cout<<"\n贪婪最佳优先搜索、普通图："<<std::endl;
    {
        SquareGridMap map(50,20);
        map.setObstacles(5,5,5,5);
        map.setObstacles(30,8,8,5);
        map.setObstacles(20,5,3,12);
        map.setObstacles(14,12,6,3);

        auto came_from= greedy_first_best_search(map,start,goal);
        auto path = map.reconstructPath(start,goal,came_from);

        map.drawWith(&start,&goal, nullptr,&path);
    }

    std::cout<<"\nA-star搜索、加权图："<<std::endl;
    {
        SquareGridMapWithWeight map(50,20);
        map.setObstacles(5,5,5,5);
        map.setObstacles(30,8,8,5);
        map.setWeight(20,5,3,12,2);
        map.setWeight(14,12,6,3,2);

        auto came_from= a_star(map,start,goal);
        auto path = map.reconstructPath(start,goal,came_from);

        map.drawWith(&start,&goal, nullptr,&path);
    }

    return 0;
}