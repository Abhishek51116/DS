#include <iostream>
#include <math.h>
using namespace std;
int size_of_segment_tree(int n){
    int  p = pow(2,ceil(log(n)/log(2)));
    return 2*p;
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



void update(int* tree,int* lazy,int node,int low,int high,int l,int r ,int val){
if (lazy[node] != 0)
    {
        tree[node] += (low-high+1)*lazy[node];

        if (low != high)
        {

            lazy[node*2]   += lazy[node];
            lazy[node*2 + 1]   += lazy[node];
        }

        lazy[node] = 0;
    }

if (low==l && high==r)
    {

        tree[node] += (high-low+1)*val;
//cout << "tree node value that was updated "<<tree[node]<<" node:"<<node<<endl;;
        if (low != high)
        {
            lazy[node*2 ]   += val;
            lazy[node*2 + 1]   += val;
        }
        return;
    }
     int mid = (low+high)/2;
    if(r<=mid)
    update(tree,lazy,node*2,low,mid,l,r,val);
else if(l>mid)
   update(tree,lazy,2*node+1,mid+1,high,l,r,val);
    else{
    update(tree,lazy,node*2,low,mid,l,mid,val);
    update(tree,lazy,node*2+1,mid+1,high,mid+1,r,val);
    }
   tree[node] = tree[2*node]+tree[2*node+1];
  // cout<<"returning node"<<node<<"value"<<tree[node]<<endl;
    return;
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
	int lazy[size] = {0};
    	cout<<"segment tree:"<<endl;
	for(int i=1;i<size;i++){
	    cout<<"tree: "<<tree[i]<<" lazy: "<<lazy[i]<<endl;
	}
	cout<<endl;
    int rangel,rangeh;
    cin >>rangel>>rangeh;
    int val;
    cin >>val;
    update(tree,lazy,1,0,n-1,rangel,rangeh,val);
    cout<<    endl;
	cout<<"segment tree:"<<endl;
	for(int i=1;i<size;i++){
	    cout<<"tree: "<<tree[i]<<" lazy: "<<lazy[i]<<endl;
	}
	cout<<endl;
	/*int suml,sumh;
	query(tree,lazy,1, 0, n-1, suml, sumh);*/
	return 0;
}
