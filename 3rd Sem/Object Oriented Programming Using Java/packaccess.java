import arithmaticpackage.*;

class packaccess
{
    public static void main(String args[])
    {
        addition a = new addition();
        subtraction s = new subtraction();

        System.out.println("Sum is " + a.sum(10.23,20.11));
        System.out.println("Difference is " + s.difference(45, 56));

    }
}