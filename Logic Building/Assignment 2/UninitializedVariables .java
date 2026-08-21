public class UninitializedVariables {
    static byte a; 
    static short b; 
    static int c; 
    static long d; 
    static float e; 
    static double f; 
    static char g; 
    static boolean h;
        
    public static void main(String[] args) 
    {
        
        System.out.println("Byte value: " + a);
        System.out.println("Short value: " + b);
        System.out.println("Integer value: " + c);          
        System.out.println("Long value: " + d);
        System.out.println("Float value: " + e);
        System.out.println("Double value: " + f);
        System.out.println("Character value: " + g);
        System.out.println("Boolean value: " + h);  
    }

    
}