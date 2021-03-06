// Java implementation to find k 
// elements with max occurrence.
import java.util.*;
public class KFrequentNumbers {
    static void print_N_mostFrequentNumber(int[] arr, 
                                           int n,
                                           int k)
    {
        Map<Integer, Integer> mp
            = new HashMap<Integer, Integer>();
  
        // Put count of all the 
        // distinct elements in Map
        // with element as the key & 
        // count as the value.
        for (int i = 0; i < n; i++) {
  
            // Get the count for the 
            // element if already
            // present in the Map or
            // get the default value
            // which is 0.
            mp.put(arr[i], 
                   mp.getOrDefault(arr[i], 0) + 1);
        }
  
        // Create a Priority Queue 
        // to sort based on the
        // count or on the key if the 
        // count is same
        PriorityQueue<Map.Entry<Integer, 
                                Integer>> queue
            = new PriorityQueue<>(
                (a, b)
                -> a.getValue().equals(b.getValue())
                   ? Integer.compare(b.getKey(),
                                     a.getKey())
                   : Integer.compare(b.getValue(),
                                     a.getValue()));
  
        // Insert the data from the map 
        // to the Priority Queue.
        for (Map.Entry<Integer, Integer> entry :
             mp.entrySet())
            queue.offer(entry);
  
        // Print the top k elements
        for (int i = 0; i < k; i++) 
        {
            System.out.println(queue.poll().getKey());
        }
    }
  
    // Driver Code
    public static void main(String[] args)
    {
        int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 };
        int n = arr.length;
        int k = 2;
        
        // Function call
        print_N_mostFrequentNumber(arr, n, k);
    }
}
