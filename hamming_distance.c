#include <stdio.h>
//requires: two non-negative integers, and a negative to stop the program
//returns a number which represents how many bits differ between the two integers 
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