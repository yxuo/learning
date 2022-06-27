import java.util.Scanner;

public class answer {

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        int a = input.nextInt();
        int b = input.nextInt();

        if(a > b)
            System.out.printf("%d\n",a);
        else
            System.out.printf("%d\n",b);

        input.close();
    }
    
}
