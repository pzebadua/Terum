//
//  Scenery.h
//  Build the scenery
//
//  Created by Pablo Zebadœa Vega March 31 2016.
//  Copyright (c) 2016 Pablo Zebadœa Vega. All rights reserved.
//
#ifndef __Scenery__
#define __Scenery__

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;
class Scenery
{
    private:
        LinkedList<string> items;
        string description;
        string title;
        LinkedList<string> paths;
    
    public:
        Scenery();
        Scenery(string, string);
        ~Scenery(void);
    
        void setItem(string);
        string getItem (string);
        LinkedList<string> getItems();
        void setDescription(string);
        string getDescription();
        void setTitle(string);
        string getTitle();
        void setPath(string);
        string getPath (string);
        LinkedList<string> getPaths();
};


#endif /* defined(__Scenery__) */
