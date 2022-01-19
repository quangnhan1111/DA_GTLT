#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include<windows.h>
#define MAX 100001

void doctaptin(int a[], int &n)
{
	FILE *FileIn; 
	FileIn = fopen("dulieu.txt", "r");

	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin dulieu.txt");
		getch();
		return;
	}
	fscanf(FileIn, "%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		fscanf(FileIn, "%d", &a[i]);
	}
	fclose(FileIn);
}

int random(int a, int b)
{
   return a + rand()%(b-a+1);
}


void ghitaptin(int &n)
{
	FILE *FileIn; 
	FileIn = fopen("dulieu.txt", "wt");

	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin dulieu.txt");
		getch();
		return;
	}
	fprintf(FileIn,"%d\n",n);
	
	for(int i = 0; i < n; i++)
	{
		 fprintf(FileIn,"%6d",random(0,100000));
	}
	fclose(FileIn);
}


void ghiketqua(int a[], int n)
{
	FILE *FileIn; 
	FileIn = fopen("output.txt", "wt");

	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin output.txt");
		getch();
		return;
	}
	fprintf(FileIn,"%d\n",n);
	
	for(int i = 0; i < n; i++)
	{
		 fprintf(FileIn,"%3d",a[i]);
	}
	fclose(FileIn);
}

void Hienthi(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d\t", a[i]);
	}
}


void Hoanvi(int &x, int &y)
{
	int tam = x;
	x=y;
	y=tam;
}


// tim hieu cac thuat toan sap xep 
// - linear search: O(n)
// - binary search: O(logn)
//---------Sap xep lua chon truc tiep (Selection Sort)----------//

void selection_sort(int a[], int n)
{
	int min;
	for(int i=1;i<=n-1;i++)
	{
		min=i;
		for(int j=i+1;j<=n;j++)
			if(a[j]<a[min])
				min = j;
		Hoanvi(a[min], a[i]);
	}
}

//---------Sap xep chen (Insert Sort)----------//

void insert_sort(int a[], int n)
{
	int pos,x;
	for (int i = 1; i < n; i++)  	// doan a[0] da duoc sap xep
	{
		x = a[i];
		pos = i-1;
		//tim vi tri chen x
		while((pos>=0) && (a[pos]>x)){
			
			//ket hop doi cho cac phan tu se dung sau x trong day moi
			a[pos+1] = a[pos];
			pos--;
		}
		
		//chen x vao day
		a[pos+1] = x;
		
//		for (int j = i; j > 0; j--)
//		{
//			if (a[j]<a[j-1])
//		  {
//				Hoanvi(a[j], a[j-1]);
//		  }
//	  }
  }
}

//---------Sap xep noi bot (Bubble Sort)----------//

void bubble_sort(int a[], int n)
{
	for (int i = 0; i < n-1 ; i++)
	{
		for (int j = n-1 ; j >= i+1; j--)
		{
			if (a[j]<a[j-1])
			{
				Hoanvi(a[j], a[j-1]);
		  }
	  }
  }
}

//---------Sap xep nhanh (Quick Sort)----------//

void quick_sort(int a[], int left, int right)
{
	int trunggian=a[(right+left)/2]; 	// chon phan tu giua lam gia tri moc
	int i=left,j=right;
	
	do
	{
		  while(a[i]<trunggian) i++;
		  while(a[j]>trunggian) j--;
		  if(i<=j)
		  {
			    Hoanvi(a[i], a[j]);
			    i++;
				j--;
		  }
		  
	}while(i<j);
	
	if(left<j)
	{
    	quick_sort(a,left,j);
	}
	if(i<right)
	{
		quick_sort(a,i,right );
	}
}

//---------Sap xep tron (Merge Sort)----------//

void merge(int a[], int x, int y, int z) 
{ 
    int i, j, k; 
    int n1 = y - x + 1; // chieu dai mang 1 
    int n2 =  z - y;    // chieu dai mang 2
  
    int L[n1], R[n2]; 
  
    
    for (i = 0; i < n1; i++) 
        L[i] = a[x + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = a[y + 1+ j]; 
  
    i = 0;
    j = 0;
    k = x; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
} 


void merge_sort(int a[], int x, int z) 
{ 
    if (x < z) 
    { 
        int y = x+(z-x)/2; 
        merge_sort(a, x, y); 
        merge_sort(a, y+1, z); 
        merge(a, x, y, z); 
    } 
}


//int b[MAX], c[MAX];
//
//int min(int x, int y)
//{
//    if (x > y ) return y;
//    return x;
//}
//
//void Merge(int Array[], int nb, int nc, int k)
//{
//    int i, ib, ic, jb, jc, kb, kc;
//    i = ib = ic = 0;
//    jb = jc = 0;
//    while ((0 < nb) && (0 < nc))
//    {
//        kb = min(k, nb);
//        kc = min(k,nc);
//        if (b[ib + jb] <= c[ic + jc])
//        {
//            Array[i++] = b[ib + jb];
//            jb ++;
//            if (jb == kb)
//            {
//                for (; jc < kc; jc++);
//                    Array[i++] = c[ic + jc];
//                ib += kb; ic += kc;
//                jb = jc = 0;
//                nb -= kb; nc -= kc;
//            }
//        }
//        else
//        {
//            Array[i++] = c[ic + jc];
//            jc ++;
//            if (jc == kc)
//            {
//                for (; jb < kb; jb++);
//                    Array[i++] = b[ib + jb];
//                ib += kb; ic += kc;
//                jb = jc = 0;
//                nb -= kb; nc -= kc;
//            }
//        }
//    }
//}
//
//void Merge_Sort_Direct(int Array[], int n)
//{
//    int i, ib, ic; //các ch? s? trên m?ng Array, b, c
//    int k = 1; //d? dài c?a dãy con khi phân ho?ch
//    do
//    {
//        //tách Array thành b và c
//        i = ib = ic = 0;
//        while (i < n)
//        {
//            for (int o = 0; (i < n) && (o < k); o++)
//                b[ib++] = Array[i++];
//            for (int o = 0; (i < n) && (o < k); o++)
//                c[ic++] = Array[i++];
//        }
//        Merge(Array, ib, ic, k);
//        k *= 2;
//    }
//    while (k < n);
//}



//---------Sap xep vun dong (Heap Sort)----------//

void heapify(int a[], int n, int i)  
{ 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    if (l < n && a[l] > a[largest]) 
        largest = l; 
  
    if (r < n && a[r] > a[largest]) 
        largest = r; 
  
    if (largest != i) { 
        Hoanvi(a[i], a[largest]); 
        heapify(a, n, largest); 
    } 
}

void heap_sort(int a[], int n) 
{ 
	// Tao Heap
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(a, n, i); 
   
   // 
    for (int i=n-1; i>=0; i--)  { 
        Hoanvi(a[0], a[i]); 
        heapify(a, i, 0); 
    } 
} 



//---------Sap xep so so (Radix Sort)----------//


int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // output array
    int i, count[10] = {0}; 
   
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    for (i = 0; i <= n-1; i++) 
        arr[i] = output[i]; 
} 
  
 void radix_sort(int arr[], int n) 
{ 
    int m = getMax(arr, n); 
  
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 


//---------Shell Sort----------//

void shell_sort(int arr[], int n) 
{ 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i ++) 
        { 
            int temp = arr[i]; 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            arr[j] = temp; 
        } 
    } 
} 

void menu(){
	
	printf("\n\n\t\t=========================MENU============================\n\n");
	printf("\t\t1. \tSap xep lua chon truc tiep(selection sort).\n");
	printf("\t\t2. \tSap xep chen(insert sort).\n");
	printf("\t\t3. \tSap xep noi bot(bubble sort).\n");
	printf("\t\t4. \tSap xep nhanh(quick sort).\n");
	printf("\t\t5. \tSap xep gop(merge sort).\n");
	printf("\t\t6. \tSap xep vun dong(heap sort).\n");
	printf("\t\t7. \tSap xep co so(radix sort).\n");
	printf("\t\t8. \tShell sort.\n");
	printf("\t\t0. \tThoat\n");
}

int main()
{
	int luachon;
	int n = 1000000; 
	int a[MAX];	
	clock_t start, end;
	double time_use;
	do{
		
		menu();
		printf("\t\t=>\tLua chon thuat toan sap xep: ");
		scanf("%d", &luachon);
		
		switch(luachon){
			case 1: 
				
				ghitaptin(n);
				doctaptin(a,n);
				printf("Mang du lieu dau: \n");
				Hienthi(a,n);
				start = clock();
				selection_sort(a,n);
				end = clock();
				printf("\nMang du lieu sau khi sap xep: \n");
				Hienthi(a,n);
				ghiketqua(a,n);
				time_use = (double)(end - start);
				printf("\nThoi gian thuc hien Selection sort: %5.5f milisecond", time_use);
				break;
			case 2:
				
				ghitaptin(n);
				doctaptin(a,n);
				printf("Mang du lieu dau: \n");
				Hienthi(a,n);
				start = clock();
				insert_sort(a,n);
				end = clock();
				printf("\nMang du lieu sau khi sap xep: \n");
				Hienthi(a,n);
				ghiketqua(a,n);
				time_use = (double)(end - start);
				printf("\nThoi gian thuc hien Insert sort: %5.5f milisecond", time_use);
				break;
			case 3: 
				
				ghitaptin(n);
				doctaptin(a,n);
				printf("Mang du lieu dau: \n");
				Hienthi(a,n);
				start = clock();
				bubble_sort(a,n);
				end = clock();
				printf("\nMang du lieu sau khi sap xep: \n");
				Hienthi(a,n);
				ghiketqua(a,n);
				time_use = (double)(end - start);
				printf("\nThoi gian thuc hien Bubble sort: %5.5f milisecond", time_use);
				break;
			case 4:
				
				ghitaptin(n);
				doctaptin(a,n);
				printf("Mang du lieu dau: \n");
				Hienthi(a,n);
				start = clock();
				quick_sort(a,1,n);
				end = clock();
				printf("\nMang du lieu sau khi sap xep: \n");
				Hienthi(a,n);
				ghiketqua(a,n);
				time_use = (double)(end - start);
				printf("\nThoi gian thuc hien Quick sort: %5.5f milisecond", time_use);
				break;
			case 5: 
				
				ghitaptin(n);
				doctaptin(a,n);
				printf("Mang du lieu dau: \n");
				Hienthi(a,n);
				start = clock();
				//Merge_Sort_Direct(a,n);
				merge_sort(a,1,n);
				end = clock();
				printf("\nMang du lieu sau khi sap xep: \n");
				Hienthi(a,n);
				ghiketqua(a,n);
				time_use = (double)(end - start);
				printf("\nThoi gian thuc hien Merge sort: %5.5f milisecond", time_use);
				break;
			case 6: 
				
				ghitaptin(n);
				doctaptin(a,n);
				printf("Mang du lieu dau: \n");
				Hienthi(a,n);
				start = clock();
				heap_sort(a,n);
				end = clock();
				printf("\nMang du lieu sau khi sap xep: \n");
				Hienthi(a,n);
				ghiketqua(a,n);
				time_use = (double)(end - start);
				printf("\nThoi gian thuc hien Heap sort: %5.5f milisecond", time_use);
				break;
			case 7:
				
				ghitaptin(n);
				doctaptin(a,n);
				printf("Mang du lieu dau: \n");
				Hienthi(a,n);
				start = clock();
				radix_sort(a,n);
				end = clock();
				printf("\nMang du lieu sau khi sap xep: \n");
				Hienthi(a,n);
				ghiketqua(a,n);
				time_use = (double)(end - start);
				printf("\nThoi gian thuc hien Radix sort: %5.5f milisecond", time_use);
				break;
			case 8: 
				
				ghitaptin(n);
				doctaptin(a,n);
				printf("Mang du lieu dau: \n");
				Hienthi(a,n);
				start = clock();
				shell_sort(a,n);
				end = clock();
				printf("\nMang du lieu sau khi sap xep: \n");
				Hienthi(a,n);
				ghiketqua(a,n);
				time_use = (double)(end - start);
				printf("\nThoi gian thuc hien Shell sort: %5.5f milisecond", time_use);
				break;
			case 0:
				printf("Thoat!");
				exit(0);
			default:
				printf("Nhap sai lua chon!");
		}
	} 	while(true);

	getch();
	return 0;
}
