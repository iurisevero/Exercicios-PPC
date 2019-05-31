#include <bits/stdc++.h>

using namespace std;
const double INF = 2e18;

vector<double> x, v;
int N;
bool has_intersetion(vector<pair<double, double>> range){
	double min_value = -INF, max_value = INF;

	for(pair<double, double> p: range){
		min_value = max(min_value, p.first);
		max_value = min(max_value, p.second);
	}

	return min_value<=max_value;
}


bool possible(double t){
	vector<pair<double, double>> ranges;

	for(int i=0; i<N; ++i){
		double L= x[i] - v[i]*t, R = x[i] + v[i]*t;
		ranges.emplace_back(L,R); //emplace_back = push_back para pair;
	}

	return has_intersetion(ranges);
}

int main()
{
	cin >> N;

	for(int i=0; i<N; ++i)
	{
		double x_aux;
		cin >> x_aux;
		x.push_back(x_aux);
	}
	for(int i=0; i<N; ++i)
	{
		double v_aux;
		cin >> v_aux;
		v.push_back(v_aux);
	}

	double L=0.0, R=1e9;
	for(int i=0; i<500; ++i)
	{
		double M = L+ (R-L)/2;
		if(possible(M))
			R=M;
		else
			L=M;
	}

	cout << fixed << setprecision(15) << L << endl;
	return 0;
}