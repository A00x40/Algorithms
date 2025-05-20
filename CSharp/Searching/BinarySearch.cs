using System;

/*

Binary Search is an efficient algorithm for finding an element in a sorted array. 
It works by repeatedly dividing the search interval in half, reducing the search space until the element is found (or it's determined that the element isn't in the array).

The first steps in the algorithm are to set the lower and upper bounds of the search.
At the beginning of the search, this means the lower and upper bounds of the array. Then, we calculate the midpoint of the array by adding the lower and
upper bounds together and dividing by 2. 

The array element stored at this position is compared to the searched-for value. If they are the same, the value
has been found and the algorithm stops. 

If the searched-for value is less than the midpoint value, a new upper bound is calculated by subtracting 1 from the midpoint. 
Otherwise, if the searched-for value is greater than the midpoint value, a new lower bound is calculated by adding 1 to the midpoint. 

The algorithm iterates until the lower bound equals the upper bound, which indicates the array has been completely searched. 

*/

public class BinarySearch
{
    public static int BinarySearch(int[] arr, int element)
    {
        int lower = 0;
        int upper = arr.Length - 1;
        int mid;

        while (lower <= upper)
        {
            mid = (upper + lower) / 2;

            if (arr[mid] < element)
            {
                lower = mid + 1; // Search the right half
            }
            else if (arr[mid] > element)
            {
                upper = mid - 1; // Search the left half
            }
            else
            {
                return mid; // Element found, return its index
            }
        }

        return -1; // Element not found
    }
}