import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

  public static void main(String[] args) {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    Stack st = new Stack();
    Stack mv = new Stack();

    for(int i = 0; i < n; i++){
      int op = sc.nextInt();
      if(op == 1){
        int num = sc.nextInt();
        st.push(num);
        if(mv.isEmpty() ||  (int)(mv.peek()) <= num)
          mv.push(num);
      }else if(op == 2){
        int num = (int)(st.pop());
        if(num == (int)(mv.peek()))
          mv.pop();
      }else if(op == 3){
        // int max = -1;
        // for(int j = 0;j < st.size();j++){
        //   int k = (int)(st.get(j));
        //   max = Math.max(max, k);
        // }
        System.out.println((int)(mv.peek()));
      }
    }
  }
}
