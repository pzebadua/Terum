//
//  Character.cpp
//  Terum
//
//  Created by Pablo Zebadúa on 31/03/16.
//  Copyright © 2016 Controversial Games. All rights reserved.
//

#include "Character.hpp"
Character::Character()
{
    hp = 5;
    xp = 0;
    magic = 0;
    atk = 1;
    money = 10;

}
Character::~Character(void)
{
    inventory.removeAll();
}
void Character::setLife(int l)
{
    hp = l;
}
void Character::setExp(int e)
{
    xp = e;
}
void Character::setMoney(int m)
{
    money = m;
}
void Character::setMagic(int m)
{
    magic = m;
}
void Character::setAttack(int a)
{
    atk = a;
}

void Character::setItem(Item i)
{
    inventory.insertLast(i);
}
void Character::dropItem(int id)
{
    for (int i = 0; i < inventory.getSize() ; ++i)
    {
        if (inventory[i].value.getID() == id)
        {
            inventory.removeAt(i);
        }
    }

}

int Character::getLife()
{
    return hp;
}
int Character::getExp()
{
    return xp;
}
int Character::getMagic()
{
    return magic;
}
int Character::getAttack()
{
    return atk;
}
int Character::getMoney()
{
    return money;
}


Item Character::getItem(int id)
{
    for (int i = 0; i < inventory.getSize() ; ++i)
    {
        if (inventory[i].value.getID() == id)
        {
            return inventory[i].value;
        }
    }
    Item empty;
    return empty;
}


LinkedList<Item> Character::getInventory()
{
    return inventory;
}
