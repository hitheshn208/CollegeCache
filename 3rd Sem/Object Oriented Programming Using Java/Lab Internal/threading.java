class Buffer
{
    static final int SIZE = 10;
    static int stack[];
    static int top = 0;
    Buffer()
    {
        this.stack = new int[SIZE];
    }
    synchronized public static boolean push(int value, Producer producer)
    {
        if (top == SIZE)
            producer.wait();
        stack[top++] = value;
        return true;
    }
    synchronized public static void pop(Consumer consumer)
    {
        if (top == 0)
            consumer.wait();
        System.out.println("Popped: " + stack[--top]);
    }
}
class Consumer implements Runnable
{
    String name;
    Consumer(String name)
    {
        this.name = name;
        this.t = Thread(this, name);
    }
    Buffer stack = new Buffer();
    public void run()
    {
        for (int i = 0; i < 100; i++) {
            System.out.println("Pushed: " + push(i, this));
        }
    }
}
class Producer implements Runnable
{
    String name;
    Producer(String name)
    {
        this.name = name;
        this.t = Thread(this, name);
    }
    Buffer stack = new Buffer();
    public void run()
    {
        stack.pop(this);
    }
}
class producerConsumer
{
    public static void main(String args[])
    {
        Buffer stack = new Buffer();
        Producer producer = new Producer("producer");
        Consumer consumer = new Consumer("consumer");

        producer.t.start();
        consumer.t.start();
        try {
            producer.t.join();
            consumer.t.join();
        }
        catch (InterruptedException e) {
            System.out.println("Caught: " + e);
        }
        System.out.println("Done!");
        return;
    }
}