#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool drop(double chance){
	ll a, b, rng;
	a = rand(), b = rand();
	rng = a*(RAND_MAX+1) + b;
	if((double)rng  <= chance * ((RAND_MAX+1)*(RAND_MAX+1)-1)) return 1;
	return 0;
}

int main(){
	ifstream in("x.txt");
	ofstream out("y.txt");
	srand(time(0));
	int t, n, kismets;
	ll a, b, rng;
	double h1, h2, base, chance, inc, diff, exp_required, exp_gained, exp;
	in>>n>>base>>exp_required>>exp_gained>>kismets;
	inc = base * (double)2 * exp_gained / exp_required;  //assuming 300 score each run
	t = 1e7/n;
	h1 = base * n;
	if(kismets) h1 *= 2;
	for(int tt=0; tt<t; tt++){
		chance = base;
		exp = 0;
		for(int i=0; i<n; i++){
			if(exp >= exp_required){  //satisfied exp requirement
				exp -= exp_required;
				h2++;
				chance = base;
				continue;
			}
			if(drop(chance)){
				h2++;
				chance = base;
				exp = 0;
				continue;
			}
			if(kismets && drop(chance)){
				h2++;
				chance = base;
				exp = 0;
				continue;
			}
			exp += exp_gained;
			chance += inc;
		}
	}
	h2 /= t;
	diff = (h2-h1)/h1 * 100;
	out<<diff;
	return 0;
}
