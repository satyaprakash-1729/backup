#include <iostream>
#include <cmath>

using namespace std;

float dist(float x1,float y1,float x2,float y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(int argc, char const *argv[])
{
    float x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    float ax1,ay1;
    ax1=(x1+x3)/2;
    ay1=(y1+y3)/2;
    //float d = dist(x2,y2,ax1,ay1);
    float ansx1 = 2*ax1-x2;
    float ansy1 = 2*ay1-y2;
    float tempx = x1;
    float tempy = y1;
    x1 = x2;
    y1 = y2;
    x2 = x3;
    y2 = y3;
    x3 = tempx;
    y3 = tempy;
    ax1=(x1+x3)/2;
    ay1=(y1+y3)/2;
    //float d = dist(x2,y2,ax1,ay1);
    float ansx2 = 2*ax1-x2;
    float ansy2 = 2*ay1-y2;
    tempx = x1;
    tempy = y1;
    x1 = x2;
    y1 = y2;
    x2 = x3;
    y2 = y3;
    x3 = tempx;
    y3 = tempy;
    ax1=(x1+x3)/2;
    ay1=(y1+y3)/2;
    //float d = dist(x2,y2,ax1,ay1);
    float ansx3 = 2*ax1-x2;
    float ansy3 = 2*ay1-y2;
    cout<<3<<endl;
    cout<<(int)ansx1<<" "<<(int)ansy1<<endl;
    cout<<(int)ansx2<<" "<<(int)ansy2<<endl;
    cout<<(int)ansx3<<" "<<(int)ansy3<<endl;
    return 0;
}