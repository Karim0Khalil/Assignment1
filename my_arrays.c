#include <stdio.h>
#define SIZE 10

// requires: a 1D array with size != 0
// effects: returns the value at each index of the array.
void printArray(int array[], int size)
{
    if (size == 0)
    {
        printf("Empty array!");
    }
    printf("Index\tValue\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t%d\n", i, array[i]);
    }
    return;
}

// requires: a non-empty 1D array and two indices
// effects: modifies the array by swaping the values of the two given indices.
void swapValues(int array[], int size, int i, int j)
{
    if (size == 0)
    {
        printf("Empty array!");
    }
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    return;
}

// requires: an array containing only digits 1,2 and 3
// effects: computes the histogram with the frequency of each digit.
void arrayHistogram(int array[])
{
    if (SIZE == 0)
    {
        printf("Empty array!");
    }
    int count[3] = {0};
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (array[i] == j)
            {
                count[j - 1]++;
            }
        }
    }
    printf("Value\tFrequency\tHistogram\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d\t", i + 1);
        printf("%d\t\t", count[i]);
        for (int j = 0; j < count[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

// requires: a non empty array
// effects: modifies the array by sorting its elements.
void bubblesort(int array[], int size)
{
    if (size == 0)
    {
        printf("Empty array!");
    }
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (array[j - 1] > array[i])
            {
                swapValues(array, size, j - 1, i);
            }
        }
    }
}

// requires: a non-empty sorted array
// effects: returns the median which is at the middle of the array
float median(int array[], int size)
{
    if (size == 0)
    {
        printf("Empty array!");
    }
    if (size % 2 == 1)
    {
        return array[size / 2];
    }
    if (size % 2 == 0)
    {
        int m = size / 2;
        float median = (array[m - 1] + array[m]) / 2.0;
        return median;
    }
}

// requires: a non-empty array
// effects: loops over the array and counts the most existing number and returns it.
int mode(int array[], int size)
{
    if (size == 0)
    {
        printf("Empty array!");
    }
    int count, temp = 0, element;
    for (int i = 0; i < size; i++)
    {
        count = 0;
        for (int j = 0; j < size; j++)
        {
            if (array[i] == array[j])
            {
                count++;
            }
        }
        if (count > temp)
        {
            temp = count;
            element = array[i];
        }
    }
    return element;
}

// requires: a non-empty array
// effects: return 1 if the array is sorted in in ascending order, else it returns 0
int isSorted(int array[], int size)
{
    if (size == 0)
    {
        printf("Empty array!");
    }
    int counter = 1;
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] < array[i + 1])
        {
            counter++;
        }
    }
    if (counter == size)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int array[SIZE] = {2, 2, 3, 3, 3, 3, 3, 3, 1, 1};
    int length = sizeof(array) / sizeof(array[0]);
    swapValues(array, length, 0, 7);
    printArray(array, length);
    arrayHistogram(array);
    bubblesort(array, length);
    printArray(array, length);

    int test[] = {1, 3, 4, 2, 9, 5, 8, 7};

    printf("%d\n", isSorted(test, sizeof(test) / sizeof(test[0])));

    bubblesort(test, sizeof(test) / sizeof(test[0]));
    printf("%d\n", isSorted(test, sizeof(test) / sizeof(test[0])));
    printf("%f\n", median(test, sizeof(test) / sizeof(test[0])));

    printf("%d", mode(array, length));
    return 0;
}