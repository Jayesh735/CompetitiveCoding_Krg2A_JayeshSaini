#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define forloop(i,a,b) for (int i = a; i <= b; i++)

vector<int> computeLPS(string pattern){
    int m = pattern.size();
    vector<int> lps(m,0);
    int len = 0;
    forloop(i,1,m-1){
        while(len > 0 && pattern[i] != pattern[len]){
            len = lps[len-1];
        }
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
        }
    }
    return lps;
}

vector<int> KMP(string text, string pattern){
    vector<int> lps = computeLPS(pattern);
    vector<int> occurrences;
    int n = text.size();
    int m = pattern.size();
    int j = 0;
    forloop(i,0,n-1){
        while(j > 0 && text[i] != pattern[j]){
            j = lps[j-1];
        }
        if(text[i] == pattern[j]){
            j++;
        }
        if(j == m){
            occurrences.push_back(i - m + 1);
            j = lps[j-1];
        }
    }
    return occurrences;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string text = "abcab";
    string pattern = "ab";
    vector<int> occurrences = KMP(text, pattern);
    for(int index : occurrences){
        cout << "Pattern found at index: " << index << endl;
    }
    return 0;
}