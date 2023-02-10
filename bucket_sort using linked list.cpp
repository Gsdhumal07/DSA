// Bucket sort in C++

//#include <iomanip>
#include <iostream>
//#include<stdio.h>
#include<stdlib.h>
using namespace std;

int NARRAY= 11  ; // Array size
int NBUCKET = 5 ; // Number of buckets
int INTERVAL = 5;  // Each bucket capacity

struct Node {
  int data;
  struct Node *next;	//creating a next pointer
};

void BucketSort(int arr[]);							// sorting function
struct Node *InsertionSort(struct Node *list);          //use insertion sort method to sort the elements in the bucket
void print(int arr[]);								// displaying the array
void printBuckets(struct Node *list);				// displaying the elements in buckets
int getBucketIndex(int value);						// for thr ndex of the bucket 

// Sorting function
void BucketSort(int arr[]) {
  int i, j;
  struct Node **buckets;

  // Create buckets and allocate memory size
  buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

  // Initialize empty buckets
  for (i = 0; i < NBUCKET; i++) {
    buckets[i] = NULL;
  }

  // Fill the buckets with respective elements
  for (i = 0; i < NARRAY; i++) {
    struct Node *current;		// create the currect pointer of the node 
    int pos = getBucketIndex(arr[i]);		// it is denoting the bucket number ( index )
    current = (struct Node *)malloc(sizeof(struct Node));		// creating current and allocate the memory size
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
  }
  
  cout <<endl<< "--------------------------------" << endl<<endl;
  for (int i=0;i<NBUCKET ; i++){
  	cout<<"BUCKET [ "<<i<<" ] =  ";
  	printBuckets(buckets[i]);
  	cout<<endl;
  }


	
  // Sort the elements of each bucket
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = InsertionSort(buckets[i]);
  }

  cout <<endl<< "--------------------------------" << endl<<endl;
  for (int i=0;i<NBUCKET ; i++){
  	cout<<"BUCKET [ "<<i<<" ] =  ";
  	printBuckets(buckets[i]);
  	cout<<endl;
  }

  // Put sorted elements on arr
  for (j = 0, i = 0; i < NBUCKET; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }


  return;
}

// Function to sort the elements of each bucket
struct Node *InsertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

int getBucketIndex(int value) {
  return value / INTERVAL;
}

// Print buckets
void print(int ar[]) {
  int i;
  for (i = 0; i < NARRAY; ++i) {
    cout <<  ar[i]<<" ";
  }
  cout << endl;
}

void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    cout <<cur->data<<" , ";
    cur = cur->next;
  }
}

// Driver code
int main(void) {
  int array[NARRAY] = {11 , 9 , 21 , 8, 17, 19 , 13 , 1 , 24 ,12 , 22};

  cout << "Initial array: " << endl<<endl;
  print(array);

  BucketSort(array);
  cout<<endl<<"-------------------------------"<<endl;
  cout <<endl<< "Sorted array: " << endl<<endl;
  print(array);
}
