//
// Created by ku-zhen on 2023/4/16.
//
#include "../headers/Position2D.h"
#include "../headers/SquareGridMap.h"

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

std::array<Position2D, 4> SquareGridMap::DIRS = {
        Position2D{1, 0}, Position2D{0, 1},
        Position2D{-1, 0},Position2D{0, -1},
};

SquareGridMap::SquareGridMap(int width_,int height_):width(width_),height(height_){
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            nodes.insert({Position2D{i,j}, FREE});
        }
    }
}

void SquareGridMap::setObstacles(int x,int y, int width_, int height_){
    if(x<0||x>=width||y<0||y>=height){
        return;
    }

    width_=x+width_>width?width-x:width_;
    height_=y+height_>height?height-y:height_;
    for (int i = x; i < width_+x; ++i) {
        for (int j = y; j <height_+y; ++j) {
            nodes[Position2D{i,j}]=OBSTACLE;
        }
    }
}

void SquareGridMap::setObstacles(Position2D pos, int width_, int height_){
    setObstacles(pos.x,pos.y,width_,height_);
}

bool SquareGridMap::isBound(int x,int y){
    return x==0||x==width-1||y==0||y==height-1;
}

bool SquareGridMap::isBound(Position2D pos){
    return isObstacle(pos.x,pos.y);
}

bool SquareGridMap::isObstacle(int x,int y){
    return nodes[Position2D{x,y}] == OBSTACLE;
}

bool SquareGridMap::isObstacle(Position2D pos){
    return isObstacle(pos.x,pos.y);
}

std::vector<Position2D> SquareGridMap::neighbors(int x, int y){
    std::vector<Position2D> nbs;
    for (auto dir:DIRS) {
        Position2D next{x + dir.x, y + dir.y};
        if(nodes.count(next)&&nodes[next]!=OBSTACLE){
            nbs.push_back(next);
        }
    }

    if((x+y)%2==0){
        std::reverse(nbs.begin(),nbs.end());
    }

    return nbs;
}

std::vector<Position2D> SquareGridMap::neighbors(Position2D pos){
    return neighbors(pos.x,pos.y);
}

void SquareGridMap::drawWith(Position2D *start,Position2D *goal,
                             std::unordered_map<Position2D,Position2D> *came_from,std::vector<Position2D> *path){
    //draw the map with start, goal, came_from and path
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if(isBound(x,y)){
                std::cout<<"#";
            }else if(isObstacle(x,y)){
                std::cout<<"#";
            }else{
                if(start&&*start==Position2D{x,y}){
                    std::cout<<"S";
                }else if(goal&&*goal==Position2D{x,y}){
                    std::cout<<"G";
                } else if(path&&std::find(path->begin(),path->end(),Position2D{x,y})!=path->end()){
                    std::cout<<"@";
                }else if(came_from){
                    Position2D last=(*came_from)[Position2D{x,y}];
                    if(last.x==x-1){
                        std::cout<<">";
                    }else if(last.x==x+1){
                        std::cout<<"<";
                    }else if(last.y==y-1){
                        std::cout<<"v";
                    }else if(last.y==y+1){
                        std::cout<<"^";
                    }else{
                        std::cout<<".";
                    }
                }else{
                    std::cout<<".";
                }
            }
        }
        std::cout<<std::endl;
    }
}

std::vector<Position2D> SquareGridMap::reconstructPath(Position2D &start, Position2D &goal,
                                        std::unordered_map<Position2D,Position2D> &came_from){
    std::vector<Position2D> path;
    if(came_from.find(goal)==came_from.end()){
        return path;
    }

    Position2D current=goal;
    while(current!=start){
        path.push_back(current);
        current=came_from[current];
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());
    return path;
}