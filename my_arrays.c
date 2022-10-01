#include <stdio.h>

#define SIZE 10

void printArray(int array[], int size){
    printf("Index\tValue\n");
    for(int i = 0;i<size;i++){
        printf("%d\t%d\n",i,array[i]);
    }
    return;
}
void swapValues(int array[], int i, int j){
   int temp = array[i];
   array[i] = array[j];
   array[j] = temp;
    return;
}

void arrayHistogram(int array[]){
    int count[3] = {0};
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if(array[i]==j){
                count[j-1]++;
            }
        }
    }
    printf("Value\tFrequency\tHistogram\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d\t",i+1);
        printf("%d\t\t",count[i]);
        for (int j = 0; j < count[i]; j++)
        {  
            printf("*");
        }
        printf("\n");
    }
}
void bubblesort(int array[], int size){
    int temp = 0;
    for(int i = 0;i<size;i++){
        for(int j = 1;j<size;j++){
            if(array[j-1]> array[i]){
                swapValues(array,j-1,i);
            }
        }
    }
}
float median(int array[], int size){
    if(size%2==1){
        return array[size/2];
    }
    if (size%2==0)
    {   
        int m = size/2;
        float median = (array[m-1]+array[m])/2.0;
        return median;
    }
}
int mode(int array[],int size){
    int count,temp = 0,element;
    for(int i = 0;i<size;i++){
        count = 0;
        for(int j = 0;j<size;j++){
            if(array[i]==array[j]){
                count++;
            }
        }
        if(count>temp){
            temp = count;
            element = array[i];
        }
    }
    return element;
}
int isSorted(int array[], int size){
    int counter = 1;
    for(int i = 0; i<size-1;i++){
        if(array[i]<array[i+1]){
            counter++;
        }
    }
    if(counter == size){
        return 1;
    }
    return 0;
}
int main(){
    int array[SIZE] = {2,2,3,3,3,3,3,3,1,1};
    int length = sizeof(array)/sizeof(array[0]);
    swapValues(array,0,7);
    printArray(array,length);
    arrayHistogram(array);
    bubblesort(array,length);
    printArray(array,length);


    int test[] = {1, 3, 4, 2, 9, 5, 8, 7};


    printf("%d\n", isSorted(test,sizeof(test)/sizeof(test[0]) ));


    bubblesort(test,sizeof(test)/sizeof(test[0]));
    printf("%d\n", isSorted(test,sizeof(test)/sizeof(test[0]) ));
    printf("%f\n",median(test,sizeof(test)/sizeof(test[0])));


    printf("%d",mode(array,length));
    return 0;
}