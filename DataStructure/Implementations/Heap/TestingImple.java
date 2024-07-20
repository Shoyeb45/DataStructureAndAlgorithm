public class TestingImple {
    public static void main(String[] args) {
        MaxHeap mxheap = new MaxHeap();
        mxheap.push(10);
        mxheap.push(12);
        System.out.println(mxheap.top());
        System.out.println(mxheap);
        mxheap.push(5);
        System.out.println(mxheap);
        mxheap.push(34);
        System.out.println(mxheap);
        System.out.println((!mxheap.empty() ? "Size: " + mxheap.size(): "Heap is empty"));
        
        
        mxheap.push(76);
        System.out.println(mxheap);
        mxheap.push(20);
        System.out.println(mxheap);
        
        mxheap.pop();
        System.out.println(mxheap);

        mxheap.pop();
        System.out.println(mxheap);
        
        mxheap.pop();
        System.out.println(mxheap);

    }
}
