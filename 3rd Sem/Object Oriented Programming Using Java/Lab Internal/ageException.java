import java.util.*;

class TooOld extends Exception
{
    TooOld()
    {
        super("Age must be below 45 for registration");
    }
}

class TooYoung extends Exception
{
    TooYoung()
    {
        super("Age must be above 18 for registration");
    }
}

class Employee
{
    Scanner sc = new Scanner(System.in);
    String name;
    int age;

    void getDetails() throws TooOld, TooYoung
    {
        System.out.println("Enter name : ");
        name = sc.nextLine();

        System.out.println("Enter age : ");
        age = sc.nextInt();

        if(age < 18)
            throw new TooYoung();
        else if(age > 45)
            throw new TooOld();
        else
        {
            System.out.println("Employee " + name + " is eligible.");
        }
    }
}

class ageException
{
    public static void main(String args[])
    {
        Employee obj = new Employee();
         
        try{
            obj.getDetails();
        }
        catch(TooOld e)
        {
            System.out.println(e.getMessage());
        }
        catch(TooYoung e)
        {
            System.out.println(e.getMessage());
        }
    }
}