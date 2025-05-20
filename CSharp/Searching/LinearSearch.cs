using System;

/*

Linear Search algorithm iterates over each element in the array, one by one, to check if it matches the element. 
If a match is found, it returns the index of the element. 
If the loop completes without finding the element, it returns -1 to indicate that the element is not in the array.

*/

public class LinearSearch
{
    public static int Search(int[] arr, element)
    {
        int n = arr.Length;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] == element) return i; // Element found, return its index
        }

        return -1; // Element not found
    }
}