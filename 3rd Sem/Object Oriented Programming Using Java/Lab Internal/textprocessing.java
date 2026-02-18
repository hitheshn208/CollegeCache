import java.util.*;

class stringOp
{
    String name;
    Scanner sc = new Scanner(System.in);

    void getString()
    {
        System.out.print("Enter the main String : ");
        this.name = sc.nextLine();
    }

    void getCharAtpos()
    {
        System.out.print("Enter the position of the char you want to get : ");
        int n = sc.nextInt();

        if(n-1 >= name.length())
        {
            System.out.println("Index is greater than String length");
            return;
        }

        System.out.println("The character at pos "  + n  + " is " + name.charAt(n-1));
        return;
    }

    void compareStrings()
    {
        String str;
        System.out.println("Enter the keyWord : ");
        str = sc.nextLine();

        int x = name.compareToIgnoreCase(str);

        if(x > 0)
        {
            System.out.println("Occurs before the main string");
            return;
        }
        else if(x < 0)
        {
            System.out.println("Occurs after the main String");
            return;
        }
        else
        {
            System.out.println("Both Strings are equal");
        }

    }

    void SubString()
    {

        System.out.println("Enter the keyword");
        String key = sc.nextLine();

        if(name.indexOf(key) == -1)
        {
            System.out.println("Keyword is not present in the main string");
            return;
        }

        System.out.println("The keyword was foud at the index " + name.indexOf(key));

        System.out.print("Enter the word that you want to replace with " + key + " : ");
        String newStr = sc.nextLine();

        System.out.println("Replaced word is " + name.replace(key, newStr));
    }

    void Extractword()
    {

        System.out.print("Enter the start ans end position of the word you want to extract ");
        int start = sc.nextInt();
        int end = sc.nextInt();

        System.out.println("The substring is " + name.substring(start, end));
    }
}

class textprocessing
{
    public static void main(String args[])
    {
        int choice;
        Scanner sc = new Scanner(System.in);

        stringOp obj = new stringOp();
        obj.getString();


        while(true)
        {
            System.out.println("\n--String Menu--");
            System.out.println("1. View character at position");
            System.out.println("2. Compare string");
            System.out.println("3. Search for keyword");
            System.out.println("4. Extract string");
            System.out.println("5. Exit");
            System.out.print("Enter your choice : ");
            choice = sc.nextInt();

            switch(choice)
            {
                case 1 : 
                    obj.getCharAtpos();
                    break;
                case 2 : 
                    obj.compareStrings();
                    break;
                case 3 : 
                    obj.SubString();
                    break;
                case 4 : 
                    obj.Extractword();   
                    break;
                case 5 : return;
                default : System.out.println("Invalid choice");

            }
        }
    }
}