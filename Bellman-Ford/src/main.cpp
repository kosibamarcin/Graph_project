/* Program is written by Marcin Kosiba
 * It's purpose is to implement Bellman-Ford algorithm
 */

#include <iostream>
#include <fstream>
#include <vector>

//structure to represent graph's edge
struct Edge{
    int from, to, weight;
};

//structure to represent graph's vertex
struct Vertex{
    int number;
};

//structure to represent a graph
//graph is initialized using adjacency matrix read from .txt file
class Graph{
public:
    int num_of_vertices;
    int num_of_edges;
    int **matrix;
    std::vector<Edge> edges;
    Vertex *vertices;

    Graph(){
        num_of_edges = 0;
        num_of_vertices = 0;
        matrix = nullptr;
        vertices = nullptr;
    }
    ~Graph(){
        if(vertices != nullptr){
            delete[] vertices;
        }
        if(matrix != nullptr){
            for(int i = 0; i<num_of_vertices; ++i)
                delete[] matrix[i];
        }
        delete[] matrix;
    }
    explicit Graph(std::string& filename){
        std::ifstream input;
        input.open(filename);

        num_of_edges = 0;
        num_of_vertices = 0;

        if(!input){
            std::cout << "Unable to open matrix file!\n";
            exit(1);
        }
        input >> num_of_vertices;

        matrix = new int*[num_of_vertices];
        for(int i = 0; i<num_of_vertices; i++) matrix[i] = new int[num_of_vertices];
        vertices = new Vertex[num_of_vertices];

        for(int i = 0; i<num_of_vertices; ++i) vertices[i].number = i;

        for(int i = 0; i<num_of_vertices; i++){
            for(int j = 0; j<num_of_vertices; j++){
                input >> matrix[i][j];
            }
        }

        input.close();

        for(int x = 0; x<num_of_vertices; ++x){
            for(int y = 0; y<num_of_vertices; ++y){
                if(matrix[x][y] != 0){
                    Edge e{};
                    e.from = x;
                    e.to = y;
                    e.weight = matrix[x][y];
                    edges.push_back(e);
                    num_of_edges ++;
                }
            }
        }

    }

};

//Bellman_Ford algorithm
//function returns array where arr[x] = y means that distance from
//vertex given to the function to vertex x is y long
int * Bellman_Ford(Graph& g, int start_node){
    int *arr = new int[g.num_of_vertices];

    //Firstly, all distances should be initialized as infinity
    for(int i = 0; i < g.num_of_vertices; i++){
        arr[i] = INT_MAX;
    }
    //distance from start_node to itself should be 0
    arr[start_node] = 0;

    //now relaxation of all edges should be done
    for(int i = 1; i < g.num_of_vertices; i++){
        for(int j = 0; j < g.num_of_edges; j++){
            if(arr[g.edges[j].from] != INT_MAX && arr[g.edges[j].from] + g.edges[j].weight < arr[g.edges[j].to]){
                arr[g.edges[j].to] = arr[g.edges[j].from] + g.edges[j].weight;
            }
        }
    }

    //now negative cycles should be found if exists
    //if found it's impossible to be right solution
    for(int i = 0; i < g.num_of_edges; i++){
        if(arr[g.edges[i].from] != INT_MAX && arr[g.edges[i].from] + g.edges[i].weight < arr[g.edges[i].to]){
            throw "Negative cycles detected";
        }
    }
    return arr;
}

void Display_Results(int *arr, int start_node, int n){
    std::cout << "\nBASED ON BELLMAN-FORD ALGORITHM\n";
    std::cout << "PROGRAM FOUND THESE SHOREST PATHS:\n";
    std::cout << "------------------------------------\n";
    for(int i = 0; i < n; i++) {
        std::cout << "MINIMAL DISTANCE from " << start_node << " to " << i << " is equal to: " << arr[i] << std::endl;
    }
    std::cout << "------------------------------------\n";
}
int main() {
    std::string filename = "../../matrix.txt";
    Graph g( filename);

    int start_node = 0;

    try {
        int *arr = Bellman_Ford(g, start_node);
        Display_Results(arr, start_node, g.num_of_vertices);
    }
    catch(const char* msg){
        std::cout << "Exception: \n";
        std::cout << msg << '\n';
    }

    return 0;
}
