#include <stdio.h>

int quick_selection(int n, int *ArrList, int k)
{
    if (ArrList == NULL || n <= k)
        return -1;
 
    int start = 0;
    int end      = n - 1;
 
    while (start < end)
    {
        int i = start;
        int j = end;
        int mid = ArrList[(i + j)/2];
 
        while (i < j)
        {
            if(ArrList[i] >= mid)
            {
                int tmp = ArrList[j];
                ArrList[j] = ArrList[i];
                ArrList[i] = tmp;
                j--;
            } else {
                i++;
            }
        }
 
        if (ArrList[i] > mid)
            i--;
 
        if (k <= i)
            end = i;
        else
            start = i + 1;
    }
 
    return ArrList[k];
}

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int arr[n];
	
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int a = quick_selection(n, arr, k-1);
	
	printf("%d", a);
}
