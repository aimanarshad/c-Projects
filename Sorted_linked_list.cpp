#include <iostream>
#include <cstdlib> // for malloc
using namespace std;

// Node definition
struct Record {
    int index;
    int RNO;
    Record* next;
};

// Function to insert a new node into a sorted linked list
void insertSorted(Record** head, int idx, int newRNO) {
    Record* newRecord = (Record*)malloc(sizeof(Record));
    newRecord->index = idx;
    newRecord->RNO = newRNO;
    newRecord->next =NULL;

    if (*head == NULL || newRNO < (*head)->RNO) {
        newRecord->next = *head;
        *head = newRecord;
    } else {
        Record* current = *head;
        while (current->next !=NULL && current->next->RNO < newRNO) {
            current = current->next;
        }
        newRecord->next = current->next;
        current->next = newRecord;
    }
}

// Function to print the list
void printList(Record* record) {
    while (record != NULL) {
        cout << "[" << record->index << ": " << record->RNO<< "] ";
        record = record->next;
    }
    cout << endl;
}

// Function to calculate the length of the linked list
int lengthOfList(Record* headof) {
    int length = 0;
    Record* current = headof;
    while (current !=NULL) {
        length++;
        current = current->next;
    }
    return length;
}

int main() {
	Record* headof =NULL;
    int idx = 0;
    int newRNO;
    char choice;

    do {
        cout << "Enter a Rollnumber to insert into the linked list: ";
        cin >> newRNO;
        insertSorted(&headof, idx++, newRNO);

        cout << "Do you want to insert another rollno? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Print the sorted linked list
    cout << "Sorted list: ";
    printList(headof);

    // Print the length of the linked list
    cout << "Length of the linked list: " << lengthOfList(headof) << endl;

    return 0;
}

