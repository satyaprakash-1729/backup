#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int n = 100;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<rand()%1000<<endl;
    }
    cout<<15<<endl;
    return 0;
}