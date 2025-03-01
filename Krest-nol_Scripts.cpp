#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::endl;
using std::cout;
using std::cin;

int pobeda(char** field, int field_size);
void show_field(char** field, int field_size);
void playing_with_computer(char** field, int field_size);
void playing_with_second_player(char**field, int field_size);
void computer_logic(char** field, int field_size);

void show_field(char** field, int field_size){

    for(int i = 0; i < field_size+1; i++){
        for(int j = 1; j < field_size+2; j++){
            if(i == 0 && j != 0){
                if(j != field_size + 1)
                    cout <<'\t' <<  j;
            }
            else if(j == 1 && j != field_size + 1)
                cout << ' ' << i << '\t';
            else
                cout << field[i-1][j-2] << '\t';
        }
        cout << endl;
    }

    cout << endl;
}

int pobeda(char** field, int field_size){
    int count_zakr = 0;

    for(int i = 0; i < field_size; i++){
        int count_nol = 0, count_iks = 0;
        for(int j = 0; j < field_size; j++){
            if(field[i][j] == 'x'){
                count_zakr++;
                count_iks++;
            }
            if(field[i][j] == 'o'){
                count_nol++;
                count_zakr++;
            }
        }
        
        if(count_iks == field_size) return 1;
        if(count_nol == field_size) return 2;
    }
    
    for(int i = 0; i < field_size; i++){
        int count_nol = 0, count_iks = 0;
        for(int j = 0; j < field_size; j++){
            if(field[j][i] == 'x') count_iks++;
            if(field[j][i] == 'o') count_nol++;
        }
        if(count_iks == field_size) return 1;
        if(count_nol == field_size) return 2;
    }

    int count_nol = 0, count_iks = 0;
    for(int i = 0; i < field_size; i++){
        if(field[i][i] == 'x') count_iks++;
        if(field[i][i] == 'o') count_nol++;
    }

    if(count_iks == field_size) return 1;
    if(count_nol == field_size) return 2;


    count_nol = 0;
    count_iks = 0;

    for(int i = 0; i < field_size; i++){
        if(field[i][field_size - i - 1] == 'x') count_iks++;
        if(field[i][field_size - i - 1] == 'o') count_nol++;
    }

    if(count_iks == field_size) return 1;
    if(count_nol == field_size) return 2;

    if(count_zakr == (field_size*field_size))
        return 3;

    return 0;
}

void computer_logic(char** field, int field_size){
    srand(time(NULL));

    for(int i = 0; i < field_size; i++){
        int count_nol = 0, count_iks = 0;
        for(int j = 0; j < field_size; j++){
            if(field[i][j] == 'o')
                count_nol++;
        }

        if(count_nol == field_size - 1){
            for(int j = 0; j < field_size; j++){
                if(field[i][j] == '*'){
                    field[i][j] = 'o';
                    return;
                }
            }
        }
    }

    for(int i = 0; i < field_size; i++){
        int count_nol = 0, count_iks = 0;
        for(int j = 0; j < field_size; j++){
            if(field[j][i] == 'o')
                count_nol++;
        }

        if(count_nol == field_size - 1){
            for(int j = 0; j < field_size; j++){
                if(field[j][i] == '*'){
                    field[j][i] = 'o';
                    return;
                }
            }
        }
    }

    int count_nol = 0;

    for(int i = 0; i < field_size; i++){
        if(field[i][i] == 'o')
            count_nol++;
    }

    if(count_nol == field_size - 1){
        for(int i = 0; i < field_size; i++){
            if(field[i][i] == '*'){
                field[i][i] = 'o';
                return;
            }
        }
    }

    count_nol = 0;

    for(int i = 0; i < field_size; i++){
        if(field[i][field_size-i-1] == 'o')
            count_nol++;
    }

    if(count_nol == field_size - 1){
        for(int i = 0; i < field_size; i++){
            if(field[i][field_size-i-1] == '*'){
                field[i][field_size-i-1] = 'o';
                return;
            }
        }
    }

    
    for(int i = 0; i < field_size; i++){
        int count_iks = 0;
        for(int j = 0; j < field_size; j++){
            if(field[i][j] == 'x')
                count_iks++;
        }
        if(count_iks == field_size - 1){
            for(int j = 0; j < field_size; j++){
                if(field[i][j] == '*'){
                    field[i][j] = 'o';
                    return;
                }
            }
        }
    }

    for(int i = 0; i < field_size; i++){
        int count_iks = 0;
        for(int j = 0; j < field_size; j++){

            if(field[j][i] == 'x')
                count_iks++;
        }

        if(count_iks == field_size - 1){
            for(int j = 0; j < field_size; j++){
                if(field[j][i] == '*'){
                    field[j][i] = 'o';
                    return;
                }
            }
        }
    }

    int count_iks = 0;

    for(int i = 0; i < field_size; i++){
        if(field[i][i] == 'x')
            count_iks++;
    }

    if(count_iks == field_size - 1){
        for(int i = 0; i < field_size; i++){
            if(field[i][i] == '*'){
                field[i][i] = 'o';
                return;
            }
        }
    }

    count_iks = 0;

    for(int i = 0; i < field_size; i++){

        if(field[i][field_size-i-1] == 'x')
            count_iks++;
    }

    if(count_iks == field_size - 1){
        for(int i = 0; i < field_size; i++){
            if(field[i][field_size-i-1] == '*'){
                field[i][field_size-i-1] = 'o';
                return;
            }
        }
    }

    if(field[field_size/2][field_size/2] == '*'){
        field[field_size/2][field_size/2] = 'o';
        return;
    }

    if(field[0][0] == '*' || field[0][field_size-1] == '*' || field[field_size-1][0] == '*' || field[field_size-1][field_size-1] == '*'){
        while(true){
            int sl = rand() % 5;

            if(sl == 1)
                if(field[0][0] == '*') {field[0][0] = 'o'; return;}
            else if(sl == 2)
                if(field[0][field_size-1] == '*') {field[0][field_size-1] = 'o'; return;}
            else if(sl == 3)
                if(field[field_size-1][0] == '*') {field[field_size-1][0] = 'o'; return;}
            else
                if(field[field_size-1][field_size-1] == '*') {field[field_size-1][field_size-1] = 'o'; return;}
        }
    }

    while(true){
        if(field[rand() % field_size][rand() % field_size] != '*'){
            field[rand() % field_size][rand() % field_size] = 'o';
            return;
        }
    }
}


void playing_with_computer(char** field, int field_size){
    srand(time(NULL));

    char flag = '1';
    show_field(field, field_size);

    while(true){
        if(pobeda(field, field_size) == 1 || pobeda(field, field_size) == 2 || pobeda(field, field_size) == 3)
            break;
        int x, y;

        if(flag == '1'){
            cout << "Time to walk crosses to the first player(must enter coordinates): ";
            cin >> x >> y;
            if(x < 1 || y < 1 || x > field_size || y > field_size || field[x-1][y-1] == 'x' || field[x-1][y-1] == 'o'){
                cout << "Incorrect coordinates" << endl;
                show_field(field, field_size);
            }
            else{
                field[x-1][y-1] = 'x';
                show_field(field, field_size);
                flag = '0';
            }
        }
        else{
            computer_logic(field, field_size);

            show_field(field, field_size);

            flag = '1';
        }
    }



    if(pobeda(field, field_size) == 1){
        show_field(field, field_size);
        cout << "First player is win!";
    }

    else if(pobeda(field, field_size) == 2){
        show_field(field, field_size);
        cout << "Computer is win!";
    }
    else
        cout << "Draw!";
}

void playing_with_second_player(char** field, int field_size){
    char flag;

    while(true){
        cout << "Who goes first? First(1) or second player(2)?" << endl;
        cin >> flag;
        if(flag == '1' || flag == '2')
            break;
    }

    show_field(field, field_size);

    while(true){
        if(pobeda(field, field_size) == 1 || pobeda(field, field_size) == 2 || pobeda(field, field_size) == 3)
            break;
        int x, y;

        if(flag == '1'){
            cout << "Time to walk crosses to the first player(must enter coordinates): ";
            cin >> x >> y;
            if(x < 1 || y < 1 || x > field_size || y > field_size || field[x-1][y-1] == 'x' || field[x-1][y-1] == 'o'){
                cout << "Incorrect coordinates" << endl;
                show_field(field, field_size);
            }
            else{
                field[x-1][y-1] = 'x';
                show_field(field, field_size);
                flag = '0';
            }
        }
        else{
            cout << "Time to walk crosses to the second player(must enter coordinates): ";
            cin >> x >> y;

            if(x < 1 || y < 1 || x > field_size || y > field_size || field[x-1][y-1] == 'x' || field[x-1][y-1] == 'o'){
                cout << "Incorrect coordinates" << endl;
                show_field(field, field_size);
            }
            else{
                field[x-1][y-1] = 'o';
                show_field(field, field_size);
                flag = '1';
            }
        }
    }



    if(pobeda(field, field_size) == 1){
        cout << "First player is win!";
    }

    else if(pobeda(field, field_size)==2){
        cout << "Second player is win!";
    }
    else
        cout << "Draw!";
}