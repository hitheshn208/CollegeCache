class MyPoint
{
    int x,y;

    MyPoint()
    {
        this.x = 0;
        this.y = 0;
    }

    MyPoint(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    void setXY(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    int[] getXY()
    {
        int[] co = {this.x, this.y};
        return co;
    }

    public String toString()
    {
        String str = " (" + this.x +  ", " + this.y + ") ";
        return str;
    }

    double distance(int x, int y)
    {
        return (double)Math.sqrt( (this.x - x) * (this.x - x) + (this.y - y) * (this.y - y) );
    }

    double distance(MyPoint obj)
    {
        return (double)Math.sqrt( (this.x - obj.x) * (this.x - obj.x) + (this.y - obj.y) * (this.y - obj.y) );
    }

    double distance()
    {
        return (double)Math.sqrt( (this.x ) * (this.x) + (this.y) * (this.y) );
    }
}

class coordinates
{
    public static void main(String args[])
    {
        MyPoint c1 = new MyPoint();
        MyPoint c2 = new MyPoint(5,6);

        c1.setXY(3,2);

        System.out.printf("\nDistance between (0, 0) and %s is %.3f\n", c1, c1.distance());
        System.out.printf("Distance between %s and %s is %.3f \n", c1, c2, c1.distance(c2));
        System.out.printf("Distance between (9, 10) and %s is %.3f\n",c1, c1.distance(9,10));
    }
}