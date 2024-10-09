/*Manipulating a Linked List*/
#include <iostream>
#include <fstream>
using namespace std;


struct NODE{
 int data ;
 NODE* link ;
};

void createList(ifstream &inFile, NODE **head);
void deleteElements(ifstream &inFileDel, NODE **head);
bool searchLinkedList(NODE *head, int, NODE **curPtr, NODE **prePtr);
void insertLinkedList(NODE **head, int data);
void deleteLinkedList(NODE **head, int data);
void displayList(NODE *head);


int main() {
    string dataFilename;
    ifstream inFile;
    string delDataFilename;
    ifstream inFileDel;
    // First part
    cout << "File name for creating linked list: ";
    cin >> dataFilename;
    cout << endl;
    inFile.open(dataFilename);
    NODE *listHead = NULL;// empty list
    if(!inFile){
    cout << "File open error!" << endl;
    exit(1);
    }
    createList(inFile, &listHead);
    inFile.close();
    displayList(listHead);


    // Second part
    cout << "\nFile name for linked list deletion: ";
    cin >> delDataFilename;
    inFileDel.open(delDataFilename);
    if(!inFileDel){
    cout << "File open error!" << endl;
    exit(1);
    }
    deleteElements(inFileDel, &listHead);
    inFileDel.close();
    cout << "\nList after deletion:" << endl;
    displayList(listHead);

    return 0;
}


void createList(ifstream &inFile, NODE **head){
    int data ;
    while (inFile >> data ){
        insertLinkedList(head,data);
    }

}

void deleteElements(ifstream &inFileDel, NODE **head) {
	int data ;
    while (inFileDel >> data ){
        deleteLinkedList(head,data);
    }
}


bool searchLinkedList(NODE *head, int data , NODE **curPtr, NODE **prePtr){

    bool isFound;
    *prePtr  = NULL;
    *curPtr = head;

    while ( (*curPtr != NULL) && (data < (*curPtr)->data)) {// supposed the linked list is in descending order
    *prePtr  = *curPtr;
    *curPtr  = (*curPtr)->link;

    }
     if (   ((*curPtr)!= NULL ) &&     data == (*curPtr)-> data )
      isFound = true;
     else isFound =  false;
    return isFound;

}
void deleteLinkedList(NODE **listHead, int data){

    NODE *curPtr;
    NODE *prePtr;

    if(!searchLinkedList(*listHead, data, &curPtr, &prePtr)){ // not found
    	return;
    }
    if(prePtr == NULL)// if the pointer to prev  == NULL
   		*listHead = (curPtr)->link;// delete the first node which is curr
    else
    	(prePtr)->link = (curPtr)->link;

   	(curPtr)->link = NULL;
    delete curPtr;
}

void insertLinkedList(NODE ** listHead, int data ){
   // creating the new node
    NODE * newNode = new NODE ;// allocating memory for the new node
    newNode -> data = data ; // inserting the data field into the new node
    newNode -> link = NULL;
    NODE *curPtr;
    NODE *prePtr;
    if (!searchLinkedList(*listHead, data, &curPtr, &prePtr)){ // if  the element is not found meaning that there is no duplicates

        if (*listHead == NULL ) { // if the linked list is empty , insert at the beginning
            *listHead = newNode;
            return;
        }

        if (prePtr == NULL && data > curPtr -> data) { // Insertion at the beginning
            newNode->link = (*listHead) ; // makes the new node become the predecessor of the previous first
            (*listHead) =  newNode; //   makes the newly connected node the first node
            return;
        }
        if ( curPtr == NULL  && data <  prePtr -> data  ) { // Insertion at the end
            prePtr->link = newNode;// connects the new node to the previous last node
            newNode-> link = NULL;// makes the newly connected node become the last one
            return;
        }
        //// Insertion in the middle
        newNode -> link   = curPtr  ; //connects the new node to its sucessor
        prePtr-> link = newNode;// connect the new node to its predecessor
        return;

    }


}


void displayList(NODE *head){

    int count = 0; // Used for counting the number of nodes
    NODE *tempPtr = head; // Set tempPtr to the head of the linked-list

    while(tempPtr != NULL){ // Check whether get to the end of the linked-list
        cout << tempPtr -> data << " "; // Print out the data stored in the node
        tempPtr = tempPtr -> link ; // Move to the next node
        count++;
        if( count % 15 == 0) // Change line if already printing 15 numbers
        cout << endl;
    }
    cout << endl;
    cout << "Total number of elements in the linked list: " << count << endl;
}
