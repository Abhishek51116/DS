#include <iostream>
using namespace std;
int size_of_segment_tree(int n){
    int x=1;
    while(n>x){
        x*=2;
    }
    return (2*x-1);
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
	for(int i=1;i<size;i++){
	    cout<<tree[i]<<endl;
	}
	return 0;
}

