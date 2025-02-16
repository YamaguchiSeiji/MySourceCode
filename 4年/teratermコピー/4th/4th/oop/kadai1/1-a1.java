import java.util.Scanner;

class SakanaDetector {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("何か入力してください: ");
        String s = in.nextLine();
        for(int i = 0; i < s.length(); i++){
            char tmp = s.charAt(i);
            if(tmp >= 0x9B5A && tmp <= 0x29F8E){
                System.out.println(i + 1 + "文字目「" + tmp + "」は魚がつく文字です！");
            }
        }
    }
}

