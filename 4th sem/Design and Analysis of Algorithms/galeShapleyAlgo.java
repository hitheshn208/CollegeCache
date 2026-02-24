import java.util.*;

class galeShapleyAlgo{
	static indexOf(int arr[], int target)
	{
		int i = 0;
		while(i < arr.length)
		{
			if(arr[i] == 
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the number of men or women : ");
		int size = sc.nextInt();

		int man[][] = new int[size][];
		int woman[][] = new int[size][];

		for(int i = 0; i<size; i++)
		{
			man[i] = new int[size];

			for(int j = 0; j<size; j++)
			{
				System.out.print("Enter the preferences of the man "  + i + " : ");
				man[i][j] = sc.nextInt();
			}
		}

                for(int i = 0; i<size; i++)
                {
                        woman[i] = new int[size];

                        for(int j = 0; j<size; j++)
                        {
                                System.out.print("Enter the preferences of the woman "  + i + " : ");
                                woman[i][j] = sc.nextInt();
                        }
                }

		int manPartner[] = new int[size];
		int womanPartner[] = new int[size];

		Arrays.fill(menPartner, -1);
		Arrays.fill(womenPartner, -1);

		int i = 0;
		while(true)
		{
			if(manPartner[i] >= 0)
			{
				i++;
				continue;
			}

			int preference = 0;
			while(preference < size)
			{
				int preferredWoman = man[i][perference]; 
				if(womanPartner[preferredWoman] < 0)
				{
					womanPartner[preferredWoman] = i;
					manPartner[i] = preferredWoman
				}
				else if(womanPartner[preferredWoman] >= 0)
				{


			
			}

	}
}

		
			
