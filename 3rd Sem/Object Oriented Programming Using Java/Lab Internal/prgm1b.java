class addition
{
    int Add(int a, int b)
    {
        return a+b;
    }

    int Add(int a, int b, int c)
    {
        return a+b+c;
    }

    double Add(double a, double b)
    {
        return a+b;
    }
}

class prgm1b
{
    public static void main(String args[])
    {
        addition obj = new addition();

        System.out.println("Sum of 5 and 3 is : " + obj.Add(5,3));
        System.out.println("Sum of 3, 5, and 9 is : " + obj.Add(3,5,9));
        System.out.println("Sum of 3.5 and 7.89 is : " + obj.Add(3.5,7.89));     
    }
}