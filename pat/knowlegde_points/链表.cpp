#include <iostream>
using namespace std;

struct node {
    typename data;
    node* next;
};

typename* a = (typename*)malloc(sizeof(typename))
int* b = (int*)malloc(sizeof(int));
node* c = (node*)malloc(sizeof(node));
typename* d = new typename;
int* e = new int;
node* f = new node;

free(a);
free(b);
free(c);
delete(d);
delete(e);
delete(f);

node* create(int array[]) {
    node *p, *pre, *head;
    head = new node;
    head->next = NULL;
    pre = head;
    for(int i = 0; i < 5; i++) {
        p = new node;
        p->data = array[i];
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    return head;
}

int search(node* head, int x) {
    int count = 0;
    node* p = head->next;
    while(p != NULL) {
        if(p->data == x) {
            count++;
        }
        p = p->next;
    }
    return count;
}

void insert(node* head, int pos, int x) {
    node* p = head;
    node* a = new node;
    a->data = x;
    for(int i = 0; i < x; i++) {
        p = p->next;
    }
    a->next = p->next;
    p->next = a;
}

void del(node* head, int x) {
    node* p = head->next;
    node* pre = head;
    while(p != NULL) {
        if(p->data == x) {
            pre->next = p->next;
            delete(p);
            p = pre->next;
        }
        else {
            pre = p;
            p = p->next;
        }
    }
}

int main() {
    int array[5] = {1, 4, 5, 6, 9};
    node* l = create(array);
    l = l->next;
    while(l != NULL) {
        printf("%d", l->data);
        l = l->next;
    }
    return 0;
}
