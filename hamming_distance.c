#include <stdio.h>
int main(){
    int a,b;
    while (1>0)
    {
        scanf("\n%d",&a);
        if(a<0){
            break;
        }
        scanf("%d",&b);
        int counter = 0;
        int xor =a^b;
        while(xor>0){
            if(xor%2==1){
                counter++;
            }
            xor/=2;
        }
        printf("%d\n",counter);
    }
    
    return 0;
}