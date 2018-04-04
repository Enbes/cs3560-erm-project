/*
Name: Braden Baker
Class: CS 2401
Date: 4/11/2017
Project: Project 6 Checkers Game
*/
#ifndef CHECKERS_H
#define CHECKERS_H
#include "game.h"
#include "colors.h"
#include "space.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <queue>

namespace main_savitch_14 
{
    class checkers : public game 
    {
      public: 
      
        checkers(){}
        static const int ROWS = 8;
        static const int COLUMNS = 8;
        
        void restart();
        void display_status() const;
        bool is_legal(const std::string& move) const;
        void make_move(const std::string& move);
        bool is_game_over() const;
        who winning( ) const;

    private:
    
      space data[COLUMNS][ROWS];
      bool is_jump_avail(queue<string>& moves) const;  //used by is_legal
      bool check4jumps(const string& move) const;  //used by is_jump_avail
      void movehelper(const string& move, int& i, int& j, int& x, int& y, int& c);  // used by make_move  // converts next parts of string to board location
      void additionaljumps(const string& move, int& x, int& y, int& c); //used by movehelper
      void getstartloc(const string& move, int& i, int& j); //used by movehelper
      void getmovetoloc(const string& move, int& x, int& y);  //used by movehelper
      void getmovetoloc(const string& move, int& x, int& y) const; // used by is_legal functions
      void getstartloc(const string& move, int& i, int& j) const; //used by is_legal functions
      bool peice_king(const string& move) const; //used by is_legal functions
      bool startnotneutral(const string& move) const; //used by is_legal functions
      bool move2neutral(const string& move) const;  //used by is_legal functions
      bool jumptopright(const string& move) const;  //all used by is_legal
      bool jumptopleft(const string& move) const;
      bool jumpbotright(const string& move) const;
      bool jumpbotleft(const string& move) const;
    };
}

#endif