import java.util.Scanner;

public class flyodalgo {

    static void floydWarshall(int graph[][], int V)
    {
        for(int k = 0; k < V; k++)
            for(int i = 0; i < V; i++)
                for(int j = 0; j < V; j++)
                    graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);

        System.out.println("All pair shortest path matrix : ");
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                System.out.print(graph[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();

        int[][] graph = new int[V][V];

        System.out.println("Enter adjacency matrix:");
        System.out.println("Use 99999 for INF");

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = sc.nextInt();
            }
        }

        floydWarshall(graph, V);

        sc.close();
    }
}
