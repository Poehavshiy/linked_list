#include "Linked_list.h"
const int N = 10;
//
int main() {
    Linked_list list;
    Person* persons = new Person[N];
    persons[0].set_all("r", 0, "2001:10:10");
    persons[1].set_all("a", 1, "2001:10:10");
    persons[2].set_all("b", 2, "2001:10:10");
    persons[3].set_all("c", 3, "2001:10:10");
    persons[4].set_all("w", 4, "2001:10:10");
    persons[5].set_all("h", 5, "2001:10:10");
    persons[6].set_all("k", 6, "2001:10:10");
    persons[7].set_all("f", 7, "2001:10:10");
    persons[8].set_all("e", 8, "2001:10:10");
    persons[9].set_all("g", 9, "2001:10:10");
    //
    for(int i = 0; i<N; ++i){
        list.insert_by_id(persons[i], i);
    }
    Person insert("mazfk", 8, "2001:10:10") ;
    list.show();
    list.sort();
    cout<<endl<<endl<<"AFTER SORTING"<<endl<<endl;
    list.show();
    return 0;
}