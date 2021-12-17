#include<iostream>
using namespace std;
#include<string>

template<typename V>
class MapNode{
	public:
		string key;
		V value;
		MapNode* next;
		
		MapNode(string key, V value){
			this->key = key;
			this->value = value;
			next = NULL;
		}
		
		~MapNode(){
			delete next;
		}
};

template<typename V>
class ourmap{
	MapNode<V>** buckets;
	int count;
	int numBuckets;
	//to get bucket index function
	int getBucketIndex(string key){
		int hasCode = 0;
		int currentCoeff = 1;
		for(int i=key.length()-1;i>=0;i++){
			hasCode += key[i]*currentCoeff;
			hasCode%numBuckets;
			currentCoeff *= 37;
			currentCoeff = currentCoeff%numBuckets;
		}
		return hasCode%numBuckets;
		}
	//rehash function
	void rehash(){
		MapNode<V>** temp = buckets;
		buckets = new MapNode<V>*[2*numBuckets];
		for(int i=0;i<2*numBuckets;i++){
			buckets[i]=NULL;
		}
		int oldBucketCount = numBuckets;
		numBuckets *= 2;
		count = 0;
		for(int i =0;i<oldBucketCount;i++){
			MapNode<V>* head = temp[i];
			while(head != NULL){
				string key = head->key;
				V value = head->value;
				insert(key,value);
				head = head->next;
			}
		}
		for(int i=0;i<oldBucketCount;i++){
			MapNode<V>* head = temp[i];
			delete head;
		}
		delete [] temp;
	}	
		public:
			//constructor
			ourmap(){
				count = 0;
				numBuckets=5;
				buckets= new MapNode<V>*[numBuckets];
				buckets=NULL;
			}
			//destructor
			~ourmap(){
				for(int i=0;i,numBuckets;i++){
					delete buckets[i];
				}
				delete [] buckets;
			}
			//size function
			int size(){
				return count;
			}
			//insert function
			void insert(string key, V value) {
		        int bucketIndex = getBucketIndex(key);
		        MapNode<V>* head = buckets[bucketIndex];
		        while (head != NULL){
			        if (head->key == key) {
				    head->value = value;
				    return;
				}
			    head = head->next;
			}
		    head = buckets[bucketIndex];
		    MapNode<V>* node = new MapNode<V>(key, value);
		    node->next = head;
		    buckets[bucketIndex] = node;
		    count++;
		    double LoadFactor = (1.0*count)/numBuckets;
		    if(LoadFactor>0.7){
		    	rehash();
			}
		    }
		    //get loadfactor function
		    double getLoadFactor(){
		    	return (1.0*count)/numBuckets;
			}
			//delete function
			V remove(string key){
				int bucketIndex = getBucketIndex(key);
				MapNode<V>* head= buckets[bucketIndex];
				MapNode<V>* previous = NULL;
				while(head != NULL){
					if(head->key == key){
						buckets[bucketIndex]=head->next;
					}
					else{
						previous->next = head->next;
					}
					V value = head->value;
					head->next = NULL;
					delete head;
					count--;
					return value;
				}
				previous = head;
				head = head->next;
				return 0;
			}
			//search function
			V getValue(string key){
				int bucketIndex = getBucketIndex(key);
				MapNode<V>* head= buckets[bucketIndex];
				while(head != NULL){
					if(head->key == key){
						return head->value;
					}
					head = head->next;
				}
				return 0;
			}
	};
int main(){
	ourmap<int> map;
	for(int i=0;i<10;i++){
		char c = '0'+i;
		string key = "abc";
		key = key+c;
		int value = 1+i;
		map.insert(key,value);
		cout<<"LOAD FACTOR : "<<map.getLoadFactor()<<" ";
	}
	cout<<endl;
	for(int i=0;i<10;i++){
		char c = '0'+i;
		string key = "abc";
		key = key+c;
		cout<<"ENTERIES IN MAP ARE:"<<endl;
		cout<<key<<":"<<map.getValue(key)<<endl;
		}
		cout<<"SIZE OF MAP IS : "<<map.size()<<endl;
		map.remove("abc2");
		map.remove("abc7");
		for(int i=0;i<10;i++){
		char c = '0'+i;
		string key = "abc";
		key = key+c;
		cout<<"ENTERIES IN MAP AFTER DELETION ARE:"<<endl;
		cout<<key<<":"<<map.getValue(key)<<endl;
		}
		cout<<"SIZE OF MAP AFTER DELETION IS : "<<map.size()<<endl;
}
