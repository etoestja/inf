#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool** arr;
short unsigned int* colors;
bool* used_all;
unsigned int N;
bool able;

void dfs(unsigned int V,short unsigned int color) {
 unsigned int i,si;

 if(colors[V]&&colors[V]!=color) {
  able=false;
  return;
 }

 if(colors[V]) {
  return;
 }

 colors[V]=color;
 used_all[V]=1;

 for(i=0;i<N;i++) {
  if(!able) return;
  if(i!=V&&arr[V][i]) dfs(i,color==1?2:1);
 }
}

int main() {
 unsigned int M;
 cin >> N >> M;
 unsigned int i,si;

 arr=new bool*[N];
 used_all=new bool[N];

 for(i=0;i<N;i++) {
  used_all[i]=0;
  arr[i]=new bool[N];
  for(si=0;si<N;si++) arr[i][si]=0;
 }

 unsigned int t1,t2;

 for(i=0;i<M;i++) {
  cin >> t1 >> t2;
  arr[t1-1][t2-1]=1;
  arr[t2-1][t1-1]=1;
 }

 colors=new short unsigned int[N];

 colors[0]=0;

 for(i=0;i<N;i++) {
  for(si=0;si<N&&used_all[si];si++);
  if(si>=N) break;

  i=si;

  able=true;
  dfs(i,1);

  if(!able) {
   cout << "NO";
   return 0;
  }

 }

 cout << "YES" << endl;
 for(i=0;i<N;i++) {
  if(colors[i]==2) cout << i+1 << " ";
 }
 return 0;
}

