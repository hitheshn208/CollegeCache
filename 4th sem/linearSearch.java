import java.util.Scanner;

class linearSearchLogic
{
	int arr[], size;
	Scanner sc = new Scanner(System.in);

	void getArray(){
		System.out.println("Enter the number of elements :");
		size = sc.nextInt();
		try{
			arr = new int[size];

			System.out.print("Enter the elements : ");
			for(int i = 0; i<size; i++)
				arr[i] = sc.nextInt();
		}
		catch (NegativeArraySizeException e){
			System.out.println("Negative size not accepted");
			this.getArray();
		}	       
	}

	void search(){
		System.out.print("Enter the element to search : ");
		int key = sc.nextInt();

		for(int i = 0; i<size; i++){
			if(arr[i] == key){
				System.out.println("Key found at the index " + i);
				return;
			}
		}

		System.out.println("Key not found");
		return;
	}
}

class linearSearch
{
	public static void main(String args[])
	{
		linearSearchLogic obj = new linearSearchLogic();
		obj.getArray();
		obj.search();
	}
}
