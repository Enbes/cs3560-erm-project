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
