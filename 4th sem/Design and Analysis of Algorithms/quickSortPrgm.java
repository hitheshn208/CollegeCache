import java.util.*;

class quickSort
{
	Scanner sc = new Scanner(System.in);
	int arr[], size;
	void getArrayandSort()
        {
                System.out.print("Enter the size of the array : ");
                size = sc.nextInt();
                arr = new int[size];

                System.out.println("Enter the elements");
                for(int i = 0; i<size; i++)
                        arr[i] = sc.nextInt();

		quicksort(0, arr.length-1);
        }

	void quicksort(int low, int high)
	{
		if(low > high) return;

		int pivot = arr[low];
		int i = low+1;
		int j = high;

		while(i <= j)
		{
			while( i<=high && arr[i] < pivot)
				i++;
			while( j>low && arr[j] > pivot)
				j--;

			if( i < j )
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		int temp = arr[low];
		arr[low] = arr[j];
		arr[j] = temp;

		quicksort(low, j-1);
		quicksort(j+1, high);
	}

	void display()
	{
		for(int x : arr)
			System.out.print(x + " ");
		System.out.println();
	}
}

class quickSortPrgm{
	public static void main(String args[])
	{
		quickSort q = new quickSort();
		q.getArrayandSort();
		System.out.println("Sorted array : ");
		q.display();
	}
}
