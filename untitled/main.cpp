#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> map(12, vector<int>(16));

    int posx = 9, posy = 2;
    int p1x = 3, p1y = 1;
    int p2x = 11, p2y = 1;
    int p3x = 7, p3y = 9;

    int nr = 0b11100100101001001010010010;

    while(true){
        switch(nr % 4){
            case 0:
                posx = (posx + p1x) /2;
                posy = (posy + p1y) /2;
                break;
            case 1:
                posx = (posx + p2x) /2;
                posy = (posy + p2y) /2;
                break;
            case 2:
                posx = (posx + p3x) /2;
                posy = (posy + p3y) /2;
                break;
            default:
                break;
        }

        map[posy][posx] = 1;
        nr /= 2;

        for(auto row: map){
            for(auto val: row) cout << val;
            cout << "\n";
        }
    }

    return 0;
}

