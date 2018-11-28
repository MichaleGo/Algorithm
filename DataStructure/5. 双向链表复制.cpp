void rcopy(DuLinkList DHead)
{
    DuLNode* p = DHead->next ;
    int t[1000],i = 0;
    
	while(p != DHead)
	{
		t[i++] = p->data ;
		p = p->next ;
	}
	int n = --i;
	p = p->prior ;
	
	for(i = n-1;i >= 0;i--)
	{
		DuLNode* q = (DuLNode*)malloc( sizeof(DuLNode));
		q->data = t[i];
		q->next = DHead;
		p->next = q;
		DHead->prior = q;
		q->prior = p;
		p = q;
	}
	
}