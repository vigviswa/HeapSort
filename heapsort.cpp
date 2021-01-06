// C++ Code to implement HeapSort using an array of random numbers, where N = 20

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

void display(int[], int n);

// Function to Build a heap from a given array Using the Max Heap Property
int *buildHeap(int[], int, int);

// Function used to maintain the value property of a heap by checking the value of a node with both it's children nodes
void check(int[], int, int);

// Function to implement the HeapSort by making use of the above two functions
void HeapSort(int[], int, int);
int temp;
int main()
{
  // Hardcoded Given array of numbers, with Random Null nodes, indicated by -1

  int arr[30] = {0, 2, 7, 98, -1, 21, -1, 10, 1, 9, -1, 14, 75, 88, 4, -1, 50, 42, -1, 100, 89, -1, 49, 70, 69, -1, 55, 20, -1, -1};
  int size_of_heap = sizeof(arr) / sizeof(arr[0]);
  int count = 0;
  for (int i = 1; i < size_of_heap; i++)
  {
    if (arr[i] != -1)
    {
      count++;
    }
  }
  cout << endl;
  cout << "The given random Array of numbers is: " << endl;
  display(arr, size_of_heap);
  cout << endl;

  // Creating an array for numbers in the heap, by getting rid of the null nodes

  int heap[count + 1];
  int o = 1;
  for (int j = 1; j < size_of_heap; j++)
  {
    if (arr[j] != -1)
    {
      heap[o] = arr[j];
      o++;
    }
  }
  // Setting the 0th element of the heap array as the number of values in the array

  heap[0] = count;
  cout << "The value of the nodes in the heap after dropping the null nodes is: " << endl;
  display(heap, count + 1);
  cout << endl;

  // Array pointer for assignment of the return value from the declared function

  int *p[22];
  *p = buildHeap(heap, count + 1, count + 1);

  cout << "The resultant heap array, satisfying the value property from the given array of random numbers is: " << endl;
  display(*p, count + 1);
  cout << endl;

  // Calling the function to implement Heapsort

  cout << "Implementation of Heapsort :" << endl;
  display(*p, count + 1);
  HeapSort(*p, count + 1, count + 1);
  cout << endl;
  cout << "The Resultant array sorted in ascending order using HeapSort is: " << endl;
  display(*p, count + 1);
  cout << endl;
  cout << "The end" << endl;
}

// Function to display the arrays at each step

void display(int a[], int m)
{
  cout << endl;
  cout << "| ";
  for (int i = 0; i < m; i++)
  {
    cout << a[i] << "\t";
  }
  cout << "|";
  cout << endl;
}

// Function to arrange the nodes of the heap according to the value property of a Max Heap

// The function uses Floyd's Method for building the heap

// It starts with the middle element and decreaments until the 1st element is reached

int *buildHeap(int a[], int n, int m)
{
  int j;

  if (n < 1)
  {
    // If first element is reached, call the check function to check value property of children
    check(a, 1, m);
    return (a);
  }
  else
  {
    if (n == m)
    {
      // Start from middle element
      j = n / 2;
    }
    else
    {
      j = n;
    }

    while (2 * j <= m)
    {
      // Check with all children

      if (a[j] > a[2 * j])
      {
        if ((a[j] < a[2 * j + 1]))
        {
          // When parent is smaller than right child
          temp = a[2 * j + 1];
          a[2 * j + 1] = a[j];
          a[j] = temp;
          // Swapping with right child
          j = 2 * j + 1;
        }
        else
        {
          // If parent is greater than both children, Break from loop and proceed to next iteration

          break;
        }
      }
      else
      {
        if ((a[j] > a[2 * j + 1]))
        {
          // When parent is smaller than left child
          temp = a[2 * j];
          a[2 * j] = a[j];
          a[j] = temp;
          j = 2 * j;
        }
        else
        {
          // // When parent is smaller than right child and left child
          // Swap with larger than both children

          temp = max(a[2 * j], a[2 * j + 1]);
          (a[2 * j] > a[2 * j + 1] ? a[2 * j] : a[2 * j + 1]) = a[j];
          a[j] = temp;
          j = a[2 * j] > a[2 * j + 1] ? 2 * j : 2 * j + 1;
        }
      }
    }
    // Decreament the value of iterator
    return (buildHeap(a, j - 1, m));
  }
}

// Function to check the value property of resultant heap

void check(int a[], int n, int m)
{

  // Check the value of the node with both children. The Last node with children will be the central element

  while (n <= m / 2)
  {
    if (a[n] > a[2 * n] && a[n] > a[2 * n + 1])
    {
      // Recursive call until the middle element is reached
      check(a, n + 1, m);
      return;
    }
    else
    {
      // Else, call the buildheap function to fix the value property

      buildHeap(a, m, m);
    }
  }
}

// Function to implement HeapSort from the concerted heap

void HeapSort(int a[], int m, int n)
{
  int temp;

  // Do while the length of heap is greater than 1

  while (a[0] > 1)
  {
    // Swap the 1st element and the element stored at the a[0]th position
    temp = a[a[0]];
    a[a[0]] = a[1];
    a[1] = temp;

    // Decreament the number of nodes of the heap
    a[0]--;

    display(a, a[0] + 1);

    // Check the value property of the resultant heap
    check(a, 1, a[0] - 1);

    // Display the heap before running it for the next iteration
    display(a, a[0] + 1);
  }
  display(a, m);
  return;
}
