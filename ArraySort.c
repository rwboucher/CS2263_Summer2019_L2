/********************************
 * 
 * ArraySort.c
 * 
 * Created by Jean-Philippe Legault
 * 
 * Your task is to implement in place sorting using the two available functions
 * swapAdjacent, and compareAdjacent.
 * 
 * Some bug might have been introduced... you will have to find out if there are any!
 * if so, you will have to correct it
 * 
 ********************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *array, int size)
{
    for(int i=0; i<size; i++)
    {
        if(i != 0)
        {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("\n");
}

void swapAdjacent(int *a, int index)
{    
    int temp = *(a + index);
    *(a + index) = *(a + index + 1);    
    *(a + index + 1) = temp;
}

int compareAdjacent(int *a, int index)
{
    return *(a + index) - *(a + index + 1);
}

/**
 * TODO: implement in place sorting on an array
 * by using the two functions swapAdjacent and compareAdjacent
 */
void inPlaceSort(int *a, int array_size)
{
	int i = 0, j=0, comp=0; 
	for (i = 0; i < array_size - 1; i++)
	{
		for (j = 0; j < array_size - i - 1; j++)
		{
			comp = compareAdjacent(&a[j], 0);
			if (comp > 0)
				swapAdjacent(&a[j], 0);
		}
	}			
}

int main(void)
{

    int array_size = 0;
    printf("Enter the array size (>0) and the numbers to fill the array with: ");
    if(!scanf("%d", &array_size))
    {
        printf("ERROR. Must enter an integer.\n");
        return EXIT_FAILURE;
    }
    else if(array_size < 1)
    {
        printf("ERROR. array size must be at least 1.\n");
        return EXIT_FAILURE;
    }

    int a[array_size];

    /**********************
     * TODO finish parsing the user input to fill the array
     * 
     * it should parse user input with scanf to fill the array with values
     **********************/
	 for (int i=0; i<array_size; i++)
	 {
		 if (scanf ("%d", &a[i]) != 1)
		 {
			 printf("Invalid integer.\n");
			 return EXIT_FAILURE;
		 }
	 }

    // printf("=== Array before Sorting = ");
    printArray(a, array_size);

    inPlaceSort(&a[0], array_size);

    // printf("=== Array after Sorting = ");
    printArray(a, array_size);

}
