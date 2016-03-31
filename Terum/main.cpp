//
//  Main.cpp
//  Text Game
//
//  Created by Pablo Zebadúa Vega March 30 2016.
//  Last Modified by Pablo Zebadúa Vega March 31 2016.
//  Copyright (c) 2016 Pablo Zebadúa Vega. All rights reserved.
//

#include <iostream>
#include <string>
#include "MapBuilder.h"
using namespace std;

int main(int argc, const char * argv[])
{
    
    MapBuilder *map = new MapBuilder();
    LinkedList<Scene<int, string>* > scenes = map->getScenes();
    
    //Creates two scenes the old scene and the new scene
    Scene<int, string> *pastPlace = scenes[0].value;
    Scene<int, string> *presentPlace = new Scene<int, string>();
    
    //Variable that defines the Edge (Path) that the scene is going to take
    string option = "start";
    while (option != "exit") {
        
        //Function that allows the new scene to get summoned
        presentPlace = pastPlace->getPath(pastPlace,option);
        
        //Prints the info of the new scene
        cout << presentPlace->getScenery().getTitle() << endl;
        cout << presentPlace->getScenery().getDescription();
        
        //Once the New Scene has been explained it becomes the Old Scene
        pastPlace = presentPlace;
        
        //The option is made
        cin>>option;
    }
    
    delete map;
    return 0;
}