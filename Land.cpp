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
#include <thread>
#include <chrono>

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

    void Land::update(){
        std::this_thread::sleep_for (std::chrono::seconds(1));
        for (int j=0; j<Y; j++) {
            for (int i=0; i<X ;i++) {
                // Set default color to White
                Yard[i][j].SetInnerSquare(sf::Color::White);
                Yard[i][j].SetOuterSquare(sf::Color::White);
            }
        }
        controller->start();
        vector<Creature *> * creatures = controller->getCreatureList();
        cout<<"\n"<<creatures->size()<<"\n";
        static int i = 0;
        /* Update Land */
        for (int i = 0; i < creatures->size(); ++i) {
            applyLandColor(creatures->at(i));
        }
        
        cout<<"CREATURE DRAWN!!!!***************************\n";
        i++;
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

    void Land::applyLandColor(Creature * creature) {
        // check the type of creature and color the grid block
        string object_type = typeid(*creature).name();
        cout<<endl<<"Create name is "<<object_type<<endl;

        int pos_x = creature->position_x;
        int pos_y = creature->position_y;

        if(object_type.compare("5Grass") == 0){
            Yard[pos_x][pos_y].SetOuterSquare(GREEN);
        }
        else if(object_type.compare("Sheep") == 0){
            Yard[pos_x][pos_y].SetInnerSquare(BLUE);
        }
        else if(object_type.compare("4Wolf") == 0){
            Yard[pos_x][pos_y].SetInnerSquare(RED);
        }
        else if(object_type.compare("Zombie") == 0){
            Yard[pos_x][pos_y].SetInnerSquare(BLACK);
        }
        else if(object_type.compare("Rabiit") == 0){
            Yard[pos_x][pos_y].SetInnerSquare(YELLOW);
        }
        else if(object_type.compare("4Deer") == 0){
            Yard[pos_x][pos_y].SetInnerSquare(BLUE);
        }
    }












