using System;
using System.Collections;

/*

Sieve Of Eratosthenes
The problem involves finding prime numbers. 

This Algorithm involves filtering numbers that are multiples of other numbers, until the only numbers left are primes. 

For example, let’s determine the prime numbers in the set of the first 100 integers. 
We start with 2, which is the first prime. We move through the set removing all numbers that are multiples of 2. 
Then we move to 3, which is the next prime. We move through the set again, removing all numbers that are multiples of 3 and so on.
*/

public class SieveOfEratosthenes
{
    public static void SieveUsingArray(int n)
    {
        // Create an array to mark prime numbers, initialize all elements as 1 (indicating prime)
        int[] arr = new int[n + 1];

        // Mark all as potential primes (1)
        for(int i = 0; i <= n ; i++) { arr[i] = 1 }
        arr[0] = arr[1] = 0;

        /*
            Start from 2 as 0,1 arenot primes
            We don't need to check numbers beyond sqrt(n) because all multiples of numbers 
            larger than sqrt(n) would have already been marked by smaller numbers.
        */
        for(int i = 2; i * i <= n ; i++) 
        { 
            // If i is prime
            if(arr[i] == 1)
            {
                // Mark all multiples of i (starting from i * i) as non-prime (0)
                for(int j = i * i; j <= n ; j += i) { arr[j] = 0 }
            }
        }

        // Printing the prime numbers
        Console.WriteLine($"Primes up to {n}:");
        for (int i = 2; i <= n; i++) if (arr[i] == 1) Console.Write(i + " ");
        Console.WriteLine();
    }

    public static void SieveUsingBitArray(int n)
    {
        BitArray primes = new BitArray(n + 1, true);
        
        primes.Set(0, false);
        primes.Set(1, false);

        
        for(int i = 2; i * i <= n ; i++) 
        { 
            if (primes.Get(i)) 
            {
                for(int j = i * i; j <= n ; j += i) { primes.Set(j, false); }
            }
        }

        // Printing the prime numbers
        Console.WriteLine($"Primes up to {n}:");
        for (int i = 2; i <= n; i++) if (primes.Get(i)) Console.Write(i + " ");
        Console.WriteLine();
    }
}