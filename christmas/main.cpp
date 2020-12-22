#include <iostream>
#include <cstring>
#define MAX 500

using namespace std;

int treeSize;
char tree[MAX][MAX];

int main(int argc, const char * argv[]) {
    memset(tree, ' ', sizeof(tree));
    printf("How big is your christmas tree?:) :");
    cin >> treeSize;
    
    int radius = 3 + 2 * (treeSize - 1);
    int diameter = 2 * radius;
    
    int current_section = 0;
    int current_height = 0;
    
    while(radius >= 3){
        
        int section_height = radius;
        int start_index = 2 * current_section;
        int current_diameter = diameter - start_index;
        int end_index = current_diameter;
        
        for(int i = 0; i < section_height; i++){
            for(int j = start_index+ 1; j < end_index; j += 2){
                tree[current_height + i][j] = '*';
            }
            start_index++;
            end_index--;
        }
        
        current_height += section_height;
        current_section++;
        radius -= 2;
    }

    string star = "";
    for(int i = 0; i < (diameter - 1)/ 2; i++){
        star += " ";
    }
    star += "⭐";
    cout << '\n' << star;
    for(int i = current_height; i >= 0; i--){
        for(int j = 0; j < diameter; j++){
            printf("%c", tree[i][j]);
        }
        printf("\n");
    }
    
    
    
    cout << '\n';
    cout << "Merry Christmas!" <<'\n';
    
    return 0;
}
