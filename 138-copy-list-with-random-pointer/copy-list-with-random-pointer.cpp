/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        while(temp){
            Node* copy = new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;
        }
        temp=head;
        while(temp){
            Node* copy=temp->next;
            if(temp->random){
                copy->random=temp->random->next;
            }
            else{
                copy->random=NULL;
            }
            temp=temp->next->next;
        }
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;
        temp = head;

        while (temp) {
            Node* copy = temp->next;
            temp->next = copy->next; 
            copyTail->next = copy; 
            copyTail = copy;

            temp = temp->next;
        }

        return dummy->next;
    }
};