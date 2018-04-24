
//*****************************************************************************
//  Name:       Brodey Dickerson
//  Email:      bd948215@ohio.edu
//  Purpose:    GoogleTest on cs3560-term-project
//  Date:       04/24/18
//*****************************************************************************
#include "gtest/gtest.h"
#include "Othello.h"

using namespace main_savitch_14;
//Test Case 1: Tie game
//------------------------------------------------------------------------------
TEST (othello_test, tie){
    Othello game;
    
    //First Four Moves
    //*******************
    game.make_move("D5");
    game.make_move("D4");
    game.make_move("E4");
    game.make_move("E5");
    //*******************
    
    game.display_status();
    bool passed = false;
    if(game.evaluate() == 0) passed = true;
    EXPECT_EQ(true, passed);
}
//------------------------------------------------------------------------------




//Test Case 2: Black is winning
//------------------------------------------------------------------------------
TEST (othello_test, black_winning){
    Othello game;
    
    //First Four Moves
    //*******************
    game.make_move("D5");
    game.make_move("D4");
    game.make_move("E4");
    game.make_move("E5");
    //*******************
    
    //Making Black Pieces out number white pieces
    //*******************
    game.make_move("C4");
    game.make_move("C3");
    game.make_move("E6");
    game.make_move("C5");
    game.make_move("B4");
    game.make_move("A3");
    //*******************
    
    game.display_status();
    bool passed = false;
    if(game.evaluate() < 0) passed = true;
    EXPECT_EQ(true, passed);
}
//------------------------------------------------------------------------------



//Test Case 3: White is winning
//------------------------------------------------------------------------------
TEST (othello_test, white_winning){
    Othello game;
    
    //First Four Moves
    //*******************
    game.make_move("D5");
    game.make_move("D4");
    game.make_move("E4");
    game.make_move("E5");
    //*******************
    
    //Making white pieces out number black pieces
    //*******************
    game.make_move("C4");
    game.make_move("C3");
    game.make_move("F4");
    game.make_move("G4");
    game.make_move("D6");
    //*******************
    
    game.display_status();
    bool passed = false;
    if(game.evaluate() > 0) passed = true;
    EXPECT_EQ(true, passed);
}
//------------------------------------------------------------------------------



//Test Case 4: Testing legal moves @ the begining
//------------------------------------------------------------------------------
TEST (othello_test, tie_legal){
    Othello game;
    
    //First Four Moves
    //*******************
    game.make_move("D5");
    game.make_move("D4");
    game.make_move("E4");
    game.make_move("E5");
    //*******************
    
    game.display_status();
    
    //Runs a nested for loop to check every board space
    //and make sure a legal moves are legal and the
    //illegal moves are illegal
    string numbers = "12345678";
    string letters = "ABCDEFGH";
    string move = "  ";
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            move[0] = letters[i];
            move[1] = numbers[j];
            
            //Legal Moves
            //**************************************
            if(move == "D3")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "C4")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "F5")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "E6")
                EXPECT_EQ(true, game.is_legal(move));
            //**************************************
            else
                EXPECT_EQ(false, game.is_legal(move));
        }
    }

}
//------------------------------------------------------------------------------



//Test Case 5: Testing legal moves @ a radom state where black is winning
//------------------------------------------------------------------------------
TEST (othello_test, black_legal){
    Othello game;
    
    //First Four Moves
    //*******************
    game.make_move("D5");
    game.make_move("D4");
    game.make_move("E4");
    game.make_move("E5");
    //*******************
    
    //Making Black Pieces out number white pieces
    //*******************
    game.make_move("C4");
    game.make_move("C3");
    game.make_move("E6");
    game.make_move("C5");
    game.make_move("B4");
    game.make_move("A3");
    //*******************
    
    game.display_status();
    
    //Runs a nested for loop to check every board space
    //and make sure a legal moves are legal and the
    //illegal moves are illegal
    string numbers = "12345678";
    string letters = "ABCDEFGH";
    string move = "  ";
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            move[0] = letters[i];
            move[1] = numbers[j];
            
            //Legal Moves
            //**************************************
            if(move == "A4")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "B2")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "B5")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "B6")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "C2")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "C6")
                EXPECT_EQ(true, game.is_legal(move));
            //**************************************
            else
                EXPECT_EQ(false, game.is_legal(move));
        }
    }
    
}
//------------------------------------------------------------------------------



//Test Case 6: Testing legal moves @ a radom state where white is winning
//------------------------------------------------------------------------------
TEST (othello_test, white_legal){
    Othello game;
    
    //First Four Moves
    //*******************
    game.make_move("D5");
    game.make_move("D4");
    game.make_move("E4");
    game.make_move("E5");
    //*******************
    
    //Making white pieces out number black pieces
    //*******************
    game.make_move("C4");
    game.make_move("C3");
    game.make_move("D3");
    game.make_move("E3");
    //*******************
    
    game.display_status();
    
    //Runs a nested for loop to check every board space
    //and make sure a legal moves are legal and the
    //illegal moves are illegal
    string numbers = "12345678";
    string letters = "ABCDEFGH";
    string move = "  ";
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            move[0] = letters[i];
            move[1] = numbers[j];
            
            //Legal Moves
            //**************************************
            if(move == "B2")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "C2")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "D2")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "E2")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "F2")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "F3")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "F4")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "F5")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "F6")
                EXPECT_EQ(true, game.is_legal(move));
            //**************************************
            else
                EXPECT_EQ(false, game.is_legal(move));
        }
    }
    
}
//------------------------------------------------------------------------------



//Test Case 7: white's turn
//------------------------------------------------------------------------------
TEST (othello_test, white_turn){
    Othello game;
    
    //First Four Moves
    //*******************
    game.make_move("D5");
    game.make_move("D4");
    game.make_move("E4");
    game.make_move("E5");
    //*******************
    
    //Making white pieces out number black pieces
    //*******************
    game.make_move("C4");
    game.make_move("C3");
    game.make_move("D3");
    game.make_move("E3");
    game.make_move("F2");
    //*******************
    
    game.display_status();
    
    //Runs a nested for loop to check every board space
    //and make sure a legal moves are legal and the
    //illegal moves are illegal
    string numbers = "12345678";
    string letters = "ABCDEFGH";
    string move = "  ";
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            move[0] = letters[i];
            move[1] = numbers[j];
            //Legal Moves
            //**************************************
            if(move == "B4")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "B5")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "C5")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "C6")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "D6")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "E2")
                EXPECT_EQ(true, game.is_legal(move));
            else if(move == "F3")
                EXPECT_EQ(true, game.is_legal(move));
            //**************************************
            else
                EXPECT_EQ(false, game.is_legal(move));
        }
    }
    
}
//------------------------------------------------------------------------------


    
int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
