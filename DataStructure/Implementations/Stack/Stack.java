class Stack {
    private int[] myStack;
    private int topOfStack;
    private int sz;
    Stack(int s) {
        sz = s;
        myStack = new int[s];
        topOfStack = -1;
    }

    public void push(int x) {
        if (topOfStack == myStack.length - 1) {
            System.err.println("Stack is Full");
        }
        else {
            System.out.println("Item added in stack");
            myStack[++topOfStack] = x;
        }
    }

    public int top() {
        if (topOfStack < 0) {
            System.err.println("Stack is empty");
            return -1;
        }
        else {
            return myStack[topOfStack];
        }
    }
    public int pop() {
        if (topOfStack < 0) {
            System.err.println("Stack is empty");
            return -1;
        }
        else {
            return myStack[topOfStack--];
        }
    }
}