#include <stdio.h>
//requires: a positive non-zero integer
//effects: returns the position of the least significant bit that is 1
int lsb(int x){
    int counter = 0;
    if(x>0){
        while(x>0){
        if(x%2==1){
            return counter;
        }
        x/=2;
        counter+=1;
    }
    }
}
//requires: a positive non-zero integer
//effects: returns the position of the most significant bit that is 1
int msb(int x){
    int counter = 0;
    while(x>1){
        x = x >> 1;
        counter++;
    }
    return counter;
}
//requires: the msb and lsb of a positive non-zero integer
//effects: returns the distance between the the most and least signifcant bits set to 1.
int main(){
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    printf("Least signifcant bit: %d\n",lsb(x));
    printf("Most signifcant bit: %d\n",msb(x));
    printf("Distance between first and last bit: %d.",msb(x)-lsb(x));
    return 0;
}