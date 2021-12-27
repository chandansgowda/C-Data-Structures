#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* link;
};

typedef struct node* NODE;
int count = 0;

NODE createNode(){
	NODE temp = (NODE)malloc(sizeof(struct node*));
	count++;
	temp->link = temp;
	printf("Enter Data>> ");
	scanf("%d",&temp->data);
	return temp;
}

void display(NODE last){
	if (last==NULL){
		printf("Empty List\n");
		return;
	}
	NODE temp = last->link;
	int i;
	for(i=0;i<count;i++){
		printf("%d -> ",temp->data);
		temp=temp->link;
	}
	printf("\nPress Any Number to Continue\n");  
	scanf("%d",&i);
}

NODE insAtFront(NODE last){
	if (last==NULL) return createNode();
	NODE temp = createNode();
	temp->link = last->link;
	last->link = temp;
	return last;
}

NODE insAtEnd(NODE last){
	if (last==NULL) return createNode();
	NODE temp = createNode();
	temp->link = last->link;
	last->link = temp;
	return temp;
}

NODE delAtFront(NODE last){
	if (last==NULL){
		printf("List Empty\n");
		return last;
	}
	NODE temp = last->link;
	last->link = temp->link;
	free(temp);
	count--;
	return last;
}

NODE delAtEnd(NODE last){
	if (last==NULL){
			printf("List Empty\n");
			return last;
		}
		NODE temp = last->link;
		int i = 0;
		for(i=0;i<count-1;i++){
			temp=temp->link;
		}
		temp->link = last->link;
		free(last);
		count--;
		return temp;
}

NODE insAtPos(NODE last, int pos){
	if ((pos<1)||(pos>count+1)){
		printf("Invalid Position\n");
		return last;
	}
	if (pos==1) return insAtFront(last);
	if (last==NULL) return createNode();
	int i; NODE temp = last->link;
	for(i = 1;i<pos-1;i++){
		temp = temp->link;
	}
	NODE newNode = createNode();
	newNode->link = temp->link;
	temp->link = newNode;
	return last;
}

NODE delAtPos(NODE last, int pos){
	if ((pos<1)||(pos>count)){
		printf("Invalid Position\n");
		return last;
	}
	if (pos==1) return insAtFront(last);
	int i; NODE temp = last->link;
	for(i = 1;i<pos-1;i++){
		temp = temp->link;
	}
	NODE ptr = temp->link;
	temp->link = temp->link->link;
	free(ptr);
	count--;
	return last;
}

int search(NODE last, int key){
	if (last==NULL){
		printf("List Empty\n");
		return 0;
	}
	int i=1; NODE temp = last->link;
	do{
		if (temp->data==key){
			return i;
		}
		temp = temp->link;
		i++;
		
	}while(i<=count);
	return 0;
}

 NODE reverse (NODE last )
 { int i=0;
  NODE temp=last->link,first,new,cur=NULL;
  if(last==NULL)
  {
   printf("empty link list ");
   return NULL;
  }
  if(count==1)
  {
   printf("only one element ");
   return last;
  }
  else
  {
   for(i=0;i<count;i++)
   { new=temp;
    temp=temp->link;
    new->link=cur;
    cur=new;
    }
   first=cur;
  while(cur->link!=NULL)
  {
  cur=cur->link;
  }
  cur->link=first;
  return cur;
 }

void main()
{
    int choice, pos, key;
    NODE last;

    while (1)
    {	
    	puts(
"\n░█████╗░░██████╗██╗░░░░░██╗░░░░░  ░█████╗░██████╗░░██████╗\n"
"██╔══██╗██╔════╝██║░░░░░██║░░░░░  ██╔══██╗██╔══██╗██╔════╝\n"
"██║░░╚═╝╚█████╗░██║░░░░░██║░░░░░  ██║░░██║██████╔╝╚█████╗░\n"
"██║░░██╗░╚═══██╗██║░░░░░██║░░░░░  ██║░░██║██╔═══╝░░╚═══██╗\n"
"╚█████╔╝██████╔╝███████╗███████╗  ╚█████╔╝██║░░░░░██████╔╝\n"
"░╚════╝░╚═════╝░╚══════╝╚══════╝  ░╚════╝░╚═╝░░░░░╚═════╝░ ");
        printf("\n   1.Display\n   2.Insert at Front\n   3.Insert at position\n   4.Insert at End\n   5.Delete at Front\n   6.Delete at Position\n   7.Delete last element\n   8.Search Value\n   9.Reverse\n   99.Exit\n   Select Option>> ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            	display(last);
            	break;
        case 2:
        		last = insAtFront(last);
            	break;
        case 3:
        		printf("Enter Position to Insert>> ");
        		scanf("%d",&pos);
        		last = insAtPos(last,pos);
            	break;
        case 4:
        		last = insAtEnd(last);
            	break;
        case 5:
        		last = delAtFront(last);
            	break;
        case 6:
        		printf("Enter Position to Delete>> ");
        		scanf("%d",&pos);
        		last = delAtPos(last,pos);
            	break;    
        case 7:
        		last = delAtEnd(last);
            	break;
        case 8:
        		printf("Enter Value to Search>> ");
        		scanf("%d",&key);
        		pos = search(last,key);
        		if (pos>0) printf("Key Found at Position - %d\n",pos);
        		else printf("Key not Found!\n");
        		break;
        case 9:
        		last = reverse(last);
        		display(last);
        		break;
        case 99:
            exit(0);
        default:
            printf("%d is invalid option", choice);
        }
    }
}
