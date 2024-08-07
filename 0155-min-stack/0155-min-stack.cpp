class MinStack {
public:
    class Node{
        public:
        int val;
        int mn;
        Node* next;
        
         Node(int val, int mn, Node* next): val(val), mn(mn), next(next) {}
    };
    Node* head;
    
    MinStack() {
        head = new Node(0, INT_MAX, nullptr);
    }
    
    void push(int val) {
        head=new Node(val,min(val,head->mn),head);
    }
    
    void pop() {
        head=head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */