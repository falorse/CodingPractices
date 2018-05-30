import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the arrayManipulation function below.
    static long arrayManipulation(int n, int[][] queries) {
      long[] diff_from_pre = new long[n + 1];

      perform_queries(diff_from_pre, queries);

      return calc_max_value(diff_from_pre);
    }

    static void perform_queries(long[] diff_from_pre, int[][] queries){
      for(int i = 0; i < queries.length; i++){
          int[] query = queries[i];
          int plus_value = query[2];
          int start_index = query[0] - 1;
          int end_index = query[1] - 1;

          diff_from_pre[start_index] += plus_value;
          diff_from_pre[end_index + 1] -= plus_value;
        }
    }

    static long calc_max_value(long[] diff_from_pre){
      long max_value = Long.MIN_VALUE;
      long sum = 0;
      for(int i = 0; i < diff_from_pre.length; i++){
        sum += diff_from_pre[i];
        max_value = Math.max(max_value, sum);
      }

      return max_value;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] nm = scanner.nextLine().split(" ");

        int n = Integer.parseInt(nm[0]);

        int m = Integer.parseInt(nm[1]);

        int[][] queries = new int[m][3];

        for (int i = 0; i < m; i++) {
            String[] queriesRowItems = scanner.nextLine().split(" ");
            scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

            for (int j = 0; j < 3; j++) {
                int queriesItem = Integer.parseInt(queriesRowItems[j]);
                queries[i][j] = queriesItem;
            }
        }

        long result = arrayManipulation(n, queries);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
