#include <bits/stdc++.h>
using namespace std;

string concatenateStrings(string &s1, string &s2){

	// If s1 is empty then return s2.
	if(s1 == ""){
		return s2;
	}

	string ans = s1; // Initialize answer with the first string.

	// Traverse and push the second string into the answer.
	for(int i=0; i<s2.size(); i++){
		ans.push_back(s2[i]);
	}

	return ans;
}

int main(){
	string s1, s2;

	// Input 2 strings.
	cin>>s1>>s2;

	// Concatenate the two strings.
	string concatString = concatenateStrings(s1, s2);

	cout<<"Original String : ";
	cout<<s1<<" "<<s2<<endl;
	cout<<"Concatenated String : "<<concatString;

	return 0;
}