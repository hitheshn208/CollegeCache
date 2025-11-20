import java.util.*;

class prgm5b
{
    public static void main(String args[])
    {
        Scanner sc  = new Scanner(System.in);
        int arr[] = new int [10];
        System.out.println("Enter 10 elements :");

        for(int i = 0; i<10; i++)
            arr[i] = sc.nextInt();
        
        for(int i = 0; i<10; i++)
        {
            for(int j=i+1; j<10 ; j++)
                if(arr[i] == arr[j] && arr[i]!=0)
                     arr[j] = 0;
        }

        System.out.println("Array with no duplicate elements");
        for(int i =0 ; i<10 ; i++)
            System.out.print(arr[i] + " ");
    }
}