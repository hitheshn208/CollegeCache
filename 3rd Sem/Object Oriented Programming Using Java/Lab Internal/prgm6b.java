class Student
{
    static
    {
        System.out.println("Welcome to Student Enrollment system");
    }

    static int count = 0;

    Student()
    {
        count++;
    }

    static int getCount()
    {
        return count;
    }
}

class prgm6b
{
    public static void main(String args[])
    {
        Student s1 = new Student();
        Student s2 = new Student();
        Student s3 = new Student();

        System.out.println("Number of students enrolled " + Student.getCount());
    }
}