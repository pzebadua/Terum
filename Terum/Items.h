//
//  Item.h
//  Build the Item
//
//  Created by Pablo Zebadœa Vega March 31 2016.
//  Copyright (c) 2016 Pablo Zebadœa Vega. All rights reserved.
//
#ifndef __Item__
#define __Item__

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;
class Item
{
    private:
    int weight;
    int type;
    int quality;
    int atk;
    int hp;
    int mg;
    string name;
    
    public:
        Item();
        Item(string, string);
        ~Item(void);
    
    void setWeight(int);
    void setType(int);
    void setQuality(int);
    void setAttack(int);
    void setHP(int);
    void setMagic(int);
    void setName(string);
    
    int getWeight();
    int getType();
    int getQuality();
    int getAttack();
    int getHP();
    int getMagic();
    string getName();



    
};


#endif /* defined(__Item__) */
