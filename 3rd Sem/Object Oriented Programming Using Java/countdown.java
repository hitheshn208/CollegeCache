class newThread implements Runnable
{
    public void run()
    {
        Thread currth = Thread.currentThread();

        for(int i = 150; i>0; i--)
        {
            try{ currth.sleep(1000);}
            catch(InterruptedException e){ System.out.println("Thread interrupted"); }
            System.out.println(i);
        }
    }
}

class countdown
{
    public static void main(String args[])
    {
        newThread task = new newThread();
        Thread t = new Thread(task);
        t.start(); 
    }
}