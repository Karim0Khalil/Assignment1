#include <stdio.h>

int main(){
    char x[] = {'h','j','k'};
    char * cards[] = {"Hearts","Diamonds", "Clubs", "Spades" };
    cards[0] = "heart";
    printf("%c",cards[0][0]);
    cards[0][0] = 'h';
    printf("%c",cards[0][0]);
    return 0;
}