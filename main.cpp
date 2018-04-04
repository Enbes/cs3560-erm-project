/*
Name: Braden Baker
Class: CS 2401
Date: 4/11/2017
Project: Project 6 Checkers Game
*/
#include "game.h"
#include "checkers.h"
#include <iostream>
#include <cstdlib>
using namespace std;

using namespace main_savitch_14; 

int main() 
 {
    
    checkers instance;
    checkers::who winner;
    char answer;
        
    do 
    {
        winner = instance.play();
    
        switch (winner) //couts ending message based on who won
        {
            case checkers::HUMAN: cout << "You Win!" << endl;; break;
            case checkers::COMPUTER: cout << "You Lose!" << endl; break;
            case checkers::NEUTRAL: cout << "Everyone Loses!" << endl; break;
        }
            
        cout << "Play again? (y/n)"; //Continues to play as long as the user doesnt pick "n"
        cin >> answer;
        answer = toupper(answer);
            
    } while (answer == 'Y');

    return EXIT_SUCCESS;
}