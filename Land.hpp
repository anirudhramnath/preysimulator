//
//  Land.hpp
//  CS474 project 3
//
//  Copyright © 2016 UIC. All rights reserved.
//

#ifndef Land_hpp
#define Land_hpp
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SquareYard.hpp"
#include "Creature.h"
#include "SimulationController.h"


class Land{

    public:
        Land();
        ~Land();
        Land(int,int,sf::RenderWindow &w);

        void update();//Update code /could be put in here.
        void draw(sf::RenderWindow &w);


        //Returns the max X and Y nodes.
        int maxX();
        int maxY();



        //Get and Set inner color.
        void setInnerColor(int,int,sf::Color);
        sf::Color getInnerValue(int,int);

        //Get and set outer color.
        void setOuterColor(int,int,sf::Color);
        sf::Color getOuterValue(int,int);

        void setAllColor(int,int,sf::Color);

    private:
        SquareYard ** Yard;
        SimulationController* controller;
        //Holds the max X and Y values.
        int X;
        int Y;

        void applyLandColor(Creature * creature);

};



#endif /* Land_hpp */
