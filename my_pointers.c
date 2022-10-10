#include <stdio.h>
// requires: 2 non-empty arrays of strings
//effects: returns an array with alpha-numeric order sorted elements
char **merge(char **array1, const int size1, char **array2, int size2)
{
    if (size1 == 0 || size2 == 0)
    {
        printf("Empty array!");
    }
    const int size = size1 + size2;
    char **c;
    c = (char **)malloc(sizeof(char *) * size);
    for (int k = 0; k < size1; k++)
    {
        c[k] = (char *)malloc(sizeof(char) * (strlen(array1[k]) + 1));
    }
    int i = 0, j = 0;
    while (i < size1 && j < size2)
    {
        if (**array1 < **array2)
        {
            c[i + j] = *array1;
            array1++;
            i++;
        }
        else
        {
            c[i + j] = *array2;
            array2++;
            j++;
        }
    }
    while (i < size1)
    {
        c[i + j] = *array1;
        array1++;
        i++;
    }
    while (j < size2)
    {
        c[i + j] = *array2;
        array2++;
        j++;
    }
    return c;
}
int main()
{
    char *array[] = {"za", "zb", "zzzzc"};
    char *array2[] = {"ab", "ac"};

    const int size1 = sizeof(array) / sizeof(array[0]);
    const int size2 = sizeof(array2) / sizeof(array2[0]);
    const int size = size1 + size2;
    char **c = merge(array, size1, array2, size2);
    for (int i = 0; i < (size1 + size2); i++)
    {
        printf("%s\n", *(c + i));
    }
    return 0;
}