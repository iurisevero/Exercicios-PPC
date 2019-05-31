#include <bits/stdc++.h>

using namespace std;

int main(){
	int month, number_depreciation;
	double down_payment, loan;

	while(cin >> month >> down_payment >> loan >> number_depreciation, month>0){
		double car_value = loan+down_payment;
		pair<int, float> depreciations[105];
		for(int i=0; i< number_depreciation; ++i){
			cin >> depreciations[i].first >> depreciations[i].second;
		}
/*
		for(auto p: depreciations)
			cout << p.first << " " << p.second << endl;
*/

		//double depreciacao = car_value*depreciations[0].second;
		car_value= car_value - car_value*depreciations[0].second;
//		cout << "car value = " << car_value << endl;
		int mes_atual=1, depreciation_atual=0;
		double pagamento_mensal = loan/month;
		for(mes_atual; mes_atual<=month; ++mes_atual){
			if(car_value>loan) break;

			if(mes_atual== depreciations[depreciation_atual+1].first){
				depreciation_atual++;
				//depreciacao = car_value*depreciations[depreciation_atual].second;
			}
/*
			cout << "mes atual: " << mes_atual << endl;
			cout << "depreciacao atual: " << depreciation_atual << endl;
			cout << "depreciacao em reais = " << depreciacao << endl;
			cout << "depreciation: " << depreciations[depreciation_atual].first;
			cout << " " << depreciations[depreciation_atual].second << endl;
			cout << "depreciation+1: " << depreciations[1+depreciation_atual].first;
			cout << " " << depreciations[depreciation_atual+1].second;
			cout << endl;
*/
			car_value = car_value - car_value*depreciations[depreciation_atual].second;
			loan-= pagamento_mensal;
/*
			cout << setprecision(10) << "car value = " << car_value;
			cout << setprecision(10) << " loan = " << loan << endl;
*/
		}

        mes_atual--;
		if(mes_atual!=1) cout << mes_atual << " months\n";
		else cout << mes_atual << " month\n";
	}
	return 0;
}
