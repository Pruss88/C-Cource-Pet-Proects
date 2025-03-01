#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Krest-nol_Scripts.cpp"

using std::cin;
using std::cout;
using std::endl;

int pobeda(char** field, int field_size);
void show_field(char** field, int field_size);
void playing_with_computer(char** field, int field_size);
void playing_with_second_player(char**field, int field_size);

int main(void){
    srand(time(NULL));
    cout << "Greetings to the game of Tic-tac-toe. The game is designed for two players or to play with a computer. The first player always goes crosses, and the second zeros, so if you play two players in advance decide. Have a good game!" << endl;
    int field_size;
    char choose;

    cout << endl;
    
    cout << "Playing with computer(1) or second player(2)?" << endl;
    cin >> choose;

    cout << "Field size: ";
    cin >> field_size;

    char** field = new char*[field_size];

    for (int i = 0; i < field_size; i++) {
        field[i] = new char[field_size];
    }

    for(int i = 0; i < field_size; i++){
        for(int j = 0; j < field_size; j++){
            field[i][j] = '*';
        }
    }

    if(choose == '1'){
        playing_with_computer(field, field_size);
    }
    else if(choose == '2'){
        playing_with_second_player(field, field_size);
    }
    else
        cout << "Incorrect choose";
    

    char to_exit;
    cin >> to_exit;
    return 0;
}

