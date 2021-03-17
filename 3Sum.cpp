#include<bits/stdc++.h>
using namespace std;

//Brute Force
vector<vector<int>> threeSumBF(vector<int> nums){
    set<vector<int>> re;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> tem(3);
                    tem[0] = nums[i];
                    tem[1] = nums[j];
                    tem[2] = nums[k];
                    re.insert(tem);
                }
            }
        }
    }
    vector<vector<int>> result(re.begin(), re.end());
    return result;
}

//Two opointer Approach
vector<vector<int>> threeSumToPointer(vector<int> nums) {
    set<vector<int>> un;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i,j,k;
    for(int i=0;i<n-2;i++){
        j = i+1;
        k = n-1;
        while (k>j)
        {
            int sum = nums[i]+nums[j]+nums[k];
            if(sum==0){
                vector<int> temp(3);
                temp[0] = nums[i];
                temp[1] = nums[j];
                temp[2] = nums[k];
                un.insert(temp);
                j++;
                k--;
            }
            else if(sum>0){
                k--;
            }
            else{
                j++;
            }
        }
        
    }
    vector<vector<int>> result(un.begin(), un.end());
    return result;   
}

//Optimize Approach

vector<vector<int>> threeSum(vector<int> nums) {
    set<vector<int>> res;
    sort(nums.begin(), nums.end());
    unordered_map<int,int> my_map;
    for(int i=0;i<nums.size();i++){
        my_map[nums[i]]++;
    }
    for(int i=0;i<nums.size()-2;i++){
        my_map[nums[i]]--;
        for(int j=i+1;j<nums.size()-1;j++){
            my_map[nums[j]]--;
            vector<int> temp;
            auto it = my_map.find(-(nums[i]+nums[j]));
            if(it != my_map.end()){
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(-(nums[i]+nums[j]));
                res.insert(temp);
            }
            my_map[nums[j]]++;
        }
        my_map[nums[i]]++;
   }
   vector<vector<int>> result(res.begin(), res.end());
    return result;   
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>> result;
    //result = threeSumToPointer(v);
    //result = threeSumBF(v);
    result = threeSum(v);
    for(auto a : result){
        for(auto b : a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
}