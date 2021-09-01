long long mergeSortedArrays(long long* arr, int start, int mid, int end)
{
    long long countInversion = 0;
    int i = start, j = mid + 1, k = 0;
    
    long long* tempArr = new long long[end - start + 1];
    
    while (i <= mid && j <= end)
    {
        if (arr[i] > arr[j])
        {
            tempArr[k] = arr[j];
            countInversion += mid + 1 - i;
            j++;
        }
        else
        {
            tempArr[k] = arr[i];
            i++;
        }
        
        k++;
    }
    
    while (i <= mid)
        tempArr[k++] = arr[i++];

    while (j <= end)
        tempArr[k++] = arr[j++];
    
    for (i=start;i<=end;i++)
    {
        arr[i] = tempArr[i - start];
    }
    
    return countInversion;
}

long long mergeSort(long long* arr, int start, int end)
{
    if (start >= end)
        return 0;
    
    int mid = start + (end - start)/2;
    
    long long leftInversion = mergeSort(arr, start, mid);
    long long rightInversion = mergeSort(arr, mid+1, end);
    
    long long mergeInversion = mergeSortedArrays(arr, start, mid, end);
    
    return leftInversion + rightInversion + mergeInversion;
}

long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, 0, n-1);
}
