/**
* @file othello.cc
* @brief Implementation of the Othello class
* @author Brodey Dickerson (original code, fixes), Braden Baker (fixes), Corbin Dotson (documentation)
*
* This file contains the implementation of the Othello class' functions.
*/

//*******************************************************************
//
//  Author:      Brodey Dickerson
//  Email:       bd948215@ohio.edu
//
//
//  Description: Implementation file for the Othello class
//
//  Date:        11/27/2017
//
//*******************************************************************
#include"othello.h"
#include <queue>
using namespace std;
using namespace main_savitch_14;



//                              restart
//*******************************************************************
/**
* Restarts the game by emptying the board, then placing the initial pieces on the board.
* takes no arguments
* @return void
*/
void Othello::restart(){
    //pass to zero
    passes = 0;
    total_passes = 0;
    //sets all array spaces to empty
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            board[i][j].set_empty();
        }
    }
    //adding 4 center pieces
    board[3][3].set_white();
    board[4][4].set_white();
    board[3][4].set_black();
    board[4][3].set_black();
}
//*******************************************************************



//                          is_legal
//*******************************************************************
/**
* Decides if a proposed move is legal by checking if the space is on the board, is adjacent to an opposing piece, and is empty.
* @param move: a string representing the board location where a piece is trying to be placed
* @return bool: true if the move is legal, false otherwise
*/
bool Othello::is_legal(const string& move)const{
    //coverting string to ints: easier to surf board
    int row = int(toupper(move[0] - 'A'));
    int column = int(move[1] - '1');
    
    //CASE 0: NON-EMPTY SPACE
    if(!board[row][column].is_empty()) return false;
    //CASE 1: black player
    else if(next_mover() == HUMAN){
        //CASE 1: checking top left
        if(board[row-1][column-1].is_white() && test_for_white(row-1,column-1,-1,-1)) return true;
        //CASE 2: checking above piece
        if(board[row-1][column].is_white() && test_for_white(row-1,column,-1,0)) return true;
        //CASE 3: checking top right
        if(board[row-1][column+1].is_white() && test_for_white(row-1,column+1,-1,1)) return true;
        //CASE 4: checking right piece
        if(board[row][column+1].is_white() && test_for_white(row,column+1,0,1)) return true;
        //CASE 5: checking bottom right
        if(board[row+1][column+1].is_white() && test_for_white(row+1,column+1,1,1)) return true;
        //CASE 6: checking down piece
        if(board[row+1][column].is_white() && test_for_white(row+1,column,1,0)) return true;
        //CASE 7: checking bottom left
        if(board[row+1][column-1].is_white() && test_for_white(row+1,column-1,1,-1)) return true;
        //CASE 8: checking left piece
        if(board[row][column-1].is_white() && test_for_white(row,column-1,0,-1)) return true;
    }
    //CASE 2: white player
    else if(next_mover() == COMPUTER){
        //CASE 1: checking top left
        if(board[row-1][column-1].is_black() && test_for_black(row-1,column-1,-1,-1)) return true;
        //CASE 2: checking above piece
        if(board[row-1][column].is_black() && test_for_black(row-1,column,-1,0)) return true;
        //CASE 3: checking top right
        if(board[row-1][column+1].is_black() && test_for_black(row-1,column+1,-1,1)) return true;
        //CASE 4: checking right piece
        if(board[row][column+1].is_black() && test_for_black(row,column+1,0,1)) return true;
        //CASE 5: checking bottom right
        if(board[row+1][column+1].is_black() && test_for_black(row+1,column+1,1,1)) return true;
        //CASE 6: checking down piece
        if(board[row + 1][column].is_black() && test_for_black(row+1,column,1,0)) return true;
        //CASE 7: checking bottom left
        if(board[row+1][column-1].is_black() && test_for_black(row+1,column-1,1,-1)) return true;
        //CASE 8: checking left piece
        if(board[row][column-1].is_black() && test_for_black(row,column-1,0,-1)) return true;
    }
    return false;
}
//*******************************************************************



//                          make_move
//*******************************************************************
/**
* Alters the game board to show the result of a new piece being placed.
* @param move: a string representing the board location where a piece is trying to be placed 
* @return void
*/
void Othello::make_move(const string& move){
    //moving piece
    int row = int(toupper(move[0] - 'A'));
    int column = int(move[1] - '1');
    if(next_mover() == HUMAN) board[row][column].set_black();
    else if(next_mover() == COMPUTER) board[row][column].set_white();
    
    //LET THE GAME BEGIN
    if(next_mover() == HUMAN){
        //CASE 1: checking top left
        if(test_for_white(row-1,column-1,-1,-1))flip_spaces(row-1,column-1,-1,-1);
        //CASE 2: checking above piece
        if(test_for_white(row-1,column,-1,0))flip_spaces(row-1,column,-1,0);
        //CASE 3: checking top right
        if(test_for_white(row-1,column+1,-1,1))flip_spaces(row-1,column+1,-1,1);
        //CASE 4: checking right piece
        if(test_for_white(row,column+1,0,1))flip_spaces(row,column+1,0,1);
        //CASE 5: checking bottom right
        if(test_for_white(row+1,column+1,1,1))flip_spaces(row+1,column+1,1,1);
        //CASE 6: checking down piece
        if(test_for_white(row+1,column,1,0))flip_spaces(row+1,column,1,0);
        //CASE 7: checking bottom left
        if(test_for_white(row+1,column-1,1,-1))flip_spaces(row+1,column-1,1,-1);
        //CASE 8: checking left piece
        if(test_for_white(row,column-1,0,-1))flip_spaces(row,column-1,0,-1);
    }
    //white player
    else if(next_mover() == COMPUTER){
        //CASE 1: checking top left
        if(test_for_black(row-1,column-1,-1,-1))flip_spaces(row-1,column-1,-1,-1);
        //CASE 2: checking above piece
        if(test_for_black(row-1,column,-1,0))flip_spaces(row-1,column,-1,0);
        //CASE 3: checking top right
        if(test_for_black(row-1,column+1,-1,1))flip_spaces(row-1,column+1,-1,1);
        //CASE 4: checking right piece
        if(test_for_black(row,column+1,0,1))flip_spaces(row,column+1,0,1);
        //CASE 5: checking bottom right
        if(test_for_black(row+1,column+1,1,1))flip_spaces(row+1,column+1,1,1);
        //CASE 6: checking down piece
        if(test_for_black(row+1,column,1,0))flip_spaces(row+1,column,1,0);
        //CASE 7: checking bottom left
        if(test_for_black(row+1,column-1,1,-1))flip_spaces(row+1,column-1,1,-1);
        //CASE 8: checking left piece
        if(test_for_black(row,column-1,0,-1))flip_spaces(row,column-1,0,-1);
    }
    game::make_move(move);
    bool legality = false;
    do{
        string numbers = "12345678";
        string letters = "ABCDEFGH";
        string tmp = "  ";
        for(int i = 0; i < 8; i++){
            for(int j =0; j < 8; j++){
                tmp[0] = letters[i];
                tmp[1] = numbers[j];
                if(is_legal(tmp)){
                    legality = true;
                }
            }
        }
        if(legality == false){
            //if(next_mover() == COMPUTER) cout << "No possible moves for COMPUTER: Turn passed\n";
            //if(next_mover() == HUMAN) cout << "No possible moves for HUMAN: Turn passed\n";
            passes++;
            total_passes++;
            game::make_move(move);
        }
    }while(legality == false && passes < 2);
    //*/

}
//*******************************************************************



//                          display_status
//*******************************************************************
/**
* Displays the game board, including a turn counter and the number of each player's pieces on the board.
* @param takes no arguments
* @return void
*/
void Othello::display_status()const{
    //Color decloration for checker patern (USED LATER)
    const string COLOR_1 = B_CYAN;
    const string COLOR_2 = B_BLUE;
    
    
    //Column numbers: string = array of char
    const string NUMBERS = " 12345678";
    for(int i = 0; i < 9; i++){
        cout << BOLD << ERROR;
        cout << " " << NUMBERS[i] << " ";
    }
    cout << RESET << endl;
    
    
    //Row letters
    const string LETTERS = "ABCDEFGH";
    
    //These for loops display the board itself along with the row letters
    for(int i = 0; i < 8; i++){
        cout << BOLD << ERROR << " " << LETTERS[i] << " ";
        for(int j = 0; j < 8; j++){
            
            //used to create checked board
            if(j%2 == 0 && i%2==0) cout << COLOR_2;
            else if(j%2==0 && i%2==1) cout << COLOR_1;
            else if(j%2==1 && i%2==1) cout << COLOR_2;
            else if(j%2==1 && i%2==0) cout << COLOR_1;
            
            //CASE 1: Black
            if(board[i][j].is_black()){
                cout << BOLD << B_BLACK << WHITE << " B " << RESET;
            }
            //CASE 2: White
            else if(board[i][j].is_white()){
                cout << BOLD << B_WHITE << BLACK << " W " << RESET;
            }
            //CASE 3: EMPTY
            else cout << "   ";
            
        }
        cout << RESET;
        //outputing peices counter and turn
        int p1 = 0;
        int p2 = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j].is_black()) p1++;
                else if(board[i][j].is_white()) p2++;
            }
        }
        if(i==0 && passes > 0){
            if(last_mover() == HUMAN) cout << " Turn skipped";
            else if(last_mover() == COMPUTER) cout << " Computer's turn skipped";
        }
        else if(i==2) cout << " Turn: " << moves_completed();
        else if(i==3){
            cout << " White pieces: " << p2;
        }
        else if(i==4){
            cout << " Black pieces: " << p1;
        }
        cout << endl;
    }
    cout << RESET << endl;;
}
//*******************************************************************



//               The best functions I've ever written :D
//*******************************************************************
//                      TEST FOR WHITE PIECES
/**
* Looks along a vector of spaces starting to determine if it contains some number of white pieces.
* @param tmp_row: start row number, tmp_column: start column number, row_op: change in row number for vector, column_op: change in column number for vector
* @return bool: true if a vector of spaces are all white and ends with black, otherwise false
*/
bool Othello::test_for_white(int tmp_row, int tmp_column,int row_op, int column_op)const{
    while(tmp_row >= 0 && tmp_row < 8 && tmp_column >= 0 && tmp_column < 8 && board[tmp_row][tmp_column].is_white()){
        tmp_row = tmp_row + row_op;
        tmp_column = tmp_column + column_op;
    }
    if(tmp_row < 0 || tmp_row >= 8 || tmp_column < 0 || tmp_column >= 8) return false;
    else return(board[tmp_row][tmp_column].is_black());
}
//                      TEST FOR BLACK PIECES
/**
* Looks along a vector of spaces starting to determine if it contains some number of black pieces.
* @param tmp_row: start row number, tmp_column: start column number, row_op: change in row number for vector, column_op: change in column number for vector
* @return bool: true if a vector of spaces are all black and ends with white, otherwise false
*/
bool Othello::test_for_black(int tmp_row, int tmp_column,int row_op, int column_op)const{
    while(tmp_row >= 0 && tmp_row < 8 && tmp_column >= 0 && tmp_column < 8 && board[tmp_row][tmp_column].is_black()){
        tmp_row = tmp_row + row_op;
        tmp_column = tmp_column + column_op;
    }
    if(tmp_row < 0 || tmp_row >= 8 || tmp_column < 0 || tmp_column >= 8) return false;
    else return(board[tmp_row][tmp_column].is_white());
}
//*******************************************************************
/**
* Flips pieces to the opposite color along a vector and ending when encountering a piece of this player's color.
* @param tmp_row: start row number, tmp_column: start column number, row_op: change in row number for vector, column_op: change in column number for vector
* @return void
*/
void Othello::flip_spaces(int tmp_row, int tmp_column, int row_op, int column_op){
    if(next_mover() == HUMAN){
        while(tmp_row >= 0 && tmp_row < 8 && tmp_column >= 0 && tmp_column < 8 && board[tmp_row][tmp_column].is_white()){
            board[tmp_row][tmp_column].flip();
            tmp_row = tmp_row + row_op;
            tmp_column = tmp_column + column_op;
        }
    }
    else if(next_mover() == COMPUTER){
        while(tmp_row >= 0 && tmp_row < 8 && tmp_column >= 0 && tmp_column < 8 && board[tmp_row][tmp_column].is_black()){
            board[tmp_row][tmp_column].flip();
            tmp_row = tmp_row + row_op;
            tmp_column = tmp_column + column_op;
        }
    }
    passes = 0;
}
//*******************************************************************



//                          Compute Moves
//*******************************************************************
/**
* Attempts all possible moves until finding a valid one.
* @param moves: a queue of strings white define possible moves
* @return void
*/
void Othello::compute_moves(std::queue<std::string>& moves)const{
  /*  string move = " ";
    for(char i = 'A'; i < 'I';i++){
        for(char j = '1'; j < '9'; j++){
            cout << "COMPUTER EVALUATING\n";
            move[0] = i;
            move[1] = j;
            if(is_legal(move)){
                moves.push(move);
                cout << "Pushed: " << move << endl;
            }
        }
    }*/
    string numbers = "12345678";
    string letters = "ABCDEFGH";
    string move = "  ";
    for(int i = 0; i < 8; i++){
        for(int j =0; j < 8; j++){
            move[0] = letters[i];
            move[1] = numbers[j];
            if(is_legal(move)){
                moves.push(move);
                //cout << "Pushed: " << move << endl;
            }
        }
    }
}
//*******************************************************************



//                          Evaluate
//*******************************************************************
/**
* Checks to see which player has more pieces on the board.
* @param takes no arguments
* @return int: how many more pieces the white player has than the black, thus negative if black is in the lead
*/
int Othello::evaluate()const{
    int num = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j].is_black()) num--;
            else if(board[i][j].is_white()) num++;
        }
    }
    return num;
}
//*******************************************************************


/**
* Checks to see which player is winning.
* @param takes no arguments
* @return game::who: the winning player
*/
game::who Othello::winning()const{
    int p1 = 0;
    int p2 = 0;
    cout << "Calculating Winner\n";
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[i][j].is_black()) p1++;
            else if(board[i][j].is_white()) p2++;
        }
    }
    cout << "Player Piece Count: " << p1 << endl;
    cout << "Computer Piece Count: " << p2 << endl;
    if(p1 > p2) return HUMAN;
    else if(p2 > p1) return COMPUTER;
    else return NEUTRAL;
}


