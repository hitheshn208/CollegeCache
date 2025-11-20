class Number
{
    int number;

    Number(int number)
    {
        this.number = number;
    }

    void shownum()
    {
        System.out.println("Number in decimal form :" + number);
    }
}

class HexNum extends Number
{
    String hex;

    HexNum(int num)
    {
        super(num);
    }
    
    void shownum()
    {
        hex = Integer.toHexString(number).toUpperCase();
        System.out.println("Number in Hexa decimal form :" + hex);
    }
}

class prgm8b
{
    public static void main(String args[])
    {
        Number num = new Number(15);
        num.shownum();

        HexNum hex = new HexNum(15);
        hex.shownum();
    }
}