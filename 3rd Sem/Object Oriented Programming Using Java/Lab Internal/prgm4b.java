import java.util.*;

class prgm4b
{
    public static void main(String args[])
    {
        int a,b,c;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the coefficients a, b, c :");
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        double D = (b*b)-(4*a*c);

        if(D>0)
        {
            System.out.println("Roots are reala and distinct");
            System.out.println("x1 = " + ((-b + Math.sqrt(D)) /(2*a)));
            System.out.println("x2 = " + ((-b - Math.sqrt(D)) /(2*a)));
        }
        else if( D==0 )
        {
            System.out.println("Roots are real and Equal");
            System.out.println("x = " + (-b/(2*a)));
        }
        else
        {
            System.out.println("x1 = "+(-b)/(2*a) + " + " + Math.sqrt((-(D)))/(2*a) + "i");
            System.out.println("x2 = "+(-b)/(2*a) + " - " + Math.sqrt((-(D)))/(2*a) + "i");
        }
    }
}