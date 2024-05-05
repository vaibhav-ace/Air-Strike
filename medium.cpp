#include "commands.h"
#include "alien.h"
#include <vector>
#include <bits/stdc++.h>
#include "graphics.h"
using namespace std;




//medium function
void medium(){

    //declaring variables
    graphics g;
    string blank_key;
    alien enemy;
    enemy.set_health(100);
    int enemy_health=enemy.get_health();

    //enemy position
    int enemy_position_row=0;
    int enemy_position_col=(random_numberx());
    string row="";
    string col="";

    int column=0; //User input converted to integer
    int loop_count=0; //no of loops' count index

    vector <string> index={"1","2","3","4","5","6","7","8","9","10"};

    int left=0; //hint variables left and right
    int right=0;


    while(enemy_health>0){

        cout << "----------------------------------------------------------------------------------------------------------------------------------" <<endl;
        cout << endl;


        //Printing board
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                if (enemy_position_row==i && enemy_position_col==j){
                    cout << " X ";
                }
                else{
                    cout << " _ ";
                }
            }
            cout << endl;
        }

        cout << endl;
        //Board finished printing


        //Enemy annihilated or survives
        if (loop_count>0){
            if (column==enemy_position_col){
                enemy.set_health(enemy.get_health()-40);
                enemy_health=enemy.get_health();
                if (enemy_health<=0){cout << "Enemy Health: " << enemy_health << "... Enemy annihilated..." << endl;}
                else{cout << "Enemy hit...Enemy Health: " << enemy_health << endl;}
            }
            else{
                cout << "Enemy survives...Enemy Health: " << enemy_health << endl;
            }
        }
        loop_count++;


        //Resetting values for next iteration
        enemy_position_row++;
        enemy_position_col=random_numberx();

        if (enemy_position_col>=2 && enemy_position_col<=7){
            left=enemy_position_col-1;
            right=enemy_position_col+1;
        }
        else if (enemy_position_col<2){
            left=1;
            right=3;
        }else{
            left=8;
            right=10;
        }

        cout << "AI Auto GPS: Next enemy spaceship located between column co-ordinates " << left << " and " << right << endl;


        //User input
        cout << "Auto AI has confirmed row co-ordinates..." << endl;
        cout << "Please enter column co-ordinates...1 to 10..." << endl;
        cin >> col;

        while(find(index.begin(),index.end(),col)==index.end()){
            cout << "AI detected user input...Auto GPS locked...Enter valid attack..." << endl;
            cin >> col;
        }

        column=stoi(col);
        column--;

        //Auto generated AI messages

        if (enemy_position_row==9){
            cout <<"Final human battle..." << endl;
        }
        if (enemy_position_row>9){
            system("clear");
            cout << "Humanity was annihilated at the hands of the aliens..." << endl;
            cout << "Game over...Exiting Game..." << endl;
            g.defeated();
            break;
        }
    }

    cout << "----------------------------------------------------------------------------------------------------------------------------------" <<endl;
    cout << endl;
    getline (cin, blank_key);

    return;
}

//End of medium mode