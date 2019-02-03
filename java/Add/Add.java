/**
 * The Add class takes two numbers and returns the sum.
 *
 * @author Kolby Heacock
 * @version 2019.2.3
 */
public class Add
{
    public static void main(String[] args)
    {
        if (args.length > 0) 
        { 
            if (args.length == 1)
            {
                System.out.println("Invalid Arguments: Only 1 argument used when 2 is required.");
            }
            else if (args.length == 2)
            {
                double first = 0, second = 0;
                try
                {
                    first = Double.parseDouble(args[0]);
                    second = Double.parseDouble(args[1]);
                }
                catch(Exception e)
                {
                    System.out.println("Invalid Arguments: Check arguments to ensure they can parse to Java Double data types.");
                }
                double result = first + second;
                System.out.println("The sum of the " + first + " and " + second + " numbers is " + result);
            }
            else
            {
                System.out.println("Invalid Arguments: Too many arguments. Only 2 required.");
                System.out.println("The command line arguments given were:");
                for (String val:args)
                {
                    System.out.println(val);
                }
            }
        } 
        else
        {
            System.out.println("Invalid Arguments: No command line arguments found."); 
        }
    }
}
