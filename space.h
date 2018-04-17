/**
* @file space.h
* @brief Header file for space class
* @author Brodey Dickerson (original code), Corbin Dotson (documentation)
* 
* This file is a header file for the space class. It contains both the definition
* and implementation of the space class.
*/

//*******************************************************************
//
//  Author:      Brodey Dickerson
//  Email:       bd948215@ohio.edu
//
//
//  Description: Class for a single space
//
//  Date:        11/27/2017
//
//*******************************************************************

class Space{
public:
    Space(char c = 'E') {state = c;}
    //Space(){ state = 'E';}
    bool is_black()const{return(state == 'B');}
    bool is_white()const{return(state == 'W');}
    bool is_empty()const{return(state == 'E');}
    
    //Mutator
    void flip(){if(state == 'B') state = 'W';else if(state == 'W') state = 'B';}
    void set_empty(){state = 'E';}
    void set_white(){state = 'W';}
    void set_black(){state = 'B';}
    
private:
    char state;
};
