import java.io.*;
import java.util.*;
class IsUnique{
    
    public static void main(String agrs[]){
        Scanner in = new Scanner(System.in);
        String data = in.nextLine();
        boolean check = checkUnique(data);
        if(check)
            System.out.println("true");
        else 
            System.out.println("false");
    }

    private static boolean checkUnique(String data){
        boolean b[] = new boolean[127];
        char dataString[] = data.toCharArray();
        for(char temp : dataString){
            if(b[(int)temp] == true)
                return false;
            else 
                b[(int)temp] = true;
        }
        return true; 
    }
}