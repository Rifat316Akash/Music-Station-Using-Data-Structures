#include <iostream>

using namespace std;

#include<bits/stdc++.h>
#include<string.h>

using namespace std;
void creathead();
void creatnodeforaccount();
int login(int l);
void addhistory(string n,string a);
void deletehistory(string n);
void seeaddhistory();
void seedeletehistory();
struct Node *insert(struct Node *temp_root, string n, string a,int i );
void inorder(struct Node *curr);
void inorderar(struct Node *curr,string mm);
struct Node *find_minimum(struct Node* root);
struct Node *find_maximum(struct Node* root);
struct Node* Delete(struct Node *root, string data,int i);
void addrequest();
struct Node *seerequest();
void deleterequest();
struct Node *seeerequest();
void searchh(struct Node *curr,string s);
struct Head{
int cnt;
struct Node *p,*top,*frnt,*rear;
}*heada,*headl,*heads,*headq,*headadd,*headdelete,*headah,*headdh,*headsah,*headsdh;
struct Node{
int data;
string name,pass,artist;
struct Node *next,*left,*right;
}*node,*temp,*root,*current,*tempadd,*tempdelete;
void creathead(){
heada=(struct Head*)malloc(sizeof(struct Head));
heada->cnt=0;
heada->p=NULL;
headadd=(struct Head*)malloc(sizeof(struct Head));
headadd->cnt=0;
headadd->frnt=NULL;
headadd->rear=NULL;
headah=(struct Head*)malloc(sizeof(struct Head));
headah->cnt=0;
headah->top=NULL;
headdh=(struct Head*)malloc(sizeof(struct Head));
headdh->cnt=0;
headdh->top=NULL;
headsdh=(struct Head*)malloc(sizeof(struct Head));
headsdh->cnt=0;
headsdh->top=NULL;
headsah=(struct Head*)malloc(sizeof(struct Head));
headsah->cnt=0;
headsah->top=NULL;
headdelete=(struct Head*)malloc(sizeof(struct Head));
headdelete->cnt=0;
headdelete->frnt=NULL;
headdelete->rear=NULL;
headl=(struct Head*)malloc(sizeof(struct Head));
headl->cnt=0;
headl->p=NULL;
heads=(struct Head*)malloc(sizeof(struct Head));
heads->cnt=0;
heads->top=NULL;
headq=(struct Head*)malloc(sizeof(struct Head));
headq->cnt=0;
headq->frnt=NULL;
headq->rear=NULL;
}
void creatnodeforaccount(){
node=new Node;
cout<<"Enter name: ";
getline(cin,node->name);
cout<<"Enter password: ";
getline(cin,node->pass);
node->next=heada->p;
heada->p=node;
heada->cnt++;
}
int login(int l){
    l=0;
string nam,pas;
cout<<"Enter the name: ";
cin>>nam;
cout<<"Enter the password: ";
cin>>pas;
temp=heada->p;
for(int i=1;i<=heada->cnt;i++){
    if(temp->name==nam){
        if(temp->pass==pas){
           cout<<"Your account is successfully loged in"<<endl;
           l=1;
           break;
        }
    }
    temp=temp->next;
}
if(l==0){
   cout<<"Error"<<endl;
}
return l;
}
void addhistory(string n,string a){
node=new Node;
node->name=n;
node->artist=a;
node->next=headah->top;
headah->top=node;
headah->cnt++;
}
void deletehistory(string n){
node=new Node;
node->name=n;
node->next=headdh->top;
headdh->top=node;
headdh->cnt++;
}
void seeaddhistory(){
    temp=headah->top;
    int t=headah->cnt;
    cout<<"ADD HISTORY:"<<endl;
for(int i=1;i<=t;i++){
    headah->top=temp->next;
    cout<<temp->name<<endl;
    temp->next=headsah->top;
    headsah->top=temp;
    headsah->cnt++;
    headah->cnt--;
    temp=headah->top;
}
temp=headsah->top;
    int r=headsah->cnt;
for(int i=1;i<=r;i++){
    headsah->top=temp->next;
    temp->next=headah->top;
    headah->top=temp;
    headah->cnt++;
    headsah->cnt--;
    temp=headsah->top;
}
}
void seedeletehistory(){
    temp=headdh->top;
    int t=headdh->cnt;
    cout<<"DELETE HISTORY:"<<endl;
for(int i=1;i<=t;i++){
    headdh->top=temp->next;
    cout<<temp->name<<endl;
    temp->next=headsdh->top;
    headsdh->top=temp;
    headsdh->cnt++;
    headdh->cnt--;
    temp=headdh->top;
}
temp=headsdh->top;
    int r=headsdh->cnt;
for(int i=1;i<=r;i++){
    headsdh->top=temp->next;
    temp->next=headdh->top;
    headdh->top=temp;
    headdh->cnt++;
    headsdh->cnt--;
    temp=headsdh->top;
}
}
struct Node *insert(struct Node *temp_root, string n, string a,int i ){
    if(temp_root == NULL)
    {
        struct Node *p_root = new Node;
        p_root->left = NULL;
        p_root->right = NULL;
        p_root->name = n;
        p_root->artist = a;
        root = p_root;
        return 0;
    }
    z:
    if((int)n[i] == (int)temp_root->name[i]){
        i++;
        goto z;
    }
    else if((int)n[i] < (int)temp_root->name[i] && temp_root->left != NULL)
    {

        temp_root = temp_root->left;
        insert(temp_root,n, a,0);
    }
    else if((int)n[i] > (int)temp_root->name[i] && temp_root->right != NULL)
    {

        temp_root = temp_root->right;
        insert(temp_root,n, a,0);
    }
    else if(temp_root->left == NULL && (int)n[i] < (int)temp_root->name[i])
    {
        struct Node *p_root = new Node;
        p_root->name = n;
        p_root->artist = a;
        p_root->right = NULL;
        p_root->left = NULL;
        temp_root->left = p_root;
        return 0;
    }
    else if(temp_root->right == NULL  &&(int)n[i] > (int)temp_root->name[i])
    {
        struct Node *p_root = new Node;
        p_root->name = n;
        p_root->artist = a;
        p_root->right = NULL;
        p_root->left = NULL;
        temp_root->right = p_root;
        return 0;
    }
}
void inorder(struct Node *curr){
    if(curr!=NULL)
    {
        inorder(curr->left);
        cout <<  curr->name<<endl;
        inorder(curr->right);
    }
}
void inorderar(struct Node *curr,string mm){
    if(curr!=NULL)
    {
        inorderar(curr->left,mm);
        if(curr->artist==mm){
        cout <<  curr->name<<endl;
        }
        inorderar(curr->right,mm);
    }
}
struct Node *find_minimum(struct Node* root){
while(root->left != NULL){
    root = root->left;
}
  return root;
}
struct Node *find_maximum(struct Node* root){
while(root->right != NULL){
    root = root->right;
}
  return root;
}
struct Node* Delete(struct Node *root, string data,int i){
    if(root == NULL){
        return root;
    }
     if(data==root->name)
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else
        {
            if(root->right==NULL){
               struct Node *temp = find_maximum(root->left);
            root->name = temp->name;
            root->left= Delete(root->left,temp->name,i=0);
            }
            else{
            struct Node *temp = find_minimum(root->right);
            root->name = temp->name;
            root->right= Delete(root->right,temp->name,i=0);
            }
        }
    }
    else{
         z:
    if((int)data[i] == (int)root->name[i]){
        i++;
        goto z;
    }
    else if((int)data[i] < (int)root->name[i])
        root->left = Delete(root->left,data,i);
    else if ((int)data[i] > (int)root->name[i])
        root->right = Delete(root->right,data,i);
    }

    return root;
}
void addrequest(){
node=new Node;
cout<<"Enter the song's name: ";
getline(cin,node->name);
cout << "Enter artist's name: ";
getline(cin,node->artist);
if(headadd->cnt==0){
    node->next=NULL;
    headadd->frnt=node;
    headadd->rear=node;
    headadd->cnt++;
}
else{
node->next=NULL;
headadd->rear->next=node;
headadd->rear=node;
headadd->cnt++;
}
}
struct Node *seerequest(){
    add:
if(headadd->cnt==0){
    cout<<"List empty"<<endl;
}
else{
tempadd=headadd->frnt;
headadd->frnt=tempadd->next;
headadd->cnt--;
cout<<"Requested song is: ";
cout<<tempadd->name<<endl;
cout<<"If insert this song press 1 or if not press any: ";
int a;
cin>>a;
if(a==1){
    int i=0;
    insert(root, tempadd->name, tempadd->artist,i);
    addhistory(tempadd->name,tempadd->artist);
    goto add;
}
else{
    free(tempadd);
    goto add;
}
}
};
void deleterequest(){
node=new Node;
cout<<"Enter the song's name: ";
getline(cin,node->name);
if(headdelete->cnt==0){
    node->next=NULL;
    headdelete->frnt=node;
    headdelete->rear=node;
    headdelete->cnt++;
}
else{
node->next=NULL;
headdelete->rear->next=node;
headdelete->rear=node;
headdelete->cnt++;
}
}
struct Node *seeerequest(){
    delet:
if(headdelete->cnt==0){
    cout<<"There are no song."<<endl;
}
else{
tempdelete=headdelete->frnt;
headdelete->frnt=tempdelete->next;
headdelete->cnt--;
cout<<"The song name is: ";
cout<<tempdelete->name<<endl;
cout<<"If delete this song press 1 or if not press any: ";
int a;
cin>>a;
if(a==1){
    int i=0;
    Delete(root, tempdelete->name, i);
    deletehistory(tempdelete->name);
    goto delet;
}
else{
    free(tempadd);
    goto delet;
}
}
};
void searchh(struct Node *curr,string s){
    if(curr!=NULL)
    {
        searchh(curr->left,s);
        int p=0;
        if(s.length()<=curr->name.length()){
        for(int i=0;i<s.length();i++){
            if(s.at(i)!=curr->name.at(i)){
                p=1;
            }
        }
        if(p==0){
            cout<<curr->name<<endl;
        }
        }
        searchh(curr->right,s);
    }
}
int main(){
    cout<<"..........WELCOME TO MUSIC STATION.........."<<endl<<endl<<endl;
int l=0,i=0,d=0;
string n,a,de,nn,pp;
creathead();
main:
cout<<"1. Create Account"<<endl;
cout<<"2. Admin Login"<<endl;
cout<<"3. User Login"<<endl;
cout << "-----------------" << endl;
cout<<"Enter the choice: ";
int ow;
cin>>ow;
if(ow==1){
        cin.ignore();
creatnodeforaccount();
cout<<endl;
    cout<<endl;
    cout<<endl;
goto main;
}
else if(ow==2){
cin.ignore();
cout<<"Enter the name: ";
getline(cin,nn);
cout<<"Enter the password: ";
getline(cin,pp);
if(nn=="Johny"){
    if(pp=="1234"){
        d=2;
        cout<<"Successfully loged in."<<endl;
         cout<<endl;
    cout<<endl;
    cout<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto main;
    }
}
else if(nn=="Tanim"){
    if(pp=="5678"){
        d=2;
        cout<<"Successfully loged in."<<endl;
         cout<<endl;
    cout<<endl;
    cout<<endl;
    }
    else{
        cout<<"ERROR"<<endl;
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto main;
    }
    }

else{
    cout<<"ERROR"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    goto main;
}
}
else if(ow==3){
 cin.ignore();
d=login(l);
if(d==0){
        cout<<endl;
    cout<<endl;
    cout<<endl;
    goto main;
}
 cout<<endl;
    cout<<endl;
    cout<<endl;
}
else{
    cout<<"Wrong keyword."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    goto main;
}
if(d==2){
        mon:
    cout<<"1.Insert song"<<endl;
    cout<<"2.Delete song"<<endl;
    cout<<"3.Search song"<<endl;
    cout<<"4.Search song by Artist."<<endl;
    cout<<"5.Show added history"<<endl;
    cout<<"6.Show deleted history"<<endl;
    cout<<"7.Show added request"<<endl;
    cout<<"8.Show deleted request"<<endl;
    cout<<"9.List of songs"<<endl;
    cout<<"10.Logout"<<endl;
    int ou;
    cout << "------------------------" << endl;
    cout<<"Enter the choice: ";
    cin>>ou;
    if(ou==1){
    cin.ignore();
    cout << "Enter song's name: ";
    getline(cin,n);
    cout << "Enter artist's name: ";
    getline(cin,a);
    i=0;
    insert(root, n, a,i);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    goto mon;
    }
    else if(ou==2){
        cin.ignore();
    cout<<"Enter the name of the song for delete: ";
    getline(cin,de);
    i=0;
    Delete(root, de,i);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    goto mon;
    }
    else if(ou==3){
        cout<<"Enter the keyword: ";
    string key;
    cin.ignore();
    getline(cin,key);
    searchh(root,key);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    goto mon;
    }
    else if(ou==4){
        cin.ignore();
        cout<<"Enter the artist's name for search: ";
        string mm;
       getline(cin,mm);
       inorderar(root,mm);
       cout<<endl;
    cout<<endl;
    cout<<endl;
    goto mon;
    }
    else if(ou==5){
        cin.ignore();
        cout<<"<ADDED HISTORY>"<<endl;
        seeaddhistory();
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto mon;
    }
    else if(ou==6){
        cin.ignore();
        cout<<"<DELETED HISTORY>"<<endl;
        seedeletehistory();
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto mon;
    }
    else if(ou==7){
        cin.ignore();
        cout<<"<ADDED REQUEST>"<<endl;
        seerequest();
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto mon;
    }
    else if(ou==8){
        cin.ignore();
        cout<<"<DELETED REQUEST>"<<endl;
        seeerequest();
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto mon;
    }
    else if(ou==9){
        cout<<"<LIST OF SONGS>"<<endl;
        inorder(root);
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto mon;
    }
    else if(ou==10){
        d=0;
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto main;
    }
    else{
        cout<<"Wrong keyword."<<endl;
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto mon;
    }
}
else if(d==1){
        mono:
    cout<<"1.List of songs"<<endl;
    cout<<"2.Request for adding a song"<<endl;
    cout<<"3.Request for deleting a song"<<endl;
    cout<<"4.Search song"<<endl;
    cout<<"5.Search song by Artist"<<endl;
    cout<<"6.Show added history"<<endl;
    cout<<"7.Show deleted history"<<endl;
    cout<<"8.Logout"<<endl;
    cout << "--------------------------------------" << endl;
    int oy;
    cout<<"Enter the choice: ";
    cin>>oy;
    if(oy==1){
       cout<<"<LIST OF SONGS>"<<endl;
        inorder(root);
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto mono;
    }
else if(oy==2){
    cin.ignore();
    addrequest();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    goto mono;
}
else if(oy==3){
    cin.ignore();
    deleterequest();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    goto mono;
}
else if(oy==4){
    cout<<"Inter the keyword: ";
    string key;
    cin.ignore();
    getline(cin,key);
    searchh(root,key);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    goto mono;
}
else if(oy==5){
    cin.ignore();
        cout<<"Enter the artist's name for search: ";
        string mm;
       getline(cin,mm);
       inorderar(root,mm);
       cout<<endl;
    cout<<endl;
    cout<<endl;
    goto mono;
}
else if(oy==6){
    cin.ignore();
    cout<<"<ADDED HISTORY>"<<endl;
        seeaddhistory();
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto mono;
}
else if(oy==7){
    cin.ignore();
    cout<<"<DELETED HISTORY>"<<endl;
        seedeletehistory();
        cout<<endl;
    cout<<endl;
    cout<<endl;
        goto mono;
}
else if(oy==8){
    d=0;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    goto main;
}
else{
    cout<<"Wrong keyword."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    goto mono;
}
}
}
