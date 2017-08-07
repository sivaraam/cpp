#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(){
    int score;

    //Vraag de score
    cout << "Score:";
    cin >> score;

    //Switch
    switch(score){
      case 0 ... 9:
            cout << "b";
            break;
       case 11 ... 24:
            cout << "c";
            break;
       case 25 ... 49:
            cout << "d";
            break;
       case 50 ... 100:
            cout << "e";
            break;         
        default:
            cout << "BAD VALUE";
            break;
    }
    cout << endl;
    return 0;
}
