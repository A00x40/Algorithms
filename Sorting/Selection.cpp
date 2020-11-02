void Selection(int* arr , int n)
{
    for(int i=0 ; i < n-1 ; i++)
    {
        int min_idx = i;
        for(int j=i+1 ; j < n ; j++)
        {
            if(arr[j] < min_idx)
                min_idx = j;
        }

        swap(arr[i] , arr[min_idx]);
    }
}