#include<iostream>
using namespace std;

string ConcatString(string s1, string s2)
{
    string s3 = "";
    s3 = s1 + " " + s2;
    return s3;
}

int main()
{
    string s1, s2;
    cout<<"Enter first string : ";
    getline(cin, s1);
    cout<<"Enter second string : ";
    getline(cin, s2);

    cout << "Concatenated string is : " << ConcatString(s1, s2);

    return 0;
}
