import java.util.*;

class prgm4a
{
    public static void main(String args[])
    {
        int N = Integer.parseInt(args[0]);
        Scanner sc = new Scanner(System.in);
        int A[][] = new int [N][N];
        int B[][] = new int [N][N];

        System.out.println("Enter the elements of matrix 1");

        for( int i = 0; i<N ; i++)
        {
            for(int j = 0 ; j<N ; j++)
            {
                A[i][j] = sc.nextInt();
            }
            System.out.println();
        }


        System.out.println("Enter the elements of matrix 2");

        for( int i = 0; i<N ; i++)
        {
            for(int j = 0 ; j<N ; j++)
            {
                B[i][j] = sc.nextInt();
            }
            System.out.println();
        }

        System.out.println("Sum of the matrices is ");
        
        for( int i = 0; i<N ; i++)
        {
            for(int j = 0 ; j<N ; j++)
            {
                System.out.print((A[i][j] + B[i][j]) + " ");
            }
            System.out.println();
        }
    }
}