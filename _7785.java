import java.io.*;
import java.util.*;

public class _7785 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Map<String, Integer> map = new HashMap<>();
        String name, state;

        for(int i=0; i<n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            name = st.nextToken();
            state = st.nextToken();

            if(state.equals("enter")){
                map.put(name, null);
            }
            else{
                map.remove(name);
            }
        }

        ArrayList<String> arr = new ArrayList<>(map.keySet());

        Collections.sort(arr, Collections.reverseOrder());

        StringBuilder sb = new StringBuilder();

        for(String temp: arr){
            sb.append(temp).append("\n");
        }
        System.out.print(sb);
    }
}
