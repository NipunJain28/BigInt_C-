#if !defined(BIGINT_H)
#define BIGINT_H
#include<bits/stdc++.h>
using namespace std;
bool isDigit(char &ch){
    if(ch>='0' && ch<='9'){
        return true;
    }
    else{
        return false;
    }
}
class BigInt{
    std::string val;
    public:
    BigInt(){

    }
    BigInt(std::string s){
        for(int start=0;start<s.length();start++){
            if(!isDigit(s[start])){
                std::cout<<"Not a valid Big Int!!";
                return;
            }
        }
        val=s;
    }
    //checks if two big Integers are equal or not!!
    bool operator ==(const BigInt &a){
        string num1=this->val;
        string num2=a.val;
        
        if(num1.length()!=num2.length()){
            return false;
        }
        else{
            for(int i=0;i<num1.length();i++){
                if(num1[i]!=num2[i]){
                    return false;
                }
            }
            return true;
        }
    }
    //perform addStringition of bigInt Number
    BigInt operator +(const BigInt &bigInt){
        std::string temp1=this->val;
        std::string temp2=bigInt.val;
        std::string sum;
        int i=temp1.length()-1;//i for temp 1 length
        int j=temp2.length()-1;//j for temp 2 length
        int carry=0;//carry used for addStringition
        while(i>=0 && j>=0){
            int addStringition=(temp1[i]-'0')+(temp2[j]-'0')+carry;
            int digit=addStringition%10;
            carry=addStringition/10;
            sum+=(digit+'0');i--;j--;
        }
        while(i>=0){//if some digits are still remaining in temp1
            int addStringition=(temp1[i]-'0')+carry;
            int digit=addStringition%10;
            carry=addStringition/10;
            sum+=(digit+'0');i--;
        }
        while(j>=0){//if digits are still remaining in temp2
            int addStringition=(temp2[j]-'0')+carry;
            int digit=addStringition%10;
            carry=addStringition/10;
            sum+=(digit+'0');j--;
        }
        while(carry!=0){
            int addStringition=carry%10;
            carry=carry/10;
            sum+=(addStringition+'0');
        }
        //now sumis ready just reverse it
        
        std::reverse(sum.begin(),sum.end());
        std::cout<<"Sum is:"<<sum<<std::endl;
        BigInt result(sum);
        
        return result;

        
    }
   
   //Subtraction
   BigInt operator-(const BigInt &bigInt){
    std::string temp1=this->val;
        std::string temp2=bigInt.val;
        string ans=subtract(temp1,temp2);
        BigInt result(ans);
        return result;
   }
    string subtract(string str1,string str2){//return str1-str2
        if(str1<str2){
            string temp=str1;
            str1=str2;
            str2=temp;
        }
        int str1_len=str1.length();
        int str2_len=str2.length();
        string ans="";
        if(str1==str2){
            return "0";
        }
        else if(str1[0]=='-' && str2[0]=='-'){
            if(str2_len==1 && str1_len==1){
                ans="0";
            }
            else{
                BigInt t1(str1.erase(0,1));
                BigInt t2(str2.erase(0,1));
                string temp=subtract(t2.val,t1.val);
                BigInt mx=maximum(t2.val,t1.val);
                if(temp[0]!='-' && mx.val==t1.val){
                    ans="-"+temp;
                }
                else{
                    ans=temp;
                }
            }
            

        }else if(str1[0]=='-'){
                ans="-"+addString(str1.erase(0,1),str2);
            }
            else if(str2[0]=='-'){
                ans=addString(str1,str2.erase(0,1));
            }
            else{
                //MAIN FUNCTION TO IMPLEMENT SUBTRACT
                int i,j,sum,carry=0;
                if(str1_len<str2_len){
                    string t=str1;
                    str1=str2;
                    str2=t;
                    ans="-"+subtract(str1,str2);
                    return ans;
                }
                else if(str1_len==str2_len){
                    BigInt a(str1);
                    BigInt b(str2);
                    BigInt mx=maximum(a.val,b.val);
                    if(mx.val==str2){
                        string t=str1;
                        str1=str2;
                        str2=t;
                        BigInt t1(str1);
                        BigInt t2(str2);
                        BigInt temp=subtract(str1,str2);
                        ans="-"+subtract(str1,str2);
                        return ans;
                    }
                }
                int val1,val2;
                for(i=str1_len,j=str2_len;i>=0 || j>=0;--i,--j){
                    if(i>=0){
                        val1=(int)str1[i]-48;
                    }
                    else{
                        val1=0;
                    }
                    if(j>=0){
                        val2=(int)str2[j]-48;
                    }
                    else{
                        val2=0;
                    }
                    sum=val1-val2-carry;
                    if(sum<0){
                        sum+=10;
                        carry=1;
                    }
                    else{
                        carry=0;
                    }
                    ans=to_string(sum)+ans;
                }
            }
            ans=ans.erase(ans.length()-1,1);
            ans=ans.erase(0,1);
            int index=0;
            while(index<ans.length() && ans[index]=='0'){
                index++;
            }
            if(index>=ans.length()){
                return "0";
            }
            else{
                ans=ans.substr(index,ans.length()-index+1);
            }
            // cout<<"Subtraction is:"<<ans<<endl;
            return ans;
    }
    //PRint Result
    void printResult(){
        std::cout<<val<<std::endl;
    }
    bool is_strictlyMaximum(string str1,string str2){
        if(str1==str2){
            return false;
        }
        if(str1==maximum(str1,str2)){
            return true;
        }
        return false;
    }
    BigInt operator ^(BigInt &bigint){
        string temp1=bigint.val;
        string temp2=this->val;
        string ans=pow(temp2,temp1);
        BigInt result(ans);
        return result;
    }
    string pow(string str1,string str2){//returns str1^str2->Power Function
        if(str2=="0"){
            return "1";
        }
        string temp=str1;
        while(str2!="1"){
            str1=multiply(str1,temp);
            str2=subtract(str2,"1");
        }
        return str1;
    }
     string maximum(string str1,string str2){
        string max="";
        bool bothNeg=false;
        bool isMax1=false;
        bool isMax2=false;
        if(str1[0]=='-' && str2[0]=='-'){
            bothNeg=true;
            str1.erase(0,1);
            str2.erase(0,1);
        }
        else if(str1[0]=='-'){
            return str2;
        }
        else if(str2[0]=='-'){
            return str1;
        }
        int len1=str1.length();
        int len2=str2.length();
        if(len1==len2){
            for(int i=0;i<len1;++i){
                if(str1[i]!=str2[i]){
                    if(str1[i]>str2[i]){
                        isMax1=true;
                    }
                    else{
                        isMax2=true;
                    }
                    break;
                }
            }
            if(!(isMax2^isMax1)){
                isMax1=true;
            }
            
        }
        else if(len1>len2){
                isMax1=true;
            }
            else{
                isMax2=true;
            }
            if(bothNeg){
                if(isMax1){
                    return "-"+str2;
                }
                else{
                    return "-"+str1;
                }
            }
            else{
                if(isMax1==true){
                    
                  
                    return str1;
                }
                else{
                    
                    return str2;
                }
            }
    }
    //Compare 2 Values
    BigInt compareValues(const BigInt &val1,const BigInt &val2){
        std::string num1=val1.val;
        std::string num2=val2.val;
        // std::cout<<"Num 1 is:"<<num1<<endl;
        if(num1.length()>num2.length()){
            std::cout<<num1<<">"<<num2<<endl;
            return val1;
        }
        else if(num1.length()<num2.length()){
            std::cout<<num1<<"<"<<num2<<endl;
            return val2;
        }
        else{
            for(int i=0;i<num1.length();i++){
                if((num1[i]-'0')>(num2[i]-'0')){
                    std::cout<<num1<<">"<<num2<<endl;
                    return val1;
                }
                else if((num1[i]-'0')<(num2[i]-'0')){
                    std::cout<<num1<<"<"<<num2<<endl;
                    return val2;
                }
            }
            cout<<"Both Values are equal!!"<<endl;
            return val1;
        }
    }
    string addString(string a,string b){
        // cout<<"Addition of"<<a<<" "<<b<<endl;
        if(a=="" && b==""){
            return "";
        }
        else if(a==""){
            return b;
        }
        else if(b==""){
            return a;
        }
        string sum="";
        int i=a.length()-1;//i for temp 1 length
        int j=b.length()-1;//j for temp 2 length
        int carry=0;//carry used for addStringition
        while(i>=0 && j>=0){
            int addition=(a[i]-'0')+(b[j]-'0')+carry;
            int digit=addition%10;
            carry=addition/10;
            sum+=(digit+'0');i--;j--;
        }
        while(i>=0){//if some digits are still remaining in temp1
            int addition=(a[i]-'0')+carry;
            int digit=addition%10;
            carry=addition/10;
            sum+=(digit+'0');i--;
        }
        while(j>=0){//if digits are still remaining in temp2
            int addition=(b[j]-'0')+carry;
            int digit=addition%10;
            carry=addition/10;
            sum+=(digit+'0');j--;
        }
        while(carry!=0){
            int addition=carry%10;
            carry=carry/10;
            sum+=(addition+'0');
        }
        
        // now sumis ready just reverse it
        
        std::reverse(sum.begin(),sum.end());
        // cout<<"Addition result is:"<<sum<<endl;
        // std::cout<<"Sum is:"<<sum<<std::endl;
        return sum;
    }
    //MULTIPLICATION 
    string multiply(string temp1,string temp2){
        string ans="";
        //start multuiplying them
        int k=0;
        for(int i=temp1.length()-1;i>=0;i--){
            int carry=0;
            string temporary="";
            for(int j=temp2.length()-1;j>=0;j--){
                int val=temp1[i]-'0';
                int multiplication=(val*(temp2[j]-'0'))+carry;
                int digit=multiplication%10;
                carry=multiplication/10;
                temporary+=(digit+'0');
            }
            while(carry!=0){
                int digit=carry%10;
                carry=carry/10;
                temporary+=(digit+'0');
            }
            reverse(temporary.begin(),temporary.end());
            int zeroes=k;
            while(zeroes!=0){
                temporary+='0';
                zeroes--;
            }
            ans=addString(ans,temporary);
            k++;
            // cout<<"Answer after addStringing is:"<<ans<<endl;
        }
        return ans;
    }
    BigInt operator * (BigInt &bigInt){
        std::string temp1=this->val;
        std::string temp2=bigInt.val;
        string ans="";
        //start multuiplying them
        int k=0;
        for(int i=temp1.length()-1;i>=0;i--){
            int carry=0;
            string temporary="";
            for(int j=temp2.length()-1;j>=0;j--){
                int val=temp1[i]-'0';
                int multiplication=(val*(temp2[j]-'0'))+carry;
                int digit=multiplication%10;
                carry=multiplication/10;
                temporary+=(digit+'0');
            }
            while(carry!=0){
                int digit=carry%10;
                carry=carry/10;
                temporary+=(digit+'0');
            }
            reverse(temporary.begin(),temporary.end());
            int zeroes=k;
            while(zeroes!=0){
                temporary+='0';
                zeroes--;
            }
            ans=addString(ans,temporary);
            k++;
            // cout<<"Answer after addStringing is:"<<ans<<endl;
        }
       
         BigInt a(ans);
         return a;
    }
    //DIVISION
    string divide(std::string str1, std::string str2) {                   // return arithmetic division of str1/str2
    // cout<<"String 1 is:"<<str1<<endl;
    // cout<<"String 2 is:"<<str2<<endl;
    std::string ans = "";
    if(str2 == "0") {
        return "0";
    } else if(str1 == str2) {
        return "1";
    } else { 
        if(str2 == "1")
            return str1;
        if(is_strictlyMaximum(str2, str1)) {
            return "0";
        }
        if(str2.length() <= 19) {
            std::stringstream strstrm(str2);
            unsigned long long int int_str2 = 0;
            strstrm >> int_str2;
            ans = shortDivide(str1, int_str2);
        }
        else {
            std::string temp = str2;
            ans = "0";
            std::string count = "0";
            while(str1 == maximum(str1, str2)) {
               
                int lenDiff = str1.length() - str2.length();
                if(lenDiff > 0 && str1[0] > str2[0]) {
                    
                    count = addString(count, pow("10", std::to_string(lenDiff)));
                    str1 = subtract(str1, multiply(str2, pow("10", std::to_string(lenDiff))));
                   
                } else if(lenDiff > 0) {
                    
                    count = addString(count, pow("10", std::to_string(lenDiff-1)));
                    
                    str1 = subtract(str1, multiply(str2, pow("10", std::to_string(lenDiff-1))));
                    
                } else {
                    // cout<<"In last"<<endl;
                    count = addString(count, "1");
                    str1 = subtract(str1, str2);
                    
                }
                // cout<<"Count is:"<<count<<endl;
            }
            ans = count;
            // cout<<"Answer is:"<<ans<<endl;
        }
    }
    return ans;
}
    string shortDivide(string s1,unsigned long long int divisor){//return str1/str2
        string ans;
        int index=0;
        long long int temp=s1[index]-'0';
        while(temp<divisor){
            temp=temp*10+(s1[++index]-'0');
            if(index>=s1.length()){
                break;
            }
        }
        while(s1.length()>index){
            ans+=(temp/divisor)+'0';
            temp=(temp%divisor)*10+s1[++index]-'0';
        }
        if(ans.length()==0){
            return "0";
        }
        return ans;
    }
    BigInt operator / (BigInt &bigInt){
        // cout<<"In division"<<endl;
        string str1=this->val;
        string str2=bigInt.val;
        string ans=divide(str1,str2);
        // cout<<"Answer is"<<ans<<endl;
        BigInt result(ans);
        return result;
    }
   
    
    BigInt calculateFactorial(int n){
        BigInt temp("1");
        BigInt ans("1");
        if(n==1 || n==0){
            return temp;
        }
        for(int i=2;i<=n;i++){
            BigInt temp(to_string(i));
            ans=ans*temp;
            cout<<"Factorial of "<<i<<"is: ";ans.printResult();
            cout<<endl;
        }
        return ans;
    }
    //GET LENGTH
    
    BigInt getLength(const BigInt &b){
        string t=b.val;
        int len=t.length();
        BigInt ans(to_string(len));
        return ans;
    }

    //Calculate Fibonnaci
    BigInt fibonnaci(int n){
        BigInt num1("0");
        BigInt num2("1");
        if(n==0){
            return num1;
        }
        if(n==1){
            return num2;
        }
        BigInt ans;
        for(int i=2;i<=n;i++){
            
            ans=num1+num2;
            num1=num2;
            num2=ans;
            cout<<"Fibonnaci of "<<i<<":";
            ans.printResult();
            cout<<endl;
        }
        return ans;
    }
   
   
};



#endif // "bigInt"
