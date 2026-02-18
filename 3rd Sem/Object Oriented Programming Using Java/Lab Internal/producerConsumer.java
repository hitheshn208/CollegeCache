class Buffer
{
    int data;
    boolean hasData = false;

    synchronized void put(int i)
    {
        while(hasData){
            try     {
                System.out.println("Producer Waiting");
                wait();
            }
            catch (InterruptedException e){
                System.out.println("Thread interrupted in put()");
            }

        }
        data = i;
        System.out.println("Produced : " + data);
        hasData = true;
        notify();
    }


    synchronized void get()
    {
        while (!hasData){
            try     {
                System.out.println("Conumer Waiting");
                wait();
            }
            catch (InterruptedException e){
                System.out.println("Thread interrupted in get()");
            }

        }

        System.out.println("Consumed : " + data);
        hasData = false;
        notify();
        return;        
    }
}

class Producer extends Thread
{
    Buffer buffer;
    int i = 0;

    Producer(Buffer buffer)
    {
        this.buffer = buffer;
    }

    public void run()
    {
        while(true)
        {
            buffer.put(++i);
            try{
                Thread.sleep(500);
            }
            catch(InterruptedException e){
                System.out.println("Producer thread interrupted");
            }
        }
    }
}

class Consumer extends Thread
{
    Buffer buffer;

    Consumer(Buffer buffer)
    {
        this.buffer = buffer;
    }

    public void run()
    {
        while(true){
            buffer.get();
            try{
                Thread.sleep(500);
            }
            catch(InterruptedException e){
                System.out.println("Consumer thread interrupted");
            }
        }
    }
}

class producerConsumer
{
    public static void main(String args[])
    {
        Buffer buffer = new Buffer();

        Producer p = new Producer(buffer);
        Consumer c = new Consumer(buffer);

        p.start();
        c.start(); 
    }
}