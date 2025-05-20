using System;

/*

The sort gets its name because values "float like a bubble" from one end of the list to another. 
Assuming you are sorting a list of numbers in ascending order, higher values float to the right whereas lower values float to the left.
This behavior is caused by moving through the list many times, 
comparing adjacent values and swapping them if the value to the left is greater than the value to the right

*/

public class BubbleSort
{
    public static void Sort(int[] arr)
    {
        int n = arr.Length;
        for (int i = 0; i < n - 1; i++)
        {
            // Optimization to stop the algorithm early if no swaps are made in a pass, which will make the algorithm more efficient for nearly sorted arrays.
            bool swapped = false;

            
            /*
                Reason for stop condition being n - 1 - i

                On each pass through the outer loop (i), the largest unsorted element gets placed in its correct position at the end of the array. 
                After the first pass, the largest element is in the last position, after the second pass, the second largest element is in the second-to-last position, 
                and so on. This reduces the number of elements that need to be compared in subsequent passes.
            */
            for (int j = 0; j < n - 1 - i; j++)
            {
                // Comparing adjacent values
                if(arr[j] > arr[j + 1])
                {
                    // Swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                    swapped = true;
                }
            }

            if(!swapped) break;
        }
    }
}