//
//  Character.hpp
//  Terum
//
//  Created by Pablo Zebadúa on 31/03/16.
//  Copyright © 2016 Controversial Games. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "Item.hpp"
using namespace std;
class Character
{
private:
    LinkedList<Item>inventory;
    LinkedList<Item>equipped;
    
    int hp;
    int xp;
    int atk;
    int magic;
    int money;
public:
    void setLife(int l);
    int getLife();
    void setItem(Item i);
    Item getItem(int id);
    void setExp(int e);
    int getExp();
    void setMagic(int m);
    int getMagic();
    void setMoney(int m);
    int getMoney();
    void setAttack(int m);
    int getAttack();
    LinkedList<Item> getInventory();
    void dropItem(int id);
    Character();
    ~Character(void);
    //To do: Equip add/remove
};


#endif /* Character_hpp */
