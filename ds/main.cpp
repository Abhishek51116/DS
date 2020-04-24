#include <iostream>
using namespace std;
int size_of_segment_tree(int n){
    int x=1;
    while(n>x){
        x*=2;
    }
    return (2*x);
}
void buildTree(int* arr,int* tree,int start,int end,int treeNode){

    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = tree[2*treeNode]+tree[2*treeNode+1];

}
//update a given index
void update(int* tree,int node,int upi,int up,int low,int high){

if(low==high){
    tree[node] = up;
    return;
}
int mid = (low+high)/2;
if(upi<=mid)
    update(tree,2*node,upi,up,low,mid);
if(upi>mid)
   update(tree,2*node+1,upi,up,mid+1,high);
 tree[node] = tree[2*node]+tree[2*node+1];
 return;

}
//function to find sum query
int query(int* tree,int node, int low, int high, int l, int r)
{
    //cout<<tree[node]<<endl;
    if(l == low && high == r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (low + high) / 2;
    if(r<=mid) return query(tree,2*node,low,mid,l,r);
    if(l>mid) return query(tree,2*node+1,mid+1,high,l,r);
    int p1 = query(tree,2*node, low, mid, l, mid);
    //cout<<"p1:"<<p1<<endl;
    int p2 = query(tree,2*node+1, mid+1, high, mid+1, r);
   // cout<<"p2:"<<p2<<endl;
    return (p1 + p2);
}


int main() {
    int n;
    cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	int size = size_of_segment_tree(n);
	int* tree = new int[size];
	buildTree(arr,tree,0,n-1,1);
    	cout<<"segment tree:"<<endl;
	for(int i=1;i<size;i++){
	    cout<<tree[i]<<endl;
	}
	cout<<endl;
	//Query
	int qlow,qhigh;
	cin>>qlow>>qhigh;
	int q_ans = query(tree,1,0,n-1,qlow,qhigh);
	cout<<"Query "<<q_ans,,endl;;

    int up,upi;//update Number and update index
    cin>>upi>>up;
    update(tree,1,upi,up,0,n-1);



	return 0;
}
