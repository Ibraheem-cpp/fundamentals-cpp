#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;

const int R = 9;
const int C = 13;

void position(char**& board,int pos[]);
void game_start();
char** create_board();
void initialize_board(char**& board , ifstream& file1);
void display_board(char**& board , int l);
void free_memory(char**& board);
bool isValidMove(char move);
bool player_move(int pos[] , char**& board , int& l);
bool move_upward(int pos[] , char**& board , int& l);
bool move_downward(int pos[] , char**& board , int& l);
bool move_left(int pos[] , char**& board , int& l);
bool move_right(int pos[] , char**& board , int& l);
void spawn_food(char**& board);
void game_end(bool flag , int score);

int main(){
    char choice = 'y';
    while(choice == 'y' || choice == 'Y'){
    srand(time(0));
    int score = 0;
    int head[2];
    bool flag = true;
    char move;
    game_start();
    ifstream file;
    char** board = create_board();
    initialize_board(board,file);
    position(board,head);
    do{

    display_board(board,score);
    flag = player_move(head,board,score);

    if(score==20){
        display_board(board,score);
        break;}

    }while(flag != false || score == 20);
   
    game_end(flag,score);

    free_memory(board);
    
    cout << endl << "Do You Want To Play Again ? (y/n) : ";
    cin >> choice;
}

    return 0;
}
void game_start(){
     cout << endl << "===============| WELCOME TO SNAKE GAME |===============" << endl << endl;
     cout << "    | RULES AND CONTROLS |" << endl << endl;
     cout << "1.You Play as The Snake, denoted by 'S' on the Gameboard." << endl;
     cout << "2.Everytime you eat Food (denoted by 'f' on the Gameboard) Your Score increases by 1." << endl;
     cout << "3.If You Hit The Wall By Any Side, You Die and The Game is Over." << endl;
     cout << "4.If you eat Food, Your Segemnt Will be left behind (denoted by 's')." << endl;
     cout << "5.If You Hit Your Segment Again, You Lose." << endl;
     cout << "6.If Your Score reaches 20, YOU WIN !!!." << endl;
     cout << "Press 'W' To Move Up." << endl;
     cout << "Press 'S' To Move Down." << endl;
     cout << "Press 'A' To Move Left." << endl;
     cout << "Press 'D' To Move Right." << endl;
}
void position(char**& board,int pos[]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(board[i][j] == 'S'){
                pos[0] = i;
                pos[1] = j;
            }
        }
    }
}
char** create_board(){
    char** board = new char*[R];
    for(int i=0;i<R;i++){
        board[i] = new char[C];
    }
    return board;
}
void initialize_board(char**& board , ifstream& file1){
    file1.open("snake.txt");
     if (!file1.is_open()) {
    cout << "File failed to open!" << endl;
    exit(1); // or handle error properly
   }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            file1 >> board[i][j];
        }
    }
    file1.close();
}

void display_board(char**& board , int l){
    cout << endl << "          GAMEBOARD" << endl;
    cout << " Score : " << l << endl;
    for(int i=0;i<R;i++){
        cout << "        ";
        for(int j=0;j<C;j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}
void free_memory(char**& board){
     for(int i=0;i<R;i++){
        delete[] board[i];
    }
    delete[] board;
}
bool player_move(int pos[] , char**& board , int& l){
    char move;
    do{
    cout << endl << "Enter Your Move : ";
    cin >> move;
    if(move == 'w' || move == 'W'){
        if(move_upward(pos,board,l) == false){return false;}
        else return true;
    }
    else if(move == 's' || move == 'S'){
        if(move_downward(pos,board,l) == false){return false;}
        else return true;
    }
    else if(move == 'a' || move == 'A'){
        if(move_left(pos,board,l) == false){return false;}
        else return true;
    }
    else if(move == 'd' || move == 'D'){
        if(move_right(pos,board,l) == false){return false;}
        else return true;
    }
    else{
        cout << "Invalid Move !!! . Enter Again."; 
    }
    }while(!isValidMove(move));
}
bool isValidMove(char move){
    if(move == 'w' || move == 'W' || move == 's' || move == 'S' || move == 'a' || move == 'A' || move == 'd' || move == 'D'){return true;}
    else return false;
}
bool move_upward(int pos[] , char**& board , int& l){
    int x = pos[0] , y = pos[1];
    if(board[x-1][y] == '_' || board[x-1][y] == 's'){return false;}

    else if(board[x-1][y] == 'f'){
        l++;
        board[x-1][y] = 's';
        spawn_food(board);
        return true;
    }

    else if(board[x-1][y] == '-'){
        board[x-1][y] = 'S';
        board[x][y] = '-';
        pos[0] = x-1;
        return true;
    }
}
bool move_downward(int pos[] , char**& board , int& l){
     int x = pos[0] , y = pos[1];
    if(board[x+1][y] == '_' || board[x+1][y] == 's'){return false;}

    else if(board[x+1][y] == 'f'){
        board[x+1][y] = 's';
        l++;
        spawn_food(board);
        return true;
    }

    else{
        board[x+1][y] = 'S';
        board[x][y] = '-';
        pos[0] = x+1;
        return true;
    }
}
bool move_left(int pos[] , char**& board , int& l){
      int x = pos[0] , y = pos[1];
    if(board[x][y-1] == '|' || board[x][y-1] == 's'){return false;}

    else if(board[x][y-1] == 'f'){
        board[x][y-1] = 's';
        l++;
        spawn_food(board);
        return true;
    }

    else{
        board[x][y-1] = 'S';
        board[x][y] = '-';
        pos[1] = y-1;
        return true;
    }
}
bool move_right(int pos[] , char**& board , int& l){
      int x = pos[0] , y = pos[1];
    if(board[x][y+1] == '|' || board[x][y+1] == 's'){return false;}

    else if(board[x][y+1] == 'f'){
        board[x][y+1] = 's';
        l++;
        spawn_food(board);
        return true;
    }

    else{
        board[x][y+1] = 'S';
        board[x][y] = '-';
        pos[1] = y+1;
        return true;
    }
}
void game_end(bool flag , int score){
     if(flag == false){
        cout << endl << "          GAME OVER !!!" << endl;
        cout << "Your Score : " << score << endl;
    }
    
    if(score == 20){
        cout << endl;
        cout << "SCORE : " << score << endl << endl;
        cout << "         CONGRATULATIONS !!!! . You Win !! " << endl << endl;
    }
}
void spawn_food(char**& board){
    int x,y;
    //srand(time(0));
    do{
        x = (rand() % 7) + 1;
        y = (rand() % 11) +1;

    }while(board[x][y] != '-');
    board[x][y] = 'f';
}

