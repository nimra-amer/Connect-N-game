#include <iostream>
#include <fstream>
#include<string>

using namespace std;

const int MaxRows = 14;
const int MaxCols = 14;

struct Player{
    string Name;
    char Mark;

    Player(char mark = 'o', string PlayerName  = "Player Name"){
        Mark = mark;
        Name = PlayerName;
    }

    void setPlayerName(string PlayerName){
        Name = PlayerName;
        return;
    }

    void setPlayerMark(char PlayerMark){
        Mark = PlayerMark;
        return;
    }
};

struct GameBoard{
    char Board[MaxRows][MaxCols];
    GameBoard( char FillChar = '.'){
        for(int r = 0; r < MaxRows; r++)
            for(int c = 0; c < MaxCols; c++)
                Board[r][c] = FillChar;
        return;
    }
};

struct Connect_N{

    GameBoard Board; // Game board to hold move data
    int Rows, Columns; // Game board size
    int ConnectLimit;// How many Marks to connect to win

    Player Players[2];// list of players
    int TurningPlayer; // index of turning player

    int GameEndState;
    // GameEndState 0 means game is not over
    // GameEndState 1 means first player has won it
    // GameEndState 2 means second player has won it

    int Moves_Made[MaxCols];
    // An array to hold the count of moves made in each
    // column. It will help us determine the row for
    // each move in an efficient way.

    Connect_N(int R = 6, int C = 7, int Limit = 4){
        if(R < 0 || R > MaxRows)
            R = 6;

        if(C < 0 || C > MaxCols)
            C = 7;

        if(Limit < 0)
            Limit = 4;

        Rows = R;
        Columns = C;
        ConnectLimit = Limit;
        TurningPlayer = 0;
        GameEndState = 0;

        for(int i = 0; i < MaxCols; i++)
            Moves_Made[i] = 0;
    }
     int Game_End_Conditions( int GameEndState)
    {
        if(GameEndState == 0)
        {
            return GameisOn();
        }
        else if(GameEndState == 1)
        {
            cout << "The first player won";
        }
        else if( GameEndState == 2 )
        {
            cout << "The second player won";
        }
        else
        {
          cout << "The game is drawn between the two players";
        }
    }
    bool MakeMove(int Col){
        /**
            This function must validate the move and if
            possible make that move and update the entire
            state like board, turning player, GameEndState
            etc.

            It will return false if the move is not
            possible for some reason and true if
            move is valid and done successfully.

            An incomplete definition of this function is given
            below. You must update and complete it in all
            respects.
        */

        // Your updated code goes here

        int R = Moves_Made[Col];
        Board.Board[Rows-1-R][Col] = Players[TurningPlayer].Mark;
        TurningPlayer = (TurningPlayer + 1 ) %2;
        Moves_Made[Col]++;
        int j;
        // Code to check the validity of movement performed by the players
        // set for n x m arrays where n and m are same
        for( j = 0 ; j < Columns ; j++)
        {
            if(j == 0)
            {
              if(Moves_Made[j] == ConnectLimit-Col)
                {
                   cout << "No more moves can be made in the respective column"<<endl;
                }
                if(Moves_Made[j+1] == ConnectLimit - Col + 2)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }
             if(Moves_Made[j+2] == ConnectLimit - Col + 3)
             {
                 cout << "No more moves can be made in the respective column"<<endl;
             }
             if(Moves_Made[j+3] == ConnectLimit - Col + 4)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }
              if(Moves_Made[j+4] == ConnectLimit - Col + 5)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }
              if(Moves_Made[j+5] == ConnectLimit - Col + 6)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }
              if(Moves_Made[j+6] == ConnectLimit - Col + 7)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }
              if(Moves_Made[j+7] == ConnectLimit - Col + 8)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }
              if(Moves_Made[j+8] == ConnectLimit - Col + 9)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }
              if(Moves_Made[j+9] == ConnectLimit - Col + 10)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }
              if(Moves_Made[j+10] == ConnectLimit - Col + 11)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }
              if(Moves_Made[j+11] == ConnectLimit - Col + 12)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }
              if(Moves_Made[j+12] == ConnectLimit - Col + 13)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }
              if(Moves_Made[j+13] == ConnectLimit - Col + 14)
              {
                cout << "No more moves can be made in the respective column"<<endl;;
              }

        }
        }
   // Program To Identify which player wins.
       /*int L = Players[0].Mark;
        int k=1;
        while(k <= ConnectLimit){
        for(int i = Rows ; i >= 0 ; i-- )
            for(int j = Columns ; j >= 0 ; j--)
        {
            if(Board.Board[i][j] == L || Board.Board[i-k][j+k] == L || Board.Board[i][j-k] == L || Board.Board[i][j-k] == L || Board.Board[i][j+k] == L ||Board.Board[i+1][j+1])
              GameEndState = 1;
              else
                GameEndState = 2;
        }
          k ++ ;

        }
        Game_End_Conditions(GameEndState);
*/

        return true;

    }

    bool GameisOn(){
        return GameEndState == 0;
    }

    bool SavedGame(string FileName){
        /**
            This function must save the entire game data
            into a file and return true.

            It will return false if the file can not be
            created or data can not be written for some
            reason
        */
        //Your Code Goes Here
        ofstream output;
        ifstream input;
        input.open(FileName.c_str());
        output.open(FileName.c_str());
        int i , j;
        if(!output || !input)
        {
            return false;
        }
        else
        {
        for( i = 0 ; i < Rows ; i++)
        {
            for( j = 0 ; j < Columns ; j++)
            {
              output << Board.Board[i][j];
            }
        }
         return true;
        output.close();
        input.close();

        }
    }

    bool LoadSavedGame(string FileName){
        /**
            This function must load a saved game
            from a file into memory and must allow users
            to continue playing it.

            It will return false if the file can not be
            opened or data can not be loaded from the file
        */
        ofstream output;
        ifstream input;
        input.open(FileName.c_str());
        output.open(FileName.c_str());
        if(!input)
        {
            return false;
        }
        else
        {
            for(int i = 0 ; i < Rows ; i++)
                for(int j = 0 ; j < Columns ; j++)
            {
                input >> Board.Board[i][j];
            }

        return true;
    }

    }

    void ShowGame(){
        /**
         This function must show the game on screen and
         if the game is not over take the next move from
         the next player and return that move.

         A very simple implementation is already provided
         to get you started but you better replace it with
         your code to produce a pleasing output
         */

         // Your better replace the following code

        for(int r = 0; r < Rows; r++){
            for(int c = 0; c < Columns; c++)
                cout<< Board.Board[r][c]<<"\t";
            cout<<endl<<endl;
        }
        if(GameisOn())
            cout<<endl<<Players[TurningPlayer].Name
                <<"("
                <<Players[TurningPlayer].Mark<<")"
                <<"Moving "<<endl;
    }

    void Play(){
        int Move;
        do{
            ShowGame();
            cout<<"ENTER NEGATIVE NUMBER FOR THE MAIN MENU"<<endl;
            cout<<"Please Enter Your Move ? (0 - "<<Columns<<") ";
            cin >> Move;
            if(Move < 0)
                break;
            MakeMove(Move);
        }while(GameisOn());
    }
};

int Menu(){
    int Choice;
    do{
        cout<<"1. Play"<<endl
            <<"2. Save Game"<<endl
            <<"3. Load Game"<<endl
            <<"4. Exit"<<endl
            <<"Enter You Choice (1 - 4)";
            cin>> Choice;
    }while(Choice < 1 || Choice > 4);
    return Choice;
}

void initNewGame(Connect_N& C){
    int Rows, Cols, Limit;
    cout<<"How Many Rows ?";
    cin>> Rows;
    cout<<"How Many Cols ?";
    cin>> Cols;
    cout<<"Connectivity Limit ?";
    cin>> Limit;
    C.Rows = Rows;
    C.Columns = Cols;
    C.ConnectLimit = Limit;
    cout<<"First Player Name? ";
    string N;
    cin>> N;
    C.Players[0].setPlayerName(N);
    cout<<"Second Player Name? ";
    cin>> N;
    C.Players[1].setPlayerMark('x');
    C.Players[1].setPlayerName(N);
}

int main()
{
     string FileName;
    int Choice ;
    bool GameNotLoaded = true;
    Connect_N Connect_Game(MaxRows,MaxCols,MaxRows);
    do{
        Choice = Menu();
        switch(Choice)
        {
        case 1:
            if(GameNotLoaded){
                initNewGame(Connect_Game);
                GameNotLoaded = false;
            }
            Connect_Game.Play();
            break;

            case 2:
            cout<<"enter the file name in which you want the game to be stored ( with txt extension)";
            cin >> FileName;
           Connect_Game.SavedGame(FileName);
           if(Connect_Game.SavedGame(FileName) == 1)
               {
                   cout<<"the game is saved successfully"<<endl;
               }
            else if(Connect_Game.SavedGame(FileName) == 0)
                {
                    cout << "the file required do not exist"<<endl;
                }
            break;

        case 3:
             cout << "enter the file name from which you want to resume the game: "<<endl;
             cin >> FileName;
             Connect_Game.LoadSavedGame(FileName);
             if(Connect_Game.LoadSavedGame(FileName) == 1 )
             {
                 cout<<"the game is loaded successfully"<<endl;
             }
             else if(Connect_Game.LoadSavedGame(FileName) == 0)
             {
                 cout<<"There was an error in loading your saved game" << endl << "The file may not exist" << endl<< "Please try again later";
             }
            break;
        }

    }while(Choice != 4);
    cout << "Thanks For Playing !!!!";
    return 0;
}
