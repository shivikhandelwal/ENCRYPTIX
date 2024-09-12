#include<iostream>
#include<map>

using namespace std;
map<string,int>mp;

struct task{
	string name;
	bool status=false;
	task *next;
	
};

task *head=NULL;
task*last=NULL;

void add_task(string name){
	if(mp[name]==1){
		cout<<"Task already exist"<<endl;
		return ;
	}
	task*newtask=new task();
	newtask->next=NULL;
	newtask->name=name;
	if(last ==NULL){
		head=newtask;
		last=newtask;
	}else{
		last->next=newtask;
		last=newtask;
		
	}
	mp[newtask->name]=1;
	cout<<"Task has added successfully"<<endl;
}

void view_task(task *ptr){
	if(head==NULL){
		cout<<"this is empty"<<endl;
		return;
		
	}
	int num=1;
	cout<<"====================================================================================="<<endl;
	while(ptr!=NULL){
		cout<<"task "<<num<<" - "<<ptr->name<<",status=";
		if(ptr->status==false){
			cout<<"pending"<<endl;
			
		}else{
			cout<<"completed"<<endl;
		}
		num++;
		ptr=ptr->next;
		
	}
	cout<<"====================================================================================="<<endl;
}
void mark_completed(task*ptr,int n){
		if(head==NULL){
		cout<<"list is empty"<<endl;
		return;
		
	}
	int num=1;
		while(ptr!=NULL){
		
		if(num==n){
			ptr->status=true;
			cout<<endl<<"task "<<n<<"has marked completed"<<endl;
			return;
		}
	
		ptr=ptr->next;
			num+=1;
	}
	cout<<"no such task is existed"<<endl;
}

void remove_task(task*ptr,int n){
		if(head==NULL){
		cout<<"list is empty"<<endl;
		return;
		
	}

		if(n==1){
		
		if(head==last){
			mp.erase(ptr->name);
			head=NULL;
			last=NULL;
			delete(ptr);
			cout<<"task deleted"<<endl;
			return ;
			
		}
		else {
			mp.erase(ptr->name);
			head=head->next;
			
			delete(ptr);
			cout<<"task deleted"<<endl;
			return ;
			
		}
	}
		int num=1;
		task *prev=ptr;
		while(ptr!=NULL){
			if(num==n){
			prev->next=ptr->next;
			if(ptr==last){
				last=prev;
			
			
			}
			mp.erase(ptr->name);
					
			delete(ptr);
			cout<<"task deleted"<<endl;
			return ;
		}
		num+=1;
		prev=ptr;
		ptr=ptr->next;
		
		}
		if(ptr==NULL){
			cout<<"no such task exist"<<endl;
		}
}

int main(){
		cout<<"======================================================================================================="<<endl;
		cout<<													"TO-DO List"											   <<endl;
		cout<<endl;
		cout<<"Press 1 to add new task"<<endl;
		cout<<"Press 2 to view all task"<<endl;
		cout<<"Press 3 to mark completed to task"<<endl;
		cout<<"Press 4 to remove task"<<endl;
		cout<<"or any other key to end this program"<<endl;
		
		
		char ch;
		cout<<"press =";
		cin>>ch;
		cout<<endl;
		 cin.ignore(); 
		while(ch=='1' || ch=='2' || ch=='3' ||ch=='4'){
			if(ch=='1'){
				string name;
				cout<<"enter task :";
				cin>>name;
				cout<<endl;
				
				add_task(name);
			}else if(ch=='2'){
				view_task(head);
				
			}else if(ch=='3'){
				int n;
				cout<<"mark completed the task from the current view of list"<<endl;
				cout<<"now enter the task number you want to mark completed :";
				cin>>n;
				mark_completed(head,n);
			}else if(ch=='4'){
				int n;
				cout<<endl;
				cout<<"removing done from the current view of the list"<<endl;
				cout<<"now enter the task number you want to remove :";
				cin>>n;
				remove_task(head,n);
			}
				cout<<endl;
		cout<<"Press 1 to add new task"<<endl;
		cout<<"Press 2 to view all task"<<endl;
		cout<<"Press 3 to mark completed to task"<<endl;
		cout<<"Press 4 to remove task"<<endl;
		cout<<"or any other key to end this program"<<endl;
		
		cout<<endl;
		cout<<"press:";
		cin >>ch;cout<<endl;
			
		}
		cout<<"program end . "<<endl;
		return 0;
}
