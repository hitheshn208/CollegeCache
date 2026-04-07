import java.util.*;

class topologicalSortPrgm{
    int graph[][];
    boolean visited[];
    Stack<Integer> stack;
    int V;
    Scanner sc = new Scanner(System.in);

    topologicalSortPrgm(int n)
    {
        V=n;
        graph = new int[n][n];
        visited = new boolean[n];
        stack = new Stack<>();
    }

    void getGraph()
    {
        System.out.println("Enter the Adjacency matrix : ");
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                graph[i][j] = sc.nextInt();
    }

    void topologicalSort()
    {
        for(int i = 0; i<V; i++)
            if(!visited[i])
                dfs(i);

        System.out.print("Topological order : ");
        while(!stack.isEmpty())
            System.out.print(stack.pop() + " ");
    }

    void dfs(int node)
    {
        visited[node] = true;

        for(int i = 0; i < V; i++)
            if(graph[node][i]==1 && !visited[i])
                dfs(i);

        stack.push(node);
    }
}

class topologicalSort{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of vertices : ");
        int n = sc.nextInt();
        topologicalSortPrgm obj = new topologicalSortPrgm(n);
        obj.getGraph();
        obj.topologicalSort();
    }
}