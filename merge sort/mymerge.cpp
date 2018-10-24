#include <cstdio>
#include <vector>

using namespace std;

void mergesort(vector<int>& v);
void mergesort(vector<int>& v, int start, int end);
void merge(vector<int>& v, int leftStart, int mid, int rightEnd);
void print(vector<int>& v);

int main(){
    vector<int> v;
    v = {10, 9, 8, 7, 1, 3, 5, 2, 4, 6};
    print(v);
    mergesort(v, 0, v.size() - 1);
    print(v);
}

void print(vector<int>& v){
    for(int i : v)
        printf("%d ", i);
    printf("\n");
}

void mergesort(vector<int>& v){
    mergesort(v, 0, v.size() - 1);
}

void mergesort(vector<int>& v, int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesort(v, l, m);
        mergesort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

void merge(vector<int>& v, int l, int m, int r){
    vector<int> aux;
    int left = l;
    int right = m + 1;

    while(left <= m && right <= r)
        if(v[left] < v[right])
            aux.push_back(v[left++]);
        else
            aux.push_back(v[right++]);

    while(left <= m)
        aux.push_back(v[left++]);
    while(right <= r)
        aux.push_back(v[right++]);

    int index = 0;
    for (int i = l; i <= r; i++) v[i] = aux[index++];
}
