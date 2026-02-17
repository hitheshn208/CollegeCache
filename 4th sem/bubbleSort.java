import java.util.Scanner;

class bubbleSortLogic{
	int arr[];
	int size;
	Scanner sc = new Scanner(System.in);

	void getArray()
	{
		System.out.print("Enter the number of elements : ");
		size = sc.nextInt();
		arr = new int[size];

		System.out.print("Enter the elements : ");
		for(int  i = 0; i < size; i++)
			arr[i] = sc.nextInt();
	}

	void sort()
	{
		for(int i = size - 1; i>=1; i--)
			for(int j = 0; j <= i-1; j++)
			       if(arr[j] > arr[j+1])
			       		swap(j,j+1);
	}

	void swap(int a, int b)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	void display()
	{
		for(int i = 0; i<size; i++)
			System.out.print(arr[i] +" ");
		System.out.println();
	}
}

class bubbleSort{
	public static void main(String args[])
	{
		bubbleSortLogic obj = new bubbleSortLogic();

		obj.getArray();
		obj.sort();
		System.out.print("Sorted array : ");
		obj.display();
	}
}
