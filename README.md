# HeapSort
Implementing HeapSort in C++

# Problem Statement:

1) Given a random array of N numbers, convert it into a heap.

2) The null nodes are indicated by -1 and the null nodes are located at any place in the array. Make this into a heap.

3) Sort the heap using HeapSort

4) Display the array after the heap is converted from the array and after HeapSort.

# Algorithm

Algorithm:

The algorithm for the given problem statement goes as follows:
Note: The implemented heap is a Max Heap

1) In the first step, the array is filtered and the null nodes are removed and stored in an array called heap[].

After that, the value property of heap is maintained, by using Floyd’s method for building a heap.

	Start from the n/2nd element and compare the values of both its children

Case 1: When the parent value is greater than both its children, continue
Case 2: When the parent is smaller than right (or) left child
Case 3: When the parent is smaller than both its children

2) After the cases, decrease n by 1 and continue till n = 1
Use a function check() and start from the first element upto the middle and check the value of all children of a given node.

For HeapSort,

3) Swap the 1st element and the a[0]th element of the array
Reduce the value of a[0]
Call the check() function
Repeat until a[0] is 1

The final array produced will be sorted in ascending order.


