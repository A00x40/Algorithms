using System;

/*

Insertion Sort is a simple comparison-based sorting algorithm that builds the sorted array one element at a time. 
It is much like sorting a hand of playing cards, where you take one card at a time and insert it into its correct position in a sorted subset of the deck.

It works by dividing the array into two parts:
Sorted part: The portion of the array that has already been sorted.
Unsorted part: The portion of the array that still needs to be sorted.

Initially, the sorted part contains just the first element of the array, and the unsorted part contains the rest. 
The algorithm iterates over the unsorted part, selecting one element at a time, and inserts it into its correct position in the sorted part.

*/

public class InsertionSort
{
    public static void Sort(int[] arr)
    {
        int n = arr.Length;
        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            int currentItem = arr[i];

            // Shift elements that are greater than currentItem one position to the right
            while(j >= 0 && arr[j] > currentItem)
            {
                // Right shift
                arr[j + 1] = arr[j];
                j--;
            }

            // Put currentItem at its correct position in sorted part
            arr[j + 1] = currentItem;
        }
    }
}