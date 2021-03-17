
#include<bits/stdc++.h>
using namespace std;

//Binary Search  

int SearchInsertBinarySearch(vector<int> num , int target){
    int left =0;
    int right = num.size()-1;
    
    int middle;
    while(left<=right){
        middle = (left+right)/2;

        if(num[middle]==target){
            return middle;
        }
        else if(num[middle]>target){
            right = middle-1;
        }
        else {
            left = middle+1;
        }

    }
    return left;
}


int SearchInsert(vector<int> nums , int target){
    int i;
    for(i=0;i<nums.size();i++){
        if(nums[i]==target){
            return i;
        }
        if(nums[i]>target){
            return i;
            break;
        }
    }
    if(i==nums.size()){
        return i;
    }
    else{
        return 1;
    }
}

int main(){
    int t,n;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<SearchInsert(v,t);

}