import java.util.Scanner;

public class galeshapley {
    static int m_list[][];
    static int w_list[][]; 
    static int m_match[];
    static int w_match[];
    static int n, startpoint[];

    static void getPreferences()
    {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter Size : ");
        n = in.nextInt();

        m_list = new int[n][n];
        w_list = new int[n][n];
        w_match = new int[n];
        m_match = new int[n];
        startpoint = new int[n];

        for (int i = 0; i < n; i++) {
            m_match[i] = -1;
            w_match[i] = -1;
            startpoint[i] = 0;
        }

        System.out.println("Enter the preferences of the men : ");
        for (int i = 0; i < n; i++) {
            System.out.printf("p%d\n", i+1);
            for (int j = 0; j < n; j++)
                m_list[i][j] = in.nextInt() - 1;
        }

        System.out.println("Enter the preferences of the woman : ");
        for (int i = 0; i < n; i++) {
            System.out.printf("p%d\n", i+1);
            for (int j = 0; j < n; j++)
                w_list[i][j] = in.nextInt() - 1;
        }

        in.close();
    }

    static boolean ispreferred(int w, int fm, int sm){
        for(int i = 0; i < n; i++)
            if(w_list[w][i] == fm)
                return true;
            else if(w_list[w][i] == sm)
                return false;

            return true;
    }

    static void stableMatch(){
        for(int m = 0; m < n; m++ ){
            if(m_match[m] == -1){
                while(startpoint[m] < n){
                    int preferredWoman = m_list[m][startpoint[m]];

                    if(w_match[preferredWoman] == -1){
                        w_match[preferredWoman] = m;
                        m_match[m] = preferredWoman;
                        startpoint[m]++;
                        break;
                    }else if(ispreferred(preferredWoman, m, w_match[preferredWoman])){
                        int prevman = w_match[preferredWoman];                    
                        m_match[w_match[preferredWoman]] = -1;
                        m_match[m] = preferredWoman;
                        w_match[preferredWoman] = m;
                        startpoint[m]++;
                        m = prevman - 1;
                    }
                    startpoint[m]++;
                }
            }
        }
    }
    public static void printMatch()
    {
        for (int i = 0; i < n; i++)
            System.out.printf("m%d : w%d\n", i + 1, m_match[i] + 1);
    }

    public static void main(String args[]){
        getPreferences();
        stableMatch();
        printMatch();
    }
}
