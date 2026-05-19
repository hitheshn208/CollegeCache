import java.util.Scanner;
public class nqueens {
    static int board[][], N;

    static boolean isSafe(int row, int col){
        
        for(int i = 0; i < N; i++) //same column
            if(board[i][col] == 1)
                return false;

        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) //Upper left diagonal
            if(board[i][j] == 1)
                return false;

        for(int i = row, j = col; i >= 0 && j < N; i--, j++) //Upper-right diagonal
            if(board[i][j] == 1)
                return false;
        
        return true;
    }

    static void printbord(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] == 1)
                    System.out.print("Q ");
                else
                    System.out.print(". ");
            }
            System.out.println();
        }

        System.out.println("-----------------------");
    }   

    static void solve(int row)
    {
        if(row == N)
        {
            printbord();
            return;
        }

        for(int col = 0; col < N; col++)
        {
            if(isSafe(row, col)){
                board[row][col] = 1;
                solve(row+1);
                board[row][col] = 0;
            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter value of N: ");
        N = sc.nextInt();

        board = new int[N][N];

        solve(0);

        sc.close();
    }
}
