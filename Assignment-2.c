/* Author-> Pratham Tagotra.
   CSE(A2).
   Program to calculate execution time diffrence between Bubble Sort and Merg Sort.
   Here i've used adaptive bubble sort which is even more efficient.
*/
#include <stdio.h>
#include <time.h>
#define max 100

int arr[max], size;

void adaptiveBubbleSort();
void mergeSort(int, int);
void merge(int, int, int);
void display();
void input();
int main()
{
    int choice;
    clock_t start_t, end_t;/*clock_t is a typedef of long int and is defined in the time. h header.
    It is used to store the processor time in terms of the number of CPU cycles passed since the start of the process.*/
    double total_t1, total_t2;

    printf("\nHello and Welcome\n");
    do
    {
        printf("Enter 1 for bubble sort\n");
        printf("Enter 2 for merge sort\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            input();
            start_t = clock(); //clock() function to calculate time.
            printf("Array before sorting\n");
            display();
            printf("\n");
            adaptiveBubbleSort();//adaptiveBubble sort function call.
            printf("Array after sorting\n");
            display();
            end_t = clock(); //end_t will store the finishing time. 
            printf("\n");
            printf("\n");
            total_t1 = (double)(end_t - start_t) / CLOCKS_PER_SEC; //Formula to calculate the total time.
            printf("Execution Time=%f\n\n", total_t1);
            break;

        case 2:
            input();
            start_t = clock(); //clock() function to calculate time
            printf("Array before sorting\n");
            display();
            printf("\n");
            mergeSort(0, size-1);//mergeSort function call.
            printf("Array after sorting\n");
            display();
            end_t = clock(); //end_t will store the finishing time of the execution.
            printf("\n");
            printf("\n");
            total_t2 = (double)(end_t - start_t) / CLOCKS_PER_SEC;//Formula to calculate the total time.
            printf("Execution Time=%f\n\n", total_t1);
            break;

        case 3:
            printf("You have sucessfully exited the program\n");
            break;

        default: printf("Please enter a valid choice\n");//default case.
            break;
        }
    } while (choice != 3);
}

void input(){
    printf("Enter the total numnber you want to enter-> ");
    scanf("%d",&size);
    printf("Enter the elements-> ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}

void display(){ //Diplay function.
    printf("Elements are-> ");
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}

void adaptiveBubbleSort() //Its adaptive bubble sort.
{
    int temp;
    int presorted = 0;
    for (int i = 0; i < size - 1; i++)
    {
        // printf("\nWorking on pass number %d\n", i + 1);
        presorted = 1;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                presorted = 0;
            }
        }
        if (presorted==1)
        {
            break;
        }
    }
}

void merge(int low, int mid, int high){ //merge() function.
    int i,j,k,b[max];
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high){
        if(arr[i] < arr[j]){
            b[k] = arr[i];
            i++;
            k++; 
        }
        else{
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        b[k] = arr[i];
        i++;
        k++;
    }
    while(j<=high){
        b[k] = arr[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = b[i];
    }
}

void mergeSort(int low, int high){ //mergeSort() function.
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(low,mid);
        mergeSort(mid+1,high);
        merge(low,mid,high);
    }
}
/*  Q: Which algorithm is faster and why? (Write a complete explanation using comment line into the same .c program file)
    Ans:  Best case time complexity of merge sort is O(n log n) and that of bubble sort is O(n).
          Here in my testing both performed equally but as soon as the input grows Merge Sort comes out on top.
          Whereas Bubble Sort is faster for small sets of data Merge Sort is faster and way more efficient for 
          large sets of data. */