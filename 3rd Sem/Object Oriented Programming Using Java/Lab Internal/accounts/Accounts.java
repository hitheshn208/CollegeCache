package accounts;
public class Accounts
{
    private String accountNo, customerName;
    public double balance;

    public Accounts(String acc, String name, double balance)
    {
        this.accountNo = acc;
        this.customerName = name;
        this.balance = balance;
    }

    public void depositMoney(double money)
    {
        balance += money;
        System.out.println("Total amount : " + balance);
    }

    public void withDrawMoney(double withdraw)
    {
        if(withdraw > balance)
        {
            System.out.println("Insufficient Balance!!");
            return;
        }
    }

    public void displayAcc()
    {
        System.out.println("Account Number : " + accountNo);
        System.out.println("Name : " + customerName);
        System.out.println("Balance : " + balance);
    }
}