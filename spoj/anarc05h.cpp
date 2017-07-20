#include <iostream>
#include <cstdio>

using namespace std;

#define sz 26
int digit[sz],length;

int nWay(int pos,int prevSum){
    int ans = 0,sum = 0;

    if(pos == length)
        return 1;
    for(int i = pos;i < length;i++){
        sum += digit[i];
        if(sum >= prevSum)
            ans += nWay(i+1,sum);
    }
    return ans;
}

int main(){
    int i,j,k,l,cas = 1;
    char s[sz];

    while(scanf("%s",s)==1){
        if(s[0] == 'b')
            break;
        for(i=0; s[i]; i++){
            digit[i] = s[i] - '0';
        }
        length = i;
        printf("%d. %d\n",cas++,nWay(0,0));
    }

    return 0;
}

