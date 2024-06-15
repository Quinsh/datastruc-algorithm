
public interface Queue<T> {
    public void enqueue(T element);
    public T dequeue();
    public T peek();
    public boolean isEmpty();
    public int size();
}

public class QueueLinkedList<T> implements Queue<T> {
    // FIELDS
    private class Node {
        T val;
        Node next;

        Node(T v) {
            val = v;
            next = null;
        }
    }
    Node head;
    Node tail;
    int size;

    public QueueLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }

    public void enqueue(T element) {
        Node newnode = new Node(element);
        if (head == null) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail.next = newnode;
            tail = tail.next;
        }
        size++;
    }

    public T dequeue() throws NoSuchElementException {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        T ret = head.val;
        head = head.next;
        if (head == null) tail = null;
        size--;
        return ret;
    }

    public T peek() {
        if (isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        return tail.val;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }
}