#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10
#define INT_MIN (-217483647 - 1)

struct Stack{
	int top;
	int capacity;
	int *arr;
};

struct Stack *CreateStack(){

	struct Stack *s = malloc(sizeof(struct Stack));
	if(!s) return NULL;

	s->capacity = MAX_SIZE;
	s->top = -1;

	s->arr = malloc(s->capacity*sizeof(int));
	if(!s->arr) return NULL;

	return s;
}

int isEmpty(struct Stack *s){
	return (s->top == -1);
}

int isFull(struct Stack *s){
	return (s->top == s->capacity-1);
}

void Push(struct Stack *s, int data){
	
	if(isFull(s))
		printf("Stack Overflow\n");
	else
		s->arr[++s->top] = data;
}

int Pop(struct Stack *s){

	if(isEmpty(s)){
		printf("Stack is Empty\n");
		return INT_MIN;
	}
	else
		return (s->arr[s->top--]);
}

void DeleteStack(struct Stack *s){
	
	if(s){
		if(s->arr)
			free(s->arr);
		free(s);
	}
}

int main(void){

	struct Stack *arr = NULL;
	int len = 0, i, j, op, data;

	printf("Stack implementation for integers\n");
	printf("Select the stack operations: \n");
	printf("1: Push\n");
	printf("2: Pop\n");
	printf("3: Display the stack \n");
	printf("4: Exit\n");

	arr = CreateStack();
	do{
		printf("Enter the operation number: \n");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
			{
			printf("Input an integer to be pushed: ");
			scanf("%d", &data);
			Push(arr, data);
			printf("\n");
			break;
			}

			case 2:
			{
			printf("Poping an element...\n");
			data = Pop(arr);
			printf("The element is poped: %d\n", data);
			break;
			}

			case 3:
			{
			printf("Displaying an array...\n");
			len = arr->top;
			for(i = 0; i < len+1; i++)
				printf(" %d ", arr->arr[i]);
			printf("\n");
			break;
			}
			
			case 4:
			{
			printf("xiting...\n");
			DeleteStack(arr);
			printf("Done\n");
			break;
			}
		}
	}while(op != 4);
	return 0;
}

