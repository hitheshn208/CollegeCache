import java.util.Scanner;

class Employee
{
    String name, designation, department;
    int Emp_id, age;
    double salary;

    void getDetails(int Emp_id, String name, int age, String designation, String department, double salary)
    {
        this.Emp_id = Emp_id;
        this.name = name;
        this.age = age;
        this.designation = designation;
        this.department = department;
        this.salary = salary;
    }

    void display()
    {
        System.out.println("ID : " + Emp_id);
        System.out.println("Name : " + name);
        System.out.println("Age : " + age);
        System.out.println("Designation : " + designation);
        System.out.println("Department : " + department);
        System.out.println("Salary : " + salary);
    }
}

class prgm2b
{
    public static void main(String args[])
    {
        Employee emp[] = new Employee[5];
        Scanner sc = new Scanner(System.in);

        for(int i = 0; i<5 ; i++)
        {        
            System.out.println("Enter the Employee " + (i+1)+ " details :");
            System.out.print("Name :");
            String name = sc.next();
            System.out.print("ID :");
            int id = sc.nextInt();
            
        }
}