#include <QCoreApplication>
#include <iostream>
#include  <ctime>
#include "windows.h"
#include <ctime>
#include <cstdlib>
#include "cstdio"
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <fstream>

using namespace std;
void checkdo(int arr[], int i)
{
    for (int j=0;j<i;j++)
    {
        cout <<arr[j]<<endl;

    }
    cout << "endrandom"<<endl;
}
void checkposle (int arr[],int i)
{
    for (int j=0;j<i;j++)
    {
        cout <<arr[j]<<endl;

    }
    cout << "endsort"<<endl;
}
/////
void swapEl(int *arr, int i)
{
 int buff;
 buff = arr[i];
 arr[i] = arr[i - 1];
 arr[i - 1] = buff;
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void random (int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
}
////////////////////////////////
void bubble_sort(int arr[], int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j< n - i -1 ; j++)
        {
            if (arr[j]  > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }

}
void insert_sort (int arr[],int n)
{
 for(int i=1; i<n; i++)
 {
     int k =i;
     while (k > 0 && arr[k-1]> arr[k])
     {
         swap (&arr[k-1],&arr[k]);
         k-=1;
     }
 }
}
void select_sort(int arr[],int n)
{
    int minj=0;
    for(int i=0;i<n-1;i++)
    {
       minj=i;
       for(int j=i+1;j< n;j++)
       {
           if(arr[j]<arr[minj])
             minj=j;
               swap(&arr[i],&arr[minj]);
       }
    }
}
void qsort(int *mas, int size)
{
       int i = 0;
       int j = size - 1;
       int mid = mas[size / 2];
       do {

           while(mas[i] < mid) {
               i++;
           }
           while(mas[j] > mid) {
               j--;
           }
           if (i <= j) {
               int tmp = mas[i];
               mas[i] = mas[j];
               mas[j] = tmp;

               i++;
               j--;
           }
       } while (i <= j);



       if(j > 0) {
           //"Левый кусок"
           qsort(mas, j + 1);
       }
       if (i < size) {
           //"Првый кусок"
           qsort(&mas[i], size - i);
       }

}
void Merge(int arr[], int minIndex, int middleIndex, int maxIndex) {
    int left = minIndex;
    int right = middleIndex + 1;
    int count = maxIndex - minIndex + 1;
    int *tempArray= new  int[maxIndex+1];
    int index = 0;

    while ((left <= middleIndex) && (right <= maxIndex))
    {
        if (arr[left] < arr[right])
        {
            tempArray[index] = arr[left];
            left++;
        }
        else
        {
            tempArray[index] = arr[right];
            right++;
        }

        index++;
    }

    for (int i = left; i <= middleIndex; i++)
    {
        tempArray[index] = arr[i];
        index++;
    }

    for (int i = right; i <= maxIndex; i++)
    {
        tempArray[index] = arr[i];
        index++;
    }

    for (int i = 0; i < count; i++)
    {
        arr[minIndex + i] = tempArray[i];
    }
delete []tempArray ;
}
void myShaker_sort(int *arr, int size)
{
 int leftMark = 1;
 int rightMark = size - 1;
 while (leftMark <= rightMark)
 {
 for (int i = rightMark; i >= leftMark; i--)
 if (arr[i - 1] > arr[i]) swapEl(arr, i);
 leftMark++;


 for (int i = leftMark; i <= rightMark; i++)
 if (arr[i - 1] > arr[i]) swapEl(arr, i);
 rightMark--;

 }
}
void gnomesort(int* l, int* r) {
    int *i = l;
    while (i < r) {
        if (i == l || *(i - 1) <= *i) i++;
        else swap(*(i - 1), *i), i--;
    }
}
void MergeSort(int arr[], int minIndex, int maxIndex) {
    if (minIndex < maxIndex) {
        int middleImdex = (minIndex + maxIndex) / 2;
        MergeSort(arr, minIndex, middleImdex);
        MergeSort(arr, middleImdex + 1, maxIndex);
        Merge(arr, minIndex, middleImdex, maxIndex);
    }
}
int main(int argc, char *argv[])
{
    FILE* f1;
    f1= fopen("all.dat","w");
    QCoreApplication a(argc, argv);
    srand(time(0));
    for (int i=100;i<150000;i+=10000)
    {
      int* arr = new int[i];

      random(arr,i);
      long int time = GetTickCount64();
      bubble_sort(arr,i);
      time= (GetTickCount64() - time);
      fprintf(f1,"%d\t%d",i,time);

      random(arr,i);
      time = GetTickCount();
      insert_sort(arr,i);
      time= (GetTickCount64() - time);
      fprintf(f1,"\t%d",time);

      random(arr,i);
        time = GetTickCount();
       select_sort(arr,i);
       time= (GetTickCount64() - time);
       fprintf(f1,"\t%d",time);

       random(arr,i);
       time = GetTickCount(); time = GetTickCount();
        qsort(arr,i);
        time= (GetTickCount64() - time);
        fprintf(f1,"\t%d" ,time);


        random(arr,i);
         time = GetTickCount();
         MergeSort(arr,0,i-1);
         time= (GetTickCount64() - time);
          fprintf(f1,"\t%d",time);

         random(arr,i);
          time = GetTickCount();
          myShaker_sort(arr,i);
          time= (GetTickCount64() - time);
          fprintf(f1,"\t%d",time);


          random(arr,i);
           time = GetTickCount();
           gnomesort(arr,arr+i);
           time= (GetTickCount64() - time);
           fprintf(f1,"%d\t%d\n",i ,time);

         cout << i<< endl;



      delete [] arr;

    }
   fclose(f1);
    return 0;
}
