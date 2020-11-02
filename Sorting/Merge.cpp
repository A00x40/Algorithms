/* 
  Merges two subarrays of arr[].
  First subarray is arr[l..m]
  Second subarray is arr[m+1..r]
*/
void merge(int* arr , int Left , int middle , int Right)
{
    int Left_arr_Length = middle - Left + 1;
    int Rigth_arr_Length = Right - middle ;

    // Temp Arrays
    int Left_arr[ Left_arr_Length ];
    int Right_arr[ Rigth_arr_Length ];
   
    // Copy data to temp arrays Left_arr and Right_arr
    for(int i=0 ; i < Left_arr_Length ; i++)
    {
        Left_arr[i] = arr[ Left+i ];
    }
    for(int j=0 ; j < Rigth_arr_Length ; j++)
    {
        Right_arr[j] = arr[ middle+1+j ];
    }

    int i = 0 , j = 0 , k = Left;
    while(i < Left_arr_Length && j < Rigth_arr_Length)
    {
        if ( Left_arr[i] <= Right_arr[j]) 
        {
            arr[k] = Left_arr[i];
            i++;
        }
        else
        {
            arr[k] = Right_arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of Left_arr if there are any 
    while( i < Left_arr_Length)
    {
        arr[k] = Left_arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of Right_arr if there are any 
    while( j < Left_arr_Length)
    {
        arr[k] = Right_arr[j];
        j++;
        k++;
    }
}

void mergeSort(int* arr , int Left , int Right)
{
    if( Left < Right )
    {
        int middle = Left + ( Right-Left ) / 2;

        mergeSort( arr , Left , middle );
        mergeSort( arr , middle+1 , Right );

        merge( arr , Left , middle , Right );
    }
}

// Initial Call
mergeSort(arr, 0, arr_size - 1);
