import java.util.HashMap;
import java.util.Random;

public class RandomizedSet {
	
	private HashMap<Integer, Integer> idxToVal;
	private HashMap<Integer, Integer> valToIdx;
	private int size;
    
    /** Initialize your data structure here. */
    public RandomizedSet() {
    	idxToVal = new HashMap<Integer, Integer>();
    	valToIdx = new HashMap<Integer, Integer>();
    	size = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (valToIdx.containsKey(val) && valToIdx.get(val)!=null) return false;
        valToIdx.put(val, size);
        idxToVal.put(size, val);
        size++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
    	if (!valToIdx.containsKey(val)) return false;
    	if (valToIdx.get(val) == null) return false;
        int idx = valToIdx.get(val);
        int lastVal = idxToVal.get(size-1);
        valToIdx.remove(lastVal);
        idxToVal.remove(size-1);
        if (val != lastVal) {
        	valToIdx.remove(val);
        	idxToVal.remove(idx);
            valToIdx.put(lastVal, idx);
            idxToVal.put(idx, lastVal);
        }
        size--;
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        Random rand = new Random();
        int idx = rand.nextInt(size);
        return idxToVal.get(idx);
    }
}

