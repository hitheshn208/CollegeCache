import java.util.*;

class mergeSortClass
{
	int arr[];
	int low, high;
	int size;
	Scanner sc = new Scanner(System.in);

	void getArray()
	{
		System.out.print("Enter the size of the array : ");
		size = sc.nextInt();
		arr = new int[size];

		System.out.println("Enter the elements");
		for(int i = 0; i<size; i++)
			arr[i] = sc.nextInt();
	}

	void mergesort(int low, int high)
	{
		if(low < high)
		{
			int mid = (low+high)/2;
			this.mergesort(low, mid);
			this.mergesort(mid+1, high);
			this.merge(low, mid, high);
		}
		return;
	}

	void merge(int low, int mid, int high)
	{
		int i = low;
		int j = mid+1;
		int temp[] = new int[high - low + 1];
		int k = 0;

		while( i<=mid && j<=high)
		{
			if(arr[i] <= arr[j])
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		
		while(i<=mid)
			temp[k++] = arr[i++];

		while(j<=high)
			temp[k++] = arr[j++];

		for(i = low; i<=high; i++)
			arr[i] = temp[i-low];	
	}

	void display()
	{
		for(int i = 0; i<size; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
		sc.close();
	}
}

class mergeSortPrgm
{
	public static void main(String args[])
	{
		mergeSortClass obj = new mergeSortClass();

		obj.getArray();
		obj.mergesort(0, obj.size-1);
		obj.display();
	}
}


