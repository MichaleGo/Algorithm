Status ListInsert( SqList &L, int i, ElemType e )
{  	//ÔÚË³ÐòÏßÐÔ±íLÖÐµÚ i (1¡Üi¡ÜL.length+1)¸öÎ»ÖÃÖ®Ç°²åÈëÔªËØe,
	if(i < 1|| i > L.length + 1) return ERROR;
	if(L.length >= L.listsize ){
	    int *newbase = (ElemType*)realloc(L.elem ,(L.listsize + 100)*sizeof(ElemType));
		if(!newbase) exit(ERROR);
		L.elem = newbase;
		L.listsize += 100;
	}
	
	int j = L.length ;
	for(;j >= i; j -- ){
		L.elem [j+1] = L.elem [j];
	}
	
	L.elem [j] = e;
	L.length ++;
	return OK;

}

Status GetElem(SqList L, int i, ElemType &e)
{

	e = L.elem [i-1];
	return OK;

}

int ListLength(SqList L)
{	

	return L.length ;

}