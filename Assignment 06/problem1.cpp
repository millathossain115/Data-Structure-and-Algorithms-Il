#include<bits/stdc++.h>
using namespace std;


int dptable[100];

int lcs(int arr[],int term){
    dptable[0]=1;

   for(int next=1;next<term;next++)dptable[next]=1;

   for(int next=1;next<term;next++){
        for(int j=0;j<next;j++){
            int tmp=max(arr[next],arr[j]);
               if(tmp==arr[next]){
                 if(dptable[j]+1>dptable[next]){

                    dptable[next]=dptable[j]+1;
                }
            }
        }
   }


   return dptable[term-1];

}

int main(){


    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int sz = sizeof(arr) / sizeof(arr[0]);
    
   

    int ans=lcs(arr,sz);
    cout<<ans<<endl;
}