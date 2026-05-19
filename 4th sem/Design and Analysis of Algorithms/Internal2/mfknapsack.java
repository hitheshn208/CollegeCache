import java.util.*;
public class mfknapsack{
    static int weight[], value[], table[][], W;

    static void getInput()
    {
        Scanner sc = new Scanner(System.in);
        int n; 
        System.out.print("Enter total number of items : ");
        n = sc.nextInt();

        System.out.print("Enter the max capacity : ");
        W = sc.nextInt();

        table = new int[n+1][W+1];

        for(int i = 0; i < n+1; i++)
            for(int j = 0; j < W+1; j++)
                table[i][j] = -1;

        weight = new int[n+1];
        value = new int[n+1];

        System.out.println("Enter the weight and value (space seperated) : ");
        for(int i = 1; i < n+1; i++){
            weight[i] = sc.nextInt();
            value[i] = sc.nextInt();
        }

        int profit = memoryFunction(n,W);
        System.out.println("Total profit is : " + profit);
        printSelectedItems(n, W);
        sc.close();
    }

    static int memoryFunction(int i, int j)
    {
        if(table[i][j] > 0)
            return table[i][j];

        if( i==0 || j==0 )
        {
            table[i][j] = 0;
            return table[i][j];
        }

        if( j < weight[i])
            table[i][j] = memoryFunction(i-1, j);
        else
            table[i][j] = Math.max(memoryFunction(i-1,j), value[i] + memoryFunction(i-1, j - weight[i]));

        return table[i][j];
    }

    static void printSelectedItems(int n, int W)
    {
        int i = n;
        int j = W;

        System.out.println("Selected items:");

        while(i > 0 && j > 0)
        {
            if(table[i][j] != table[i-1][j])
            {
                System.out.println("Item " + i);

                j = j - weight[i];
            }

            i--;
        }
    }

    public static void main(String args[])
    {
        long start = System.nanoTime();
        getInput();
        long end = System.nanoTime();
        System.out.println("Total time of execution is " + (end - start)/1000000000 + " seconds ");
        return;
    }

}