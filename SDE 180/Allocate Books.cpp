#include <bits/stdc++.h>
using namespace std;


int countStudentHelper(vector<int> &a, int n, int b) {
    long long count=1, page = 0;
    for(int i=0; i<n; i++) {
        if(page + a[i] <= b) 
            page += a[i];
        else {
            count++;
            page = a[i];
        }
    }
    return count;
}
// time: O((array-sum) * n)
int countStudentLinear(vector<int> &a, int n, int s, int l, int r) {
    int count=1, page = 0;
    for(int b=l; b<=r; b++) {
        int students = countStudentHelper(a, n, b);
        if(students == s)
            return b;
    }
    return -1;
}

// time: OLog2((array-sum) * n)
int countStudentBS(vector<int> &a, int n, int s, int l, int r) {
    if(s > n)
        return -1;
    while(l <= r) {
        int mid = (l + r)/2;
        int students = countStudentHelper(a, n, mid);
        // if(students == s) ->avoiding to get min val
        //     return mid;
        if(students > s) 
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}

int booksApp1(vector<int> &a, int s) {
    int n = a.size();
    // to find: min (max page books allocated)
    int l = *max_element(begin(a), end(a)); // minimum possible case to give maxBooks
    int r = accumulate(begin(a), end(a), 0);
    
    return countStudentBS(a, n, s, l, r);
}


int Solution::books(vector<int> &A, int B) {
    return booksApp1(A, B);
}

