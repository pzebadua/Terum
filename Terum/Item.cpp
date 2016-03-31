//
//  Item.cpp
//  Terum
//
//  Created by Pablo Zebadúa on 31/03/16.
//  Copyright © 2016 Controversial Games. All rights reserved.
//

#include "Item.hpp"
Item::Item()
{
     ID = 0;
     weight = 0;
     type = 0;
     quality = 0;
     atk = 0;
     hp = 0;
     mg = 0;
     name = "";
}
Item::~Item(void)
{

}

void Item::setID(int ids)
{
    ID = ids;
}
void Item::setWeight(int w)
{
    weight = w;
}
void Item::setType(int t)
{
    type = t;
}
void Item::setQuality(int q)
{
    quality = q;
}
void Item::setAttack(int a)
{
    atk = a;
}
void Item::setHP(int h)
{
    hp = h;
}
void Item::setMagic(int m)
{
    mg = m;
}
void Item::setPrice(int p)
{
    price = p;
}
void Item::setName(string n)
{

    name = n;
}

int Item::getID()
{
    return ID;
}


int Item::getWeight()
{
    return weight;
}

int Item::getType()
{
    return type;
}
int Item::getQuality()
{
    return quality;
}
int Item::getAttack()
{
    return atk;
}
int Item::getHP()
{
    return hp;
}
int Item::getMagic()
{
    return mg;
}
int Item::getPrice()
{
    return price;
}
string Item::getName()
{
    return name;
}