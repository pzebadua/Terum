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
        string description;
        string title;
    
    public:
        Scenery();
        Scenery(string, string);
        ~Scenery(void);
    
        void setDescription(string);
        string getDescription();
        void setTitle(string);
        string getTitle();
};


#endif /* defined(__Scenery__) */
