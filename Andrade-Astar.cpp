#include <bits/stdc++.h>
using namespace std;

int n;

//RECIBE DE INPUT NODOS, ARISTAS Y CADA ARISTA CON SU PESO

//INPUT
/*
1
20 23 0 1
0 19 75
19 12 71
12 15 151
0 15 140
0 16 118
16 9 111
9 10 70
10 3 75
3 2 120
15 5 99
15 14 80
14 13 97
14 2 146
2 13 138
5 1 211
13 1 101
1 6 90
1 17 85
17 7 98
7 4 86
17 18 142
18 8 92
8 11 87
*/

vector<vector<int>> m;
vector<vector<int>> conec;
vector<int> distancias;
int sldbucharest[20] = {366, 0, 160, 242, 161, 178, 77, 151, 226, 244, 241, 234, 380, 98, 193, 253, 329, 80, 199, 374};
vector<int> padres(20,-1);

void mostrar(int i){
	switch(i){
		case 0: cout << "Arad"; break;
		case 1: cout << "Bucharest"; break;
		case 2: cout << "Craiova"; break;
		case 3: cout << "Dobreta"; break;
		case 4: cout << "Eforie"; break;
		case 5: cout << "Fagaras"; break;
		case 6: cout << "Giurgiu"; break;
		case 7: cout << "Hirsova"; break;
		case 8: cout << "Iasi"; break;
		case 9: cout << "Lugoj"; break;
		case 10: cout << "Mehadia"; break;
		case 11: cout << "Neamt"; break;
		case 12: cout << "Oradea"; break;
		case 13: cout << "Pitesti"; break;
		case 14: cout << "Rimnicu Vilcea"; break;
		case 15: cout << "Sibiu"; break;
		case 16: cout << "Timisoara"; break;
		case 17: cout << "Urziceni"; break;
		case 18: cout << "Vaslui"; break;
		case 19: cout << "Zerind"; break;
		default: break;
	}
}

void astar(int ini, int fin){
	vector<int> dis(n,1e7);
	padres[ini] = ini;
	dis[ini] = sldbucharest[ini];
	vector<int> camino(n,-1);
	deque<int> q;
	q.push_front(ini);
	while(!q.empty()){
		int elem = q.front();
		q.pop_front();
		if(elem == fin) break;
		int f = dis[elem] - sldbucharest[elem];
		map<int,int> inq;
		for(auto i : conec[elem]){
			int peso = m[elem][i];	
			int ndis = f + peso + sldbucharest[i];
			cout << "-";
			mostrar(i);
			cout << " " << ndis << endl;
			if(ndis < dis[i]){
				padres[i] = elem;
				dis[i] = ndis;
				q.push_back(i);
			}
		}
		vector<int> nord;
		deque<int> nq;
        for (int i = 0; i < q.size(); i++){
			nord.push_back(dis[q[i]]);
        }
        sort(nord.begin(), nord.end());
        for (int i = 0; i < q.size(); i++){
			for(int j = 0; j < q.size(); j++){
				if(dis[q[j]] == nord[i]){
					nq.push_back(q[j]);
					break;
				}
			}
        }
        for(int i = 0; i < q.size(); i++){
        	q[i] = nq[i];
        }
	}
	for(auto i : dis){
		distancias.push_back(i);
	}
}

int main(){
	cout.sync_with_stdio(false);
	int t,ar,s,T,a,b,c;
	cin >> t;
	int caso=0;
	while(t--){
		caso++;
		cin >> n >> ar >> s >> T;
		m = vector<vector<int>>(n,vector<int>(n,1e7)); //matriz de pesos
		conec = vector<vector<int>>(n); //matriz de adyacencia
		for(int i = 0; i < ar; ++i){
			cin >> a >> b >> c;
			m[a][b] = c;
			m[b][a] = c;
			conec[a].push_back(b);
			conec[b].push_back(a);
	    }	
		cout << "Case #" << caso << ": " << endl;
		astar(s,T);
		cout << "Distancia más corta a ";
		mostrar(T);
		cout << " es " << distancias[T] << endl;
		int aux = T;
		vector<int>paux;
		mostrar(s); cout << "->";
		while(padres[aux]!=s){
			paux.push_back(padres[aux]);
			aux = padres[aux];
		}
		reverse(paux.begin(),paux.end());
		for(auto i : paux){
			mostrar(i);
			cout << "->";
		}
		mostrar(T);
	}
	
	return 0;
}