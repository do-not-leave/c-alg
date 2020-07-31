while( tmp->pNext!=NULL && tmp2->pNext !=NULL  )
	{

        tmp = tmp->pNext;
		tmp2 = tmp2->pNext;
		printf("%d - %d\n", tmp->data,tmp2->data);
		if(tmp2 == tmp){
			printf("入环节点 %d - %d\n", tmp->data,tmp2->data);
			break;
		}
	}