abstract class Car
{
    long price;

    Car(long price)
    {
        this.price = price;
    }

    abstract long getSalesPrice();
}

class Truck extends Car
{
    int weight;

    Truck (long Price, int weight)
    {
        super(Price);
        this.weight = weight;
    }

    long getSalesPrice()
    {
        if(weight > 2000)
            return price - (price*10)/100;
        else
            return price - (price*15)/100;
    }
}

class prgm5a
{
    public static void main(String args[])
    {
        Car obj = new Truck(80000,3000);
        System.out.println(obj.getSalesPrice());
    }
}