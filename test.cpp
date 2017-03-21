#include <iostream>
 
using namespace std;

typedef class num{
public:
    int data;
    num(int dat){
        data = dat;
        cout<<data<<endl;
    }
} num;
 
int main() {
    num a[100];
    return 0;
}