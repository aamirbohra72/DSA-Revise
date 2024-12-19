class solution {
    public:
    Node* inorderSuccessor(Node* root, Node* p){
        Node* succ = 0;
        Node* curr = root;
        while(curr){
            if(curr->data > p->data){
                succ = curr;
                curr = curr -> left;
            }else{
                curr = curr ->right;
            }

        }
        return succ;
    }
}