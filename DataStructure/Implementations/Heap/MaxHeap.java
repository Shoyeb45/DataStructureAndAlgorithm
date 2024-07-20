class MaxHeap {
    public static final int MAX_SIZE = 100000;

    private int sz = 0;
    private int[] storedData = new int[MAX_SIZE];

    private void swap(int[] array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    /**
     * Method for inserting value in heap.
     * @param data
     * @throws MaxSizeReachedException
     */
    void push(int data) {
        if(sz == MAX_SIZE) {
            System.err.println("Maximum capacity of heap reached.");
            return;
        }
        int idx = sz;
        storedData[idx] = data;
        sz++;

        while(idx != 0) {
            if(storedData[idx] > storedData[parent(idx)]) {
                swap(storedData, idx, parent(idx));
                idx = parent(idx);
            } else {
                return;
            }
        }
    }

    /**
     * Method for checking if heap is empty or not
     * @return true if it is empty else false
     */
    boolean empty() {
        return this.size() == 0;
    }

    /**
     * Method for getting the size of heap
     * @return size in int
     */
    int size() {
        return sz;
    }

    /**
     * @return Maximum element or top element 
     */ 
    int top() {
        if(this.empty()) {
            System.err.println("Heap is empty.");
            return -1;
        }
        return storedData[0];
    }
    
    /**
     * Private method for calculating parent index
     * @param x
     * @return parent index
     */
    private int parent(int x) {
        return (x - 1) / 2;
    }
    
    /**
     * Private method for calculating left child index
     * @param x
     * @return left child index
     */
    private int leftChild(int x) {
        return 2 * x + 1;
    }
    /**
     * Private method for calculating right child index
     * @param x
     * @return right child index
     */
    private int rightChild(int x) {
        return 2 * x + 2;
    }
    
    /**
     * Method for deleting top element or maximum element in heap
     */
    void pop() {
        if(sz == 0) {
            System.err.println("Heap is empty.");
            return;
        }
        storedData[0] = storedData[sz - 1];
        storedData[sz - 1] = 0;
        sz--;
        int idx = 0;
        while(true) {
            int currElement = storedData[idx];
            int leftChildElement = leftChild(idx) < sz? storedData[leftChild(idx)]: Integer.MIN_VALUE;
            int rightChildElement = rightChild(idx) < sz? storedData[rightChild(idx)]: Integer.MIN_VALUE;
            
            int maximum = Math.max(currElement, Math.max(leftChildElement, rightChildElement));
            if(maximum == currElement) {
                return;
            } else if(maximum == leftChildElement) {
                swap(storedData, leftChild(idx), idx);
                idx = leftChild(idx);
            } else if(maximum == rightChildElement) {
                swap(storedData, rightChild(idx), idx);
                idx = rightChild(idx);
            }
        }
    }

    public String toString() {
        StringBuilder str = new StringBuilder("");
        for(int i = 0; i < sz; i++) {
            if(i == 0) {
                str.append("[" + Integer.toString(storedData[i]) + ",");
            } else if(i == sz - 1) {
                str.append(" " + Integer.toString(storedData[i]) + "]");
            } else {
                str.append(" " + Integer.toString(storedData[i]) + ",");
            }
        }
        return str.toString();
    }
    
}