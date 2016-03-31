
#include "Scenery.h"

Scenery::Scenery()
{
}

Scenery::Scenery(string t, string d)
{
    title = t;
    description = d;
}

Scenery::~Scenery()
{
    paths.removeAll();
    items.removeAll();
}

void Scenery::setItem(string i)
{
    items.insertLast(i);
    
}

//The reason why it returns string is because later there is going to be a class Item
string Scenery::getItem (string name)
{
    for (int i = 0; i < items.getSize(); i++)
    {
        if (items[i].value == name)
        {
            string item = items[i].value;
            items.removeAt(i);
            return item;
        }
    }
    
    return "";
}

LinkedList<string> Scenery::getItems()
{
    return items;
}

void Scenery::setDescription(string d)
{
    description = d;
}

string Scenery::getDescription()
{
    return description;
}

void Scenery::setTitle(string t)
{
    title = t;
}

string Scenery::getTitle()
{
    return title;
}

void Scenery::setPath(int attribute, int noScene, string pathName)
{
    int indexNum = (3 * noScene + attribute);
    paths.insertAt(indexNum, pathName);
}

//Create a class of paths where locked and unlocked
string Scenery::getPath (int attribute, int noScene)
{
    int indexNum = (3 * noScene + attribute);
        string path = paths[indexNum].value;
    if (path != "")
    {
        return path;
    }
    //Later will manage what happens if path not found here
    return path;
}

LinkedList<string> Scenery::getPaths()
{
    return paths;
}




