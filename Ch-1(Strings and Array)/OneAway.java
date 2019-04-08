import java.util.*; 
class OneAway{
    
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        String data1 = in.nextLine();
        String data2 = in.nextLine();
        if(data1.length() == data2.length()){
            replace(data1, data2);
        }
        else if( Math.abs(data1.length() - data2.length())==1 ){
            noOfCharacterEqual(data1, data2);
        }else {
            System.out.println(false);
        }

    }

    private static void replace(String data1 , String data2){
        int noOfDiffChar = 0 ;
        for(int i=0 ; i<data1.length() ; i++){
            if(data1.charAt(i) != data2.charAt(i)){
                noOfDiffChar++;
                if(noOfDiffChar > 1){
                    System.out.println(false);
                    return;
                }
            }
        }
        System.out.println(true);
    }


    private static void noOfCharacterEqual(String data1 , String data2){
        int index1 = 0;
        int index2 = 0;
        int noOfMismatch = 0;
            while(index1 != data1.length() && index2 != data2.length() ){
                if(data1.charAt(index1) == data2.charAt(index2)){
                    index1++;
                    index2++;
                }else{
                    noOfMismatch++;
                    if(data1.length() > data2.length()){
                        index1++;
                    }else{
                        index2++;
                    }
                }
            }
            if(noOfMismatch >1)
                System.out.println("False");
            else
                System.out.println("True");
            }
    }
