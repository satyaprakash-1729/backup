#include <stdio.h>

int main(int argc, char const *argv[])
{
    long i,n;
    long a=0,b=0;
    scanf("%ld",&n);
    long diff = 1<<30;
    for(i=1;i<=n;i++){
        if(n%i==0){
            if(i>n/i){
                break;
            }else{
                if((n/i)-i<diff){
                    diff = (n/i)-i;
                    a = i;
                    b = n/i;
                }
            }
        }
    }
    printf("%ld %ld\n",a,b );
    return 0;
}