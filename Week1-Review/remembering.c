#include <stdio.h>
#define MAX 5

void inputArr(int arr[], int size);

int main(){
	
	int arr[MAX];
	
	inputArr(arr, MAX);
	
	int i;
	for(i = 0; i < MAX; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}

void inputArr(int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
}
