import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class _1978 {
    
    public static boolean check(int n){

        if(n==1){
            return false;
        }

        for(int i=2; i*i <= n; i++){
            if(n % i == 0) return false;
        }

        return true;
    }

    public static void main(String[] args) throws IOException {
        int ans = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();

        input = br.readLine();
        
        StringTokenizer st =  new StringTokenizer(input);

        while(st.hasMoreTokens()){
            int num = Integer.parseInt(st.nextToken());

            if(check(num)){
                ans++;
            }
        }
        
        System.out.println(ans);
    }
}
