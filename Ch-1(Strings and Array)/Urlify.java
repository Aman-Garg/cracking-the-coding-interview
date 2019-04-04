import java.util.*;

class Urilify {
    
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        String data = in.nextLine();
        int dataLength = in.nextInt();
        int newDataLength = dataLength + 2*countNoOfSpace(data , dataLength);
        char dataArray[] = new char[newDataLength];
        for(int i=dataLength-1 ; i>=0 ; i--){
            if(data.charAt(i) == ' '){
                dataArray[newDataLength-1] = '0';
                dataArray[newDataLength-2] = '2';
                dataArray[newDataLength-3] = '%';
                newDataLength = newDataLength -3;
            }else {
                dataArray[newDataLength-1] = data.charAt(i); 
                newDataLength--;
            }
        }
        System.out.println(new String(dataArray));
    }

    private static int countNoOfSpace(String data , int dataLength){
        int count = 0;
        for(int i=0 ; i < dataLength ; i++){
            if(data.charAt(i) == ' ')
                count++;
        }
        return count ; 
    }

}