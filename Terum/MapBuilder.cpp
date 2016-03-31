/*
 
Map:
 Terum
 
Scenes:
 
 [0] Eyrie_Town
    Paths:
        tavern, smith
 
 [1] Eyrie_Tavern
    Paths:
        back
 
 [2] Eyrie_Smith
    Paths:
        back
 
 [3] Eyrie_Bridge
    Paths:
        back
 
 [4] Eyrie_Forest
    Paths:
        back
 
 */

#include "MapBuilder.h"


MapBuilder::MapBuilder()
{
    map = new Map<int, string>();
    
    scenes = CreateScenes();

    CreatePaths(map, scenes);
}


MapBuilder::~MapBuilder()
{
    delete map;
    scenes.removeAll();
}

LinkedList<Scene<int, string>* > MapBuilder::getScenes()
{
    return scenes;
}

//Sets all the values of the scene
void MapBuilder::FillScene (Scene<int, string>* s, int ids, string t)
{
    s->setInfo(ids);
    string desc = ReadDescription (t);
    string tit = ReadTitle(t);
    Scenery scenery(tit,desc);
    s->setScenery(scenery);
}

//Scenes are created and added to the list
LinkedList<Scene<int, string>* > MapBuilder::CreateScenes()
{
    LinkedList<Scene<int, string>* > l;
    
    //Create [0] Eyrie
    Scene<int, string> *Eyrie_Town = new Scene<int, string>();
    l.insertLast(Eyrie_Town);
    FillScene (l[0].value, 0, "Resources/Places/Eyrie_Town.txt");

    //Create [1] Eyrie_Tavern
    Scene<int, string> *Eyrie_Tavern = new Scene<int, string>();
    l.insertLast(Eyrie_Tavern);
    FillScene (l[1].value, 1, "Resources/Places/Eyrie_Tavern.txt");
    
    //Create [2] Eyrie_Smith
    Scene<int, string> *Eyrie_Smith = new Scene<int, string>();
    l.insertLast(Eyrie_Smith);
    FillScene (l[2].value, 2, "Resources/Places/Eyrie_Smith.txt");
    
    //Create [3] Eyrie_Bridge
    Scene<int, string> *Eyrie_Bridge = new Scene<int, string>();
    l.insertLast(Eyrie_Bridge);
    FillScene (l[3].value, 3, "Resources/Places/Eyrie_Bridge.txt");

    //Create [4] Eyrie_Bridge
    Scene<int, string> *Eyrie_Forest = new Scene<int, string>();
    l.insertLast(Eyrie_Forest);
    FillScene (l[4].value, 4, "Resources/Places/Eyrie_Forest.txt");
    
    return l;
}


//Paths that connect the scenes are filled here
void MapBuilder::CreatePaths(Map<int, string> * m, LinkedList<Scene<int, string>* > l)
{
    //Fill the scenes into the map
    for (int i = 0 ; i < l.getSize(); i++)
    {
        m->insertScene(l[i].value);
    }
    //Define the Paths
    //Eyrie_Town
    m->insertPath(l[0].value, l[1].value, "tavern");
    m->insertPath(l[0].value, l[2].value, "smith");
    m->insertPath(l[0].value, l[3].value, "bridge");
    m->insertPath(l[0].value, l[4].value, "forest");

    //Eyrie_Tavern
    m->insertPath(l[1].value, l[0].value, "town");
    
    //Eyrie_Smith
    m->insertPath(l[2].value, l[0].value, "town");
    
    //Eyrie_Bridge
    m->insertPath(l[3].value, l[0].value, "town");
    
    //Eyrie_Forest
    m->insertPath(l[4].value, l[0].value, "town");
    
}



/************ Private ***************/
string MapBuilder::ReadTitle (string f)
{
    
    std::ifstream file(f);
    std::string str;
    std::string file_contents;
    std::getline(file, str);
    file_contents += str;
    return file_contents;
    
}

string MapBuilder::ReadDescription (string f)
{

    std::ifstream file(f);
    std::string str;
    std::string file_contents;
    //Skip the title
    std::getline(file, str);
    while (std::getline(file, str))
    {
        file_contents += str;
        file_contents.push_back('\n');
    }
    return file_contents;
    
}

