public class QueueManager {
    private String[] queue;
    private int front, rear, size;
    private static final int MAX = 100;

    public QueueManager() {
        queue = new String[MAX];
        front = 0;
        rear = -1;
        size = 0;
    }

    public void enqueue(String value) {
        if (size >= MAX) {
            System.out.println("Queue Overflow");
            return;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = value;
        size++;
    }

    public String dequeue() {
        if (isEmpty()) {
            System.out.println("Queue Underflow");
            return null;
        }
        String value = queue[front];
        front = (front + 1) % MAX;
        size--;
        return value;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int getSize() {
        return size;
    }
}
