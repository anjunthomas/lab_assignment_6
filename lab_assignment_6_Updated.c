#include <stdio.h>

int search(int numbers[], int low, int high, int value);


void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}

int search(int numbers[], int low, int high, int value)
{
	if(low > high){ // meaning value was not found in the array
		return -1;
	}
	// Binary Search: We will split this array in 2, and the middle element of the array will be tested against the value
	// If the middle element is less than value, move to the half with bigger numbers (right)
	// if the middle element is More than value, move to the half with smaller numbers (left)
	int half = ((high + low) / 2 );
	if(numbers[half] == value) {
		return half; // meaning value was found in the middle value
	}
	else if(numbers[half] < value){
		return search(numbers, half + 1, high, value); // less than value, move to right
	}
	else (numbers[half] > value){
		return search(numbers, low, half - 1 , value); // more than value, move to left
	}
}