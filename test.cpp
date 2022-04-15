#include<bits/stdc++.h>
using namespace std;
const int maxV = 11;
set<int> graph[maxV];
int isComplete(int[]);
int main(){
    int a, b;
    while(cin >> a >> b && a &&b){
        a--;
        b--;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    bool isOutput = 0;
    int vertical[5], e, f, g, h, i;
    for(vertical[0] = 0;vertical[0]<maxV;vertical[0]++){
        for(vertical[1] = vertical[0]+1;vertical[1]<maxV;vertical[1]++){
            for(vertical[2] = vertical[1]+1;vertical[2]<maxV;vertical[2]++){
                for(vertical[3] = vertical[2]+1;vertical[3]<maxV;vertical[3]++){
                    for(vertical[4] = vertical[3]+1;vertical[4]<maxV;vertical[4]++){
                        if(isComplete(vertical)){
                            if(!isOutput) cout << "\nCannot be simplize:\n";
                            for(int i=0;i<5;i++){
                                cout << vertical[i]+1 << " ";

                            }
                            cout << endl;
                            isOutput = 1;
                        }

                    }
                }
            }
        }
    }

    if(! isOutput) cout << "All graph can be simplize!\n";
    return 0;;
}
int isComplete(int vertical[]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i == j) continue;
            if(graph[vertical[i]].count(vertical[j])) return 0;
        }
    }
    return 1;
}
/*
1 3
2 3
6 7
1 2
5 8
5 9
5 10
6 8
6 9
6 10
6 2
7 2
8 2
10 2
9 2
8 4
9 4
10 4
11 8
11 9
11 10
0 0
*/
