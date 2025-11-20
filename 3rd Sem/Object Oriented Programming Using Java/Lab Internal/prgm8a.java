class outer
{
    void display()
    {
        System.out.println("In outer class");
    }

    class Inner
    {
        void display()
        {
            System.out.println("In inner class");
        }
    }
}

class prgm8a
{
    public static void main(String args[])
    {
        outer OuterObj = new outer();
        OuterObj.display();

        outer.Inner innerObj = OuterObj.new Inner();
        innerObj.display();
    }
}