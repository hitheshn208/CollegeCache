import java.util.*;
class primsAlgo{
    // public static void primsMST(int graph[][], int V)
    // {
    //     int key[] = new int[V];
    //     boolean mstSet[] = new boolean[V];
    //     int parent[] = new int[V];

    //     Arrays.fill(key, 999);
    //     key[0] = 0;
    //     parent[0] = -1;

    //     for(int count = 0 ; count < V-1; count++){
    //         int min = 999;
    //         int u = -1;

    //         for(int i = 0; i<V;i++)
    //         {
    //             if(!mstSet[i] && key[i] < min)
    //             {
    //                 min = key[i];
    //                 u = i;
    //             }
    //         }

    //         mstSet[u] = true;

    //         for(int v = 0; v<V; v++)
    //         {
    //             if(graph[u][v]!=0 && !mstSet[v] && graph[u][v] < key[v])
    //             {
    //                 key[v] = graph[u][v];
    //                 parent[v] = u;
    //             }
    //         }
    //     }

    //     System.out.println("Edge \tWeight");
    //     int cost = 0;
    //     for(int i = 1; i<V; i++)
    //     {
    //         System.out.println(parent[i] + " - " + i + "\t" + key[i]);
    //         cost += key[i];
    //     }
    //     System.out.println("Minimum cost is " + cost);

    // }

    public static void primsMST(int graph[][], int V){
        int key[] = new int[V]; 
        boolean mst[] = new boolean[V]; 
        int parent[] = new int[V];
        
        Arrays.fill(key, 999);
        parent[0] = -1;
        key[0] = 0;

        for(int count = 0; count < V-1; count++){
            int u = -1;
            int min = 999;

            for(int i = 0; i < V; i++)
            {
                if(!mst[i] && key[i] < min){
                    min = key[i];
                    u = i;
                }
            }

            mst[u] = true;

            for(int j = 0; j < V; j++)
            {
                if(graph[u][j] != 0 && graph[u][j] != 999 && !mst[j] && key[j] > graph[u][j])
                {
                    key[j] = graph[u][j];
                    parent[j] = u;
                }
            }
        }

        int cost = 0;
        System.out.println("\nEdge\tWeight");
        for(int i = 1; i < V; i++)
        {
            System.out.println(parent[i] + " - " + i + "\t" + key[i]);
            cost += key[i];
        }
        System.out.println("Minimum cost is " + cost);
    }

    public static void main(String args[])
    {
        // Scanner sc = new Scanner(System.in);
        // int V;
        // // int graph[][], V;
        // System.out.print("Enter the number of vertices : ");
        // V = sc.nextInt();
        // int graph[][] = new int[V][V];
        // System.out.println("Enter the adjacency matrix : ");
        // for(int i = 0; i<V; i++)
        //     for(int j = 0; j<V; j++)
        //         graph[i][j] = sc.nextInt();
int graph[][] = {
    {0,7,3,12,0},
    {7,0,0,0,9},
    {3,0,0,0,7},
    {12,0,0,0,5},
    {0,9,7,5,0}
};
        primsMST(graph, 5);
    }
}