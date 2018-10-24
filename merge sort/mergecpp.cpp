#include <vector>
#include <cstdio>

#define pb(n) push_back(n)

using namespace std;

typedef vector<int> vi;

int merge(vi &v, int l, int m, int r) {
    vector<int> aux;

    int left = l;
    int right = m + 1;

    while(left <= m && right <= r) 
        if(v[left] < v[right]) 
            aux.push_back(v[left++]);
        else 
            aux.push_back(v[right++]);

    while (left <= m)
        aux.push_back(v[left++]);
    while (right <= r)
        aux.push_back(v[right++]);

    int index = 0;
    for (int i = l; i <= r; i++) v[i] = aux[index++];
}

int msort(vector<int> &v, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        msort(v, l, mid);
        msort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}

int main(){
    vi v = {10, 9, 8, 7, 1, 3, 5, 2, 4, 6};
    msort(v, 0, v.size() - 1);
    for(int i : v)
        printf("%d ", i);
}