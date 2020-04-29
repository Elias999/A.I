#include <iostream>
#include<math.h>
#include <list>
#include <vector>
#include <stack>
#include <algorithm>    // std::find


/*
empty() – Returns whether the stack is empty – Time Complexity : O(1)
size() – Returns the size of the stack – Time Complexity : O(1)
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
pop() – Deletes the top most element of the stack – Time Complexity : O(1)
*/
using namespace std;
class branch_bound{

  public:
     int debug = 1;

     int initx = 5;
     int inity = 1;

     int finishx = 4;
     int finishy = 4;

     //lifo metopo_anazitisis     stack <int> metopo_anazitisis;
     //Closed←∅;Frontier←<InitialState>;BestCost←∝;BestState←null;
     /*
     Οιτελεστές μεταφοράςείναιοιεξής: πήγαινε μίαθέσηαριστερά, πήγαινε μίαθέσηεπάνω,  πήγαινε  μίαθέσηδεξιά,  πήγαινε  μίαθέσηκάτω,  εφόσονηθέσηείναιελεύθερη.vΟχώροςκαταστάσεωνείναιόλεςοιελεύθερεςθέσεις,  χωρίςεμπόδια,  τουπλέγ-ματος
     */

     int dromos[6][5] = { {1,1,1,1,1}
                        ,{1,0,0,0,1}
                        ,{1,0,1,0,1}
                        ,{1,0,1,0,1}
                        ,{1,0,0,0,0} //G
                        ,{1,0,1,1,1} };
                          //I


  void make_the_box(int thebox[6][5])
  {
  // black box \u25A1 white box \u25A0
  //int dromos[6][5] = {thebox[6][5]};


  std::cout<<"\u250C";
  for (size_t g = 0; g < 19; g++) {
    std::cout << "\u2500";
  }
  std::cout<<"\u2510";
      std::cout<<"\n";
    for (int i = 0; i < 6; i++) {
      for (size_t y = 0; y < 5; y++) {

        std::cout << "\u2502"<<" ";        if (thebox[i][y] == 1) {
        std::cout << "\u25A0"<<" ";
        }
        else{
        std::cout << "\u25A1"<<" ";
        }
      }
      std::cout << "\u2502"<<" ";
      std::cout<<"\n";
      std::cout<<"\u251C";
        for (size_t g = 0; g < 19; g++) {
          std::cout << "\u2500";
      }
      std::cout<<"\u2524";
      std::cout<<"\n";
    }

}

  list<std::vector<int>> search_near(int thesix,int thesiy)
    {
      list<vector<int>>  syntetagmenes;
      vector<int> syntetagmeni;

//elegxos gia panw katw
      if (thesix < 5 && thesix > 0) {
        //check panw
        if (debug == 2){
        std::cout <<"Κάτω " << dromos[thesix - 1][thesiy] << '\n';
        //check katw
        std::cout <<"Πάνω " << dromos[thesix + 1][thesiy] << '\n';
        }

        if (dromos[thesix + 1][thesiy] != 1) {
          syntetagmeni = {(thesix + 1),thesiy};
          syntetagmenes.push_back(syntetagmeni);
          syntetagmeni.empty();
        }
        if (dromos[thesix - 1][thesiy] != 1) {
          syntetagmeni = {(thesix - 1), thesiy};
          syntetagmenes.push_back(syntetagmeni);
          syntetagmeni.empty();
        }
      }
      else if( thesix == 0){

        if (debug == 2){
        //check mono katw
        std::cout<<"Κάτω " << dromos[thesix + 1][thesiy] << '\n';
        }

        if (dromos[thesix + 1][thesiy] != 1) {
          syntetagmeni = {(thesix + 1),thesiy};
          syntetagmenes.push_back(syntetagmeni);
          syntetagmeni.empty();
        }

      }
      else if(thesix == 5){
        //check mono panw
        if (debug == 2){
        std::cout << "Πάνω "<< dromos[thesix - 1][thesiy] << '\n';
       }

       if (dromos[thesix - 1][thesiy] != 1) {
         syntetagmeni = {(thesix - 1),thesiy};
         syntetagmenes.push_back(syntetagmeni);
         syntetagmeni.empty();
       }

      }

      else{

        if (debug == 2){
        std::cout << "Kati pige lathos" << '\n';
        }

      }


      //elegxos gia de3ia aristera
      if (thesiy < 4 && thesiy > 0) {

        if (debug == 2){
          //check de3ia aristera
          std::cout <<"Δεξία " << dromos[thesix][thesiy + 1] << '\n';
          std::cout <<"Αριστερά "  << dromos[thesix][thesiy - 1] << '\n';
        }

        if (dromos[thesix][thesiy + 1] != 1) {
          syntetagmeni = {thesix,(thesiy + 1 )};
          syntetagmenes.push_back(syntetagmeni);
          syntetagmeni.empty();
       }
        if (dromos[thesix][thesiy - 1] != 1) {
          syntetagmeni = {thesix,(thesiy - 1 )};
          syntetagmenes.push_back(syntetagmeni);
          syntetagmeni.empty();
        }

      }

      else if( thesiy == 0){

        if (debug == 2){
        //check mono de3ia
          std::cout<<"Δεξία " << dromos[thesix][thesiy + 1] << '\n';
        }

        if (dromos[thesix + 1][thesiy] != 1) {
          syntetagmeni = {thesix,(thesiy +1 )};
          syntetagmenes.push_back(syntetagmeni);
          syntetagmeni.empty();
        }

      }
      else if(thesiy == 4){

        if (debug == 2){
        //check mono aristera
          std::cout <<"Αριστερά " << dromos[thesix][thesiy - 1] << '\n';

        }
        if (dromos[thesix - 1][thesiy] != 1) {
          syntetagmeni = {thesix,(thesiy - 1 )};
          syntetagmenes.push_back(syntetagmeni);
          syntetagmeni.empty();
        }

      }
      else{

        if (debug == 2){
          std::cout << "Kati pige lathos" << '\n';
        }
      }

      return syntetagmenes;

    };

  double distanceCalculate(double x1, double y1, double x2, double y2)
    {
    	double x = x1 - x2; //calculating number to square in next step
    	double y = y1 - y2;
    	double dist;

    	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
    	dist = sqrt(dist);

    	return dist;
    };

  void print(std::vector<int> const &input)
    {
      std::cout << "(";
    	for (int i = 0; i < input.size(); i++) {
    		std::cout << input.at(i) << ' ';
    	}
      std::cout << ")" << '\n' ;
    }

  void run(){
    int current_cost;
    vector<int> finalbox{finishx,finishy};
    vector<int> last_item;
    vector<vector<int>> close_state;
    vector<vector<int>> current_state,best_solution,temp_state;
    list<vector<int>> available_boxes;
    stack<vector<vector<int>>> metopo_anazitisis,temp_metopo,paidia;
    vector<vector<int>>::iterator it;

    //1o arxiki katastasi
    metopo_anazitisis.push({{initx,inity}});
    //2o arxikes timi kalyteris lysis
    int best_cost = 6*5+1;

    while (metopo_anazitisis.size() > 0) {
      std::cout << "Νέος γύρος!----------------------------------------" << '\n';
      current_state.empty();
      current_state = metopo_anazitisis.top();
      if (debug == 1) {
        std::cout << "Το πρώτο στοιχείο του μετόπου" << '\n';
        for (int is = 0; is < current_state.size(); is++) {
          print(current_state.at(is)) ;
        }
      }

      metopo_anazitisis.pop();
      current_cost = current_state.size(); //To cost einai to megethos tou dianismatos
      if (debug == 1) {
      std::cout << "Το μέτοπο αναζήτησης έχει ακόμα "<< metopo_anazitisis.size() << " στοιχεία" << '\n';
      std::cout  << "Κόστος τωρινής κατάστασης "<< current_cost << '\n';
    }
      if (best_cost > current_cost) {
        last_item = current_state.back();
        if (debug == 1) {
          std::cout << "Η τωρινή κατάστασης δεν είναι χειρότερη" << '\n';
          std::cout << "Τελευταίο στοιχείο της κατάστασης" << '\n';
          print(last_item);
          std::cout << "Τελικό στοιχείο της λύσης" << '\n';
          print(finalbox);
        }
        if ( finalbox == last_item ){ //last vector is final if final stop
          if (debug == 1) {
            std::cout << "Αλλάζει η καλύτερη λύση, βρέθηκε καλύτερη κατάσταση με μικρότερο κόστος και τελική κατάσταση" << '\n';
          }
          best_cost = current_state.size(); //best cost = posa vector yparxoun mesa sto current_state!!
          best_solution = current_state;
        }//endif
      else{
        if (debug == 1) {
          std::cout << "Η τωρινή κατάστασης δεν είναι χειρότερη αλλά δεν είναι τελική " << '\n';
        }
        last_item = current_state.back();
        available_boxes = search_near(last_item.at(0),last_item.at(1)); // current_state.end(teleutaoiovector 0),current_state.at(teleutaoiovector 1)next boxes
        for (auto const& box: available_boxes){
          temp_state = current_state; //we dont want to lose the state we join when we make the new states
          if (debug == 1) {
          std::cout << "Διαθέσιμο κουτί " ;
          print(box);
          std::cout << "Στοιχεία μέσα στη τωρινή κατάσταση" << '\n';
          for (int is = 0; is < temp_state.size(); is++) {
            print(current_state.at(is)) ;
          }
        }
          it = find (temp_state.begin(), temp_state.end(),box); //if box_vector in current_state o algorithmos leei gia to fronter
        if (it != temp_state.end() ){ // box !in current_state && close_state
          if (debug == 1) {
            std::cout << "Το στοιχείο υπάρχει μέσα στο σύνολο οπότε προσπερνάτε" << '\n';
          }
          //  close_state.push_back(current_state); prepei na dw to close state
          }
          else{
            temp_state.push_back(box);
            if (debug == 1) {
              std::cout << "Το στοιχείο δεν υπάρχει μέσα στο σύνολο" << '\n';
            std::cout << "Τα ακόλουθα στοιχεία θα μπουν στο μέτοπο αναζήτησης" << '\n';
            for (int is = 0; is < temp_state.size(); is++) {
              print(temp_state.at(is)) ;
            }
          }
            metopo_anazitisis.push(temp_state);
          }
        } //end box for
       }
      }//end first if
    }//end of while
    std::cout << "Το μέτοπο αναζήτησης έχει "<< metopo_anazitisis.size() << " Στοιχεία" << '\n';
    std::cout<<"Καλύτερο Κόστος " << best_cost << "\nΤα στοιχεία της καλύτερης λύσης \n";
    for (int is = 0; is < best_solution.size(); is++) {
      print(best_solution.at(is)) ;
    }
  };
};


int main()
{
  branch_bound algo;
  int dromos[6][5] = { {1,1,1,1,1}
                      ,{1,0,0,0,1}
                      ,{1,0,1,0,1}
                      ,{1,0,1,0,1}
                      ,{1,0,0,0,0} //G
                      ,{1,0,1,1,1} };
                        //I
  static int initx = algo.initx;
  static int inity = algo.inity;

  algo.make_the_box(dromos);
  algo.run();

  return 0;
}
