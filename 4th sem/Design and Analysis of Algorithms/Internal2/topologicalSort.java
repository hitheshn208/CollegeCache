import java.util.*;

public class topologicalSort {
    static int graph[][];
    static boolean visited[];
    static Stack <Integer> stack = new Stack<>();
    static int V;

    static void getGraph(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of vertices : ");
        V = sc.nextInt();
        graph = new int[V][V];
        visited = new boolean[V];
        System.out.println("Enter the Adjacency matrix : ");
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                graph[i][j] = sc.nextInt();

        sc.close();
    }

    static void topological(){
        for(int i = 0; i < V; i++)
            if(!visited[i])
                dfs(i);

        System.out.print("Topological Sorting : ");
        while(!stack.isEmpty())
            System.out.print(stack.pop() + " ");
    }

    static void dfs(int node)
    {
        visited[node] = true;

        for(int i = 0; i < V; i++)
            if(graph[node][i] == 1 && !visited[i])
                dfs(i);

        stack.push(node);
    }

    public static void main(String args[]){
        getGraph();
        topological();
    }
}
