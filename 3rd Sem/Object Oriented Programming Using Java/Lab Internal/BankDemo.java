import accounts.Accounts;
import services.interest;

class BankDemo
{
    public static void main(String args[])
    {
        Accounts a = new Accounts("123456CNBR", "Hithesh",50000);
        interest i = new interest();
        a.displayAcc();
        a.depositMoney(10000);
        a.displayAcc();
        i.computeInterest(a, 10);
        a.displayAcc();
    }
}