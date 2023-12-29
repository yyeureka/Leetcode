#include "head.h"

/*
Implement a load balancer for web servers. It provide the following functionality:
Add a new server to the cluster => add(server_id).
Remove a bad server from the cluster => remove(server_id).
Pick a server in the cluster randomly with equal probability => pick().
At beginning, the cluster is empty. When pick() is called you need to randomly return a server_id in the cluster.

Example 1:
Input:
add(1)
add(2)
add(3)
pick()
pick()
pick()
pick()
remove(1)
pick()
pick()
pick()
Output:
1
2
1
3
2
3
3
Explanation: The return value of pick() is random, it can be either 2 3 3 1 3 2 2 or other.

解题思路：跟#380一毛一样
*/

class LoadBalancer {
public:
	unordered_map<int, int> getIndex;
	vector<int> server;

	LoadBalancer() {

	}

	void add(int server_id) {
		if (getIndex.find(server_id) == getIndex.end()) {
			getIndex[server_id] = server.size();
			server.push_back(server_id);
		}
	}

	void remove(int server_id) {
		if (getIndex.find(server_id) != getIndex.end()) {
			getIndex[server.back()] = getIndex[server_id];
			server[getIndex[server_id]] = server.back();
			getIndex.erase(server_id);
			server.pop_back();
		}
	}

	int pick() {
		if (server.empty()) return rand();
		return server[rand() % server.size()];
	}
};

//class LoadBalancer {
//public:
//	unordered_set<int> server;
//	int size;
//
//	LoadBalancer() {
//		size = 0;
//	}
//
//	void add(int server_id) {
//		if (server.find(server_id) == server.end()) {
//			server.insert(server_id);
//			size++;
//		}
//	}
//
//	void remove(int server_id) {
//		if (server.find(server_id) != server.end()) {
//			server.erase(server_id);
//			size--;
//		}
//	}
//
//	int pick() {
//		if (!size) return rand();
//		return *next(server.begin(), rand() % size);
//	}
//};