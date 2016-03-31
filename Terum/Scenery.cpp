
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






