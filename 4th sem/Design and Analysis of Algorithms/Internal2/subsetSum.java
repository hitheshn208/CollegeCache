import java.util.Scanner;

public class subsetSum {
    static int target;
    static int set[];

    static void subset(int index, int currentSum, String subsetStr)
    {
        if(currentSum == target)
        {
            System.out.println("Subset : " + subsetStr);
            return;
        }

        if(index == set.length || currentSum > target)
            return;

        subset(index+1, currentSum, subsetStr);
        subset(index+1, set[index] + currentSum, subsetStr + set[index] + " ");
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements : ");
        int n = sc.nextInt();

        set = new int[n];
        System.out.print("Enter the set : ");
        for(int i = 0; i < n ; i++)
            set[i] = sc.nextInt();

        System.out.print("Enter the target sum : ");
        target = sc.nextInt();

        subset(0,0,"");
        sc.close();
    }
}
