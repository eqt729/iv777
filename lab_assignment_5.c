#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head){
    node* head_ptr = head; 
	int numNodes = 0;
	if (head == NULL)
		return;
	while (head_ptr != NULL) {	
		numNodes ++;
		head_ptr = head_ptr -> next;

	}
	return numNodes;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head){
	if (head == NULL)
	 	return NULL;
	
	int n = length(head);
	int i= 0;
	char* cString = (char*)malloc(sizeof(char)* (n+1));

	while (head != NULL){
		cString[i] = head->letter;
		head = head ->next;
		i++; 
	}

	cString[i]= '\0';
	return cString;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|

void insertChar(node** pHead, char c){
	node* newNode = (node*)malloc(sizeof(node));
	newNode-> letter = c;
	newNode -> next = NULL;

	if (*pHead == NULL) {
		*pHead = newNode;
	} else {
		node* help_ptr = *pHead;
		while (help_ptr -> next != NULL) 
			help_ptr = help_ptr -> next;
		help_ptr -> next = newNode;

	} 
		
	

		
	
	

}

//check if*phead id nul
// deletes all nodes in the linkedList.
void deleteList(node** pHead){
	node* temp = NULL;
	while (*pHead != NULL){
		temp = *pHead;
		*pHead = (*pHead) ->next; 
		free(temp);

	}
	
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}


	}

	fclose(inFile);
}