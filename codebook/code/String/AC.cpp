struct Node{
	Node *index[30];
	Node *fail;
	int word;
	int num;
	Node(){
		for(int i=0;i<30;i++)
		index[i]=NULL;
		fail=NULL;
		word=0;
		num=-1;
	}
}*root=new Node();
void add(char c[]){
	Node *n=root;
	for(int i=0;c[i]!=0;i++){
		
		if(!n->index[c[i]-'a'])
		n->index[c[i]-'a']=new Node();
		n=n->index[c[i]-'a'];
	}
	n->word=1;
	n->num=t++;
}
void ac(){
	queue<Node*> q;
	q.push(root);
	root->fail=NULL;
	while(!q.empty()){
		Node *n=q.front();
		q.pop();
		for(int i=0;i<30;i++){
			if(n->index[i]){
				q.push(n->index[i]);
				Node* p=n->fail;
				while(p!=NULL&&!p->index[i])
				p=p->fail;
				if(p)
				n->index[i]->fail=p->index[i];
				else
				n->index[i]->fail=root;
			}
		}
	} 
}
void search(char c[]){
	Node *n=root;
	for(int i=0;c[i]!=0;i++){
		
		while(!n->index[c[i]-'a']&&n!=root){
			n=n->fail;
		}
		if(n->index[c[i]-'a'])
		n=n->index[c[i]-'a'];
		Node *p=n;
		while(p){
			if(p->num!=-1)
			{
				ans[p->num]++;
			}
			p=p->fail;
		}
	}
}
void del(Node *n=root){
	for(int i=0;i<30;i++)
	if(n->index[i])
	del(n->index[i]);
	free(n);
}
