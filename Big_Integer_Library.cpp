#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<cstring>
#define ll long long
#define limit 1000
using namespace std;

void fact();
string multiply(string  , string );
void fastexp();
string divide(string);
void gcd(string , string);
string subtract(string , string);
bool my_compare(string ,string);


int main()
{
    // cout << "Enter the number of test cases : ";
    ll t;
    cin >> t;

    for(ll i = 0 ; i < t ; i++){
        // cout << "Enter your choice between 1-3: ";
        ll k;
        cin >> k;
        if(k == 1)
            fastexp();
        else if(k == 2){
            string n1 , n2;
            // cout << "Enter the numbers : ";
            cin >> n1;
            cin >> n2;
            // if(n2.compare(n1) < 0){
                // n1.swap(n2);
            // }
            gcd(n1 , n2);
        } 
        else if(k == 3)
            fact();
        // else
            // cout << "Invalid Choice \n";
    }
}

string divide(string s)
{
    ll temp = s[0] -'0';
    ll index = 0;
    string result;
    while(temp < 2 && temp != 0)
    {
        index++;
        temp = temp*10  + (s[index] - '0');
    }

    while(s.length() > index)
    {
        string val = to_string(temp/2);
        result = result + val;
        index++;
        temp = (temp%2)*10 + (s[index]-'0');
    }

    if(result.length() == 0)
        return "0";
    else
        return result;
}


string multiply(string n1 , string n2)

{
    ll n1len = n1.length();
    ll n2len = n2.length();
    ll len = n1len + n2len;
    vector<ll> answer(len , 0);
    ll index1 =0;

    for(ll i = n1len-1 ; i > -1 ; i--)
     {
        ll carry = 0;
        ll num1 = n1[i] - '0';
        ll index2 = 0;

        for(ll j = n2len-1 ; j > -1 ; j--)
	{
            ll num2 = n2[j] - '0';
            ll prod = num1*num2 + carry + answer[index1 + index2];
            answer[index1 + index2] = prod%10;
            carry = prod/10;

            index2++;


        }
        if(carry > 0)
            answer[index1 + index2] = answer[index1 + index2] + carry;

        index1++;
    }

    ll i = answer.size() - 1;
    while (i>=0 && answer[i] == 0)
    i--;

    if(i == -1)
        return "0";

    string result = "";


    while(i > -1)
   {
        result = result + to_string(answer[i]);
        i--;
    }

    return result;
}

void fact()
{
    // cout << "Enter your number: ";
    string f , temp = "2", result = "1";

    cin >> f;

    if(f[0] == '-'){
        cout << "-";
        f = f.substr(1);
    }

    if(f.length() == 0)
        cout << "0";
    else{
        while(f.compare(temp) != 0){
            result = multiply(result , temp);
            temp = to_string(stoi(temp) +1);
        }
        result = multiply(f,result);
        cout << result << endl;
    }

}

void fastexp(){
    string num, pow;
    // cout <<"Enter your number : ";
    cin >> num;
    // cout << "Ent1er the power : ";
    cin >> pow;

    ll value = pow[pow.length() -1] - '0';


    string result = "1";

    if(num[0] == '-' && value%2 == 0)
        num = num.substr(1);

    else if(num[0] == '-' && value%2 !=0){
        num = num.substr(1);
        cout << '-';
    }

    while((pow[0]- '0') > 0){
        if((pow[pow.length()-1] -'0') % 2 != 0)
            result = multiply(result , num);

        pow = divide(pow);
        num = multiply(num , num);
    }
    cout << endl << result;
}

void gcd(string a , string b)

{
    
    while(a.compare(b) != 0){
	if(my_compare(a,b)){
        	a = subtract(a,b);
		int i =0;
		while(i < a.length() && a[i] == '0')
			i++;
		a = a.substr(i);
        // cout << a << endl;
	}
	else{
        	b = subtract(b,a);
		int i =0;
		while(i < b.length() && b[i] == '0')
			i++;
		b = b.substr(i);
        // cout << b << endl;
        }
    }
    cout<< a << endl;
}

string subtract(string n1 , string n2){
    string str = "" ;
    ll len1 = n1.length();
    ll len2 = n2.length();

    ll borrow = 0;
    reverse(n1.begin() , n1.end());
    reverse(n2.begin() , n2.end());

    for(ll i= 0; i < len2 ; i++){
        ll sub = (n1[i] - '0') - (n2[i] - '0') - borrow;
        if(sub < 0){
                sub = sub + 10;
                borrow = 1;
        }
        else
            borrow = 0;

        str.push_back(sub + '0');
    }

    for(ll i = len2; i < len1 ; i++){
        ll sub = (n1[i] - '0') - borrow;

        if(sub < 0){
            sub = sub +10;
            borrow = 1;
        }
        else
            borrow = 0;

        str.push_back(sub + '0');
    }

    reverse(str.begin() , str.end());
    return str;
}

bool my_compare(string a ,string b){
	if(a.length() == b.length()){
		int res = a.compare(b);
		if(res>0)
			return true;
		else
			return false;
	}
	if(a.length() > b.length())
		return true;
	else
		return false;

}
















