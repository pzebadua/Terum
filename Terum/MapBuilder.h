//
//  MapBuilder.h
//  Puts all the scenes and paths in the map
//
//  Created by Pablo Zebadœa Vega March 30 2016.
//  Last Modified by Pablo Zebadœa Vega March 31 2016.
//  Copyright (c) 2016 Pablo Zebadœa Vega. All rights reserved.
//
#ifndef __MapBuilder__
#define __MapBuilder__

#pragma once
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "Map.h"

using namespace std;
class MapBuilder
{
    private:
        Map<int, string> *map;
        LinkedList<Scene<int, string>* > scenes;
    
        void FillScene (Scene<int, string>* s, int ids, string t);
        LinkedList<Scene<int, string>* > CreateScenes();
        void CreatePaths(Map<int, string> * m, LinkedList<Scene<int, string>* > l);
        string ReadDescription(string f);
        string ReadTitle(string f);


    public:
        MapBuilder();
        ~MapBuilder(void);
    
        LinkedList<Scene<int, string>* > getScenes();
};


#endif /* defined(__MapBuilder__) */
