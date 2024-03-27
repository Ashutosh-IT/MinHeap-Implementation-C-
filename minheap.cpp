#include<iostream>
using namespace std;

class MinHeap{
  int *arr;
  int size,capacity;
  
  void Heapify(int index){
      
      int smallest = index;
      int left = index*2+1;
      int right = index*2+2;
      
      if(left<size && arr[left]<arr[smallest])
      smallest = left;
      if(right<size && arr[right]<arr[smallest])
      smallest = right;
      
      if(smallest == index) 
      return;
      
      swap(arr[index],arr[smallest]);
      Heapify(smallest);
      
  }
  
  public :
  MinHeap(int n){
      arr = new int[n];
      size = 0;
      capacity = n;
  }
  
  void insert(int x){
      if(size == capacity){
          cout<<"Heap Overflow..."<<endl;
          return;
      }
      int index = size++;
      arr[index] = x;
      
      while(index>0 && arr[(index-1)/2]>x){
          swap(arr[index],arr[(index-1)/2]);
          index = (index-1)/2;
      }
      
      cout<<x<<" inserted into heap"<<endl;
  }
  
  void remove(){
      if(size == 0){
          cout<<"Heap Underflow..."<<endl;
          return;
      }
      if(size == 1){
          cout<<arr[0]<<" deleted from heap"<<endl;
          size--;
          return;
      }
      
      cout<<arr[0]<<" deleted from heap"<<endl;
      arr[0] = arr[size-1];
      size--;
      
      Heapify(0);
  }
  
  
  void print(){
      for(int i=0; i<size; i++)
      cout<<arr[i]<<" ";
      cout<<endl;
  }
  
};

int main(){
    MinHeap H(10);
    H.insert(16);
    H.insert(4);
    H.insert(13);
    H.insert(8);
    H.print();
    H.remove();
    H.remove();
    H.print();
    H.insert(15);
    H.insert(8);
    H.print();
    
    
}
