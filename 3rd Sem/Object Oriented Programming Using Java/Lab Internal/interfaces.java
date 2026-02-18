interface CircleOps
{
    double Circlearea(double r);
    double CirclePerimeter(double r);
}

interface RectangleOps
{
    double RectangleArea(double l, double w);
    double RectanglePrimeter(double l, double w);
}

interface ShapeOps extends CircleOps, RectangleOps
{
    void displaySummary();
}

class ShapeBase
{
    final double PI = 3.1415;
    String name;
    
    ShapeBase(String name)
    {
        this.name = name;
    }
}

class ShapeCalculator extends ShapeBase implements ShapeOps
{
    ShapeCalculator(String name)
    {
        super(name);
    }

    public double Circlearea(double r)
    {
        return PI*r*r;
    }

    public double CirclePerimeter(double r)
    {
        return 2*PI*r;
    }

    public double RectangleArea(double l, double w)
    {
        return l*w;
    }

    public double RectanglePrimeter(double l, double w)
    {
        return 2*(l + w);
    }

    public void displaySummary()
    {
        System.out.println("Shape : " + name);
    } 
}

class ShapeDemo
{
    public static void getShape(ShapeOps s)
    {
        System.out.print("A general shape initialized " );
        s.displaySummary();
    }

    public static void getCircle(CircleOps c, double r)
    {
        System.out.println("Area : " + c.Circlearea(r));
        System.out.println("Perimeter : " + c.CirclePerimeter(r));
    }

    public static void getRectangle(RectangleOps R, double l, double w)
    {
        System.out.println("Area : " + R.RectangleArea(l,w));
        System.out.println("Perimeter : " + R.RectanglePrimeter(l,w));
    }
}

class interfaces
{
    public static void main(String args[])
    {
        ShapeCalculator obj = new ShapeCalculator("A shape");
        ShapeDemo.getShape(obj);

        ShapeDemo.getCircle(obj, 7);
        ShapeDemo.getRectangle(obj, 5,2);
    }
}