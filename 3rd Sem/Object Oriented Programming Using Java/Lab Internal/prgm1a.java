class Car
{
    private long baseprice;

    Car()
    {}

    Car(long baseprice)
    {
        this.baseprice = baseprice;
    }

    public long getPrice()
    {
        return baseprice;
    }
}

class Ford extends Car
{
    private int tax;
    private long baseprice;

    Ford()
    {}

    Ford(long baseprice, int tax)
    {
        this.baseprice = baseprice;
        this.tax = tax;
    }

    public long getPrice()
    {
        return baseprice + tax;
    }
}

class LuxuryFord extends Ford
{
    private int tax;
    private long baseprice;
    private int luxurylevel;

    LuxuryFord(long baseprice, int tax, int luxurylevel)
    {
        this.baseprice = baseprice;
        this.tax = tax;
        this.luxurylevel = luxurylevel;
    }

    public long getPrice()
    {
        return (baseprice + tax + (luxurylevel*1000));
    }
}

class prgm1a
{
    public static void main(String args[])
    {
        Car c = new Car(80000);
        Ford f = new Ford(80000, 5000);
        LuxuryFord lf = new LuxuryFord(80000, 5000, 5);
        
        Car obj;
        obj = c;
        System.out.println("BasePrice : " + obj.getPrice() + " (1st level of inheritance)");
        obj = f;
        System.out.println("BasePrice + Tax : " + obj.getPrice() + " (2nd level of inheritance)");
        obj = lf;
        System.out.println("BasePrice + tax + Luxury " + obj.getPrice() + " (3rd level of inheritance)");
    }
}