import java.util.*;
class PalindromePermutation{
    
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        String data = in.nextLine();
        data = removeSpaceFromString(data.toLowerCase());
        int count[] = countCharacter(data.toLowerCase());
        System.out.println(checkNoOfOddCharacter(count));
    }

    private static int[] countCharacter(String data){
        int[] count = new int[26];
        for(int i=0 ; i<data.length() ; i++){
            int index = (int)data.charAt(i) - (int)'a';
            count[index]++;
        }
        return count;
    }

    private static boolean checkNoOfOddCharacter(int[] data){
        // return false if number of odd character is more than one 
        int noOfOdd=0; 
        for(int i=0 ; i < data.length ; i++){
            if(data[i]%2==1){
                noOfOdd++;
            }
            if(noOfOdd > 1){
                return false;
            }
        }
        return true;
    }

    private static String removeSpaceFromString(String data){
        String s = "";
        for(int i =0 ; i<data.length() ; i++){
            if(data.charAt(i) == ' ');
            else 
                s = s.concat(data.substring(i,i+1));
        }
        return s; 
    }

}