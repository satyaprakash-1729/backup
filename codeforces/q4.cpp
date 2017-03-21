#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

typedef struct piece{
    char color;
    char type;
} piece;

piece* create(char color1,char type1){
    piece* temp = (piece *)malloc(sizeof(piece));
    temp->color=color1;
    temp->type = type1;
    return temp;
}

int main(int argc, char const *argv[])
{
    int g;
    cin>>g;
    for(int z =0;z<g;z++){
        int w,b,m;
        int row;
        char type,col1;
        cin>>w>>b>>m;
        vector<vector<piece*>> Board;
        for(int y=0;y<w;y++){
            cin>>type>>col1>>row;
            int col = (int)col1-64;
            
        }
        for(int y=0;y<b;y++){
            cin>>type>>col>>row;
            
        }

    }
    return 0;
}