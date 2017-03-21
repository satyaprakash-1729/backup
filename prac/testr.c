#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t temp = 0;
    long temp1 = (long)temp;
    printf("%s\n",ctime(&temp1));
    return 0;
}