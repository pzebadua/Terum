//
//  Item.hpp
//  Terum
//
//  Created by Pablo Zebadúa on 31/03/16.
//  Copyright © 2016 Controversial Games. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "LinkedList.h"
using namespace std;
class Item
{
private:
    int ID;
    int weight;
    int type;
    int quality;
    int atk;
    int hp;
    int mg;
    int price;
    string name;
    
public:
    Item();
    Item(string, string);
    ~Item(void);
    
    void setID(int);
    void setWeight(int);
    void setType(int);
    void setQuality(int);
    void setAttack(int);
    void setHP(int);
    void setMagic(int);
    void setPrice(int);
    void setName(string);
    
    int getID();
    int getWeight();
    int getType();
    int getQuality();
    int getAttack();
    int getHP();
    int getMagic();
    int getPrice();
    string getName();
    
    
};


#endif /* Item_hpp */
