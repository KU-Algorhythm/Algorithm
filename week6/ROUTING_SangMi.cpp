#include<iostream>
#include<vector>
#include<utility>
#include<limits>
#include<queue>

using namespace std;

const double INF = numeric_limits<double>::max();
int N;
vector<pair<int, double>> adj[10000];

double minNoise() {
	vector<double> noise(N, INF);
	noise[0] = 1;

	priority_queue<pair<double, int>> pq;
	pq.push(make_pair(-1, 0));

	while (!pq.empty()) {
		int here = pq.top().second;
		double hereNoise = -pq.top().first;
		pq.pop();

		if (hereNoise > noise[here])
			continue;

		for (int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i].first;
			double nextNoise = hereNoise * adj[here][i].second;

			if (noise[next] > nextNoise) {
				noise[next] = nextNoise;
				pq.push(make_pair(-nextNoise, next));
			}
		}
	}

	return noise[N - 1];
}

int main() {

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int M;
		cin >> N >> M;
		//init
		for (int i = 0; i < N; i++) {
			adj[i].clear();
		}

		for (int i = 0; i < M; i++) {
			int a, b;
			double noise;
			cin >> a >> b >> noise;
			adj[a].push_back(make_pair(b, noise));
			adj[b].push_back(make_pair(a, noise));
		}

		cout << fixed;
		cout.precision(10);
		cout << minNoise() << endl;
	}

	return 0;
}