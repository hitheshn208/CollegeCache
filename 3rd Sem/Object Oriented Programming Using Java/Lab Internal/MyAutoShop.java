class Car 
{
    int speed;
    double regularprice;
    String color;

    Car(int speed, double regularprice, String color)
    {
        this.speed = speed;
        this.regularprice = regularprice;
        this.color = color;
    }

    double getSalePrice()
    {
        return regularprice;
    }
}

class Truck extends Car
{
    int weight;
    
    Truck (int speed, double regularprice, String color, int weight)
    {
        super(speed, regularprice, color);
        this.weight = weight;
    }

    double getSalePrice()
    {
        if(weight > 2000)
        {
            return (super.getSalePrice() * 0.90);
        }
        else
        {
            return (super.getSalePrice() * 0.80);
        }
    }

    
}

class Ford extends Car
{
    int year, manufacturerDiscount;

    Ford(int speed, double regularprice, String color, int year, int manufacturerDiscount)
    {
        super(speed, regularprice, color);
        this.year = year;
        this.manufacturerDiscount = manufacturerDiscount;
    }

    double getSalePrice()
    {
        return (super.getSalePrice() - manufacturerDiscount);
    }
}

class Sedan extends Car
{
    int length;

    Sedan(int speed, double regularprice, String color, int length)
    {
        super(speed, regularprice, color);
        this.length = length;
    }

    double getSalePrice()
    {
        if(length > 20)
            return (super.getSalePrice() * 0.95);
        else
            return (super.getSalePrice() * 0.90 );
    }
}

class MyAutoShop
{
    public static void main(String srgs[])
    {
        Car c = new Car(100, 1000000, "Gold");
        Truck t = new Truck(75, 5000000, "Grey", 3500);
        Ford f = new Ford(150, 2000000, "White", 2020, 50000);
        Sedan s = new Sedan(125, 1500000, "Black", 25);

        System.out.println(c.getSalePrice());
        System.out.println(t.getSalePrice());
        System.out.println(f.getSalePrice());
        System.out.println(s.getSalePrice());

    }
}