import java.util.*;
class employee
{
    Scanner sc = new Scanner(System.in);

    String name;
    long emp_id, salary;
    String department, designation;
    int age;

    void getDetails()
    {
        System.out.print("Name : ");
        name = sc.nextLine();
        System.out.print("Emp ID : ");
        emp_id = sc.nextLong();
        sc.nextLine();
        System.out.print("Department : ");
        department = sc.nextLine();
        System.out.print("Age : ");
        age = sc.nextInt();
        sc.nextLine();
        System.out.print("Designation : ");
        designation  = sc.nextLine();
        System.out.print("Salary : ");
        salary = sc.nextLong();

        return;
    }

    void displayDetails()
    {
        System.out.println("Name : " + name);
        System.out.println("Emp Id : " + emp_id);
        System.out.println("Department : " + department);
        System.out.println("Age : " + age);
        System.out.println("Designation : " + designation);
        System.out.println("Salary : " + salary);
    }
}

class employeeprgm
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of employees : ");
        int n = sc.nextInt();

        employee[] e = new employee[n];

        for(int i = 0; i<n; i++ )
        {
            System.out.println("Enter the details of employee " + (i+1));
            e[i] = new employee();
            e[i].getDetails();
        }

        for(employee obj : e)
        {
            obj.displayDetails();
        }

        long salary = 0;

        for(employee obj : e)
        {
            if(obj.department.equalsIgnoreCase("sales"))
                salary += obj.salary;
        }
 
        employee highestPaidManager = null;
        int maxSalary = -1;

        for(employee obj : e)
        {
            if(obj.designation.equalsIgnoreCase("manager") && obj.department.equalsIgnoreCase("purchase"))
                if(maxSalary < obj.salary || maxSalary == -11)
                    highestPaidManager = obj;
        }

        System.out.println("Total salary in sales department is " + salary);
        if(highestPaidManager == null)
        {
            System.out.println("Highest paid manager in the Purchase department not found");
            return;
        }
        System.out.println("Highest paid manager in the Purchase department is  ");
        highestPaidManager.displayDetails();
    }
}