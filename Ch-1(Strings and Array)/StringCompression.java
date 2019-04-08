import java.util.*;
class StringCompression{
    
    public static void main(String agrs[]){
        Scanner in = new Scanner(System.in);
	    String data = in.nextLine();
	    String newString = "";
        int startIndex = 1 , endIndex = 1;
        char firstChar = data.charAt(0);
        for(int i=1 ; i<data.length() ; i++){
            if(firstChar == data.charAt(i)){
                endIndex++;
            }else{
                newString = newString.concat(data.substring(startIndex-1 ,startIndex).concat(Integer.toString(endIndex-startIndex+1)));
                startIndex = endIndex+1;
                endIndex++;
                firstChar = data.charAt(i);
            }
        }
        newString = newString.concat(data.substring(startIndex-1 ,startIndex).concat(Integer.toString(endIndex-startIndex+1)));
        if(newString.length() > data.length()){
            System.out.println(data);
        }else{
            System.out.println(newString);
        }
    }

}