//
//  Land.cpp
//  CS474 project 3
//
//  Copyright © 2016 UIC. All rights reserved.
//

#include "Land.hpp"
#include "Creature.h"
#include <vector>
#include <typeinfo>
#include <string>

#define BLACK sf::Color::Black
#define WHITE sf::Color::White
#define RED sf::Color::Red
#define GREEN sf::Color::Green
#define BLUE sf::Color::Blue
#define YELLOW sf::Color::Yellow
#define MAGENTA sf::Color::Magenta
#define CYAN sf::Color::Cyan

using namespace std;

    Land::Land(){

    }
    Land::~Land(){
        if (Y>0) {
            for (int j=0; j<X; j++) {
                delete[] Yard[j];
            }
        }
        delete[] Yard;
    }

    Land::Land(int horizontalSquares,int VerticalSquares,sf::RenderWindow &w){
        X = horizontalSquares;
        Y = VerticalSquares;
        float xOffset=0;
        float yOffset=0;

        float dx = (float (w.getSize().x) / float (horizontalSquares));
        float dy = (float (w.getSize().y) / float (VerticalSquares));

        // Initialize simulation controller
        controller = new SimulationController();

        // Allocate the array
        Yard = new SquareYard*[X];
        for(int i = 0; i < X; ++i){
            Yard[i]= new SquareYard[Y];
        }

        //Setup the default state.
        for (int j=0; j<Y; j++) {
            xOffset=0;
            for (int i=0; i<X ;i++) {
                Yard[i][j].set(xOffset,yOffset,dx,dy);
                // Set default color to White
                Yard[i][j].SetInnerSquare(sf::Color::White);
                Yard[i][j].SetOuterSquare(sf::Color::White);
                xOffset+=dx;
            }
            yOffset+=dy;
        }
    }

    void Land::update(std::vector<Creature *> &creatures){
        //controller->routine();
        vector<Creature *> creatures = controller->getCreatureList();

        /* Update Land */
        for (int i = 0; i < creatures.size(); ++i) {
            applyLandColor(creatures[i]);
        }
    }

    void Land::draw(sf::RenderWindow &w){
        for (int j=0; j<Y; j++) {
            for (int i=0; i<X ;i++) {
                Yard[i][j].draw(w);
            }
        }
    }


    //Get Maxes
    int Land::maxX(){
        return X;
    }
    int Land::maxY(){
        return Y;
    }



    //Get and Set inner color.
    void Land::setInnerColor(int x,int y,sf::Color c){
        Yard[x][y].SetInnerSquare(c);
    }
    sf::Color Land::getInnerValue(int x,int y){
        return Yard[x][y].getInnerSquare();
    }
        //Get and set outer color.
    void Land::setOuterColor(int x,int y,sf::Color c){
        Yard[x][y].SetOuterSquare(c);
    }
    sf::Color Land::getOuterValue(int x,int y){
        return Yard[x][y].getOuterSquare();
    }

    void Land::setAllColor(int x,int y,sf::Color c){
        Yard[x][y].SetInnerSquare(c);
        Yard[x][y].SetOuterSquare(c);
    }

    void Land::applyLandColor(Creature creature) {
        // check the type of creature and color the grid block
        object_type = typeid(creature).name();
        int pos_x = creature.position_x;
        int pos_y = creature.position_y;

        if(object_type.compare("Grass") == 0){
            Yard[pos_x][pos_y].setOuterColor(GREEN);
        }
        else if(object_type.compare("Sheep") == 0){
            Yard[pos_x][pos_y].setInnerColor(BLUE);
        }
        else if(object_type.compare("Wolf") == 0){
            Yard[pos_x][pos_y].setInnerColor(RED);
        }
        else if(object_type.compare("Zombie") == 0){
            Yard[pos_x][pos_y].setInnerColor(BLACK);
        }
        else if(object_type.compare("Rabiit") == 0){
            Yard[pos_x][pos_y].setInnerColor(YELLOW);
        }
        else if(object_type.compare("Deer") == 0){
            Yard[pos_x][pos_y].setInnerColor(MAGENTA);
        }
    }












