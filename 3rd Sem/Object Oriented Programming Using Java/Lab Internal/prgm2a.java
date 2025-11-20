class Car
{
    long price;

    Car(long price)
    {
        this.price = price;
    }

    long getSalePrice()
    {
        return price;
    }
}

class Truck extends Car
{
    int weight;

    Truck(long price, int weight)
    {
        super(price);
        this.weight = weight;
    }

    long getSalePrice()
    {
        return super.getSalePrice() - (100*weight);
    }
}

class prgm2a
{
    public static void main(String args[])
    {
        Truck obj = new Truck(50000, 50);

        System.out.println("Final sales Price : " + obj.getSalePrice());
    }
}