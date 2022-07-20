#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,N=100000;
	for (n=2;n<10;n++){
	float sum=0;
	for(int i=0;i<N;i++){
		vector<int> q;
		for (int j =0;j<n;j++){
			int r = rand()%n;
			//it = find(q.begin(), q.end(), r);
			while (find(q.begin(), q.end(), r) != q.end()){
				r = rand()%n;
			} 
			q.push_back(r);
		}
		int cycles =0;	
		for (int j =0;j<n;j++){
			int temp = q[j];
			if (temp == -1) continue;
			q[j]=-1;
			int t= temp;
			//t=q[t];
			while (t!= j){
				int f=t;
				t = q[t];
				q[f]=-1;
			}
		cycles++;
		}
		sum+=cycles;
	}
	cout<<sum/N<<" ";
	float s=0;
	for (int i =0;i<n;i++){
		s+=1/float(i+1);
	}
	cout<<s<<endl;
	}
}
