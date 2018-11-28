
SNODE * ziplist( SNODE * head1, SNODE * head2 ){
    int flag=1,m,n;
    SNODE *p1=head1,*p2=head2,*p_1,*p_2;
    m=listlen(head1);
    n=listlen(head2);
    while (m>n) {
        p1=p1->next;
        m--;
    }
    while (m<n) {
        p2=p2->next;
        n--;
    }
    for (; p1->next!=NULL; p1=p1->next,p2=p2->next) {
        if (p1->next->data==p2->next->data) {
            if (flag==1) {
                p_1=p1;
                p_2=p2;
                flag=0;
            }
        }
        else {
            flag=1;
            p_1=p_2=NULL;
        }
    }
    if (p_1==NULL) {
        return NULL;
    }
    else {
        p_2->next=p_1->next;
        return p_2->next;
    }
}