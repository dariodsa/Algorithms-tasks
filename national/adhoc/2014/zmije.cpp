#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 300000;
int a,b,c,d,e,f;
int arr[N];
bool bio[N];
char letter[N];
char lastLetter = 'A';

void nextLetter() {
    if( lastLetter == 'C') lastLetter = 'A';
    else lastLetter = lastLetter +1;
}

int main() {
    scanf("%d",&a);
    for(int i=0;i<a;++i) {
        scanf("%d",&arr[i]);
        --arr[i];
    }
    for(int i=0;i<a;++i) {
        if(!bio[i]) {
            int pos = i;
            int last = i;
            do { 
                bio[pos] = true;
                letter[pos] = lastLetter;
                nextLetter();
                last = pos;
                pos = arr[pos];
            } while(pos != i);
            if(letter[last] == letter[i]) {
                char t1 = letter[i];
                char t2 = letter[arr[i]];
                letter[i] = t2;
                letter[arr[i]] = t1;
            }
        }

    }
    for(int i=0;i<a;++i) {
        printf("%c",letter[i]);
    }
    return 0;
}
