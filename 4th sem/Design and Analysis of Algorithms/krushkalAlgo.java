import java.util.*;

class krushkalAlgo{
    static int find(int parent[], int i)
    {
        while(parent[i] != i)
            i = parent[i];
        return i;
    }

    static void union(int parent[], int x, int y)
    {
        parent[x] = y;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int V = sc.nextInt();

        int graph[][] = new int[V][V];

        System.out.println("Enter adjacency matrix (0 for self loop, 999 - if no edge):");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = sc.nextInt();
            }
        }

        int parent[] = new int[V];
        for(int i = 0; i<V; i++)
            parent[i] = i;

        int edges = 0, cost = 0;

        while(edges < V-1)
        {
            int min = 999;
            int u = -1, v = -1;

            for(int i = 0; i<V; i++)
                for(int j = 0; j<V; j++)
                {
                    if(graph[i][j] != 0 && graph[i][j] < min)
                    {
                        int pu = find(parent, i);
                        int pv = find(parent, j);
                        if(pu != pv)
                        {
                            min = graph[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }

            if(u==-1 || v==-1)
                break;

            System.out.println(u + " - " + v + " weight : " + min);
            union(parent, find(parent, u), find(parent, v));
            cost += min;
            edges++;
        }

        if (edges != V - 1) {
            System.out.println("No Spanning Tree exists (Graph is disconnected)");
        } else {
            System.out.println("Total cost = " + cost);
        }

        sc.close();
    }
}