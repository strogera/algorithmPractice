#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ratio>
#include <vector>
#include <chrono>

#define N 100000

using namespace std;

vector<int> mergeSort(vector<int> &);
void printDuration(chrono::steady_clock::time_point, chrono::steady_clock::time_point);

int main(){
    srand(time(NULL));
    vector<int> list;
    for (int i = 0; i < N; i++){
        list.push_back(rand());
    }
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    vector<int> sortedList = mergeSort(list);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Sorted " << N << " numbers in:" <<  endl;
    printDuration(begin, end);
}

void printDuration(chrono::steady_clock::time_point begin, chrono::steady_clock::time_point end){
    auto minutes = chrono::duration_cast<chrono::minutes>(end - begin).count(); 
    auto seconds = chrono::duration_cast<chrono::seconds>(end - begin).count();
    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    cout << minutes << "m " << seconds << "s " << milliseconds%100 << "ms"<< endl;
}


vector<int> merge(vector<int> & list1, vector<int> & list2){
	int i, j;
	vector<int> merged;
	for(i = 0, j = 0; i < list1.size() && j < list2.size();){
		if(list1[i] < list2[j]){
			merged.push_back(list1[i++]);

		}else{
			merged.push_back(list2[j++]);
		}
	}
	while(i<list1.size()){
		merged.push_back(list1[i++]);
	}
	while(j<list2.size()){
		merged.push_back(list2[j++]);
	}
	return merged;
}

vector<int> mergeSort(vector<int> & list){
	int size = list.size();
	if(size <= 1){
		return list;	
	}
	vector<int> ls1 = vector<int>(list.begin(), list.begin() + (size+1)/2);
	vector<int> l1 = mergeSort(ls1);
	vector<int> ls2 = vector<int>(list.begin()+(size+1)/2, list.end());
	vector<int> l2 = mergeSort(ls2);
	vector<int> sorted = merge(l1, l2);
	return sorted;
}
