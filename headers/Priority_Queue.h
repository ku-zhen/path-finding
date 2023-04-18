//
// Created by ku-zhen on 2023/4/16.
//

#ifndef PATH_FINDING_PRIORITY_QUEUE_H
#define PATH_FINDING_PRIORITY_QUEUE_H

#include <queue>

// wrapper of priority_queue
template<typename T,typename priority_t>
class Priority_Queue{
protected:
    typedef std::pair<priority_t,T> ElementType;
    std::priority_queue<ElementType,std::vector<ElementType>,std::greater<ElementType>> elements;

public:
    inline bool empty()const{
        return elements.empty();
    }

    inline void put(T item, priority_t priority){
        elements.emplace(priority,item);
    }

    T get(){
        T item=elements.top().second;
        elements.pop();
        return item;
    }
};


#endif //PATH_FINDING_PRIORITY_QUEUE_H
