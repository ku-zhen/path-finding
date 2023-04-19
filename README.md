
## 图搜索算法

**注：本仓库仅用于学习目的，代码并未进行性能考量**

基于栅格的图搜索算法实现，仅使用标准库（C++11），并通过控制台显示。已实现如下算法：

- 宽度优先搜索：[breadth_first_search.cpp](https://github.com/ku-zhen/path-finding/blob/master/graph_search/breadth_first_search.cpp)
- 统一代价搜索(Dijkstra)：[uniform_cost_search.cpp](https://github.com/ku-zhen/path-finding/blob/master/graph_search/uniform_cost_search.cpp)
- 贪婪优先搜索：[greedy_best_first_search.cpp](https://github.com/ku-zhen/path-finding/blob/master/graph_search/greedy_best_first_search.cpp)
- A-star 搜索：[a_star.cpp](https://github.com/ku-zhen/path-finding/blob/master/graph_search/a_star.cpp)

## 代码结构

- 图搜索算法实现于 [graph_search](https://github.com/ku-zhen/path-finding/tree/master/graph_search) 目录。
- [headers](https://github.com/ku-zhen/path-finding/tree/master/headers) 和 [sources](https://github.com/ku-zhen/path-finding/tree/master/sources) 目录，提供了用于图搜索的简单数据结构。
- main 函数的调用示例如下：

```cpp
    Position2D start=Position2D{10,12};
    Position2D goal=Position2D{40,12};
    
    std::cout<<"\n宽度优先搜索、普通图（#为障碍,@为路径）："<<std::endl;
    {
        // 创建栅格地图，并添加障碍
        SquareGridMap map(50,20);
        map.setObstacles(5,5,5,5);
        map.setObstacles(30,8,8,5);
        map.setObstacles(20,5,3,12);
        map.setObstacles(14,12,6,3);

        // 应用图搜索算法
        auto came_from= breadth_first_search(map,start,goal);
        auto path = map.reconstructPath(start,goal,came_from);

        // 绘制结果
        map.drawWith(&start,&goal, nullptr,&path); // 第三个参数设置为&came_from，则输出会显示算法的搜索方向
    }
```

## 效果图

<div align="center">
  <img height="400px" src="https://github.com/ku-zhen/path-finding/blob/master/images/bfs.png" />
  <img height="400px" src="https://github.com/ku-zhen/path-finding/blob/master/images/dijkstra.png" />
</div>

<div align="center">
  <img height="400px" src="https://github.com/ku-zhen/path-finding/blob/master/images/gbfs.png" />
  <img height="400px" src="https://github.com/ku-zhen/path-finding/blob/master/images/astar.png" />
</div>
