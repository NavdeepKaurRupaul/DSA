#include<iostream>
using namespace std;
//#include<vector>
//#include<climits>
class PriorityQueue{
	vector<int> pq;
	public:
		//to check PQ is empty or not function
		bool isEmpty(){
			return pq.empty()==0;
		}
		//to check size of PQ function
		int getSize(){
			return pq.size();
		}
		//to get the minimum element of PQ function
		int getMin(){
			return pq[0];
		}
		//to insert element in PQ function
		void insert(int element){
			pq.push_back(element);
			int ChildIndex = pq.size()-1;
			while(ChildIndex > 0){
				int ParentIndex = (ChildIndex-1)/2;
				if(pq[ChildIndex] < pq[ParentIndex]){
					int temp = pq[ChildIndex];
					pq[ChildIndex] = pq[ParentIndex];
					pq[ParentIndex] = temp;
				}
				else{
					break;
				}
				ChildIndex = ParentIndex;
			}
		}
		//to delete element in PQ function
		int removeMin() {
		    if(isEmpty()) {
			   return 0;		// Priority Queue is empty
	    	}
		    int ans = pq[0];
		    pq[0] = pq[pq.size() - 1];
		    pq.pop_back();
		    int parentIndex = 0;
		    int leftChildIndex = 2 * parentIndex + 1;
		    int rightChildIndx = 2 * parentIndex + 2;	
		    while(leftChildIndex < pq.size()) {
		    	int minIndex = parentIndex;
			    if(pq[minIndex] > pq[leftChildIndex]) {
				    minIndex = leftChildIndex;
		    	}
			    if(rightChildIndx < pq.size() && pq[rightChildIndx] < pq[minIndex]) {
				    minIndex = rightChildIndx;
			    }
			    if(minIndex == parentIndex) {
			    	break;
			    }
		    	int temp = pq[minIndex];
		    	pq[minIndex] = pq[parentIndex];
		    	pq[parentIndex] = temp;		
		    	parentIndex = minIndex;
		    	leftChildIndex = 2 * parentIndex + 1;
		    	rightChildIndx = 2 * parentIndex + 2;
		    }
		return ans;
	    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}

