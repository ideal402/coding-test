import java.io.*;
import java.util.*;

public class _18870 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");

        int[] arr = new int[n];
        int[] arr2 = new int[n];

        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(input[i]);
            arr2[i] = arr[i];
        }

        Arrays.sort(arr2);

        int[] arr3 = new int[n];

        arr3[0] = arr2[0];
        int idx = 0;

        for(int i=1; i<n; i++){
            if(arr3[idx] != arr2[i]){
                arr3[idx+1] = arr2[i];
                idx++;
            };
        }
    
        StringBuilder sb = new StringBuilder();

        for(int a: arr){
            int temp = Arrays.binarySearch(arr3,0, idx+1, a);
            if(temp >= 0){
                sb.append(temp).append(" ");
            }
        }
        System.out.println(sb);

    }
}