import java.util.Arrays;

public class dijkstra {

    static void printPath(int parent[], int V){
        if(parent[V] == -1){
            System.out.print(V);
            return;
        }

        printPath(parent, parent[V]);
        System.out.print(" -> " + V);
    }

    static void dijkstraAlgo(int graph[][], int V, int src){
        int dist[] = new int [V];
        boolean visited[] = new boolean[V];
        int parent[] = new int [V];

        Arrays.fill(dist, 999);
        dist[src] = 0;
        parent[src] = -1;

        for(int count = 0; count < V; count++){
            int min = 999;
            int u = -1;

            for(int i = 0; i < V; i++)
                if(!visited[i] && dist[i] < min){
                    min = dist[i];
                    u = i;
                }

            visited[u] = true;

            for(int i = 0; i < V; i++)
            {
                if(graph[u][i] != 0 && graph[u][i] != 999 && !visited[i] && dist[i] > dist[u] + graph[u][i]){
                    dist[i] = dist[u] + graph[u][i];
                    parent[i] = u;
                }
            }
        }

        System.out.println("Path\tDistance");
            for(int i = 0; i < V; i++){
                printPath(parent, i);
                System.out.println("\t" + dist[i]);
            }
    }

        public static void main(String args[])
    {
        int graph[][] = {
            {0,3,999,7,8},
            {3,0,1,4,999},
            {999,1,0,2,999},
            {7,4,2,0,3},
            {8,999,999,3,0}
        };

        int V = 5;

        dijkstraAlgo(graph, V, 0);
    }
}
