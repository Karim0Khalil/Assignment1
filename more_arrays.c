#include <stdio.h>
#include <string.h>

// char * concat(char array[2][6],int length, int size){
//     char * result;
//     for (int i = 0; i < length; i++)
//     {
//         result[i] = array[0][0];

//         for(int j = 1;j < size;j++){
//             strcat(result," ");
//             strcat(result,array[i][j]);
//         }
//     }
//     return result;

// }
void concat(char **array, char *result, int size, int length);

int main()
{
    char *array[][3] = {{"I", "LOVE", "CODING"}, {"THIS", "IS", "SPARTA"}};
    const int SizeArray = sizeof(array)/sizeof(array[0]);
    char *result[2];
    concat(array,result, SizeArray,3);

    for (int i = 0; i < SizeArray; i++)
    {
        printf("%d\n",*result+i);
        printf("%s\n",result[1]);
    }
    
    return 0;
}
void concat(char **array, char *result, int size, int length)
{
    char str[] = "";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < length; j++)
        {
            strcat(str, *(&array[i]+j) );
            strcat(str," ");
        }
        result[i] = str;
    }
}