import java.util.*;

class topologicalSort
{
	Scanner sc = new Scanner(System.in);
	boolean graph[][];
	int V,E;
	int stack[];
	int top = -1;

	int pop()
	{
		if(top > -1)
			return stack[top--];
	}

	void push(int item)
	{
		if(top < V)
			stack[top++] = item;
	}

	void getGraph()
	{
		System.out.print("Enter the number of vertices : ");
		V = sc.nextInt();
		
		stack = new int[V]
		graph = new boolean[V][V];

		System.out.print("Enter the number of edges :");	
		E = sc.nextInt();

		int i,j;
		System.out.println("Enter the starting and ending vertex (enter vertices with space seperated) : ");
		for(int k = 0; k < E; k++)
		{
			System.out.println("Edge - " + (k+1));
			i = sc.nextInt();
			j = sc.nextInt();
			graph[i][j] = true;
		}
	}

	boolean visited[] = new boolean[V];
	
	void topological_sort(int num)
	{
		if(visited[num]) return;

		for(int i = 0; i<V; i++)
		{
			if(graph[i][num])
			{
				if(!visited[num]){
					visited[num] = true;
					push(num);
				}
				topological_sort(i);
			}
		}

		System.out.print(num + " ");
	}



	void displayGraph()
	{
		System.out.println("Graph " );
		for(int i = 0; i < V; i++)
			for(int j = 0; j < V; j++)
				if(graph[i][j])
					System.out.println( i + " -> " + j);
	}
}

class topologicalSortPrgm{
	public static void main(String args[])
	{
		topologicalSort obj = new topologicalSort();
		obj.getGraph();
		obj.displayGraph();
	}
}
