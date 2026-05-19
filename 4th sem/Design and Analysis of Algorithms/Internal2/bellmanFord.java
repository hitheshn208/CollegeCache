import java.util.Scanner;

public class bellmanFord {
    static int vertices;
    static int graph[][];

    static void printpath(int p[], int i)
    {
        if(i==-1)
            return;
        printpath(p, p[i]);
        System.out.print(i + " -> ");
    }

    static void bellman(int graph[][], int source)
    {
        int n = graph[0].length;
        int d[] = new int [n];
        int p[] = new int [n];
        d[0] = 0;
        p[0] = -1;
        for(int i = 1; i < n; i++)
        {
            d[i] = 999;
            p[i] = -1;
        }

        for(int k = 1; k <= n; k++){
            for(int u = 0; u < n; u++){
                for(int v = 0; v < n; v++){
                    if(graph[u][v] != 0 && (d[v] > graph[u][v] + d[u]))
                    {
                        d[v] = graph[u][v] + d[u];
                        p[v] = u;
                    }
                }
            }
        }

        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(graph[u][v] != 0 && (d[v] > graph[u][v] + d[u]))
                {
                    System.out.println("Negative cycle exists");
                    return;
                }
            }
        }

        System.out.println("Shortest distance");

        for(int i = 0; i < n; i++)
        {
            if(i==source)
                continue;
            printpath(p, i);
            System.out.println(" : " + d[i]);
        }
    }

    static void getInput()
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices : ");
        vertices = sc.nextInt();

        graph = new int[vertices][vertices];

        System.out.println("Enter adjacency matrix:");

        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < vertices; j++)
            {
                graph[i][j] = sc.nextInt();
            }
        }

        System.out.print("Enter source vertex : ");
        int source = sc.nextInt();

        bellman(graph, source);

        sc.close();
    }

    public static void main(String[] args) {
        getInput();
    }

}
