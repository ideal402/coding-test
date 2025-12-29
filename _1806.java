import java.io.*;
import java.util.*;

public class _1806 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n, s;
        int [] arr = new int[1000005];
        int idx = 0;

        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        while(st.hasMoreTokens()){
            arr[idx++] = Integer.parseInt(st.nextToken());
        }
        
        int left = 0;
        int sum = 0;
        int ans = n+1;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while(sum >= s){
                ans = Math.min(ans, right-left+1);
                sum -= arr[left++];
            }
        }

        if(ans > n){
            System.out.println(0);
        }
        else{
            System.out.println(ans);
        }
    }
}
