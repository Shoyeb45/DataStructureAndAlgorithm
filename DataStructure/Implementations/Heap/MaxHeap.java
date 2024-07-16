
class MaxHeap {
    public static final int MAX_SIZE = 100000;

    private int sz = 0;
    private int[] storedData = new int[MAX_SIZE];

    private static void swap(int[] array, int index1, int index2) {
        int temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
    void push(int data) throws MaxSizeReachedException {
        if(sz == MAX_SIZE) {
            throw new MaxSizeReachedException("Size limit reached");
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
     * Function for checking if heap is empty or not
     * @return true or false
     */
    boolean empty() {
        return this.size() == 0;
    }

    int size() {
        return sz;
    }

    int top() {
        if(this.empty()) {
            throw new EmptyDataStructureException("Heap is empty\n");
        }
        return storedData[0];
    }

    private int parent(int x) {
        return (x - 1) / 2;
    }
    private int leftChild(int x) {
        return 2 * x + 1;
    }
    private int rightChild(int x) {
        return 2 * x + 2;
    }

    void pop() {
        if(sz == 0) {
            
        }
        storedData[0] = storedData[sz - 1];
        sz--;
        int idx = 0;
        while(true) {
            int currElement = storedData[idx];
            int leftChildElement = leftChild(idx) < sz? storedData[leftChild(idx)]: Integer.MIN_VALUE;
            int rightChildElement = rightChild(idx) < sz? storedData[rightChild(idx)]: Integer.MIN_VALUE;
            
            int maximum = Math.max(currElement, Math.max(leftChildElement, rightChildElement));
            if(maximum == currElement) {
                return;
            } else if(maximum > leftChildElement) {
                swap(storedData, leftChild(idx), maximum);
                idx = leftChild(idx);
            } else if(maximum > rightChildElement) {
                swap(storedData, rightChild(idx), maximum);
                idx = rightChild(idx);
            }
        }
    }

}