/*
Name: Braden Baker
Class: CS 2401
Date: 4/11/2017
Project: Project 6 Checkers Game
*/
#ifndef SPACE_H
#define SPACE_H

class space 
{
  private:
  
    bool kingstatus;  
    enum board { NONE, GREEN, RED };
    board color;
    
  public:
    space() { 
        color = NONE; 
        kingstatus = false;
        }

    void make_king() { 
        kingstatus = true; 
        }
    
    void make_green() { 
        color = GREEN; 
        }
    void make_red() { 
        color = RED; 
        }
    void make_neutral() { 
        color = NONE; 
        kingstatus = false;
        }
    void kingslayer() { 
        kingstatus = false; 
        }
    bool is_king() const { 
        return kingstatus; 
        }

    bool is_green() const
    {
        if (color == GREEN) return true;
        else return false;
    }
    bool is_red() const
    {
        if (color == RED) return true;
        else return false;
    }
    bool is_neutral() const
    {
        if (color == NONE) return true;
        else return false;
    }
};

#endif 