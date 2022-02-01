#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:

        vector<int> knapsackZeroOne(int weights[], int profits[], int size, int maxWeight){
            vector<int> result(size);            
            int rowCount = size;
            int colCount = maxWeight;

            int V[rowCount+1][colCount+1];
            for(int i = 0; i<=rowCount; i++){
                for(int w = 0; w<=colCount; w++){
                    if(i == 0 || w == 0)
                        V[i][w] = 0;
                    else if(weights[i-1] <= w)
                        V[i][w] = max(V[i-1][w], V[i-1][w - weights[i-1]] + profits[i-1]);
                    else
                        V[i][w] = V[i-1][w];                    
                    cout<<V[i][w]<<"\t";
                }
                cout<<endl;
            }            

            int capacityOfBag = maxWeight;
            int i = rowCount;
            while(i > 0){
                if(V[i][capacityOfBag] == V[i-1][capacityOfBag]){
                    result[i-1] = 0;                    
                }
                else{
                    result[i-1] = 1;
                    capacityOfBag = capacityOfBag - weights[i-1];
                }
                i--;
            }

            cout<<"Maxm profit: "<<V[rowCount][colCount]<<endl;;

            return result;

        }
};

int main(){
    int weights[] = {2, 3, 4, 5};
    int profits[] = {1, 2, 5, 6};

    Solution* soln = new Solution();
    vector<int> result = soln->knapsackZeroOne(weights, profits, 4, 8);
    for(int i=0; i<result.size(); i++){
        cout<<"Item no "<<std::to_string(i+1);
        if(result[i])
            cout<<" is included"<<endl;
        else 
            cout<<" not included"<<endl;
    }
    // cout<<"Maximum profit is: "<<soln->knapsackZeroOne(weights, profits, 8);

    return 0;
}