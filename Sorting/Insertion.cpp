// Start From Second Element
for( int i=1 ; i < n ; ++i)
{
    // Store current index value
    int key = arr[i];

    // Compare prev values 
    int j = i-1;
    while(j > -1 && arr[j] > key)
    {
        arr[j+1] = arr[j];
        j--;
    }

    // Put key in its ordered position
    arr[j+1] = key;
}
