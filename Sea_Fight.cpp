#include <iostream>


using std::endl;
using std::cin;
using std::cout;


void show_field(char** field);
void fill_field(char** field);

int main(void)
{
    cout << "Welcome to the game of naval combat. It is designed for two players, so call a friend and start playing! " << endl;

    char** first_player_field = new char*[10];
    char** second_player_field = new char*[10];

    char x, flag = 0;
    int y, count_first_player = 0, count_second_player = 0;

    for(int i = 0; i < 10; i++){
        first_player_field[i] = new char[10];
        second_player_field[i] = new char[10];
    }

    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++){
            first_player_field[i][j] = '*';
            second_player_field[i][j] = '*';
        }
    
    cout << "It's time for the first player to arrange the ships" << endl << endl << endl << endl;;
    fill_field(first_player_field);

    cout << "It's time for the second player to arrange the ships" << endl;
    fill_field(second_player_field);

    while(count_first_player != 20 || count_second_player != 20){
        if(flag == 0){
            cout << "Time of the first player's turn. Write the coordinates of where to strike:" << endl;
            cin >> x >> y;
            if(y >= 1 && y <= 10 && x-97 >= 0 && x-97 <= 9 && second_player_field[y-1][x-97] != '*' && second_player_field[y-1][x-97] != 'x'){
                cout << "You're screwed! Keep going" << endl;
                show_field(first_player_field);
                second_player_field[y-1][x-97] = 'x';
                count_first_player++;
            }
            else{
                cout << "You missed. Give control to another player" << endl;
                flag = 1;
            }
        }
        else if(flag == 1){
            cout << "Time of the second player's turn. Write the coordinates of where to strike:" << endl;
            cin >> x >> y;
            if(y >= 1 && y <= 10 && x-97 >= 0 && x-97 <= 9 && first_player_field[y-1][x-97] != '*' && first_player_field[y-1][x-97] != 'x'){
                cout << "You're screwed! Keep going" << endl;
                show_field(second_player_field);
                first_player_field[y-1][x-97] = 'x';
                count_second_player++;
            }
            else{
                cout << "You missed. Give control to another player" << endl;
                flag = 0;
            }
        }
    }

    if(count_first_player == 20){
        cout << "First player is a CHAMPION";
    }
    else if(count_second_player == 20){
        cout << "Second player is a CHAMPION";
    }

    char to_exit;
    cin >> to_exit;

    return 0;
}



void show_field(char** field){
    char alph[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            if(i == 0)
                cout << '\t' << ' ' << alph[j];
            else if(j == 0)
                cout << ' ' << i << "\t";
            else{
                if(field[i-1][j-1] == '*' || field[i-1][j-1] == 'x')
                    cout << '[' <<  field[i-1][j-1] << ']' << "\t";
                else
                    cout << '[' <<  (int)field[i-1][j-1] << ']' << "\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void fill_field(char** field){
    char flag1 = 0;

    while(flag1 != 4){
        char x, x1, choice;
        int y, y1;

        for(int i = 0; i < 4; ){
            show_field(field);

            cout << "Enter the coordinates of the point where to place the single-deck ship: " << endl;
            cin >> x >> y;

            if(y >= 1 && y <= 10 && x-97 >= 0 && x-97 <= 9 && field[y-1][x-97] == '*'){
                field[y-1][x-97] = 1;
                i++;
            }
            else{
                cout << "Incorrect coordinates" << endl;
            }
        }

        flag1++;
        cout << endl;

        for(int i = 0; i < 3; ){
            show_field(field);

            cout << "How will the double-deck ship be positioned? Is it vertical(1) or horizontal(2)?" << endl;
            cin >> choice;

            if(choice == '1'){
                cout << "Enter the start coordinates of the double-deck ship: " << endl;
                cin >> x >> y;

                cout << "Enter the end coordinates of the double-deck ship: " << endl;
                cin >> x1 >> y1;

                if(y1 <= 10 && y <= 10 && y>= 1 && y1 >= 1 && x==x1 && field[y-1][x-97] == '*' && field[y1-1][x1-97] == '*' && y1 == y+1){
                    field[y-1][x-97] = 2;
                    field[y1-1][x1-97] = 2;
                    i++;
                }
                else{
                    cout << "Incorrect coordinates" << endl;
                }
            }
            else if(choice == '2'){
                cout << "Enter the start coordinates of the double-deck ship: " << endl;
                cin >> x >> y;

                cout << "Enter the end coordinates of the double-deck ship: " << endl;
                cin >> x1 >> y1;

                if(x1-97 <= 9 && (x-97) <= 9 && x1-97 >= 0 && (x -97) >= 0 && y==y1 && field[y-1][x-97] == '*' && field[y1-1][x1-97] == '*' && (x1-97) == (x-97) + 1){
                    field[y-1][x-97] = 2;
                    field[y1-1][x1-97] = 2;
                    i++;
                }
                else
                    cout << "Incorrect coordinates" << endl;
            }

            else
                cout << "Incorrect choose" << endl;
        }
    flag1++;

    for(int i = 0; i < 2; ){
        show_field(field);

        cout << "How will the triple-deck ship be positioned? Is it vertical(1) or horizontal(2)?" << endl;
        cin >> choice;

        if(choice == '1'){
            cout << "Enter the start coordinates of the triple-deck ship: " << endl;
            cin >> x >> y;

            cout << "Enter the end coordinates of the triple-deck ship: " << endl;
            cin >> x1 >> y1;

            if(y1 <= 10 && y <= 10 && y>= 1 && y1 >= 1 && x==x1 && field[y-1][x-97] == '*' && field[y1-1][x1-97] == '*'){
                if(y1 == y-2){
                    field[y-1][x-97] = 3;
                    field[y-2][x-97] = 3;
                    field[y1-1][x1-97] = 3;
                    i++;
                }
                else if(y1 == y + 2){
                    field[y-1][x-97] = 3;
                    field[y1-2][x-97] = 3;
                    field[y1-1][x1-97] = 3;
                    i++;
                }
                else
                    cout << "Incorrect coordinates" << endl;
            }
            else{
                cout << "Incorrect coordinates" << endl;
            }
        }
        else if(choice == '2'){
            cout << "Enter the start coordinates of the triple-deck ship: " << endl;
            cin >> x >> y;

            cout << "Enter the end coordinates of the triple-deck ship: " << endl;
            cin >> x1 >> y1;

            if(x1-97 <= 9 && (x-97) <= 9 && x1-97 >= 0 && (x -97) >= 0 && y==y1 && field[y-1][x-97] == '*' && field[y1-1][x1-97] == '*'){
                if((x1-97) == (x-95)){
                    field[y-1][x-97] = 3;
                    field[y-1][x-96] = 3;
                    field[y1-1][x1-97] = 3;
                    i++;
                }
                else if((x-97) == (x-99)){
                    field[y-1][x-97] = 3;
                    field[y-1][x-98] = 3;
                    field[y1-1][x1-97] = 3;
                    i++;
                }
                else
                    cout << "Incorrect coordinates" << endl;
            }
            else
                cout << "Incorrect coordinates" << endl;
        }

        else
            cout << "Incorrect choose" << endl;
    }

    flag1++;
    

    for(int i = 0; i < 1; ){
        show_field(field);

        cout << "How will the quadruple-deck ship be positioned? Is it vertical(1) or horizontal(2)?" << endl;
        cin >> choice;

        if(choice == '1'){
            cout << "Enter the start coordinates of the quadruple-deck ship: " << endl;
            cin >> x >> y;

            cout << "Enter the end coordinates of the quadruple-deck ship: " << endl;
            cin >> x1 >> y1;

            if(y1 <= 10 && y <= 10 && y>= 1 && y1 >= 1 && x==x1 && field[y-1][x-97] == '*' && field[y1-1][x1-97] == '*'){
                if(y1 == y-3){
                    field[y-1][x-97] = 4;
                    field[y-2][x-97] = 4;
                    field[y-3][x-97] = 4;
                    field[y1-1][x1-97] = 4;
                    i++;
                }
                else if(y1 == y + 3){
                    field[y-1][x-97] = 4;
                    field[y][x-97] = 4;
                    field[y+1][x-97] = 4;
                    field[y1-1][x1-97] = 4;
                    i++;
                }
                else
                    cout << "Incorrect coordinates" << endl;
            }
            else{
                cout << "Incorrect coordinates" << endl;
            }
        }
        else if(choice == '2'){
            cout << "Enter the start coordinates of the quadruple-deck ship: " << endl;
            cin >> x >> y;

            cout << "Enter the end coordinates of the quadruple-deck ship: " << endl;
            cin >> x1 >> y1;

            if(x1-97 <= 9 && (x-97) <= 9 && x1-97 >= 0 && (x -97) >= 0 && y==y1 && field[y-1][x-97] == '*' && field[y1-1][x1-97] == '*'){
                if((x1-97) == (x-94)){
                    field[y-1][x-97] = 4;
                    field[y-1][x-96] = 4;
                    field[y-1][x-95] = 4;
                    field[y1-1][x1-97] = 4;
                    i++;
                }
                else if((x-97) == (x-100)){
                    field[y-1][x-97] = 3;
                    field[y-1][x-99] = 3;
                    field[y-1][x-99] = 3;
                    field[y1-1][x1-97] = 3;
                    i++;
                }
                else
                    cout << "Incorrect coordinates" << endl;
            }
            else
                cout << "Incorrect coordinates" << endl;
        }
        else
            cout << "Incorrect choose" << endl;
    }
    flag1++;

    }

}