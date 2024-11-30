//
// Created by MiloslavŠvábenský(ml on 30.11.2024.
//

#ifndef MAP_H
#define MAP_H



class Map {
    std::vector<std::vector<MapObject*>> m_MapMatrix; //probrat na meetingu

public:
       Map();
       int getWidth();
       int getHeight();
       MapObject getObjectAt(int row, int column);
       ~Map();
};



#endif //MAP_H
