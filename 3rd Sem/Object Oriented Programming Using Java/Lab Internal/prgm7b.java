class Car
{
    double fuel;
    Car(double fuel)
    {
        this.fuel = fuel;
    }

    void showfuel()
    {
        System.out.println("Fuel Level " + fuel);
    }

    void estimate(double fuel, double distance)
    {
        double est = fuel - (0.1*distance);
        System.out.println("Estimated Fuel after the trip is : " + est);
    }

    void update(Car c, double distance)
    {
        c.fuel = c.fuel - (0.13*distance);
        System.out.println("Fuel Updated in the system");
    }
}

class prgm7b
{
    public static void main(String args[])
    {
        Car c1 = new Car(50);

        System.out.println("Before Trip");
        c1.showfuel();

        System.out.println("--Call by value--");
        c1.estimate(c1.fuel, 100);
        System.out.println("After the estimation");
        c1.showfuel();

        System.out.println("--Call by reference--");
        c1.update(c1, 100);
        System.out.println("After the updation");
        c1.showfuel();

    }
}