import java.util.Scanner;
class Match {
    int m_list[][], w_list[][], n;
    int m_match[], w_match[], startpoint[];
    public Match(int n) {
        this.n = n;
        this.m_list = new int[n][n];
        this.w_list = new int[n][n];
        this.w_match = new int[n];
        this.m_match = new int[n];
        this.startpoint = new int[n];
        initialize();
    }
    public void initialize()
    {
        for (int i = 0; i < n; i++) {
            this.m_match[i] = -1;
            this.w_match[i] = -1;
            this.startpoint[i] = 0;
        }
    }
    // Get the preference list of both men and women.
    public void getList(int arr[][])
    {
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < n; i++) {
            System.out.printf("p%d\n", i+1);
            for (int j = 0; j < n; j++)
                arr[i][j] = in.nextInt() - 1;
        }
        return;
    }
    // Calculate the stable match.
    public void getStableMatch() {
        for (int m = 0; m < n; m++) {
            if (this.m_match[m] == -1) {
                while (startpoint[m] < n) {
                    int prefwoman = m_list[m][startpoint[m]];
                    // If the woman is free, accept proposal.
                    if (this.w_match[prefwoman] == -1) {
                        // Both the man and woman are engaged to each other.
                        this.w_match[prefwoman] = m;
                        this.m_match[m] = prefwoman;
                        startpoint[m]++;
                        break;
                    }
                    // If the current man is earlier in the woman's pref list,
                    else if (pref(prefwoman, m, this.w_match[prefwoman])) {
                        System.out.printf("Swapping %d with %d\n", this.w_match[prefwoman], m);
                        int prevman = this.w_match[prefwoman];
                        // Change the woman's partner.
                        this.w_match[prefwoman] = m;
                        // Set free the other man.
                        this.m_match[prevman] = -1;
                        // The current man is engaged and his startpointer goes up.
                        this.m_match[m] = prefwoman;
                        startpoint[m]++;
                        m = prevman - 1; // m++ happens.
                        break;
                    }
                    startpoint[m]++;
                }
            }
        }
    }
    // Print the final stable match.
    public void printMatch()
    {
        for (int i = 0; i < n; i++)
            System.out.printf("m%d : w%d\n", i + 1, this.m_match[i] + 1);
    }
    // Check if the first man is more preferred than the second man in the woman's list.
    public boolean pref(int w, int fm, int sm) {
        for (int i = 0; i < n; i++) {
            if (this.w_list[w][i] == fm)
                return true;
            else if (this.w_list[w][i] == sm)
                return false;
        }
        return false;
    }
}
class galeShapelyDemo {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        System.out.print("Set size: ");
        int n = in.nextInt();

        Match match = new Match(n);

        System.out.println("Mens' Preference List");
        match.getList(match.m_list);

        System.out.println("Womens' Preference List");
        match.getList(match.w_list);

        match.getStableMatch();

        System.out.println("::Stable Match::");
        match.printMatch();

        in.close();
        return;
    }
}