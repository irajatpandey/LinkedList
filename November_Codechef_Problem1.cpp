#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCase;
    cin >> testCase;
    
    while(testCase--){
        int N;
        cin >> N;
        string str[N];
       
        for(int i = 0; i < N; i++)
            cin >> str[i];
        long c = 0;    
        for(int i = 1; i < N; i++){
            string str2 = "";
            for(int j = 0; j < 10; j++){

                 int val = int(str[i-1][j]) ^ int(str[i][j]);
                 str2 += char(val);
                 
            }
            //cout << str2 << endl;
            str[i] = str2;
            //cout << endl;
        }
        for(int i = 0; i < 10; i++){
            if(str[N - 1][i] == '1')
                c++;
        }
        cout << c << endl;
               
    }

    
    return 0;
}