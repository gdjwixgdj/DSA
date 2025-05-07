#include<iostream>
using namespace std;
class Graph
{
        int** adjMat;
        string* names;
        int vertices, edges;
    public:
        Graph()
        {
            cout << "How many Cities : ";
            cin >> vertices;
            names = new string[vertices];

            adjMat = new int*[vertices]; //array of pointers
            for(int i = 0 ; i < vertices ; i++)
                adjMat[i] = new int[vertices]; //normal arrays
        }
        void createGraph()
        {
            cout << "Enter " << vertices << " names for Cities\n";
            for(int i = 0 ; i < vertices ; i++)
            {
                cout << "City" << i + 1 << " : ";
                cin >> names[i];
            }

            cout << "How many Leased lines : ";
            cin >> edges;
        
            string src, dest;
            int cost, srcIndex, destIndex;
            for(int i = 0 ; i < edges ; ++i)
            {
                cout << "Enter Source City for LeasedLine-" << i + 1 << " : ";
                cin >> src;
        
                cout << "Enter Destination City for LeasedLine-" << i + 1 << " : ";
                cin >> dest;
        
                cout << "Enter Cost : ";
                cin >> cost;
        
                srcIndex = searchIndex(src);
                destIndex = searchIndex(dest);
        
                adjMat[srcIndex][destIndex] = adjMat[destIndex][srcIndex] = cost;
            }            
        }
        int searchIndex(string vertex)
        {
            for(int i = 0 ; i < vertices ; i++)
                if(names[i] == vertex)
                    return i;
            return -1;
        }
        int mst()
        {
            int** tempMat;
            tempMat = new int*[vertices];
            for(int i = 0 ; i < vertices ; i++)
                tempMat[i] = new int[vertices];
            
            for(int i = 0 ; i < vertices ; i++)
                for(int j = 0 ; j < vertices ; j++)
                    tempMat[i][j] = adjMat[i][j];
            
            int minRow, minCol, cost = 0;
            int* visited = new int[vertices];
            int arrayCount = 0;
            for(int i = 0 ; i < vertices ; i++)
                visited[i] = -1;

            int count = 0;

            while(count < vertices - 1)
            {
                findMinimumElement(tempMat, minRow, minCol);
                
                int rowStatus = isMember(visited, arrayCount, minRow);
                int colStatus = isMember(visited, arrayCount, minCol);

                if(count == 0 || rowStatus ^ colStatus)                  
                {
                    if(!isMember(visited, arrayCount, minRow))
                       visited[arrayCount++] = minRow;

                    if(!isMember(visited, arrayCount, minCol))
                        visited[arrayCount++] = minCol;
                    cost += tempMat[minRow][minCol];
                    count++;
                }
                
                if(rowStatus & colStatus || rowStatus ^ colStatus)
                    tempMat[minRow][minCol] = tempMat[minCol][minRow] = -1; //already taken
            }
            return cost;
        }
        void findMinimumElement(int**& tempMat, int& minRow, int& minCol)
        {
            int minElement = 9999;
            for(int i = 0 ; i < vertices ; i++)
                for(int j = 0 ; j < vertices ; j++)
                    if(tempMat[i][j] > 0 && tempMat[i][j] < minElement)
                    {
                        minRow = i;
                        minCol = j;
                        minElement = tempMat[i][j];
                    }
        }
        bool isMember(int* visited, int arrayCount, int ele)
        {
            for(int i = 0 ; i < arrayCount ; i++)
                if(visited[i] == ele)
                    return true;
            return false;
        }
};
int main()
{
    Graph graph;
    graph.createGraph();
    cout << "Minimum Cost : " << graph.mst() << endl;
    return 0;
}   
/*
     A     B      C      D        E   

A    0     -1    -1     60        -1     
  
B   -1      0    -1     0         0  

C   -1     -1     0      32        0  

D   60     0      32     0         0      

E   -1     0       0     0         0  

minRow = 2
col = 3
min = 32

cost = 0, 7, 17, 29, 61
visited : {-1, -1, -1, -1, -1}
*/
