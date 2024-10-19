class Solution {
public:
    // vector<int> plusOne(vector<int>& digits) {
    //     long long ans=0;//int
    //     int multiplier=1;//int
    //     vector<int> ansList;
    //     // cout<<digits.size()<<endl;
    //     for(int i=digits.size()-1;i>=0;i--){
    //         // cout<<digits[i]<<endl;
    //         ans+=(digits[i]*multiplier);
    //         multiplier*=10;
    //     }
    //     ans+=1;
    //     while(ans){//ans/10 != 0
    //         ansList.insert(ansList.begin(), ans%10);// ansList.push_front(ans%10);//push_back and reverse the ans while returning from function
    //         ans/=10;
    //     }
    //     // if(digits[digits.size()-1]+1 == 10){
    //     //     digits[digits.size()-1] = 0;
    //     //     digits[digits.size()-2] += digits[digits.size()-2] + 1;//recursive soln
    //     // }else{
    //     //     digits[digits.size()-1] += digits[digits.size()-1] + 1;
    //     // }
    

    //     return ansList;
    // }

    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        for(int i = n-1; i >= 0; i--){
            if(i == n-1)
                v[i]++;
            if(v[i] == 10){
                v[i] = 0;
                if(i != 0){
                    v[i-1]++;
                }
                else{
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }
        return v;
    }

    // vector<int> plusOne(vector<int>& digits) {
    //     vector<int> number(digits);
    //     if (number[number.size() - 1] < 9) {    // if less than 9 then directly increment by 1 and return
    //         number[number.size() - 1] += 1;
    //         return number;
    //     } else  // else make a function call
    //         plusOne9(number, number.size()-1);
    //     return number;
    // }

private:
    void plusOne9(vector<int>& num, int idx) {
        if(idx==0 && num[idx]==9){  // when reached at index 1
            num[idx]=0;             // set value to 0
            num.insert(num.begin(), 1);     // insert 1 in beginning
            return;
        } 
        else if(num[idx]==9){       // if value is 9
            num[idx]=0;             // set to 0
            if(num[idx-1]==9)       // if prev value also 9 then make recursive call with idx-1 i.e for prev index
                plusOne9(num, idx-1);
            else
                num[idx-1] += 1;    // otherwise increment by 1
        }
    }
};
