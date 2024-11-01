#include <iostream>
#include <string>
using namespace std;
string dics[] = {"IS","THIS","HIS","AT","YOU","HI","IT","TWO",
                "OF","FAT","THAT","HAT", "GOD","CAT",
                "HAT", "AN","FOUR"};
string word_search[] = {"THIS","WATS","OAHG","FGDT"};
string  temp = "";
bool found_word(string ch){
    for(string dic : dics){
        if (ch == dic)
            return true;
    }
    return false;
}
void search(){
    int rows = sizeof(word_search)/sizeof(word_search[0]);
    int cols = word_search[0].size();
    int direction;
    int count = 0;
    for (direction = 1;  direction <= 2 ; direction++) {
        for (int word = 0; word < 4; word++) {
            for (int i = 0; i < rows; i++) {
                for (int j = i; j < cols;j++) {
                    for (int k = i; k <= j; k++) {
                        if (direction == 1)
                            temp += word_search[k][word];
                        else
                            temp += word_search[word][k];
                    }
                    cout << temp << " " ;
                    if (found_word(temp)){
                        cout << " Found ";
                        count++;
                    }
                    cout << endl;
                    temp.clear();

                }


            }
        }

    }

    for (int k = 3; k >= 0 ; k--) {

        for (int i = k; i >= 0; i--) {
            for (int j = i; j >= i; j--) {
                if (i == j) {
                    temp += word_search[i][j];
                }
              }
            cout << temp ;
            if (found_word(temp)){
                cout << " Found ";
                count++;
            }
            cout << endl;
        }
        temp.clear();
    }
    cout << "Total = " << count;

}
int main(){
    search();
    return 0;
}