import java.util.*;

class CheckPermutation{
    
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        String data1 = in.nextLine();
        String data2 = in.nextLine();
        String sortedData1 = sortString(data1);
        String sortedData2 = sortString(data2);
        if(checkPermutation(sortedData1 , sortedData2)){
            System.out.println("True");
        }else {
            System.out.println("False");
        }
    }

    private static boolean checkPermutation(String data1 , String data2){
            if(data1.length() != data2.length())
                return false;
            else 
                return data1.equalsIgnoreCase(data2);
    }

    private static String sortString(String data){
        char[] dataArray = data.toCharArray();
        Arrays.sort(dataArray);
        return new String(dataArray);
    }

}