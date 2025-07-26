public class StackManager {
    private String[] stack;
    private int top;
    private static final int MAX = 100;

    public StackManager() {
        stack = new String[MAX];
        top = -1;
    }

    public void push(String value) {
        if (top >= MAX - 1) {
            System.out.println("Stack Overflow");
            return;
        }
        stack[++top] = value;
    }

    public String pop() {
        if (isEmpty()) {
            System.out.println("Stack Underflow");
            return null;
        }
        return stack[top--];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public int getSize() {
        return top + 1;
    }
}
