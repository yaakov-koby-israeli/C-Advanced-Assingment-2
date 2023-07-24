// Course: Advanced C programming
// exercise 2, question 2
// file name: ex2_q2.c

// --------------------------- //
//
//	Assigned by:
//		Student1_Full_Name #ID
//		Student2_Full_Name #ID
//
// --------------------------- //

// --------------------------------------- //
// Include and definition package section:
// --------------------------------------- //
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define scanf_s scanf
#define ROWS 4
#define COLS 5
// --------------------------------------- //
// Types declration section:
// --------------------------------------- //
typedef struct four
{
	int i, j, d, value;
} four;

typedef struct list
{
	four data;
	struct list* next;
} list;
// --------------------------------------- //
// Functions declration section:
// --------------------------------------- //
int createArrayAndList(int A[][COLS], list **lst, four **arr, int rows, int cols);
four createFour(int i, int j, int d, int value);
list* createElement(four data);
void printArray(four* arr, int n);
void printList(list* lst);
void freeDynamic(list** lst, four **arr);

// --------------------------------------- //
// Main section:
// --------------------------------------- //
int main()
{
	unsigned long id_num;
	int n;
	list* lst = NULL;
	four* arr = NULL;
	int A[ROWS][COLS] = {
		{0, 6, 5, 6, 6},
		{8, 9, 5, 6, 7},
		{7, 6, 5, 4, 7},
		{9, 8, 1, 6, 7},
	};

	// Start Program:
	printf("Start Program\n");

	// call functions:
	n = createArrayAndList(A, &lst, &arr, ROWS, COLS);

	// write output:
	printf("Output:\n");
	printArray(arr, n);
	printList(lst);

	// free dynamic:
	freeDynamic(&lst, &arr);

	return 0;
}
// --------------------------- //

/// <summary>
/// This function allocate a dynamic array and list, 
/// from elements found at matrix A 
/// </summary>
/// <param>int A[][] - The static matrix</param>
/// <param>list** lst - Pointer to the pointer of the head of the list</param>
/// <param>four** arr - Pointer to the pointer of the head of the array</param>
/// <param>int rows - The number of rows in the matrix</param>
/// <param>int cols - The number of colums in the matrix</param>
/// <returns>Number of requested elements in found in A</returns>
int createArrayAndList(int A[][COLS], list** lst, four** arr, int rows, int cols)
{
	// your code:
	int i, j,d, counter = 0;
	list* prev=NULL;
	list* head=NULL;
	*arr = (four*)calloc(rows*cols, sizeof(four));
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (abs(A[i][j] - j) == abs(i - j)) {


				four f = createFour(i, j, j-i, A[i][j]);
				(*arr)[counter] = f;
				counter++;
				if (*lst == NULL) {
					*lst = createElement(f);
					head = prev = *lst;
				}
				else {
					prev->next = createElement(f);
					prev = prev->next;
				}
			}
		}
	}
	(*arr) = (four*)realloc((*arr), counter * sizeof(four));
	return counter;
}
// --------------------------- //

/// <summary>
/// The function receives 4 integer values 
/// and returns a value from type four.
/// </summary>
/// <param>int i - The cell row number in matrix</param>
/// <param>int j - The cell colum number in the matrix</param>
/// <param>int d - The difference between the consecutive values</param>
/// <param>int value - The value at position [i,j] in matrix</param>
/// <returns>value from type four</returns>
four createFour(int i, int j, int d, int value)
{
	// your code:
	four f;
	f.i = i;
	f.j = j;
	f.d = d;
	f.value = value;
	return f;
}
// --------------------------- //

/// <summary>
/// The function receives a value from type four
/// and returns a dynamic element from type list  
/// </summary>
/// <param>four data - value from type four</param>
/// <returns>dynamic value from type list</returns>
list* createElement(four data)
{
	// your code:
	list* l = (list*)calloc(1, sizeof(list));
	l->data = data;
	l->next = NULL;
	return l;
}
// --------------------------- //


/// <summary>
/// The function receives an array from type four,
/// and print its values.  
/// </summary>
/// <param>four* arr - the array</param>
/// <param>int n - number of elements</param>
/// <returns>None</returns>
void printArray(four* arr, int n)
{
	// your code:
	int i;
	for(i=0;i<n;i++){
	printf("%d , %d, %d, %d", arr[i].value, arr[i].i, arr[i].j, arr[i].d);
	printf("\n");
	}
	printf("\n");
}
// --------------------------- //


/// <summary>
/// The function receives a list,
/// and print its values.  
/// </summary>
/// <param>list* lst - the list</param>
/// <returns>None</returns>
void printList(list* lst)
{
	// your code:
	
	while (lst != NULL) {
		
		printf("%d , %d, %d, %d", lst->data.value, lst->data.i, lst->data.j, lst->data.d);
		printf("\n");
		lst = lst->next;
	}

}
// --------------------------- //

/// <summary>
/// The function free all allocated memory of the program. 
/// </summary>
/// <param>list** lst - Pointer to the pointer of the head of the list</param>
/// <param>four** arr - Pointer to the pointer of the head of the array</param>
/// <returns>None</returns>
void freeDynamic(list** lst, four** arr)
{
	// your code:
	list* current = *lst;
	list* prev = NULL;
	while (current != NULL) {
		prev = current;
		current = current->next;
		free(prev);
	}
	free(*arr);
}
// --------------------------- //
