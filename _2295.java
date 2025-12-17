import java.io.*;
import java.util.*;

public class _2295 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr);

        ArrayList<Integer> two = new ArrayList<>(n*n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                two.add(arr[i]+arr[j]);
            }
        }
        

        Collections.sort(two);        

        for(int i = n-1; i > -1; i--){
            for(int j = 0; j < n; j++){
                int target = arr[i] - arr[j];

                if(Collections.binarySearch(two, target) >= 0){
                    System.out.println(arr[i]);
                    return;
                }
            }
        }
    }
    
}
