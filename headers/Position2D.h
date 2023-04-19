//
// Created by 20273 on 2023/4/19.
//

#ifndef PATH_FINDING_POSITION2D_H
#define PATH_FINDING_POSITION2D_H

#include <tuple>
#include <unordered_map>
#include <unordered_set>

struct Position2D
{
    int x, y;
};

inline bool operator == (Position2D a, Position2D b) {
    return (a.x==b.x)&&(a.y==b.y);
}

inline bool operator != (Position2D a, Position2D b) {
    return !(a==b);
}

inline bool operator < (Position2D a, Position2D b) {
    return std::tie(a.x, a.y) < std::tie(b.x, b.y);
}

/*hash函数对象的偏特化，用于 unordered_map/set*/
namespace std{
    template<>
    class hash<Position2D>{
    public:
        std::size_t operator()(const Position2D& pos) const{
            return std::hash<int>()(pos.x ^ std::hash<int>()(pos.y));
        }
    };
}

#endif //PATH_FINDING_POSITION2D_H
