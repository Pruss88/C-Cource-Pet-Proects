#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

void show_pole(char** pole, int max_field_size){

    for(int i = 0; i < max_field_size+1; i++){

        for(int j = 0; j < max_field_size; j++){
            if(i == 0 && j == 0){
                std::cout << '\t' << ' ' << j+1 << '\t';
            }
            else if(i == 0){
                std::cout << ' ' << j+1 << '\t';
            }

            else{
                if(j == 0)
                    std::cout << i << '\t';
                if(pole[i-1][j] == '*')
                    std::cout << '[' << pole[i-1][j] << ']' << '\t';
                else if(pole[i-1][j] == 'f')
                    std::cout << '[' << pole[i-1][j] << ']' << '\t';
                else
                    std::cout << '[' << (int)pole[i-1][j] << ']' << '\t';
            }
        }
        std::cout << std::endl;
    }

    std::cout<< std::endl;

}

void show_pole(int** pole, int max_field_size){

    for(int i = 0; i < max_field_size; i++){
        for(int j = 0; j < max_field_size; j++){
            if(pole[i][j] == '*')
                std::cout << '[' << pole[i][j] << ']' << ' ';
            else
                std::cout << '[' << (int)pole[i][j] << ']' << ' ';
        }
        std::cout << std::endl;
    }

    std::cout<< std::endl;

}

void otkrit_noli(char** pole2, int** pole1, int i, int j, int* count_otkr){
    if(pole1[i][j] != 0 || pole2[i][j] != '*')
        return;

    pole2[i][j] = pole1[i][j];

    *count_otkr+=1;

    if(i-1 >= 0 && pole1[i-1][j] == 0)
        otkrit_noli(pole2, pole1, i-1, j, count_otkr);
    else if(i-1 >= 0 && pole1[i-1][j] != -1)
        {pole2[i-1][j] = pole1[i-1][j]; *count_otkr += 1;}

    if(i+1 < 10 && pole1[i+1][j] == 0)
        otkrit_noli(pole2, pole1, i+1, j, count_otkr);
    else if(i + 1 < 10 && pole1[i+1][j] != -1)
        {pole2[i+1][j] = pole1[i+1][j]; *count_otkr += 1;}

    if(j-1 >= 0 && pole1[i][j-1] == 0)
        otkrit_noli(pole2, pole1, i, j-1, count_otkr);
    else if(j-1 >= 0 && pole1[i][j-1] != -1)
        {pole2[i][j-1] = pole1[i][j-1]; *count_otkr += 1;}

    if(j+1 < 10 && pole1[i][j+1] == 0)
        otkrit_noli(pole2, pole1, i, j+1, count_otkr);
    else if(j+1<10 && pole1[i][j+1] != -1)
        {pole2[i][j+1] = pole1[i][j+1];  *count_otkr+=1;}
}

int main()
{   
    srand(time(NULL));

    std::cout << "Hello, this is Saper game!" << std::endl;

    int field_size, mins_count;

    std::cout << "Field size: ";
    std::cin >> field_size;

    while(true){
        std::cout << "Mines count: ";
        std::cin >> mins_count;

        std:: cout << std::endl;
        if(mins_count < field_size*field_size && mins_count != 0)
            break;
        else{
            std::cout << "This number of mines is unacceptable" << std::endl;
        }
    }

    int** pole = new int*[field_size];
    char** pole2 = new char*[field_size];

    int mins_count_2 = 0;

    for (int i = 0; i < field_size; ++i) {
        pole2[i] = new char[field_size];
    }

    for (int i = 0; i < field_size; ++i) {
        pole[i] = new int[field_size];
    }

    //заполнение отображаемого поля '*'
    for(int i = 0; i < field_size; i++){
        for(int j = 0; j < field_size; j++){
            pole2[i][j] = '*';
        }
    }

    //заполнение pole нулями
    for(int i = 0; i < field_size; i++){
        for(int j = 0; j < field_size; j++){
            pole[i][j] = 0;
        }
    }

    //заполнение минами

    while(mins_count_2 < mins_count){
        int strok_zap = rand() % field_size;
        int stolb_zap = rand() % field_size;

        if(pole[strok_zap][stolb_zap] != -1){
            pole[strok_zap][stolb_zap] = -1;
            mins_count_2++;
        }
    }

    //заполнение всех клеток количеством мин вокруг них
    for(int i = 0; i < field_size; i++){
        for(int j = 0; j < field_size; j++){
            if(pole[i][j] != -1){
                int min_count_3 = 0;
                if(j+1 < field_size && pole[i][j+1] == -1){ min_count_3++;}
                if(j - 1 >= 0 && pole[i][j-1] == -1){ min_count_3++;}
                if(i-1 >= 0 && pole[i-1][j] == -1){ min_count_3++;}
                if(i+1 < field_size && pole[i+1][j] == -1){ min_count_3++;}
                if(i-1 >= 0 && j-1>=0 && pole[i-1][j-1] == -1){ min_count_3++;}
                if(i-1>=0 && j+1 < field_size && pole[i-1][j+1] == -1){ min_count_3++;}
                if(i+1 < field_size && j-1 >= 0 && pole[i+1][j-1] == -1){ min_count_3++;}
                if(i+1 < field_size && j+1 < field_size && pole[i+1][j+1] == -1){ min_count_3++;}

                pole[i][j] = min_count_3;
            }
        }
    }

    int count_otkr = 0;
    int null_zn;

    while(count_otkr != (field_size*field_size) - mins_count){
        std::cout<< std::endl;
        int vibor;
        show_pole(pole2, field_size);

        std::cout << "Open a point(1) or place a flag(2): ";
        std::cin >> vibor;
        
        std::cout << "Enter the coordinates of the point:" << std::endl;
        int x, y;
        std::cin >> x >> y;

        if(vibor == 1){
            if(x > field_size || x < 0 || y > field_size || y < 0){
                std::cout << "Incorrect point coordinates" << std::endl;
                continue;
            }
            std::cout << std::endl;

            if(pole[x-1][y-1] == 0)
                otkrit_noli(pole2, pole, x-1, y-1, &count_otkr);
            else{
                pole2[x-1][y-1] = pole[x-1][y-1];
                if(pole[x-1][y-1] == -1){
                    show_pole(pole2, field_size);
                    std::cout << "You stepped on a land mine" << std::endl;
                    break;
                }
                count_otkr++;
            }
        }
        else{
            pole2[x-1][y-1] = 'f';
        }
    }

    show_pole(pole2, field_size);
    
    if(count_otkr == (field_size*field_size) - mins_count)
        std::cout << "You are a champion!";
    
    std::cin >> null_zn;
    return  0;
}