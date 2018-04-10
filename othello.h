//*******************************************************************
//
//  Author:      Brodey Dickerson
//  Email:       bd948215@ohio.edu
//
//
//  Description: header file for the Othello class
//
//  Date:        11/27/2017
//
//*******************************************************************
#include"game.h"
#include"space.h"
#include"colors.h"
#include<iostream>
namespace main_savitch_14{
    class Othello:public game{
    public:
        Othello(){restart();}
        void restart();
        bool is_legal(const std::string& move)const;
        
        
        void make_move(const std::string& move);
        void display_status()const;
        
        
        //return(number of moves == 60)
        bool is_game_over()const{return((moves_completed()-total_passes == 60) || passes == 2);}
        // Return a pointer to a copy of myself:
        game* clone()const{return new Othello(*this);}
        // Evaluate a board position:
        // NOTE: positive values are good for the computer.
        int evaluate()const;
        // Compute all the moves that the next player can make:
        void compute_moves(std::queue<std::string>& moves)const;
        
        
        bool test_for_black(int tmp_row, int tmp_column,int row_op, int column_op)const;
        bool test_for_white(int tmp_row, int tmp_column,int row_op, int column_op)const;
        void flip_spaces(int tmp_row, int tmp_column, int row_op, int column_op);
        who winning( ) const;
    private:
        Space board[8][8];
        int passes;
        int total_passes;
    };
}

/*
 // *******************************************************************
	// OPTIONAL VIRTUAL FUNCTIONS (overriding these is optional)
	// *******************************************************************
	virtual void display_message(const std::string& message) const;
 virtual std::string get_user_move( ) const;
	virtual who last_mover( ) const
 { return (move_number % 2 == 1 ? HUMAN : COMPUTER); }
	virtual int moves_completed( ) const { return move_number; }
	virtual who next_mover( ) const
 { return (move_number % 2 == 0 ? HUMAN : COMPUTER); }
	virtual who opposite(who player) const
 { return (player == HUMAN) ? COMPUTER : HUMAN; }
 virtual who winning( ) const;
*/
