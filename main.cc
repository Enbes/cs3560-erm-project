/**
* @file main.cc
* @brief Main function
* @author Brodey Dickerson (original code), Corbin Dotson (documentation), Braden Baker (error checking)
*
* This file only contains the main function to run the program. It declares 
* several variables for the game, and begins its execution.
*/

//*******************************************************************
//
//  Author:      Brodey Dickerson
//  Email:       bd948215@ohio.edu
//
//
//  Description: Main for part 3
//
//  Date:        11/27/2017
//
//*******************************************************************
#include<cstdlib>
#include<iostream>
#include"game.h"
#include"colors.h"
#include"othello.h"
using namespace std;
using namespace main_savitch_14;
int main(){
    game::who Winner;
    Othello mygame;
    Winner = mygame.play();
    if(Winner == main_savitch_14::Othello::HUMAN) cout << "Player 1 wins!\n";
    else if (Winner == main_savitch_14::Othello::COMPUTER) cout << "Computer wins!\n";
    else if (Winner == main_savitch_14::Othello::NEUTRAL) cout << "TIE GAME\n";
    else cout << "ERROR\nNO WINNER: GAME BROKE\n";
    return EXIT_SUCCESS;
}
