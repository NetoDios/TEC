#ifndef MYBST_H
#define MYBST_H
struct MyNodeBST{
    int data;
    MyNodeBST *left,
              *right;
    MyNodeBST(int data){
        this->data=data;
        this->left=this->right=nullptr;
    }
};
 

class MyBST{
    private:
        int size;
        MyNodeBST* root;
        void destruct(MyNodeBST* current);

        bool search(int data, MyNodeBST* current);
        bool insert(int data, MyNodeBST* current);

        void preorder(MyNodeBST* current);
        void inorder(MyNodeBST* current);
        void postorder(MyNodeBST* current);

        int height(MyNodeBST* current);
    public:
        MyBST();
        ~MyBST();
        int length();
        bool isEmpty();

        bool search(int value);
        bool insert(int value);
        bool remove(int value);

        void preorder();
        void inorder();
        void postorder();
        void level();

        void visit(int type);
        int height();
        void ancestors(int value);
        int whatLevelAmI(int value);
};
#endif