// Initial I is 0
void heapify(int arr[], int n, int i) 
{
    int largest = i;   // Initialize largest as root 
    int L = 2 * i + 1; // Left = 2*i + 1
    int R = 2 * i + 2; // Right = 2*i + 2

    // If Left child is larger than root 
    if ( L < n && (arr[L] > arr[largest]) ) 
        largest = L; 
  
    // If Right child is larger than largest so far 
    if (R < n && arr[R] > arr[largest]) 
        largest = R; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
}

/* 
   Build Max Heap
   Rearrange Heap from leafs to root

   Last non-leaf node = parent of last-node.
   or, Last non-leaf node = parent of node at (n-1)th index.
   or, Last non-leaf node = Node at index ((n-1) - 1)/2.
   = (n/2) - 1.
*/ 

void Build_Max_Heap(int* arr , int n)
{
    for (int Idx = (n/2) - 1 ; Idx >= 0; Idx--)
        heapify(arr , n , Idx);
}