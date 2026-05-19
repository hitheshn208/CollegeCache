public class horspool {

    static int[] shiftTable(String pattern){
        int table[] = new int[256];

        int n = pattern.length();

        for(int i = 0; i < 256; i++)
            table[i] = n;

        for(int i = 0; i<n-1; i++)
            table[(int)pattern.charAt(i)] = n-1-i;

        return table;
    }

    static int horspoolalgo(String text, String pattern){
        int n = pattern.length();
        int m = text.length();
        int table[] = shiftTable(pattern);

        int i = n-1;
        while (i < m) {
            int k = 0;
            // System.out.println("Came Here 1");
            
            while(k < n && pattern.charAt(n-1-k) == text.charAt(i-k)){
                k++;
                // System.out.println("Came here 2");
            }

            if(k==n)
                return i-n+1; 

            i += table[text.charAt(i)];
        }

        return -1;
    }

    public static void main(String[] args) {

        String text = "COMPUTER SCIENCE AND ENGINEERING";
        String pattern = "ENGINE";

        int pos = horspoolalgo(text, pattern);

        if (pos != -1)
            System.out.println("Pattern found at position: " + pos);
        else
            System.out.println("Pattern not found");
    }
}
