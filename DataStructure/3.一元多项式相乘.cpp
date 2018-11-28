void multiplication( NODE *head1, NODE *head2 , NODE *head3 )
{/*ÊäÈëÓÐÁË£¬¶¨Òå±äÁ¿³õÊ¼»¯£¬
Ã¿Ò»¸öÁ´±í£¬Ò»¸öÍ·Ö¸Õë£¨ÓÐÍ·½áµã£© £¬Ò»¸öNULL£¬Ò»¸öµ±Ç°½ÚµãÖ¸Õë
Í·½áµãµÄ´æÔÚ£¬·½±ã½¨Á¢Á´±í£¬´úÂëÁ¿¼õÉÙ£¬ÆÕÊÊ»¯*/
    NODE *t1 = head1, *t2 = head2, *t3 = head3,*t; 
    int c,e;
    
    t1 = t1->next ;
    t2 = t2->next ;//t1 t2 Ö¸Ïòµ±Ç°ÓÐÊý¾ÝµÄ½áµã ,Ö»ÓÐÕâÑù£¬while£¨t1/t2£© ²ÅÓÐÒâÒåÑ½ 
    while(t1){
    	
    	e = t2->exp + t1 ->exp;
    	c = t2->coef * t1 ->coef;
    	
    		t = (NODE*) malloc(sizeof(NODE));
    		t->exp = e;
    		t->coef = c;
    		t->next = NULL;
    		t3->next = t;
    		t3 = t;
		
			
    	t1 = t1->next ;
	}
	t2 = t2 ->next;//µÚ¶þ¸öÊý¾Ý½Úµã 
	
	while(t2){
		t1 = head1->next  ;
		t3 = head3->next  ;
		while(t1){
			e = t2->exp + t1->exp ;
			c = t2->coef* t1->coef;
			//t3 = head3->next ;  ÓÐÐò±í£¬ËùÒÔÕâÌõÓï¾ä²»±ØÐë¡£ÕÒÒ»¸ö Àý×Ó£¬ ¿ÉÒÔ±ÜÃâÕâÖÖ´íÎó 
			while(t3->next&&t3->next->exp < e ){
				t3 = t3->next ;
			}
		
			if( t3 ->next&&t3->next->exp == e){// && Ç°ºóÓï¾ä ²»ÄÜµßµ¹ 
				t3 ->next->coef += c;
			}else{ 
					t = (NODE*) malloc(sizeof(NODE));
    				t->exp = e;
    				t->coef = c;
    				t->next = t3 ->next;
    				t3->next =t;
			}
			
			t1 = t1->next ;
		}
		
		t2 = t2 ->next; 
	} 
	
	
	//´¦ÀíËùÓÐÏµÊý¶¼ÊÇ0µÄÇé¿ö£¬ÒÔÂú×ãÊä³öÒªÇó 
	NODE *tmp = head3;
	t3 = head3->next ;
	while(t3){
		if(t3->coef == 0){
			tmp->next = t3->next ;
			free(t3);
			t3 = tmp->next ;
		}else{
			t3 = t3->next ;
		    tmp = tmp->next ;
		}	
	}
	if(head3->next == NULL){
		t = (NODE*)malloc(sizeof(NODE));
		t->coef = 0;
		t->exp = 0;
		t->next = NULL;
		head3->next = t;
	}
	
 }