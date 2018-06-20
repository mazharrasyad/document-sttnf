/*
	Sekolah Tinggi Teknologi Terpadu Nurul Fikri
	Angkatan 2017
	Teknik Informatika 1
	
	Muhammad Azhar Rasyad
	0110217029
	Struktur Data dan Algoritma
	Graph	
	
	Catatan : Diharapkan menggunakan aplikasi Dev C++ pada Sistem Operasi Windows
*/

#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
 
class Graph
{
    int V; 
    list<int> *adj;
    
	public:
	    Graph(int V);
	    void addEdge(int v, int w, int weight); 
	    int findShortestPath(int s, int d);
	    int printShortestPath(int parent[], int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[2*V];
}
 
void Graph::addEdge(int v, int w, int weight)
{
    if (weight == 2)
    {
        adj[v].push_back(v+V);
        adj[v+V].push_back(w);
    }
    else
        adj[v].push_back(w);
}
 
int Graph::printShortestPath(int parent[], int s, int d)
{
    static int level = 0;
 
    if (parent[s] == -1)
    {
        cout << "Jarak Terdekat Antara " << s << " dan " << d << " : "  << s;
		return level;        
    }
 
    printShortestPath(parent, parent[s], d);
    level++;
    
    if (s < V)
        cout << " -> " << s;
    else
    	cout << "";
 
    return level;
}
 
int Graph::findShortestPath(int src, int dest)
{
    bool *visited = new bool[2*V];
    int *parent = new int[2*V];
 
    for (int i = 0; i < 2*V; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
 
    list<int> queue;
    visited[src] = true;
    queue.push_back(src);
    list<int>::iterator i;
 
    while (!queue.empty())
    {
        int s = queue.front();
 
        if (s == dest)
            return printShortestPath(parent, s, dest);
 
        queue.pop_front();
 
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
                parent[*i] = s;
            }
        }
    }
}
 
int main()
{
	int V = 5;
    int src;
 	int dest;
 
    Graph g(V);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 4, 1);
	g.addEdge(1, 0, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 1, 1);
    g.addEdge(3, 2, 1);
    g.addEdge(4, 0, 1);
    g.addEdge(4, 1, 1);
	
	menu_utama:
	system("cls");
	cout << "----- Graph Jarak Terdekat -----" << endl << endl;
	
	cout << "|0| ----- |1| ----- |2|" << endl;
	cout << " |        / \\        | " << endl;
	cout << " |       /   \\       | " << endl;
	cout << " |      /     \\      | " << endl;
	cout << " |     /       \\     | " << endl;
	cout << " |    /         \\    | " << endl;
	cout << " |   /           \\   | " << endl;
	cout << " |  /             \\  | " << endl;
	cout << " | /               \\ | " << endl;
	cout << "|4|                 |3|" << endl;
	cout << endl;
	
    cout << "Masukkan Graph Dari = ";
    cin >> src;
    
    cout << "Masukkan Graph " << src << " Ke = ";
    cin >> dest;
    
    cout << endl;
    
    if(src == 0 || src == 1 || src == 2 || src == 3 || src == 4)
    {
    	if(dest == 0 || dest == 1 || dest == 2 || dest == 3 || dest == 4)
	    {
	    	g.findShortestPath(src, dest);	
	     	cout << endl << endl << "Tekan Enter Untuk Mengulang...";
			getch();
			goto menu_utama;		
		}
    	else
		{
			cout << "Graph Tidak Ada" << endl << endl;
			cout << "Tekan Enter Untuk Mengulang...";
			getch();
			goto menu_utama;		
		}
	}
	else
	{
		cout << "Graph Tidak Ada" << endl << endl;
		cout << "Tekan Enter Untuk Mengulang...";
		getch();
		goto menu_utama;		
	}
 
    return 0;
}
