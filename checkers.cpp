/*
Name: Braden Baker
Class: CS 2401
Date: 4/11/2017
Project: Project 6 Checkers Game

Description: This file contains the restart, display_status, is_legal, and make_move
    restart: Resets the board and puts all the peices back in there original places
    display_status: Displays the pieces on the board
    is_legal: Checks the move input by the users and makes sure that move is legal
    make_move: Moves the pieces on the board based on the user input as long as its legal
*/
#include "checkers.h"
using namespace std;

namespace main_savitch_14
{

    void checkers::restart() {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                
                if (i == 0 && (j == 1 || j == 3 || j == 5 || j == 7)) 
                    data[i][j].make_red();
                else if (i == 1 && (j == 0 || j == 2 || j == 4 || j == 6)) 
                    data[i][j].make_red();
                else if (i == 2 && (j == 1 || j == 3 || j == 5 || j == 7)) 
                    data[i][j].make_red();
                else if (i == 5 && (j == 0 || j == 2 || j == 4 || j == 6)) 
                    data[i][j].make_green();
                else if (i == 6 && (j == 1 || j == 3 || j == 5 || j == 7)) 
                    data[i][j].make_green();
                else if (i == 7 && (j == 0 || j == 2 || j == 4 || j == 6)) 
                    data[i][j].make_green();
                else 
                    data[i][j].make_neutral();
                if (data[i][j].is_king()) 
                    data[i][j].kingslayer();
            }
        }
        game::restart();
    }


    void checkers::display_status() const {      
        int count = 1;
        cout << B_BLACK << "                                " << RESET << endl;
        cout << B_BLACK << "  " << B_MAGENTA << "   A  B  C  D  E  F  G  H   "  << B_BLACK << "  " << RESET << endl;
        for (int i = 0; i < ROWS; i++) {
            cout << B_BLACK << "  " << B_MAGENTA << count << " ";   
            for (int j = 0; j < COLUMNS; j++) {
                if (((j+i)%2) == 0) cout << B_WHITE << "   " << RESET;
                else if (!data[i][j].is_green() && !data[i][j].is_red()) 
                    cout << B_BLACK << "   " << RESET;  
                else if (data[i][j].is_red() && data[i][j].is_king()) 
                    cout << B_BLACK << RED << " K " << RESET;
                else if (data[i][j].is_red()) 
                    cout << B_BLACK << RED << " O " << RESET;
                else if (data[i][j].is_green() && data[i][j].is_king()) 
                    cout << B_BLACK << GREEN << " K " << RESET;
                else if (data[i][j].is_green()) 
                    cout << B_BLACK << GREEN << " O " << RESET; 
            }
            cout << B_MAGENTA << " " << count << B_BLACK << "  " << RESET << endl;
            count++;
        }
        cout << B_BLACK << "  " << B_MAGENTA << "   A  B  C  D  E  F  G  H   " << B_BLACK << "  " << RESET<< endl << B_BLACK << "                                " << RESET << endl;
    }

    bool checkers::is_legal(const string& move) const { 
                    //BASE OBVIOUS FAILURES
            if (move[1] < '1' || move[1] > '8') 
                return false;
            if (move[3] < '1' || move[3] > '8') 
                return false;  
            if (move[0] < 'a' || move[0] > 'h') 
                return false;
            if (move[2] < 'a' || move[2] > 'h') 
                return false;
            if (!startnotneutral(move)) 
                return false;
            if (!move2neutral(move)) 
                return false;
                    //GREEN MOVES - JUMPS - RED MOVES - JUMPS - CATCH ALL
            if (moves_completed()%2 == 0 && (move[0] - 1 == move[2] || move[0] + 1 == move[2]) && (move[1] - 1 == move[3] || (peice_king(move) && move[1] + 1 == move[3])) ) 
                return true;
            else if (moves_completed()%2 == 0 && (move[0]-2 == move[2] || move[0]+2 == move[2]) && (jumptopright(move) || jumptopleft(move) || jumpbotright(move) || jumpbotleft(move)) ) 
                return true;
            else if (moves_completed()%2 == 1 && (move[0]-1 == move[2] || move [0]+1 == move[2]) && (move[1]+1 == move[3] || (peice_king(move) && move[1]-1 == move[3])) ) 
                return true;
            else if (moves_completed()%2 == 1 && (move[0]-2 == move[2] || move[0]+2 == move[2]) && (jumptopright(move) || jumptopleft(move) || jumpbotright(move) || jumpbotleft(move)) ) 
                return true;
            else return false;
    }
    
    void checkers::make_move(const string& move) {   //overridden
        int i, j, x, y, c;
        i = j = x = y = c =0;  //reset all to zero each time this function is called
        while (move[c] != '\0') {
                                  //NORMAL AND KING MOVES
            checkers::movehelper(move, i, j, x, y, c);  //advance the move
            
            if (data[i][j].is_green() && (i - 1 == x || i + 1 == x) && (j + 1 == y || j - 1 == y) ) { //basic green moves including kings
                data[x][y].make_green();
                if (data[i][j].is_king()) 
                    data[x][y].make_king();  //keep king status while moving around
                data[i][j].make_neutral();
                if (!data[x][y].is_king() && x == 0) 
                    data[x][y].make_king();  //make king if not already and on the last row
                c += 2;
            }

            if (data[i][j].is_red() && (i - 1 == x || i + 1 == x) && (j + 1 == y || j - 1 == y) ) {  //basic red moves including kings
                data[x][y].make_red();
                if (data[i][j].is_king()) 
                    data[x][y].make_king();  //keep king status while moving around
                data[i][j].make_neutral();
                if (!data[x][y].is_king() && x == 7) 
                    data[x][y].make_king();  //make king if not already and on the last row
                c += 2;
            }
                                //NORMAL JUMPS
            if (data[i][j].is_green() && (i - 2 == x) && (j + 2 == y) ) {  //green jumps top right
                data[x][y].make_green();
                if (data[i][j].is_king()) 
                    data[x][y].make_king();
                data[i][j].make_neutral();
                data[i - 1][j + 1].make_neutral();
                if (!data[x][y].is_king() && x == 0) {  //make king and end turn as per checkers rules
                    data[x][y].make_king();
                    game::make_move(move); //move_number++
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }

            if (data[i][j].is_green() && (i - 2 == x) && (j - 2 == y) ) {  //green jumps top left
                data[x][y].make_green();
                if (data[i][j].is_king()) 
                    data[x][y].make_king();
                data[i][j].make_neutral();
                data[i - 1][j - 1].make_neutral();
                if (!data[x][y].is_king() && x == 0) {  //make king and end turn as per checkers rules
                    data[x][y].make_king();
                    game::make_move(move); //move_number++
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }

            if (data[i][j].is_red() && (i + 2 == x) && (j  + 2== y) ) {  //red jumps bot right
                data[x][y].make_red();
                if (data[i][j].is_king()) 
                    data[x][y].make_king();
                data[i][j].make_neutral();
                data[i + 1][j + 1].make_neutral();
                if (!data[x][y].is_king() && x == 7) {  //make king and end turn as per checkers rules
                    data[x][y].make_king();
                    game::make_move(move); //move_number++
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }
            
            if (data[i][j].is_red() && (i + 2 == x) && (j - 2 == y) ) {  //red jumps bot left
                data[x][y].make_red();
                if (data[i][j].is_king()) 
                    data[x][y].make_king();
                data[i][j].make_neutral();
                data[i + 1][j - 1].make_neutral();
                if (!data[x][y].is_king() && x == 7) {  //make king and end turn as per checkers rules
                    data[x][y].make_king();
                    game::make_move(move); //move_number++
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }
                                //KINGS JUMPS
            if (data[i][j].is_red() && data[i][j].is_king() && (i - 2 == x) && (j + 2 == y) ) {  //red king jumps top right
                data[x][y].make_red();
                if (data[i][j].is_king()) 
                    data[x][y].make_king();
                data[i][j].make_neutral();
                data[i - 1][j + 1].make_neutral();
                if (!data[x][y].is_king() && x == 7) {  //make king and end turn as per checkers rules
                    data[x][y].make_king();
                    game::make_move(move); //move_number++
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }

            if (data[i][j].is_red() && data[i][j].is_king() && (i - 2 == x) && (j - 2 == y) ) {  //red king jumps top left
                data[x][y].make_red();
                if (data[i][j].is_king()) 
                    data[x][y].make_king();
                data[i][j].make_neutral();
                data[i - 1][j - 1].make_neutral();
                if (!data[x][y].is_king() && x == 7) {  //make king and end turn as per checkers rules
                    data[x][y].make_king();
                    game::make_move(move); //move_number++
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }

            if (data[i][j].is_green() && data[i][j].is_king() && (i + 2 == x) && (j  + 2== y) ) {  //green king jumps bot right
                data[x][y].make_green();
                if (data[i][j].is_king()) 
                    data[x][y].make_king();
                data[i][j].make_neutral();
                data[i + 1][j + 1].make_neutral();
                if (!data[x][y].is_king() && x == 0) {  //make king and end turn as per checkers rules
                    data[x][y].make_king(); 
                    game::make_move(move); //move_number++
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }
            if (data[i][j].is_green() && data[i][j].is_king() && (i + 2 == x) && (j - 2 == y) ) {  //green kings jumps bot left
                data[x][y].make_green();
                if (data[i][j].is_king()) 
                     data[x][y].make_king();
                data[i][j].make_neutral();
                data[i + 1][j - 1].make_neutral();
                if (!data[x][y].is_king() && x == 0) {  //make king and end turn as per checkers rules
                    data[x][y].make_king(); 
                    game::make_move(move); //move_number++
                    return;
                }
                i = x;
                j = y;
                c += 2;
                continue;
            }
        }
        game::make_move(move); //move_number++
    }

bool checkers::is_game_over() const {    //pure virutal : gets game status
    cout << "Checking if game is over...\n";
    int humancount = 0;
    int computercount = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (data[i][j].is_green()) humancount++;
            else if(data[i][j].is_red()) computercount++;              
            else;
        }
    }
    cout << "Green (human player) has " << humancount << " peices left.\n";
    cout << "Red (computer player) has " << computercount << " peices left.\n";
    cout << "On turn " << moves_completed()+1 << ". ";
    if (moves_completed()%2 == 0) cout << GREEN << "Green Player's turn." << RESET<< endl;
    else cout << RED << "Red Player's turn." << RESET << endl;
    if (humancount == 0 || computercount == 0) return true; //game is over if either player has 0 pieces
    else return false;
    }

checkers::who checkers::winning() const {  //overridden
    int humancount = 0;
    int computercount = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (data[i][j].is_green()) 
                humancount++;
            else if(data[i][j].is_red()) 
                computercount++;              
            else;
        }
    }
    if (humancount == computercount) 
        return NEUTRAL;
    return (humancount > computercount) 
        ? HUMAN : COMPUTER ;
    }

bool checkers::is_jump_avail(queue<string>& moves) const {
    string tmp;
    int i, j, x, y;
    i = j = x = y = 0;
    int count = 0;
    for (char uno = 'a'; uno < 'i'; uno++) {
        for(char dos = '1'; dos < '9'; dos++) {
            for(char tres = 'a'; tres < 'i'; tres++) {
                for(char quatro = '1'; quatro < '9'; quatro++) {
                    tmp[0] = uno;
                    tmp[1] = dos;
                    tmp[2] = tres;
                    tmp[3] = quatro;
                    if (check4jumps(tmp)) { 
                        count++; 
                        moves.push(tmp);
                    }
                }
            }
        }
    }
    if (count > 0) return true;
    else return false;
}

bool checkers::check4jumps(const string& move) const {
    if (move[1] < '1' || move[1] > '8') return false;
    if (move[3] < '1' || move[3] > '8') return false;  
    if (move[0] < 'a' || move[0] > 'h') return false;
    if (move[2] < 'a' || move[2] > 'h') return false;
    if (!startnotneutral(move)) return false;
    if (!move2neutral(move)) return false;    
    if (moves_completed()%2 == 0 && (move[0]-2 == move[2] || move[0]+2 == move[2]) && (jumptopright(move) || jumptopleft(move) || jumpbotright(move) || jumpbotleft(move)) ) 
        return true;
    else if (moves_completed()%2 == 1 && (move[0]-2 == move[2] || move[0]+2 == move[2]) && (jumptopright(move) || jumptopleft(move) || jumpbotright(move) || jumpbotleft(move)) ) 
        return true;
    else return false;
    }

bool checkers::jumptopright(const string& move) const { //checks if peice can be jumped top right side
    int x = 0, y = 0;
    checkers::getmovetoloc(move, x, y);
    if (moves_completed()%2 == 0 && data[x + 1][y - 1].is_red() && data[x ][y].is_neutral()) 
        return true;  //green peice jump
    if (moves_completed()%2 == 1 && peice_king(move) && data[x + 1][y - 1].is_green() && data[x ][y ].is_neutral()) 
        return true; //red king backwards jump
    return false;
    }

bool checkers::jumptopleft(const string& move) const {  //checks if peice can be jumped on top left side
    int x= 0, y = 0;
    checkers::getmovetoloc(move, x, y);
    if (moves_completed()%2 == 0 && data[x + 1][y + 1].is_red() && data[x][y ].is_neutral()) 
        return true;  //green peice jump
    if (moves_completed()%2 == 1 && peice_king(move) && data[x + 1][y + 1].is_green() && data[x ][y ].is_neutral()) 
        return true; //red king backwards jump
    return false;
    }

bool checkers::jumpbotright(const string& move) const {  //checks if peice can be jumped on bottom right side
    int x = 0, y = 0;
    checkers::getmovetoloc(move, x, y);
    if (moves_completed()%2 == 1 && data[x - 1][y - 1].is_green() && data[x ][y ].is_neutral()) 
        return true;  //red peice jump
    if (moves_completed()%2 == 0 && peice_king(move) && data[x - 1][y - 1].is_red() && data[x][y].is_neutral()) 
        return true; //green king backwards jump
    return false;    
    }

bool checkers::jumpbotleft(const string& move) const {  //checks if peice can be jumped on the bottom left side
    int x = 0, y = 0;
    checkers::getmovetoloc(move, x, y);
    if (moves_completed()%2 == 1 && data[x - 1][y + 1].is_green() && data[x ][y ].is_neutral()) 
        return true;  //red peice jump
    if (moves_completed()%2 == 0 && peice_king(move) && data[x - 1][y + 1].is_red() && data[x ][y].is_neutral()) 
        return true; //green king backwards jump
    return false;    
    }

bool checkers::startnotneutral(const string& move) const { //checks that starting location is not neutral
    int i = 0, j = 0;
    checkers::getstartloc(move, i, j);
    if (data[i][j].is_neutral()) 
        return false;
    else return true;
    }

bool checkers::move2neutral(const string& move) const { //checks if move to location is neutral
    int x = 0, y = 0;
    checkers::getmovetoloc(move, x, y);
    if (data[x][y].is_neutral()) 
        return true;
    else return false;
    }

bool checkers::peice_king(const string& move) const{ //checks if current peice to move is a legal king
    int i = 0, j = 0;
    checkers::getstartloc(move, i, j);
    if (data[i][j].is_king()) 
        return true;
    else return false;
    }

void checkers::movehelper(const string& move, int& i, int& j, int& x, int& y, int& c) {  //converts next 2 of string to [i][j] or [x][y]
    if (c == 0) {  //first part of move
        checkers::getstartloc(move, i, j);
        checkers::getmovetoloc(move, x, y);
        c += 2;
    } 
    else {
        checkers::additionaljumps(move, x, y, c);
    }
}

void checkers::getstartloc(const string& move, int& i, int& j) const {
    for (int z = 0; z < 2; z++) {
        if (move[z] == 'a') j = 0;
        if (move[z] == 'b') j = 1;
        if (move[z] == 'c') j = 2;
        if (move[z] == 'd') j = 3;
        if (move[z] == 'e') j = 4;
        if (move[z] == 'f') j = 5;
        if (move[z] == 'g') j = 6;
        if (move[z] == 'h') j = 7;
        if (move[z] == '1') i = 0;
        if (move[z] == '2') i = 1;
        if (move[z] == '3') i = 2;
        if (move[z] == '4') i = 3;
        if (move[z] == '5') i = 4;
        if (move[z] == '6') i = 5;
        if (move[z] == '7') i = 6;
        if (move[z] == '8') i = 7;
    }
}

void checkers::getstartloc(const string& move, int& i, int& j) {
    for (int z = 0; z < 2; z++) {
        if (move[z] == 'a') j = 0;
        if (move[z] == 'b') j = 1;
        if (move[z] == 'c') j = 2;
        if (move[z] == 'd') j = 3;
        if (move[z] == 'e') j = 4;
        if (move[z] == 'f') j = 5;
        if (move[z] == 'g') j = 6;
        if (move[z] == 'h') j = 7;
        if (move[z] == '1') i = 0;
        if (move[z] == '2') i = 1;
        if (move[z] == '3') i = 2;
        if (move[z] == '4') i = 3;
        if (move[z] == '5') i = 4;
        if (move[z] == '6') i = 5;
        if (move[z] == '7') i = 6;
        if (move[z] == '8') i = 7;
    }
}

void checkers::getmovetoloc(const string& move, int& x, int& y) const {
    for (int z = 2; z < 4; z++) {
        if (move[z] == 'a') y = 0;
        if (move[z] == 'b') y = 1;
        if (move[z] == 'c') y = 2;
        if (move[z] == 'd') y = 3;
        if (move[z] == 'e') y = 4;
        if (move[z] == 'f') y = 5;
        if (move[z] == 'g') y = 6;
        if (move[z] == 'h') y = 7;
        if (move[z] == '1') x = 0;
        if (move[z] == '2') x = 1;
        if (move[z] == '3') x = 2;
        if (move[z] == '4') x = 3;
        if (move[z] == '5') x = 4;
        if (move[z] == '6') x = 5;
        if (move[z] == '7') x = 6;
        if (move[z] == '8') x = 7;
    }    
}

void checkers::getmovetoloc(const string& move, int& x, int& y) {
    for (int z = 2; z < 4; z++) {
        if (move[z] == 'a') y = 0;
        if (move[z] == 'b') y = 1;
        if (move[z] == 'c') y = 2;
        if (move[z] == 'd') y = 3;
        if (move[z] == 'e') y = 4;
        if (move[z] == 'f') y = 5;
        if (move[z] == 'g') y = 6;
        if (move[z] == 'h') y = 7;
        if (move[z] == '1') x = 0;
        if (move[z] == '2') x = 1;
        if (move[z] == '3') x = 2;
        if (move[z] == '4') x = 3;
        if (move[z] == '5') x = 4;
        if (move[z] == '6') x = 5;
        if (move[z] == '7') x = 6;
        if (move[z] == '8') x = 7;
    }    
}

void checkers::additionaljumps(const string& move, int& x, int& y, int& c) {
    for (int z = c; z < c+2; z++) {
        if (move[z] == 'a') y = 0;
        if (move[z] == 'b') y = 1;
        if (move[z] == 'c') y = 2;
        if (move[z] == 'd') y = 3;
        if (move[z] == 'e') y = 4;
        if (move[z] == 'f') y = 5;
        if (move[z] == 'g') y = 6;
        if (move[z] == 'h') y = 7;
        if (move[z] == '1') x = 0;
        if (move[z] == '2') x = 1;
        if (move[z] == '3') x = 2;
        if (move[z] == '4') x = 3;
        if (move[z] == '5') x = 4;
        if (move[z] == '6') x = 5;
        if (move[z] == '7') x = 6;
        if (move[z] == '8') x = 7;
    }    
}

}