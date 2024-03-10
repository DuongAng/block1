#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    if(n<=3){
        if(n==3 && a[0]==a[1] && a[1]==a[2]){
            cout<<"1 2";
        }
        else if (n==3){
            cout<<"1 3";
        }
        else if(n==2){
            cout<<"1 2";

        }
        else if(n==1){
            cout<<"1 1";

        }
        else{
            cout<<"0 0";
        }
    }
    else{
    int max1=2, arrin=0, arrend=1;
    int count1=1, count2=0;
    int wstart=0;
    for(int wend =1; wend<n; wend++){
        if(a[wend-1]==a[wend])
            count2++;
        else
            count2=0;
        if (count2+1==3){
            if(max1<count1){
                max1=count1;
                arrin=wstart;
                arrend=wend-1;
            }
            count2--;
            count1=2;
            wstart=wend-1;
        }
        else{
            count1++;
        }
    }

    if(count1>max1){
        arrin=wstart;
        arrend=n-1;
    }
    cout<<arrin+1<<" "<<arrend+1;
    }
    return 0;
}
