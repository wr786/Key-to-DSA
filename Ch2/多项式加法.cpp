// 程序设计实习写的
# include<cstdio>
# include<set>
# include<unordered_map>
using namespace std;

int main() {
	int _n; scanf("%d", &_n);
	while(_n--) {
		set<int, greater<int> > es; // 存放出现过的e，从大到小排序
		unordered_map<int, int> kOf; // 存放e的系数k
		for(int i=0; i<2; i++) {
			int K, E;
			while(~scanf("%d%d", &K, &E) && E >= 0) {
				if(es.count(E)) {
					kOf[E] += K;
					if(!kOf[E]) es.erase(E);
				}
				else if(K){
					es.insert(E);
					kOf[E] = K;
				}
			}
		}
		for(set<int>::iterator it = es.begin();
				it != es.end(); ++it) {
					if(it != es.begin()) printf(" ");
					printf("[ %d %d ]", kOf[*it], *it);
				}
		printf("\n");
	}
}