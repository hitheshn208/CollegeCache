class MyThread extends Thread
{
    MyThread()
    {
        super("Brooo");
    }
    public void run()
    {
        try{
            this.sleep(5000);
        }
        catch(InterruptedException e)
        {
            System.out.println("MyThread interrrupted");
        }
        System.out.println("Inside the run method");
    }
}

class singleThread
{
    public static void main(String args[])
    {
        MyThread obj = new MyThread();
        obj.start();
        System.out.println(obj);

        try{
            System.out.println(obj.getPriority());
            System.out.println(Thread.currentThread().getPriority());
            obj.join();
        }
        catch(InterruptedException e)
        {
            System.out.println("Thread Interrupted");
        }
        System.out.println("Printed this message after obj finished execution seconds");
    }
}