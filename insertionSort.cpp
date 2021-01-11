#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ratio>
#include <vector>
#include <chrono>

#define N 30000

using namespace std;

vector<int> insertionSort(vector<int> &);
void insertionSortSameVector(vector<int> &);
void printDuration(chrono::steady_clock::time_point, chrono::steady_clock::time_point);

int main(){
    srand(time(NULL));
    vector<int> list;
    for (int i = 0; i < N; i++){
        list.push_back(rand());
    }
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    vector<int> sortedList = insertionSort(list);
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "Method 1 Sorted " << N << " numbers in:" <<  endl;
    printDuration(begin, end);
    begin = chrono::steady_clock::now();
    insertionSortSameVector(list);
    end = chrono::steady_clock::now();
    cout << "Method 2 Sorted " << N << " numbers in:" <<  endl;
    printDuration(begin, end);
}

void printDuration(chrono::steady_clock::time_point begin, chrono::steady_clock::time_point end){
    auto minutes = chrono::duration_cast<chrono::minutes>(end - begin).count(); 
    auto seconds = chrono::duration_cast<chrono::seconds>(end - begin).count();
    auto milliseconds = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    cout << minutes << "m " << seconds << "s " << milliseconds%100 << "ms"<< endl;
}

vector<int> insertionSort(vector<int> & list){
    vector<int>  sorted;
    int j;
    for (auto x : list){
        j = sorted.size();
        while(j > 0 && x < sorted[j-1] ){
            j--;
        }
        sorted.insert(sorted.begin() + j, x);
    }
    return sorted;
}

void insertionSortSameVector(vector<int> & list){
    int j, key;
    for(int i = 1; i < list.size(); i++){
        key = list[i];
        j = i - 1;
        while(j >= 0 && list[j] > key){                
            list[j + 1] = list[j];
            j--;
        }
        list[j+1] = key;
    }
}