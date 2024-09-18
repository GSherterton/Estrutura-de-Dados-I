#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

#define INFINITY 1000000000

using namespace std;

vector<vector<double>> read_instance(const string& instance_name){
    vector<vector<double>> distance_matrix;

    ifstream fp;

    fp.open(instance_name);

    if(!fp.is_open()){
        cout << "Nao foi possivel abrir o arquivo\n";
        return vector<vector<double>>();
    }

    int dimension;
    fp >> dimension;

    distance_matrix.resize(dimension);
    for(int i = 0; i < dimension; i++){
        distance_matrix[i].resize(dimension);
    }
    
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            fp >> distance_matrix[i][j];
        }
    }

    fp.close();

    return distance_matrix;
}

vector<vector<pair<int, double>>> fill_adj_matrix(const vector<vector<double>>& distance_matrix){
    vector<vector<pair<int, double>>> adj_matrix;

    int dimension = distance_matrix.size();
    for(int i = 0; i < dimension; i++){
        vector<pair<int, double>> aux;
        //cout << "Criando a adjacencia do vertice " << i << ":" << endl;
        for(int j = 0; j < dimension; j++){
            if(distance_matrix[i][j]){
                //cout << "Adicionei o vertice " << j << endl;
                aux.push_back(make_pair(j, distance_matrix[i][j]));
            }
        }
        adj_matrix.push_back(aux);
    }

    return adj_matrix;
}

void print_distance_matrix(const vector<vector<double>>& distance_matrix){
    int n = distance_matrix.size();

    cout << "Distance Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << distance_matrix[i][j] << " ";
        }cout << endl;
    }
}

void print_adj_matrix(const vector<vector<pair<int, double>>>& adj_matrix){
    int n = adj_matrix.size();

    cout << "Adjacency Matrix:\n";
    for(int i = 0; i < n; i++){
        cout << "Vertex [" << i << "]: ";

        if(adj_matrix[i].size() == 0){
            cout << "-";
        }else{
            for(int j = 0; j < adj_matrix[i].size(); j++){
                cout << "(" << adj_matrix[i][j].first << ", " << adj_matrix[i][j].second << ") ";
            }
        }

        cout << endl;
    }
}

vector<int> find_path(const vector<int>& parent, const int& start, int end){
    if(parent[end] == -1){
        cout << "Não há caminho entre os vértices " << start << " e " << end << endl;
        return vector<int>();
    }

    vector<int> route; //the route who will be returned
    
    vector<int> aux; //the auxiliar vector to stores the reversed route

    aux.push_back(end);
    while(parent[end] != start){
        aux.push_back(parent[end]);
        end = parent[end];
    }
    aux.push_back(start);

    for(int i = aux.size()-1; i >= 0; i--){
        route.push_back(aux[i]);
    }

    return route;
}

void print_route(const vector<int>& route){
    int n = route.size();

    cout << "Rota: ";
    for(int i = 0; i < n; i++){
        cout << route[i] << (i == n-1 ? "\n" : " -> ");
    }
}

//the bfs will return the vector of parents to could recuperate the route to two vertex
vector<int> BFS(const int& start, const vector<vector<pair<int, double>>>& adj_matrix){
    int n = adj_matrix.size();

    vector<int> status(n, 0); //represents the status of each vertex
    vector<double> distance(n, INFINITY); //initializates all the distances with INFINITY
    vector<int> parent(n, -1); //initializates the vector of parents as an invalid parent

    status[start] = 1; //just the start vertex is 1
    distance[start] = 0; //the distance to the start from the start is 0

    queue<int> q; //the queue with the vertex of the graph

    q.push(start);

    while(!q.empty()){
        int index_aux = q.front();
        q.pop();

        for(auto edge : adj_matrix[index_aux]){ //iterates above the adjacent vertex of index aux
            if(status[edge.first] == 0){ //if the vertex iterated is not touched yet
                //cout << edge.first << " - ";

                status[edge.first] = 1; //update it status
                distance[edge.first] += 1; //update it distance
                parent[edge.first] = index_aux; //update it parent
                q.push(edge.first); //adds it to the queue
            }
        }

        status[index_aux] = 2;
    }
    // cout << endl;

    return parent;
}

void print_forest(const vector<vector<int>>& forest){
    if(forest.empty()){
        cout << "Nenhuma árvore encontrada\n";
        return;
    }

    for(int i = 0; i < forest.size(); i++){
        cout << "Árvore: [";

        for(int j = 0; j < forest[i].size(); j++){
            cout << forest[i][j] << ((j == forest[i].size() - 1) ? ("") : (", "));
        }

        cout << "]\n";
    }
}

vector<vector<int>> DFS(const vector<vector<pair<int, double>>>& adj_matrix){
    int n = adj_matrix.size();

    vector<vector<int>> forest;

    vector<int> status(n, 0); //represents the status of each vertex
    vector<int> parent(n, -1); //initializates the vector of parents as an invalid parent

    stack<int> s; //stack aux

    for(int i = 0; i < n; i++){
        if(status[i] == 0){
            vector<int> tree;

            tree.push_back(i);

            int index_aux = i;

            status[index_aux] = 1; //just the start vertex is 1

            //put the vertex on the stack
            s.push(index_aux);
            //cout << s.top() << " ";

            bool flag = 0; //flag para indicar se foi achado um novo no ou nao

            //while(there_is_adj_not_visited(s.top(), adj_matrix, status)){
            while(!s.empty()){
                for(auto edge : adj_matrix[s.top()]){
                    if(status[edge.first] == 0){
                        //updates the status of the vertex
                        status[edge.first] = 1;
                        //put the vertex on the stack
                        s.push(edge.first);
                        tree.push_back(s.top()); //adds the new vertex on the tree
                        //cout << s.top() << " ";

                        //search in the adj
                        flag = 1;
                        break;
                    }
                }

                if(flag){
                    flag = 0;
                    continue;
                }

                s.pop();
            }

            forest.push_back(tree);
        }
    }

    return forest;
}

int main(int argc, char** argv){
    //a instancia b é uma instancia extra que eu já havia feito
    if(argc < 2){ //at least the instance name is needed
        cout << "Missing parameters!\n";

        return -1;
    }

    string instance_name = argv[1];

    vector<vector<double>> distance_matrix;
    vector<vector<pair<int, double>>> adj_matrix;

    //leitor do arquivo e carregamento da matriz de distancias e matriz de adjacência
    distance_matrix = read_instance(instance_name);
    adj_matrix = fill_adj_matrix(distance_matrix);

    //debug para poder visualizar
    print_distance_matrix(distance_matrix);
    print_adj_matrix(adj_matrix);

    //escolhe dois vertices para procurar a distancia
    int start, end;
    cout << "Digite dois vertices: ";
    cin >> start >> end;

    //roda o BFS e recupera o caminho
    vector<int> parent = BFS(start, adj_matrix);
    print_route(find_path(parent, start, end));

    vector<vector<int>> forest;

    //roda o DFS
    forest = DFS(adj_matrix);
    print_forest(forest);

    return 0;
}