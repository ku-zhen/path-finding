//
// Created by ku-zhen on 2023/4/16.
//

#include "../headers/SquareGridMapWithWeight.h"
#include <iostream>
#include <algorithm>

SquareGridMapWithWeight::SquareGridMapWithWeight(int width_,int height_): SquareGridMap(width_,height_){}

void SquareGridMapWithWeight::setWeight(Position2D node_,int weight_){
    nodes[node_]=FOREST;
}

void SquareGridMapWithWeight::setWeight(int x, int y, int width_, int height_,int weight_){
    if(x<0||x>=width||y<0||y>=height){
        return;
    }
    width_=x+width_>width?width-x:width_;
    height_=y+height_>height?height-y:height_;
    for (int i = x; i < width_+x; ++i) {
        for (int j = y; j <height_+y; ++j) {
            nodes[Position2D{i,j}]=FOREST;
        }
    }
    weight=weight_;
}

int SquareGridMapWithWeight::cost(Position2D from_node_,Position2D to_node_){
    return nodes[to_node_]==FOREST?weight:1;
}

void SquareGridMapWithWeight::drawWith(Position2D *start, Position2D *goal,
                                       std::unordered_map<Position2D, Position2D, PositionHash> *came_from,
                                       std::vector<Position2D> *path) {
    //draw the map with start, goal, came_from and path
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            if(path&&std::find(path->begin(),path->end(),Position2D{x,y})!=path->end()){
                std::cout<<"@";
            }else if(isBound(x,y)){
                std::cout<<"#";
            }else if(isObstacle(x,y)){
                std::cout<<"#";
            }else if(isForest(x,y)){
                std::cout<<"*";
            }else{
                    if(start&&*start==Position2D{x,y}){
                        std::cout<<"S";
                    }else if(goal&&*goal==Position2D{x,y}){
                        std::cout<<"G";
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
