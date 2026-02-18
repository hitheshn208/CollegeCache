package services;
import accounts.Accounts;

public class interest
{
    public void computeInterest(Accounts acc, double rate)
    {
        acc.balance = acc.balance + (acc.balance*(rate/100));
    }
}