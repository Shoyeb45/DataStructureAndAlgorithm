package HashMapInJava;

import java.util.ArrayList;
import java.util.NoSuchElementException;


/**
 * This is Hash Map data structure . It uses generic data type and hashing function to convert given key into index of given capacity.
 * 
 * Separate chaining is used to minimize the colliding. It's implemented using {@code ArrayList} data structure.
 * 
 * <hr>
 * {@code HashMap<K, V> mp = HashMap<K, V>();}
 * 
 * @see ArrayList
 * @author Shoyeb Ansari
 */
public class HashMap<K, V> {
    /**
     * Maximum size for hash map
     */ 
    public static final int MAX_SIZE = 16;
    /**
     * Maximum Threshold for hash map
     */
    public static final double MAX_THRESHOLD = 0.5;

    /**
     * Entry class for storing key, value and hashcode of key.
     */
    @SuppressWarnings("hiding")
    private class Entry<K, V> {
        K key;
        V value;
        int hashCode;
        Entry(K ky, V val, int hc) {
            this.key = ky;
            this.value = val;
            this.hashCode = hc;
        }
    }
    
    /**
     * Fields
     */
    /**
     * Current size
     */
    private int sz;   
    /**
     * Maximum capacity
     */
    private int capacity;   
    /**
     * For storing entries
     */
    public ArrayList<ArrayList<Entry<K, V>>> data;  
    
    /**
     * Public constructor to initialize hash map.
     * We can initialize hashmap with any data type as key and give any data type as value.<hr>
     * {@code HashMap<K, V> name = new HashMap<K, V>();}
     */
    public HashMap() {
        this.sz = 0;
        this.capacity = MAX_SIZE;
        this.data = new ArrayList<>();

        for (int i = 0; i < capacity; i++) {
            data.add(new ArrayList<Entry<K, V>>());
        }
    }
    
    /**
     * Inserting Key and value into Hash Table.
     * The average time complexity of inserting operation will be O(1)
     * If the key is already present then it will update the value with new given value.<hr>
     * {@code HashMap<Integer, Integer> mp = new HashMap<>();        
     *        mp.insert(1, 12);  
     * }
     * @param k : key
     * @param v : value
     */
    public void insert(K k, V v) {
        if((double) sz / capacity > MAX_THRESHOLD) {
            this.resize();
        }
        
        int idx = getIndex(hash(k));
        Entry<K, V> newEntry = new Entry<K,V>(k, v, idx);
        
        for(Entry<K, V> entry: data.get(idx)) {
            if(entry.key == k) {
                entry.value = v;
                return;
            }
        }
        data.get(idx).add(newEntry);
        sz++;   
    }
    
    /**
     * Get size of the hash map.
     * @return
     * size of hash map
     */
    public int size() {
        return sz;
    }
    
    
    /**
     * Checks if hash map is empty or not.
     * @returns
     * {@code true} if empty
     */
    public boolean empty() {
        return (sz == 0);
    }
    
    /**
     * This will check wheter the key is already present in hash map or not.
     * @return
     * {@code true}, if present
     */
    public boolean contains(K key) {
        int idx = getIndex(hash(key));
        for(int i = 0; i < data.get(i).size(); i++) {
            if(data.get(idx).get(i).key == key) {
                return true;
            }
        }
        return false;
    }
    
    /**
     * Deletes the particulatr  key from the hash  map.
     * @return void
     * {@code NoSuchElementException} if key is not present.
     */
    public void delKey(K key) {
        int idx = getIndex(hash(key));
        for(int i = 0; i < data.get(idx).size(); i++) {
            if(data.get(idx).get(i).key == key) {
                data.get(idx).remove(i);
                sz--;
                return;
            }
        }
        throw new NoSuchElementException("Key not found: " + key);
    }
    
    /**
     * Getting the value of particular element by passing key as argument.
     * @param key
     * @return value
     * {@code null} if key is not present, else it will return the value of that key.
     */
    public V get(K key) {
        int idx = getIndex(hash(key));
        for(int i = 0; i < data.get(idx).size(); i++) {
            if(data.get(idx).get(i).key == key) {
                return data.get(idx).get(i).value;
            }
        }
        return null;
    }

    /**
     * Getting hash key
     * @param key
     * @return hash code
     */
    private int hash(K key) {
        return key.hashCode();
    }
    
    /**
     * Get index for current capacity
     * @param hc
     * @return Index
     */
    private int getIndex(int hc) {
        return (hc % capacity + capacity) % capacity; 
    }
    
    /**
     * Resizing the hash map if current {@code loadfactor} exceedes the {@code MAX_THREHOLD}
     */
    private void resize() {
        int new_capacity = 2 * capacity;
    
        ArrayList<ArrayList<Entry<K, V>>> new_data = new ArrayList<>();
        for(int i = 0; i < new_capacity; i++) {
            new_data.add(new ArrayList<Entry<K, V>>());
        }
    
        for(int i = 0; i < capacity; i++) {
            for(Entry<K, V> entry: data.get(i)) {
                int new_index = getIndex(entry.hashCode % new_capacity);
                new_data.get(new_index).add(entry);
            }
        }
        data = new_data;
        capacity = new_capacity;
    }
    
}