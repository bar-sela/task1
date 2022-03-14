// Your First C++ Program

#include <string>   
#include <iostream>
#include <vector>
using namespace std;

namespace ariel {



   string mat(int column, int row, char a, char b) {

   if(column%2 == 0 || row%2 ==0)
       __throw_invalid_argument("Mat size cannot be even!");

    if(column <= 0 || row <= 0)
    __throw_invalid_argument("Mat size have to be a non-negative number!");

    if (a == '\n' || b == '\n' || a== '\t' || b == '\t'
    || a == '\r' || b == '\r' || a == ' ' || b == ' ')
       __throw_invalid_argument("Invalid char!");



    vector<vector<char>> arr(row, vector<char>(column, ' '));
    int divided;
    int s = 0;
    int min;
    if (column > row) {
        divided = row / 2;
        min = row;
    } else {
        divided = column / 2;
        min = column;
    }
    char chr = a;

    while (min - s >= divided) {
        if (s % 2 == 0)
            chr = a;
        else
            chr = b;
            //// up
        for (int i = 0 + s; i < column - s; i++) {
            arr[s][i] = chr;
        }
         // left
        for (int i = 0 + s; i < row - s; i++) {
            arr[i][s] = chr;
        }
          // buttom
        for (int i = 0+s; i < column - s ; i++) {
            arr[row - 1 - s][i] = chr;
        }
        // right
        for (int i = 0 + s; i < row - s ; i++) {
            arr[i][column - 1 - s] = chr;
        }
        s++;
    }
    string ans = string("");
    for(int i = 0 ; i<row;i++ ){
        for(int j = 0 ; j < column ; j ++ ){
            ans+= arr[i][j];
        }
        ans += "\n";
    }
    return ans;
}
}
