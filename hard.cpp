#include "commands.h"
#include "alien.h"
#include "graphics.h"
#include <vector>
#include <time.h>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;




void hard(){

    //declaring variables
    graphics g;
    string blank_key;
    alien enemy;
    alien enemy2;
    enemy.set_health(100);
    enemy2.set_health(100);
    int enemy_health=enemy.get_health();
    int enemy2_health=enemy2.get_health();
    //enemy position
    int enemy_position_row=0;
    int enemy_position_col=(random_numberx());
    int enemy2_position_row=0;
    int enemy2_position_col=(random_numberx());
    while(enemy_position_col==enemy2_position_col){
        enemy_position_col=(random_numberx());
        enemy2_position_col=(random_numberx());
    }
    string row="";
    string col="";
    int column=0; //User input converted to integer
    int loop_count=0; //no of loops' count index
    vector <string> index={"1","2","3","4","5","6","7","8","9","10","1967"};
    int left=0; //hint variables left and right
    int right=0;
    int left2=0; //hint variables left and right
    int right2=0;


    while(enemy_health>0 || enemy2_health>0){
        cout << "----------------------------------------------------------------------------------------------------------------------------------" <<endl;
        cout << endl;


        //Printing board
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                if (enemy_position_row==i && enemy_position_col==j && enemy_health>0){
                    cout << " X ";
                }
                else if (enemy2_position_row==i && enemy2_position_col==j && enemy2_health>0 && enemy_position_col!=enemy2_position_col){
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
            //Enemy 1
            if (column==enemy_position_col || enemy_health<=0){
                cout << "Enemy 1 annihilated..." << endl;
                enemy.set_health(enemy.get_health()-100);
                enemy_health=enemy.get_health();
            }
            else{
                cout << "Enemy 1 survives..." << endl;
            }
            //Enemy 2
            if (column==enemy2_position_col || enemy2_health<=0){
                cout << "Enemy 2 annihilated..." << endl;
                enemy2.set_health(enemy2.get_health()-100);
                enemy2_health=enemy2.get_health();
            }
            else{
                cout << "Enemy 2 survives..." << endl;
            }
            if (enemy_health<=0 && enemy2_health<=0){
                continue;
            }
        }
        loop_count++;


        //Resetting values for next iteration
        enemy_position_row++;
        enemy2_position_row++;
        enemy_position_col=(random_numberx());
        enemy2_position_col=(random_numberx());
        while(enemy_position_col==enemy2_position_col){
            enemy_position_col=(random_numberx());
            enemy2_position_col=(random_numberx());
        }
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

        if (enemy2_position_col>=2 && enemy2_position_col<=7){
            left2=enemy2_position_col-1;
            right2=enemy2_position_col+1;
        }
        else if (enemy2_position_col<2){
            left2=1;
            right2=3;
        }else{
            left2=8;
            right2=10;
        }

        //AI lock
        if (enemy_health>0){
            cout << "AI Auto GPS: Next enemy spaceship located between column co-ordinates " << left << " and " << right << endl;
        }
        if (enemy2_health>0){
            cout << "AI Auto GPS: Next enemy spaceship located between column co-ordinates " << left2 << " and " << right2 << endl;
        }




        //User input
        cout << "Auto AI has confirmed row co-ordinates..." << endl;
        cout << "Please enter column co-ordinates...1 to 10..." << endl;
        cin >> col;
        //AI Hack
        //temporary variable
        int hack=0;
        if(col == "1967"){
            g.honor();
            hack=1;
            if (enemy_health>0 && enemy2_health>0){
                cout << "AI hack power accepted... Enemy 1 at location " << enemy_position_col+1 << " and Enemy 2 at location " << enemy2_position_col+1 << endl;
            }
            if (enemy_health>0 && enemy2_health<=0){
                cout << "AI hack power accepted... Enemy 1 at location " << enemy_position_col+1 << endl;
            }
            if (enemy_health<=0 && enemy2_health>0){
                cout << "AI hack power accepted... Enemy 2 at location " << enemy2_position_col+1 << endl;
            }
            cout << "Enter co-ordinates again..." << endl;
        }
        while(find(index.begin(),index.end(),col)==index.end() || col=="1967"){
            cout << "AI detected user input...Auto GPS locked...Enter valid attack..." << endl;
            cin >> col;
        }
        column=stoi(col);
        column--;



        //AI messages

        if (enemy_position_row==9 || enemy2_position_row==9){
            cout <<"Final human battle..." << endl;
        }
        if (enemy_position_row>9 || enemy2_position_row>9){
            system("clear");
            if (hack==1){
                cout << "Sadly, the aliens saw your hacking power at final battle and deceived it!" <<endl;
            }
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

//End of hard mode