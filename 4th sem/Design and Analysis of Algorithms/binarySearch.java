import java.util.Scanner;

class binarySearchLogic
{
	int arr[], size;
	Scanner sc = new Scanner(System.in);

        void getArray(){
	        System.out.println("Enter the number of elements :");
                size = sc.nextInt();
                try{
                        arr = new int[size];

                        System.out.print("Enter the elements (in sorted order) : ");
                        for(int i = 0; i<size; i++)
                                arr[i] = sc.nextInt();
                }
                catch (NegativeArraySizeException e){
                        System.out.println("Negative size not accepted");
                        this.getArray();
                }
        }

	void Bsearch()
	{
		System.out.print("Enter the key element : ");
		int key = sc.nextInt();

		int low,high,mid;
		low = 0;
		high = size-1;
		mid = (low + high)/2;

		while(low<=high)
		{
			if(arr[mid] == key)
			{
				System.out.println("Key was found at index : " + mid);
				sc.close();
				return;
			}
			else if(arr[mid] < key)
				low = mid+1;
			else if(arr[mid] > key)
				high = mid-1;

			mid = (low+high)/2;
		}

		System.out.println("Key not found");
		sc.close();
	}
}

class binarySearch
{
	public static void main(String args[])
	{
		binarySearchLogic obj = new binarySearchLogic();
		obj.getArray();
		obj.Bsearch();
	}
}
