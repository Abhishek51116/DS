#include <iostream>

using namespace std;

int getSum(int Bit[], int index)
{
    int sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += Bit[index];
        index -= index & (-index);
    }
    return sum;
}

void update(int val,int* Bit,int size,int index){
    index = index+1;
    while(index <=size){
        Bit[index] +=val;
        index += index & (-index);
    }
}
int* constBit(int *arr,int size){
int *Bit = new int[size+1];
for(int i=0;i<size+1;i++){
    Bit[i] = 0;
}
for(int i=0;i<size;i++){
    update(arr[i],Bit,size,i);
}

    for(int i=1;i<size+1;i++){
        cout<<Bit[i]<<" ";
    }
    return Bit;
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int* Bit = constBit(arr,size);
    int queryI;
    cin>>queryI;
    int query=getSum(Bit,queryI);
    cout<<query<<endl;
    return 0;
}
