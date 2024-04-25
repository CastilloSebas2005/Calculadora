#include<shunting_yard.hh>
#include <stack>
#include <queue>
#include<token.hh>
#include <string>
#include<postfija.hh>
using namespace std;

calpostfija::calpostfija(shunting_yard output_Queue):output_Queue(output_Queue){
    cola=output_Queue.getOutputQueue();

}