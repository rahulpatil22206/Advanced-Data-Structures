#include<bits/stdc++.h> 
using namespace std; 

class Hash { 
	int BUCKET; 
	list<int> *table; 
    public: 
    	Hash(int V);
    
    	void insertItem(int x);
    	
    	int search(int val); 
    
    	void deleteItem(int key); 
    
    	int hashFunction(int x){ 
    		return (x % BUCKET); 
    	} 
    
    	void displayHash(); 
}; 

Hash::Hash(int b){ 
	this->BUCKET = b; 
	table = new list<int>[BUCKET]; 
} 


void Hash::insertItem(int key){ 
	int index = hashFunction(key); 
	table[index].push_back(key); 
} 


int Hash::search(int val) { 
    int index = hashFunction(val); 
     
    list <int> :: iterator i; 
    for (i = table[index].begin(); i != table[index].end(); i++) { 
    	if (*i == val) 
    	break; 
    } 
    if (i != table[index].end()) 
    	return index;
    return -1;
} 

void Hash::deleteItem(int key){ 
    int index = hashFunction(key); 
     
    list <int> :: iterator i; 
    for (i = table[index].begin(); i != table[index].end(); i++) { 
    	if (*i == key) 
    	break; 
    } 
    
    if (i != table[index].end()) 
    	table[index].erase(i); 
} 


void Hash::displayHash() { 
    for (int i = 0; i < BUCKET; i++){ 
    	cout << i <<" "; 
    	for (auto x : table[i]) 
    	cout << " --> " << x; 
    	cout << endl; 
    } 
} 


int main() {
    int m, n;
    cout<<"Enter the count of buckets in Hash table : ";
    cin>>m;
    Hash h(m);
    cout<<"Enter a element to insert into Hash table : ";
    cin>>n;
    while(n!=-1){
        h.insertItem(n);
        cout<<"Enter a element to insert into Hash table : ";
        cin>>n;
    }
    cout<<"\nThe hash table after insertion is : \nKeys\tElements"<<endl;
    h.displayHash(); 
    cout<<"\nEnter an element to search a element in hash table : ";
    cin>>n;
    if(h.search(n) == -1)
        cout<<"Element "<<n<<" is not found :("<<endl;
    else
        cout<<"Element "<<n<<" is found at key "<<h.search(n)<<endl;
    cout<<"\nEnter an element to delete from hash table : ";
    cin>>n; 
    h.deleteItem(n); 
    cout<<"\nThe hash table after Deletion is : "<<endl;
    h.displayHash(); 
    return 0; 
}
