import java.io.*;

public class _2577 {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int a = Integer.parseInt(br.readLine()); 
        int b = Integer.parseInt(br.readLine()); 
        int c = Integer.parseInt(br.readLine()); 
        
        int ans[] = new int[10];

        int sum = a*b*c;

        while(sum > 9){
            int m = sum%10;
            ans[m]++;
            sum /= 10;
        }
        ans[sum]++;
        
        for(int i=0; i<10; i++){
            System.out.println(ans[i]);
        }

    }
}
