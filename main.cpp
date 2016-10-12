#include "Linked_list.h"
const int N = 10;
//
int main() {
    Linked_list list;
    Person* persons = new Person[N];
    persons[0].set_all("adsgsdb", 0, "2001:10:10");
    persons[1].set_all("jy,fyu", 1, "2001:10:10");
    persons[2].set_all("dshbarrb", 2, "2001:10:10");
    persons[3].set_all("arhj", 3, "2001:10:10");
    persons[4].set_all("srksrtk", 4, "2001:10:10");
    persons[5].set_all("fjsrj", 5, "2001:10:10");
    persons[6].set_all("rhaerj", 6, "2001:10:10");
    persons[7].set_all("aaafb", 7, "2001:10:10");
    persons[8].set_all("aaafb", 8, "2001:10:10");
    persons[9].set_all("awggf", 9, "2001:10:10");
    //
    for(int i = 0; i<N; ++i){
        list.insert(persons[i]);
    }
    list.show();
    Person insert("mazfk", 8, "2001:10:10") ;
    list.insert_by_id( insert, 0);
    cout<<endl<<endl<<"AFTERDELETING"<<endl<<endl;
    list.show();
    return 0;
}