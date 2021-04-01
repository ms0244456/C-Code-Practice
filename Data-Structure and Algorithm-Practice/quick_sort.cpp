//quick sort
//O(n) = nlog(n)
#include<iostream>
#include<time.h>   
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int *arr, int left, int right)
{  
    int pivot,i,j;
    //if L has not passed R 
    if(left < right)
    {
        pivot = arr[left];  //pivot = the leftest element
        i = left;   //assign L to i
        j = right;  //assign R to j
    
        while(i < j) //while i has not passed j 
        {
            //i go next(->) while i not pass the right bound and pivot is still smaller than the i's element
            while( i <= right && pivot < arr[i])
            {
                i++;
            }
            //j go next(<-) while j not pass the left bound and pivot is still bigger than the j's element
            while( j >= left && pivot > arr[j])
            {
                j--;
            }
            //means there are 1 element in j is smaller than pivot and 1 element in i is bigger than pivot,thus swap these two element  
            if(i < j)
            {
                swap(arr[i],arr[j]);
            }   
        }
        //if i is righter than j (j(<-) .. i(->)) not(i(->) .... (<-)j),than swap pivot and j's element
        swap(pivot,arr[j]);
        // .....|K|......
        //    ^  --> sort these part
        quicksort(arr,0,j-1);
        // .....|K|......
        //            ^  --> sort these part
        quicksort(arr,j+1,right);
    }
}

int main()
{
    //using time random seed to generate 10 numbers in array
    int arr[10] = {0};
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        arr[i] = rand() % 100;
    }
    //print out the unsorted array
    cout << "排序前: ";
    for(int i=0;i<10;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    //sorting array with quick sort method
    quicksort(arr,0,9);
    //print out the sorted array
    cout << "排序後: ";
    for(int i=0;i<10;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
