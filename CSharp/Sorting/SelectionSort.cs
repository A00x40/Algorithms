using System;

/*

This sort works by starting at the beginning of the array, 
comparing the first element with the other elements in the array. 
The smallest element is placed in position 0, and the sort then begins again at position 1. 
This continues until each position except the last position has been the starting point for a new loop

*/

public class SelectionSort
{
    public static void Sort(int[] arr)
    {
        int n = arr.Length;
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            int minimum = arr[i];

            for (int j = i + 1; j < n; j++)
            {
                if(minimum > arr[j])
                {
                    minIndex = j;
                    minimum = arr[j];
                }
            }

            // Swap the found minimum element with the element at the current loop starting index i
            if (minIndex != i) 
            {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }
}