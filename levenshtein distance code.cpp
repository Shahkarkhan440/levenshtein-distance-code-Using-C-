#include<iostream>
#include <cstring>
using namespace std;

int Levenshtein_distance (const char * source, const char * target, int insert_cost,int delete_cost,int subsitute_cost)
{
    int delete1,insert,substitute,minimum;
    int m = strlen (source);
    int n = strlen (target);
    
    int matrix[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        matrix[i][0] = i;
    }
    for (int i = 0; i <= n; i++) {
        matrix[0][i] = i;
    }
    for (int i = 1; i <= m; i++) {
         char ch1 = source[i-1];
        for (int j = 1; j <= n; j++) {
            char ch2 = target[j-1];
            if (ch1 == ch2) {
                matrix[i][j] = matrix[i-1][j-1];
            }
            else 
            {
                insert = matrix[i][j-1] + insert_cost;
                delete1 = matrix[i-1][j] + delete_cost;
                substitute = matrix[i-1][j-1] + subsitute_cost;
                minimum = insert;
                if (delete1 < minimum) {
                    minimum = delete1;
                }
                if (substitute < minimum) {
                    minimum = substitute;
                }
                matrix[i][j] = minimum;
            }
        }
    }
    return matrix[m][n];
}
int main ()
{
    const char * source = "intention";
    const char * target= "execution";
    
    //Here you can set your own cost for each operation
    
    int insert_cost=1;   
    int delete_cost=1;
    int subsitute_cost=2;
    
    int distance = Levenshtein_distance (source,target,insert_cost,delete_cost,subsitute_cost);
    cout <<"The Levenshtein distance between (source) " <<source <<"  ===>  (target) "<<target<<" is "<<distance;
   
}