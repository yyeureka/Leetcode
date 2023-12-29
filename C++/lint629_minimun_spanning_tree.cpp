#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
Given a list of Connections, which is the Connection class (the city name at both ends of the edge and a cost between them), find some edges, connect all the cities and spend the least amount.
Return the connects if can connect all the cities, otherwise return empty list.
Return the connections sorted by the cost, or sorted city1 name if their cost is same, or sorted city2 if their city1 name is also same.

Example
Gievn the connections = ["Acity","Bcity",1], ["Acity","Ccity",2], ["Bcity","Ccity",3]
Return ["Acity","Bcity",1], ["Acity","Ccity",2]

解题思路：
先按cost、city1、city2排序Connection
将所有city加进hash，value即序号、依次递增
unionfind，遍历Connection，将city1和city2 union，如果union个数为1时，即成功
注意！！只有city1和city2可以union成功时，才能加进结果中！！
*/

class Connection {
public:
	string city1, city2;
	int cost;
	Connection(string& city1, string& city2, int cost) {
		this->city1 = city1;
		this->city2 = city2;
		this->cost = cost;
	}
};

bool cmp(Connection a, Connection b) {
    if (a.cost == b.cost) {
        if (a.city1 == b.city1) return a.city2 < b.city2;
        return a.city1 < b.city1;
    }
    return a.cost < b.cost;
} 

class Solution {
private:
    class UF {
    private:
        vector<int> v;
        vector<int> sz;
        
        int getRoot(int i) {
            while (i != v[i]) {
                v[i] = v[v[i]];
                i = v[i];
            }
            return i;
        }
    public:
        int count;
        
        UF(int n) {
            count = n;
            for (int i = 0; i < n; i++) {
                v.push_back(i);
                sz.push_back(1);
            }
        }
        
        bool quickUnion(int p, int q) {
            int i = getRoot(p);
            int j = getRoot(q);
            if (i == j) return false;
            
            if (sz[i] < sz[j]) {
                v[i] = j;
                sz[j] += sz[i];
            }
            else {
                v[j] = i;
                sz[i] += sz[j];
            }
            count--;
            return true;
        }
    };

public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        sort(connections.begin(), connections.end(), cmp);
        
        unordered_map<string, int> m;
        int i = 0;
        for (auto j : connections) {
            if (m.find(j.city1) == m.end()) m[j.city1] = i++;
            if (m.find(j.city2) == m.end()) m[j.city2] = i++;
        }
        
        vector<Connection> res;
        UF uf(i);
        for (auto j : connections) {
            if (uf.quickUnion(m[j.city1], m[j.city2])) { //这个条件是关键
                res.push_back(j);
                if (1 == uf.count) return res;
            }
        }
        return {};
    }
};