/*
    Input: nums = [1,3,4,2,2]
    Output: 2

    Input: nums = [1,1,2]
    Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

int FindDuplicateNumber(vector<int> num){
    map<int , int> my_map;
    for(int a : num){
        my_map[a]++;
    }
    for(auto b : my_map){
        if(b.second>1){
            return b.first;
        }
    }
    return 0;
}

//Two pointer approach

int FindDuplicate(vector<int> num){

    int duplicate_num;
    sort(num.begin(), num.end());
    int slow=0;
    int fast =1;
    while (fast<num.size())
    {
        if(num[slow] != num[fast]){
            slow++;
            fast++;
        }
        else{
            return num[slow];
        }
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0 ; i < n ; i++){
        cin>>arr[i];
    }

    cout<<FindDuplicateNumber(arr)<<endl;

    cout<<FindDuplicate(arr)<<endl;
}